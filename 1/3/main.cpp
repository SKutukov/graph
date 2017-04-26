#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    ///---------------input data ---------------
    ifstream in("connect.in");
    int N,M;
    in>>N>>M;
    bool** A=new bool*[N];
    for(int i=0;i<N;i++)
        A[i]=new bool[N];
    for(int i=0;i<M;i++)
    {
        int a,b;
        in>>a>>b;
        A[a][b]=true;
    }
    in.close();
    bool isConnected=true;
    auto dfs= [=]()
    {
        return true;
    };

    for(int i=0;i<N;i++)
    {
        bool* B=new bool[N];
        for(int j=0;j<N;i++)
        {
            if(A[i,j])
            {
                B[j]=true;
                continue;
            }else{

            }
        }
    }
    ofstream out("connect.out");
    out << isConnected?"YES":"NO";
    ///------release memory ---------------
    out.close();
    for(int i=0;i<N;i++)
        delete A[i];
    delete A;
    return 0;
}

