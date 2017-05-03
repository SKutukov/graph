#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "deque"
using namespace std;
int MAXN=100000;
int N,M;
vector<vector<int> > adj;
vector<bool> used(MAXN);
bool isCycleExist=false;
bool isCycleEnd=false;
deque<int> cycle;
int b;
void dfs(int cur) {
    used[cur] = true;
   for (int next :adj[cur]) {
    if (used[next] == true)
    {
       b=next;
       isCycleExist=true;
    }
    if(isCycleExist &&  isCycleEnd)
    {
        if(cur!=b)
        {
           isCycleEnd=true;
        }else
        {
            cycle.push_front(cur);
        }
    }
    dfs(next);
  }
}
void findCycle() {
  for (int i=0;i<N;i++) {
    if(isCycleExist==true)
    {
        break;
    }
    if (used[i] == false) {
        dfs(i);
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
    findCycle();
    ///------------output data -----------
    ofstream out("cycle.out");
    if(isCycleExist)
    {
        out<< "YES"<<std::endl;
        for(int i=0;i<cycle.size();i++)
        {
            out<<cycle[i]+1<<' ';
        }
    }else{
        out << "NO";
    }
    ///------release memory ---------------
    out.close();
    return 0;
}
