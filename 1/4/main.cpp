#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int MAXN=100000;
int N,M;
enum COLOR{WHITE,GRAY,BLACK};
vector<vector<int> > adj;
vector<COLOR> used(MAXN);
bool isTopExist=true;
void dfs(int cur, vector<int> &res) {
    used[cur] = GRAY;
  for (int next :adj[cur]) {
    if (used[next] == GRAY)
        {
             isTopExist=false;
             return;
        }
    if (used[next] == WHITE)
      dfs(next,res);
  }
  used[cur] = BLACK;
  res.push_back(cur);
}
void topsort(vector<int> &res) {
  for (int i=0;i<N;i++) {
    if (used[i] == WHITE) {
        dfs(i,res);
      }
    }
}


int main(int argc, char *argv[])
{
    ///---------------input data ---------------
    ifstream in("topsort.in");
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
    vector<int> res;
    topsort(res);
    ///------------output data -----------
    ofstream out("topsort.out");
    if(isTopExist)
    {
        for(int i=res.size()-1;i>=0;i--)
            {
                std::cout<<res[i]+1<<std::endl;
                out <<res[i]+1<<' ';
            }
    }else{
        out << "-1";
    }
    ///------release memory ---------------
    out.close();
    return 0;
}

