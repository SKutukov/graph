#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <utility>
#include "algorithm"
const int inf = 100000;
using namespace std;

struct edge
{
    long int st, to;
    long long int w;

    edge(long int a,long int b, long long int c):
        st(a),to(b),w(c)
    { }

};

int main(int argc, char *argv[])
{
    ifstream in("distance.in");
    long int N,M,S, F;
    in >> N >> M >> S >> F;
    S--;
    F--;
    vector<edge> adj;
    for (int i = 0; i < M; i++)
    {
        long int a, b;
        int c;
        in >> a >> b >> c;
        a--;
        b--;
        adj.push_back(edge(a,b,c));
        adj.push_back(edge(b,a,c));
    }
    in.close();
    vector<int>  d(N);
    for (int i = 0; i < N; i++)
    {
        d[i] = inf;
    }
    d[S] = 0;

    vector<int> p (N, -1);
        for (;;) {
            bool any = false;
            for (auto next: adj)
            {
                if (d[next.st] < inf)
                    if (d[next.to] > d[next.st] + next.w) {
                        d[next.to] = d[next.st] + next.w;
                        p[next.to] = next.st;
                        any = true;
                    }
            }
            if (!any)  break;
        }


        ofstream out("distance.out");
        if (d[F] == inf)
            out << "-1";
        else {
            vector<int> path;
            for (int cur=F; cur!=-1; cur=p[cur])
                path.push_back (cur);
            reverse(path.begin(), path.end());

            out << d[F] <<endl;
            for (size_t i=0; i<path.size(); ++i)
                out << path[i] +1 << ' ';
        }
        out.close();
}
