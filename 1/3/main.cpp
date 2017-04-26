#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


const int size =100;
int N,M;
vector<int> adj[size];
bool used[size];
vector<int> comp;

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (size_t i=0; i<adj[v].size(); ++i) {
        int next = adj[v][i];
        if (! used[next])
            dfs (next);
    }
}

int find_comps() {
    for (int i=0; i<N; ++i)
        used[i] = false;
    int n=0;
    for (int i=0; i<N; ++i)
        if (! used[i]) {
            n++;
            comp.clear();
            dfs (i);

        }
    return n;
}

using namespace std;
int main(int argc, char *argv[])
{
    ///---------------read data ---------------
    ifstream in("connect.in");
    in>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        in>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    in.close();
    bool isConnected=true;
    ///---------- begin dfs -----------
    isConnected=find_comps()==1;

    ofstream out("connect.out");
    string s=isConnected?"YES":"NO";
    std::cout<<s<<std::endl;
    out << s;
    ///------release memory ---------------
    out.close();
    return 0;
}

