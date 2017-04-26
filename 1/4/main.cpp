#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//int dfs(int v,vector<vector<int>> A,vector<bool> used) {

//    int n=0;
//    if (used[v]) {
//        return n;
//    }
//    n+=1;
//    used[v] = true;
//    for (auto i:A[v])
//    {
//        n+=dfs(i,A,used);
//    }
//    return n;
//}
int main(int argc, char *argv[])
{
    vector<vector<int>> A;
    int N,M;
    ///---------------input data ---------------
    ifstream in("topsort.in");
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
    ///------------topsort -------------
    ///------------output data -----------
    ofstream out("topsort.out");
    int i=-1;
    out << i;
    ///------release memory ---------------
    out.close();
    return 0;
}

