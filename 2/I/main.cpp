#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const long long int inf = 100000;

using namespace std;

struct edge
{
    long int st, to;
    long long int w;

    edge(long int a,long int b, long long int c):
        st(a),to(b),w(c)
    { }

};

int main()
{
    vector<long long int> dist;
    ifstream in;
    in.open("negcycle.in");
    long int N,M=0;
    in >> N;
    vector<edge> adj;
    for (int i = 0; i < N; i++)
        {
            int w;
            for (int j = 0; j < N; j++)
            {
                in >> w;
                if(w !=100000)
                {
                    adj.push_back(edge(i,j,w));
                    M++;
                }
          }
    }

    dist.resize(N);
    for (int i = 0; i < N; i++)
    {
        dist[i] = 0;
    }
    in.close();

    //dist[0] = 0;
    vector<int> path(N, -1);
    int x;
    for (int i=0; i<N; ++i)
    {
        x = -1;
        bool any = false;
        for (int j=0; j<M; ++j)
        {
            if (dist[adj[j].st] < inf)
                if (dist[adj[j].to] > dist[adj[j].st] + adj[j].w)
                {
                    dist[adj[j].to] = std::max(-inf, dist[adj[j].st] + adj[j].w);
                    path[adj[j].to] = adj[j].st;
                    x = adj[j].to;
                    any = true;
                }

        }
        if (!any)  break;
    }

    ofstream out;
    out.open("negcycle.out");
    if (x == -1)
    {
        out << "NO"<<std::endl;
    }
    else {
        out << "YES"<<std::endl;
        int y = x;
        for (int i=0; i<N; ++i)
            y = path[y];

        vector<int> path_res;
        for (int cur=y; ; cur=path[cur]) {
            path_res.push_back (cur);
            if (cur == y && path_res.size() > 1)
            {
                break;
            }
        }
        reverse (path_res.begin(), path_res.end());
        out << path_res.size()-1<<std::endl;
        for (size_t i=0; i<path_res.size()-1; ++i)
            out << path_res[i]+1 << ' ';
    }

    out.close();

    return 0;
}
