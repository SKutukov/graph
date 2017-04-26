#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
    ifstream in("topsort.in");
    int a,b;
    in>>a>>b;
    ofstream out("topsort.out");
    out << a+b;
    out.close();
    return 0;
}


