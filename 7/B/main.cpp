#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

class edge
{
public:
    int to;
    long c, f;
    edge(int a, long b)
    {
        to = a;
        c = b;
        f = 0;
    }
};

vector<int> S;

vector<edge> adj;
vector<int> * g;
bool * used;
int timer;

long flow(int v, long mn)
{
    used[v] = true;
    if (v == timer)
        return mn;

    for (int i : g[v])
    {
        edge &u = adj[i];
        if (u.c > u.f && !used[u.to])
        {
            if (int f = flow(u.to, min(mn, u.c - u.f)))
            {
                u.f += f;
                adj[i ^ 1].f -= f;
                return f;
            }
        }
    }
    return 0;
}

int main()
{
    ifstream in("flow.in");
    ofstream out("flow.out");
    int n, m;
    in >> n >> m;
    timer = n - 1;
    g = new vector<int>[n];
    used = new bool[n];
    bool * edges = new bool[n];
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        long c;
        in >> a >> b >> c;
        a--; b--;
        g[a].push_back(adj.size());
        adj.push_back(edge(b, c));
        g[b].push_back(adj.size());
        adj.push_back(edge(a, c));
    }
    queue<int> q;
    q.push(n - 1);
    bool * inq = new bool[n];
    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
        inq[i] = 0;
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        used[cur] = true;
        inq[cur] = false;
        for (int i : g[cur])
        {
            edge &u = adj[i];
            if (!used[u.to])
            {
                u.f = 0;
                if (!inq[u.to])
                {
                    q.push(u.to);
                    inq[u.to] = true;
                }
            }
        }
    }

    long sum = 0;
    long f;
    do {
        for (int i = 0; i < n; i++)
            used[i] = 0;
        f = flow(0, 5000);
        sum += f;
    } while (f != 0);

    out << setprecision(7);
    out << fixed << (double)sum << '\n';
    for (int i = 0; i < m; i++)
    {
        edge &u = adj[2*i], &v = adj[2*i ^ 1];
        if (u.f < 0)
            out << fixed << (double)-v.f << '\n';
        else
            out << fixed << (double)u.f << '\n';
    }
    in.close();
    out.close();
    return 0;
}
