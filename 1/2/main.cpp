#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    ifstream in("m2e.in");
    int n;
    in>>n;
    ofstream out("m2e.out");
    int k;
    for(int i=1;i<=n;i++)
    {
        for(int s=1;s<=i;s++)
        {
            in>>k;
        }
        for(int j=i+1;j<=n;j++)
        {
            in>>k;
            if(k==1)
            {
                out <<i;
                out <<' ';
                out <<j;
                out <<std::endl;
            }
            k=0;
        }
    }
    out.close();
    in.close();
    return 0;
}
