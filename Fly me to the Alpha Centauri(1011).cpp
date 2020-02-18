#include <iostream>
#include <vector>

using namespace std;

long long teleport(long long len);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long x, y;
    int T;
    vector <long long> answer;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;
        answer.push_back(teleport(y - x));
    }

    for (int i = 0; i < T; i++) cout << answer[i] << "\n";

    return 0;
}

long long teleport(long long len)
{
    long long max = 1;

    while (1)
    {
        if (max * max == len)
        {
            return max + max - 1;
        }
        else if (max * max > len)
        {
            max = max - 1;
            if (len <= max * max + max) return max + max;
            else return max + max + 1;
        }
        max++;
    }
       
}