#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int MAXN=100000;
int N,M;
vector<bool> used(MAXN);
vector<vector<int> > adj;
void dfs(int cur, int &n) {
  int max_d=0;
  used[cur]=true;
  for (int next :adj[cur]) {
        if(!used[next])
        {
            int d=1;
            dfs(next,d);
            max_d=std::max(d,max_d);
        }
  }
  n+=max_d;
}
int longpath() {
  int max=0;
  for (int i=0;i<N;i++) {
        int n=0;
        if(!used[i])
        {
            dfs(i,n);
        }
        max=std::max(max,n);
    }
  return max;
}


int main(int argc, char *argv[])
{
    ///---------------input data ---------------
    ifstream in("longpath.in");
    in>>N>>M;
    adj.resize(N);
    for(int i=0;i<M;i++)
    {
        int a,b;
        in>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    in.close();
    ///------------topsort -------------
    int n=longpath();
    ///------------output data -----------
    ofstream out("longpath.out");
    out<<n;
    ///------release memory ---------------
    out.close();
    return 0;
}

