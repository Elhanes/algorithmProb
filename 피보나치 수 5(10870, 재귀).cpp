#include <iostream>

using namespace std;

int recursiveFibonacci(int N);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;

    cin >> N;
    cout << recursiveFibonacci(N);

    return 0;
}

int recursiveFibonacci(int N)
{
    if (N == 0) return 0;
    if (N == 1) return 1;
    return recursiveFibonacci(N - 1) + recursiveFibonacci(N - 2);
}