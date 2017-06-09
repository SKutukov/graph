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
int color=0;
vector<vector<int>> adj, adjT;
vector<int> used;
vector<int> colors;
vector<int> order;
//vector<int> component;
set<pair<int, int>> condense_adj;

void dfs1(int v)
{
    used[v] = true;
    for (int next : adj[v])
    {
        if (!used[next])
        {
            dfs1(next);
        }
    }
    order.push_back(v);
}
void dfs2 (int v) {
    used[v] = true;
//    component.push_back(v);
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

///// first dfs
    used.assign (N, false);
    for (int i=0; i<N; ++i)
    {
        if (!used[i])
        {
            dfs1(i);
        }
    }

/////////

    used.assign (N, false);
    for (int i = 0; i != order.size(); i++)
    {
                int v = order[N-1-i];
                if (!used[v])
                {
                    color++;
                    dfs2 (v);
//                    for(int i=0;i<component.size();i++)
//                    {
//                        std::cout<<component[i]<<' ';
//                    }
//                    component.clear();
                }
 //               std::cout<<std::endl;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j : adj[i])
        {
            if (colors[i] != colors[j])
            {
                condense_adj.insert(make_pair(colors[i], colors[j]));
            }
        }
    }


   ofstream out("condense2.out");
   out<<condense_adj.size();
   out.close();

   return 0;
}
