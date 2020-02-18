#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, tmp, max = 0;

    cin >> N >> M;

    vector <int> cards(N);

    for (int i = 0; i < N; i++) cin >> cards[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                tmp = cards[i] + cards[j] + cards[k];
                //cout << i << " " << j << " " << k << " : " << tmp << "\n";
                if (max < tmp && tmp <= M) max = tmp;
                tmp = 0;
            }
        }
    }

    cout << max << "\n";

    return 0;
}
