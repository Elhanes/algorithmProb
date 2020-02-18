#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, ans = 0, sum = 0, origin = 1, copy = 0;

    cin >> N;

    while (origin != N)
    {
        copy = origin;
        while (copy != 0)
        {
            sum += (copy % 10);
            copy = copy / 10;
        }
        sum += origin;

        if (sum == N)
        {
            ans = origin;
            break;
        }
        
        sum = 0;
        origin++;
    }
    
    cout << ans << "\n";

    return 0;
}
