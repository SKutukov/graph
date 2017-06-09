#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> adj;
int timer = 0;
vector<bool> used;
vector<int>  fup,tin;
set<long int> points;


void dfs(int v, int p = -1)
{
    used[v] = true;
    fup[v] = tin[v] = timer++;
    int k = 0;
    for (auto next : adj[v])
    {
        if (next == p)
        {
            continue;
        }
        if (used[next])
        {
            fup[v] = min (fup[v], tin[next]);
        }
        else
        {
            dfs(next, v);
            fup[v] = min (fup[next], fup[v]);
            if (p == -1)
            {
                k++;
            }
            if (fup[next] >= tin[v] && p!= -1)
            {
                points.insert(v+1);
            }

        }
    }
    if (k > 1)
    {
        points.insert(v+1);
    }
}

int main()
{
    ifstream in("points.in");
    int N, M;
    in >> N >> M;
    adj.resize(N);
    for (long int i = 1; i <= M; i++)
    {
        int a, b;
        in >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    in.close();
    used.assign(N,false);
    tin.assign(N,-1);
    fup.assign(N,-1);
// dfs
    dfs(0);
//output
    ofstream out("points.out");
    out << points.size() << endl;
    for (int q : points)
        out << q << endl;

    out.close();

    return 0;
}
