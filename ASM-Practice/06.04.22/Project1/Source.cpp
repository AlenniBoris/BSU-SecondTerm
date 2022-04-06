#include <iostream>

using namespace std;
int mas[4][5];
bool IsMin(int m, int v);
bool IsMax(int m, int v);
void main()
{
    cout << "enter matrix\n";
    for (int i = 0; i < 4; i++)
        cin >> mas[i][0] >> mas[i][1] >> mas[i][2] >> mas[i][3] >> mas[i][4];
    int cCounter = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (IsMin(i, j) && IsMax(i, j))
            {
                cCounter++;
                cout << i << ' ' << j << endl;
            }
        }
    }
    if (cCounter == 0)
        cout << "error can't find\n";
}

bool IsMin(int m, int v)
{
    int min = mas[m][v];
    for (int i = 0; i < 5; i++)
        if (min > mas[m][i])
            return false;
    return true;
}

bool IsMax(int m, int v)
{
    int max = mas[m][v];
    for (int i = 0; i < 4; i++)
        if (max < mas[i][v])
            return false;
    return true;
}