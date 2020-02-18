#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, x, y;

    cin >> N;

    vector < vector <int> > input;

    for (int i = 0; i < N; i++)
    {
        vector < int > tmp;
        cin >> x >> y;
        tmp.push_back(x);
        tmp.push_back(y);
        tmp.push_back(1);
        input.push_back(tmp);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;

            if (input[i][0] < input[j][0] && input[i][1] < input[j][1]) input[i][2]++;
        }
    }

    for (int i = 0; i < N; i++) cout << input[i][2] << " ";

    return 0;
}
