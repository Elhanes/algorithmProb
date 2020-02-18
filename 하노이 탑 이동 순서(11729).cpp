#include <iostream>
#include <vector>

using namespace std;

void hanoi(int N, int from, int by, int to);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, n = 1;

    cin >> N;

    for (int i = 1; i <= N; i++) n *= 2;
    cout << n - 1 << "\n";
    hanoi(N, 1, 2, 3);

    return 0;
}

void hanoi(int N, int from, int by, int to)
{
    if (N == 1) cout << from << " " << to << "\n";
    else
    {
        hanoi(N - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(N - 1, by, from, to);
    }
}
