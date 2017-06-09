#include <fstream>
#include <vector>

using namespace std;

vector<int>  mt;
vector<bool> used;
vector<vector<int>>  adj;

bool kuhn(int v)
{
    if (used[v])
    {
        return false;
    }
    used[v] = true;
    for (auto next:adj[v])
    {
        if (mt[next] == -1 || kuhn(mt[next]))
        {
            mt[next] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream in("pairs.in");
    int N, M;
    in >> N >> M;
    mt.assign(M,-1);
    used.resize(N);
    adj.resize(N);

    for (int i = 0; i < N; i++)
    {
        int a;
        in >> a;
        while (a!= 0)
        {
            a--;
            adj[i].push_back(a);
            in >> a;
        }
    }
    in.close();
    for (int i = 0; i<N; i++)
    {
        used.assign(N,false);
        kuhn(i);
    }
    vector<pair<int, int> > toOut;
    for (int i = 0; i<M; i++)
    {
        if (mt[i]!= -1)
            toOut.push_back(make_pair(mt[i]+1, i+1));
    }

    ofstream out("pairs.out");
    out << toOut.size() << '\n';
    for (auto u : toOut)
    {
        out << u.first << ' '<< u.second << '\n';
    }
    out.close();
    return 0;
}
