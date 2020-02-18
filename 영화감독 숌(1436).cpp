#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, sixcheck, tmp, i = 1, check = 0;

    cin >> N;

    while (1)
    {
        sixcheck = 0;
        tmp = i;
        while (1)
        {
            if (tmp == 0 || sixcheck == 3) break;
            if (tmp % 10 == 6) sixcheck++;
            else  sixcheck = 0;

            tmp /= 10;
        }

        if (sixcheck == 3) check++;
        if (check == N) break;
        i++;
    }

    cout << i;

    return 0;
}
