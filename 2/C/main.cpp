#include <iostream>
#include <fstream>
#include <vector>

const long long int wa = 1e18;
const long long int inf = 1e11;

using namespace std;
vector<long long int> dist;
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
    ifstream in;
    in.open("fb.in");
    long int N, M, S, T;
    in >> N >> M >> S >> T;
    S--; T--;
    vector<edge> adj;
    for (int i = 0; i < M; i++)
    {
        long int a, b;
        long long int c;
        in >> a >> b >> c;
        a--;
        b--;
        adj.push_back(edge(a,b,c));
    }
    dist.resize(N);
    for (int i = 0; i < N; i++)
    {
        dist[i] = inf;
    }
    in.close();

   dist[S] = 0;
   while(true)
   {
       bool any = false;
       for (auto e:adj)
           if (dist[e.st] < inf)
           {
               if (dist[e.to] > dist[e.st] + e.w)
               {
                   dist[e.to] = dist[e.st] + e.w;
                   any = true;
               }
           }
       if (!any)  break;
   }



    ofstream out;
    out.open("fb.out");
    if (dist[T] == inf )
    {
        out << wa;
    }
    else
    {
        out << dist[T];
    }


    out.close();

    return 0;
}
