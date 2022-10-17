#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MaxSzie = 100001;
int Balloons[MaxSzie];

int N, length;

void GetCoordinate()
{
    cin >> N >> length;
    for (int i = 0; i < N; ++i)
    {
        cin >> Balloons[i];
    }
}

void BallonPop()
{
    int poistion = 0, num = 0;
    int tempBalloon, tempPoistion, tempNum;
    for (int i = N - 1; i >= 0; --i)
    {
        tempPoistion = Balloons[i] - length;
        tempBalloon = i;
        tempNum = 0;
        while (true)
        {
            if (Balloons[tempBalloon] >= tempPoistion && tempBalloon >= 0)
            {
                --tempBalloon;
                ++tempNum;
            }
            else
            {
                break;
            }
        }
        if (tempNum >= num)
        {
            num = tempNum;
            poistion = tempPoistion;
        }
    }
    cout << poistion << ' ' << num;
}

int main()
{
    GetCoordinate();
    BallonPop();
    return 0;
}