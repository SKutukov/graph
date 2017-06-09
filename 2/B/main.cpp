#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <list>
using namespace std;
const int maxN=100000;

queue<int> q;
vector<vector<int>> adj;
vector<bool> baron, used;
vector<int> dist, path;

void bfs(int S)
{
    list<int> q;
    q.push_back(S);
    dist[S] = 0;
    while (!q.empty())
        {
            int v = q.front();
            int d = dist[v];
            used[v] = false;
            q.pop_front();
            for (int next : adj[v])
            {
                if (!used[next])
                {
                    if (baron[v] == baron[next])
                    {
                        if (d < dist[next])
                        {
                            q.push_front(next);
                            used[next] = true;
                            dist[next] = d;
                            path[next] = v;
                        }
                    }
                    else
                    {
                        if (d + 1 < dist[next])
                        {
                            q.push_back(next);
                            dist[next] = d + 1;
                            path[next] = v;
                            used[next] = true;
                        }
                    }
                }
            }
        }
}

int main()
{
    int N, M;
/// input data
    ifstream in;
    in.open("island.in");
    in >> N >> M;
    dist.resize(N);
    adj.resize(N);
    baron.resize(N);
    used.resize(N);
    path.resize(N);

    used.assign (N, false);
    path.assign(N,-1);
    for (int i = 0; i < N; i++)
    {
        int b;
        in >> b;
        baron[i] = b-1;
        dist[i]=maxN;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        in >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

   in.close();
/// bfs
   bfs(0);

/// output
   ofstream out;
   out.open("island.out");

   if(path[N - 1] != -1)
   {
       list<int> path_res;
       int prev = path[N - 1];
       while (prev != 0)
       {
           path_res.push_front(prev);
           prev = path[prev];
       }
       out << dist[N - 1];
       out << ' ' ;
       out<< path_res.size() + 2;
       out<< endl;
       out << 1 << ' ';
       for (auto i = path_res.begin(); i != path_res.end(); i++)
       {
                   out << *i + 1 << ' ';
       }
       out << N;

   }
   else{
        out << "impossible";
   }
   out.close();
   return 0;


}


