#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, ans = 0, tmp1 = 0, tmp2 = 0;
    char color;

    cin >> N >> M;

    vector < vector <char> > input;
    vector < vector <char> > whiteBoard(8, vector<char>(8, ' '));
    vector < vector <char> > blackBoard(8, vector<char>(8, ' '));

    for (int i = 0; i < N; i++)
    {
        vector < char > tmp;
        for (int j = 0; j < M; j++)
        {
            cin >> color;
            tmp.push_back(color);
        }
        input.push_back(tmp);
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                whiteBoard[i][j] = 'W';
                blackBoard[i][j] = 'B';
            }
            else if (i % 2 == 0 && j % 2 == 1)
            {
                whiteBoard[i][j] = 'B';
                blackBoard[i][j] = 'W';
            }
            else if (i % 2 == 1 && j % 2 == 1)
            {
                whiteBoard[i][j] = 'W';
                blackBoard[i][j] = 'B';
            }
            else if(i % 2 == 1 && j % 2 == 0)
            {
                whiteBoard[i][j] = 'B';
                blackBoard[i][j] = 'W';
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i + 7 < N && j + 7 < M)
            {
                for (int k = 0; k < 8; k++)
                {
                    for (int l = 0; l < 8; l++)
                    {
                        if (input[k + i][l + j] != whiteBoard[k][l]) tmp1++;
                        if (input[k + i][l + j] != blackBoard[k][l]) tmp2++;
                    }
                }
                if (i == 0 && j == 0) ans = tmp1;

                if (ans > tmp1) ans = tmp1;
                if (ans > tmp2) ans = tmp2;

                tmp1 = 0;
                tmp2 = 0;
            }
        }
    }

    cout << ans;

    return 0;
}
