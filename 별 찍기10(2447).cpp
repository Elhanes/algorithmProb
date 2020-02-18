#include <iostream>
#include <vector>

using namespace std;

//int starDust(int x, int y, int N); for recursive programming
//vector <vector <char> > milkyWay;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tmp, N, k, l = 1;

    cin >> N;
    tmp = 1;

    /*if (N == 1)
    {
        cout << "*\n";
        return 0;
    }
    milkyWay.resize(N);
    for (int i = 0; i < N; i++) milkyWay[i].resize(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) milkyWay[i][j] = ' ';


    starDust(0, 0, N);*/

    vector <vector <char> > milkyWay(N, vector<char>(N, '*'));

    while (1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (milkyWay[i][j] == '*' && i / tmp == 1 && j / tmp == 1)
                {
                    milkyWay[i][j] = ' ';
                    k = tmp * 3;
                    while (1)
                    {
                        if (i + k >= N) break;
                        milkyWay[i + k][j] = ' ';
                        k += tmp * 3;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (milkyWay[i][j] == ' ')
                {
                    k = tmp * 3;
                    while (1)
                    {
                        if (j + k >= N) break;
                        milkyWay[i][j + k] = ' ';
                        k += tmp * 3;
                    }
                }
            }
        }

        if (tmp == N) break;
        tmp *= 3;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cout << milkyWay[i][j];
        cout << "\n";
    }

    return 0;
}

/*int starDust(int x, int y, int N)
{
    if (N == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1) milkyWay[i + x][j + y] = ' ';
                else milkyWay[i + x][j + y] = '*';
            }
        }
        return 0;
    }

    else
    {
        int m = N / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 1 && j == 1) continue;
                starDust(x + i * m, y + j * m, m);
            }
        }
    }
}*/