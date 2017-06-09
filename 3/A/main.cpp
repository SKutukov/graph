#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
const int inf=100000;
int main()
{
    ifstream in("diameter.in");
    int N;
    in >> N;
    vector<vector<long int>> w(N);
    long int D = 0;
    vector<long int> ext(N);
    for (int i = 0; i < N; i++)
    {
        ext[i] = 0;
        w[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            int a;
            in >> a;
            w[i][j]= (a == -1) ? inf : a;
        }
    }
    in.close();

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                w[i][j]=min<int>(w[i][k] + w[k][j],w[i][j]);
            }

    for (int i = 0; i<N; i++)
        for (int j = 0; j < N; j++)
        {
            ext[i]=max(ext[i], w[i][j]);
            D=max(w[i][j],D);
         }

    long R = ext[0];
    for (int i = 1; i < N; i++)
        R=min(R,ext[i]);

    ofstream out;
    out.open("diameter.out");
    out << D << endl;
    out << R;
    out.close();

}
