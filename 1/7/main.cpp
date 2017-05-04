#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "deque"
#include "set"
#include "map"
using namespace std;
int MAXN=100000;
int N,M;

vector<vector<int>> adj, adjT;
vector<int> used;
vector<int> colors;
int color=0;
vector<int> order,component;
vector<set<int>> component_adj;
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<adj[v].size(); ++i)
        if (!used[ adj[v][i] ])
            dfs1 (adj[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back(v);
    colors[v]=color;
    for (size_t i=0; i<adjT[v].size(); ++i)
        if (!used[ adjT[v][i] ])
            dfs2 (adjT[v][i]);
}


int main(int argc, char *argv[])
{
    ///---------------input data ---------------
    ifstream in("condense2.in");
    in>>N>>M;
    adj.resize(N);
    adjT.resize(N);
    colors.resize(N);
    for(int i=0;i<M;i++)
    {
        int a,b;
        in>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }
    in.close();

    used.assign (N, false);
    for (int i=0; i<N; ++i)
    {
        if (!used[i])
        {
            dfs1 (i);
        }
    }
    int a=0;
    used.assign (N, false);
    for (int i=0; i<N; ++i)
    {
        int v = order[N-1-i];
        if (!used[v])
        {
            a++;
            dfs2 (v);
            for(int i=0;i<component.size();i++)
            {
                std::cout<<component[i]<<' ';
            }
            component.clear();
        }
        std::cout<<std::endl;
    }
    component_adj.resize(a);
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            component_adj[colors[i]].insert(colors[j]);
        }
    }
    int c=0;
    for(int i=0;i<component_adj.size();i++)
    {
        c+=component_adj[i].size();
    }
   ofstream out("condense2.out");
   out<<c;
   out.close();

   return 0;
}
