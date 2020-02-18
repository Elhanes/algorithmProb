#include <iostream>
#include <vector>

using namespace std;

int calFamily(int k, int n);

int main()
{
    int K, N, T;
    cin >> T;
    vector <int> answer;

    for (int i = 0; i < T; i++)
    {
        cin >> K >> N;
        answer.push_back(calFamily(K, N));
    }

    for (int i = 0; i < T; i++) cout << answer[i] << "\n";

    return 0;
}

int calFamily(int k, int n)
{
    vector < vector <int> > memo(k, vector<int>(n, 0));
    int tmp = 0;
    
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0) memo[i][j] = j + 1;
            else
            {
                if (j == 0) memo[i][j] = 1;
                else
                {
                    for (int l = 0; l <= j; l++) memo[i][j] += memo[i - 1][l];
                }
            } 
        }
    }

    for (int i = 0; i < n; i++) tmp += memo[k - 1][i];

    return tmp;
}