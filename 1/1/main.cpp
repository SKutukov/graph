#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    ifstream in("sum.in");
    int a,b;
    in>>a>>b;
    ofstream out("sum.out");
    out << a+b;
    out.close();
    return 0;
}


