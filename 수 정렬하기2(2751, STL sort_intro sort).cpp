#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, a;
    vector <int> input;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        input.push_back(a);
    }

    sort(input.begin(), input.end());

    for (int i = 0; i < N; i++) cout << input[i] << "\n";

    return 0;
}
