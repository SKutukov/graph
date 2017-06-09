#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const long long int inf = 1e16;

int main()
{
	ifstream in;
	in.open("path.in");
    int N, M, S;
    in >> N >> M >> S;
    S--;
    vector<vector<pair<int, long long int>>> adj(N);
    for (int i = 0; i < M; i++)
	{
		int a, b;
        long long int c;
		in >> a >> b >> c;
		a--;
		b--;
        adj[a].push_back(make_pair(b,c));
	}
    in.close();
    vector<long long int> dist(N);
    vector<bool> isExists(N);

    for (int i = 0; i < N; i++)
	{
        dist[i] = inf;
        isExists[i] = true;
	}

    dist[S] = 0;
    bool any;
    for (int i = 0; i < N - 1; i++)
	{
        any = false;
        for (int j = 0; j < N; j++)
		{
            for (auto next : adj[j])
                if (dist[j] < inf)
                    if (dist[next.first] > dist[j] + next.second)
					{
                        dist[next.first] = dist[j] + next.second;
                        any = true;
					}
		}
        if (!any)
		{
            break;
		}
	}
    bool neg_cicle = false;
    for (int j = 0; j < N; j++)
    {
        for (auto next : adj[j])
            if (dist[j] < inf)
                if (dist[next.first] > dist[j] + next.second)
                {
                    dist[next.first] = dist[j] + next.second;
                    neg_cicle = true;
                    isExists[next.first] = false;
                }
    }

    //bfs
    if (neg_cicle)
	{
        if (isExists[S])
		{
			queue<int> q;
            for (int i = 0; i < N; i++)
                if (!isExists[i])
					q.push(i);
			while (!q.empty())
			{
                int v = q.front();
				q.pop();
                for (auto next : adj[v])
				{
                    if (isExists[next.first])
					{
                        isExists[next.first] = false;
                        q.push(next.first);
					}
				}
			}
		}
	}

    ofstream out;
    out.open("path.out");
    for (int i = 0; i < N; i++)
	{
        if (isExists[i])
        {
            if (dist[i] <= 0.5*inf)
                out << dist[i] << endl;
            else
                out << '*' << endl;
        }
		else
		{
            out << '-' << endl;
		}
	}
	out.close();

	return 0;
}
