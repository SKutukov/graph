#include <fstream>
#include <string>
#include <queue>
#include <list>
#include <utility>

using namespace std;
vector<bool> used[8];
vector<pair<int,int>> path[8];
int main()
{
    ifstream in;
    in.open("knight1.in");

    string S, F;
    in >> S >> F;

    in.close();
    int sx = S[0] - 97, sy = S[1] - 49, fx = F[0] - 97, fy = F[1] - 49;

    for (int i = 0; i < 8; i++)
    {
        used[i].assign(8,false);
        path[i].assign(8,make_pair(-1,-1));
    }

    queue<pair<int,int>> q;
    q.push(make_pair(sx, sy));
    used[sx][sy] = true;
    while (!q.empty())
    {
        auto v=q.front();
        int x = v.first;
        int y = v.second;
        q.pop();
        if (x > 0)
        {
            if (y < 6)
            {
                if (!used[x - 1][y+2])
                {
                    used[x - 1][y+2] = true;
                    path[x - 1][y+2] = make_pair(x, y);
                    q.push(make_pair(x - 1, y + 2));
                }
            }
            if (y > 1)
            {
                if (!used[x - 1][y-2])
                {
                    used[x - 1][y-2] = true;
                    path[x - 1][y-2] = make_pair(x, y);
                    q.push(make_pair(x - 1, y - 2));
                }
            }
        }
        if (x > 1)
        {
            if (y < 7)
            {
                if (!used[x - 2][y+1])
                {
                    used[x - 2][y+1] = true;
                    path[x - 2][y+1] = make_pair(x, y);
                    q.push(make_pair(x - 2, y + 1));
                }
            }
            if (y > 0)
            {
                if (!used[x - 2][y-1])
                {
                    used[x - 2][y-1] = true;
                    path[x - 2][y-1] = make_pair(x,y);
                    q.push(make_pair(x - 2, y - 1));
                }
            }
        }
        if (x < 6)
        {
            if (y < 7)
            {
                if (!used[x + 2][y+1])
                {
                    used[x + 2][y+1] = true;
                    path[x + 2][y+1] = make_pair(x, y);
                    q.push(make_pair(x + 2, y + 1));
                }
            }
            if (y > 0)
            {
                if (!used[x + 2][y-1])
                {
                    used[x + 2][y-1] = true;
                    path[x + 2][y-1] = make_pair(x, y);
                    q.push(make_pair(x + 2, y - 1));
                }
            }
        }
        if (x < 7)
        {
            if (y < 6)
            {
                if (!used[x + 1][y+2])
                {
                    used[x + 1][y+2] = true;
                    path[x + 1][y+2] = make_pair(x, y);
                    q.push(make_pair(x + 1, y + 2));
                }
            }
            if (y > 1)
            {
                if (!used[x + 1][y-2])
                {
                    used[x + 1][y-2] = true;
                    path[x + 1][y-2] = make_pair(x, y);
                    q.push(make_pair(x + 1, y - 2));
                }
            }
        }
        if (path[fx][fy].first != -1)
        {
            break;
        }
    }

    ofstream out("knight1.out");
    list<pair<int,int>> toOut;
    toOut.push_front(make_pair(fx,fy));
    pair<int,int> p = path[fx][fy];
    int l=0;
    while (l != -1)
    {
        toOut.push_front(p);
        p = path[p.first][p.second];
        l=p.first;
    };

    for (auto i = toOut.begin(); i != toOut.end(); i++)
    {
        out << (char)(i->first + 97) << (char)(i->second + 49) << endl;
    }
    out.close();

    return 0;
}
