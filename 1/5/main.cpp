#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int MAXN=100000;
int N,M;
vector<bool> used(MAXN);
vector<vector<int> > adj;
vector<int> depths;

int dfs(int cur) {
  int max_d=0;
  used[cur]=true;

  for (int next :adj[cur])
  {
        if(!used[next])
        {
            int d=dfs(next);
            max_d=std::max(d+1,max_d);
        }
        if (used[next])
        {
            max_d=std::max(depths[next] + 1,max_d);
        }
  }
  depths[cur]=max_d;
  return max_d;
}
int longpath() {
  int max=0;
  for (int i=0;i<N;i++) {
        int n=0;
        if(!used[i])
        {
           n=dfs(i);
           max=std::max(max,n);
        }

    }
  return max;
}


int main(int argc, char *argv[])
{
    ///---------------input data ---------------
    ifstream in("longpath.in");
    in>>N>>M;
    adj.resize(N);
    depths.resize(N);
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
    int maxLen=longpath();
    ///------------output data -----------
    ofstream out("longpath.out");
    out<<maxLen;
    ///------release memory ---------------
    out.close();
    return 0;
}

