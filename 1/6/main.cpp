#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "deque"
using namespace std;
int MAXN=100000;
int N,M;
vector<vector<int> > adj;
vector<char> used;
vector<int> path;
int cycle_status, cycle_end;

bool dfs (int v) {
    used[v] = 1;
    for (auto next:adj[v]) {
        if (used[next] == 0) {
            path[next] = v;
            if (dfs (next))  return true;
        }
        else if (used[next] == 1) {
            cycle_end = v;
            cycle_status = next;
            return true;
        }
    }
    used[v] = 2;
    return false;
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

     path.assign (N, -1);
     used.assign (N, 0);
     cycle_status = -1;
     for (int i=0; i<N; ++i)
         if (dfs (i))
             break;

     ofstream out("cycle.out");
     if (cycle_status == -1)
         out<<"NO";
     else {
         out<<"YES"<<std::endl;
         vector<int> cycle;
         cycle.push_back(cycle_status);
         for (int v=cycle_end; v!=cycle_status; v=path[v])
             cycle.push_back(v);
         cycle.push_back (cycle_status);
         for (size_t i=cycle.size()-1; i>0; i--)
             out<<cycle[i]+1<<' ';
     }

    return 0;
}
