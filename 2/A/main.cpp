#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
const int maxN=100;
bool used[maxN];
queue<int> q;
vector<vector<int>> adj;
int N, F, S;
vector<int> dist;
bool isExist=false;

void bfs(int S)
{

    q.push(S);
    dist[S] = 0;

    while (!q.empty())
    {
        int v = q.front();
        int d = dist[v]+1;
        q.pop();
        for (int next : adj[v])
        {
            if (dist[next] > d)
            {
                dist[next] = d;
                if (next == F)
                {
                    isExist=true;
                    return;
                }
                q.push(next);
            }
        }
    }

}

int main()
{


    ifstream in;
    in.open("bfs.in");
    in >> N >> S >> F;
    dist.resize(N);
    adj.resize(N);
    F--; S--;
    for (int i = 0; i < N; i++)
    {
        int w;
        dist[i] = maxN*maxN;
        for (int j = 0; j < N; j++)
        {
            in >> w;
            if (w == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
   in.close();



    bfs(S);

    ofstream out;
    out.open("bfs.out");

    if(isExist)
    {
         out << dist[F] << endl;
    }
    else{
         out << 0 << endl;
    }
    out.close();
    return 0;


}
