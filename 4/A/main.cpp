#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
struct edge{
    int to;
    int num;
    edge(int t,int n):
        to(t),num(n){}
};

vector<vector<edge>> adj;
int timer;
vector<bool> used;
vector<int>  tin,fup;
set<long int> bridges;

void dfs(int v, int p = -1)
{
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (auto next:adj[v])
    {
        if (next.to == p)
        {
            continue;
        }
        if (used[next.to])
        {
            fup[v] = min (fup[v], tin[next.to]);
        }
        else
        {
            dfs(next.to, v);
            fup[v] = min (fup[next.to], fup[v]);
            if (fup[next.to] > tin[v])
            {
                bridges.insert(next.num);
            }

        }
    }
}

int main()
{
    ifstream in("bridges.in");
    int N,M;
    in >> N >> M;
    adj.resize(N);
    for (long int i = 1; i <= M; i++)
    {
        int a, b;
        in >> a >> b;
        a--;
        b--;
        adj[a].push_back(edge(b,i));
        adj[b].push_back(edge(a,i));
    }
    in.close();

    used.resize(N);
    tin.resize(N);
    fup.resize(N);
    timer = 0;
    for (int i=0; i<N; ++i)
    {
           used[i] = false;
           tin[i]=-1;
           fup[i]=-1;
    }
// dfs
    dfs(0);
//output
    ofstream out("bridges.out");
    out << bridges.size() << endl;
    for ( int q : bridges)
    {
        out << q << ' ';
    }
    out.close();

    return 0;
}
