#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, a, max = 0;
    vector <int> counting(10001, 0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        counting[a]++;
        if (max < a) max = a;
    }

    for (int i = 0; i <= max; i++)
    {
        while (counting[i] != 0)
        {
            cout << i << "\n";
            counting[i]--;
        }
    }

    return 0;
}