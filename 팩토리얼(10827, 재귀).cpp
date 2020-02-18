#include <iostream>

using namespace std;

int recursiveFactorial(int N);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;

    cin >> N;
    if (N == 0) cout << "1";
    else cout << recursiveFactorial(N);

    return 0;
}

int recursiveFactorial(int N)
{
    if (N == 1) return 1;
    return N * recursiveFactorial(N - 1);
}