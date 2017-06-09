#include <fstream>

using namespace std;
#define max_N 1000000
#define max_A 20

//0 undefined
//1 first
//2 second
int winner[max_N+1] = {0};

long int a[max_A] = {0};
int K;

int dfs(long int u)
{
    if (winner[u]!=0)
    {
        return winner[u];
    }
    for (int i = 0; i<K; i++)
    {
        long int v = a[i];
        if ((u-v)>=0)
        {
            if (dfs(u-v) == 2)
            {
                winner[u]=1;
                return 1;
            }
        }
    }
    winner[u]=2;
    return  2;
}

int main()
{
    ifstream in("heaps2.in");
    in >> K;
    winner[0] = 2;
    for (int i = 0; i<K; i++)
    {
        long int b;
        in >> b;
        a[i]=b;
        winner[b] = 1;
    }

    int M;
    in >> M;
    ofstream out("heaps2.out");
    for (int i = 0; i<M; i++)
    {
        long int b;
        in >> b;
        if (dfs(b)==1)
        {
            out << "First\n";
        }
        else
        {
            out << "Second\n";
        }
    }

    in.close();
    out.close();

    return 0;
}

