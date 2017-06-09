#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <utility>

const int inf = 100000;

using namespace std;

int main()
{
    ifstream in("distance.in");
    long int N,M,S, F;
    in >> N >> M >> S >> F;
    S--;
    F--;
    vector<vector<pair<long int, int>>>  adj(N);
    for (int i = 0; i < M; i++)
    {
        long int a, b;
        int c;
        in >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    in.close();
    vector<int>  d(N);
    for (int i = 0; i < N; i++)
    {
        d[i] = inf;
    }
    d[S] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        bool any = false;
        for (int j = 0; j < N; j++)
        {
            for (auto next : adj[j])
                if (d[next.first] > d[j] + next.second)
                {
                    d[next.first] = d[j] + next.second;
                    any = true;
                }
        }
        if (!any)
        {
            break;
        }
    }

    ofstream out("distance.out");
    if (d[F] < inf)
    {
        out << d[F];
    }
    else
    {
        out << -1;
    }
    out.close();

    return 0;
}

