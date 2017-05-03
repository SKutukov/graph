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
bool isCycleExist=false;
vector<int> cycle;
void dfs(int cur, vector<int> &res) {
    used[cur] = GRAY;
  for (int next :adj[cur]) {
    if (used[next] == GRAY)
    {
          isCycleExist=true;
          cycle.push_back(cur);
          return;
    }
    if (isCycleExist)
    {
        cycle.push_back(cur);
    }
    if (used[next] == WHITE)
      dfs(next,res);
  }
  used[cur] = BLACK;
  res.push_back(cur);
}
void findCycle(vector<int> &res) {
  for (int i=0;i<N;i++) {
    if(isCycleExist==true)
    {
        break;
    }
    if (used[i] == WHITE) {
        dfs(i,res);
      }
    }
}


int main(int argc, char *argv[])
{
    ///---------------input data ---------------
    ifstream in("cycle.in");
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
    findCycle(res);
    ///------------output data -----------
    ofstream out("cycle.out");
    if(isCycleExist)
    {
        out<< "YES"<<std::endl;
        for(auto c:cycle)
        {
            out<<c<<' ';
        }
    }else{
        out << "NO";
    }
    ///------release memory ---------------
    out.close();
    return 0;
}
