#include <fstream>
#include <vector>

using namespace std;

vector<bool>  usedl,usedr;
vector<int>  mt;
vector<vector<int>>  adj;

bool kuhn(int v)
{
    if (usedl[v])
    {
        return false;
    }
    usedl[v] = true;
    for (auto u : adj[v])
    {
        usedr[u] = true;
        if (mt[u] == -1 || kuhn(mt[u]))
        {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream in("minimal.in");
    int M,N;
    in >> M >> N;
    usedl.assign(M,false);
    usedr.assign(N,false);
    adj.resize(M);
    mt.assign(N,-1);
    for (int i =0; i<M; i++)
    {
        int a;
        in >> a;
        for (int j = 0; j<a; j++)
        {
            int b;
            in >> b;
            b--;
            adj[i].push_back(b);
        }
    }

    vector<int> g;
    int size = 0;
    for (int i = 0; i<M; i++)
    {
        int a;
        in >> a;
        if (a==0)
            g.push_back(i);
        else
        {
            size++;
            mt[a-1] = i;
        }
    }
    in.close();
    for (int u : g)
    {
        kuhn(u);
    }


    ofstream out("minimal.out");
    vector<int> left, right;
    for (int i =0; i<M; i++)
    {
        if (!usedl[i])
        {
            left.push_back(i);
        }
    }
    for (int i = 0; i<N; i++)
    {
        if (usedr[i])
        {
            right.push_back(i);
        }
    }

    out << size << endl;
    out << left.size() << ' ';
    for (int u : left)
    {
        out << u+1 << ' ';
    }
    out << endl ;
    out<< right.size() << ' ';
    for (int u : right)
    {
        out << u+1 << ' ';
    }
    out.close();
    return 0;
}
