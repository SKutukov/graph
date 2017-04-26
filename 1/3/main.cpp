#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int dfs(int v,vector<vector<int>> A,vector<bool> used) {

    int n=0;
    if (used[v]) {
        return n;
    }
    n+=1;
    used[v] = true;
    for (auto i:A[v])
    {
        n+=dfs(i,A,used);
    }
    return n;
}
using namespace std;
int main(int argc, char *argv[])
{
    vector<vector<int>> A;
    int N,M;
    ///---------------read data ---------------
    ifstream in("connect.in");
    in>>N>>M;
    A.resize(N);
    for(int i=0;i<M;i++)
    {
        int a,b;
        in>>a>>b;
        a--;
        b--;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    in.close();
    bool isConnected=true;
    ///---------- begin dfs -----------
    for(int i=0;i<N;i++)
    {
        vector<bool> used(A.size());
        isConnected=dfs(i,A,used)==N;
    }
    ofstream out("connect.out");
    string s=isConnected?"YES":"NO";
    out << s;
    ///------release memory ---------------
    out.close();
    return 0;
}

