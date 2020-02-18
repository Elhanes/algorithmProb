#include <iostream>
#include <vector>

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

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            a = 0;
            if (input[i] > input[j])
            {
                a = input[j];
                input[j] = input[i];
                input[i] = a;
            }
        }
    }

    for (int i = 0; i < N; i++) cout << input[i] << "\n";

    return 0;
}
