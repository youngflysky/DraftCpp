#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MaxSzie = 10005;
typedef struct
{
    int Nin = 0;
    int Nout = 0;
    vector<int> follers;
    int OofOL = 0;
} Node;
int N, T;
int maxOP = 0;
Node G[MaxSzie];
vector<int> oLeaders;

void IniteG()
{
    for (int i = 1, v; i <= N; ++i)
    {
        cin >> G[i].Nout;
        for (int j = 0; j < G[i].Nout; ++j)
        {
            cin >> v;
            ++G[v].Nin;
            G[v].follers.push_back(i);
        }
    }
}

void OLeaders()
{
    for (int i = 1; i <= N; ++i)
    {
        if (G[i].Nin >= T * G[i].Nout)
        {
            oLeaders.push_back(i);
        }
    }
}

void ListOL()
{
    int i;
    for (int x = 0; x < oLeaders.size(); ++x)
    {
        i = oLeaders[x];
        for (int j = 0; j < G[i].follers.size(); ++j)
        {
            for (int k = 0; k < oLeaders.size(); ++k)
            {
                if (G[i].follers[j] == oLeaders[k])
                {
                    ++G[i].OofOL;
                }
            }
        }
        if (maxOP < G[i].OofOL)
        {
            maxOP = G[i].OofOL;
        }
    }
    for (int x = 0, space = 0; x < oLeaders.size(); ++x)
    {
        i = oLeaders[x];
        if (G[i].OofOL == maxOP)
        {
            if (space)
            {
                cout << ' ' << i;
            }
            else
            {
                cout << i;
                space = 1;
            }
        }
    }
}

int main()
{
    cin >> N >> T;
    IniteG();
    OLeaders();
    ListOL();
    return 0;
}