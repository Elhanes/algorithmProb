#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compair(const pair<int, int>& a, const pair<int, int>& b);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, a, sum = 0, max = -1;
    vector <pair <int, int> > counting;

    cin >> N;

    if (N == 1)
    {
        cin >> a;
        cout << a << "\n" << a << "\n" << a << "\n" << 0 << "\n";

        return 0;
    }

    vector <int> input(N, 0);

    for (int i = 0; i <= 8001; i++)
    {
        if (i <= 4000) counting.push_back(make_pair(0, i));
        else counting.push_back(make_pair(0, -i + 4000));
    }

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a >= 0) counting[a].first++;
        else counting[(a * (-1)) + 4000].first++;

        input[i] = a;
        sum += a;
    }

    sort(input.begin(), input.end());
    sort(counting.begin(), counting.end(), compair);

    if (counting[8001].first == counting[8000].first) max = counting[8000].second;
    else max = counting[8001].second;

    cout << round((float)sum / (float)N) << "\n";
    cout << input[N / 2] << "\n";
    cout << max << "\n";
    cout << input[N - 1] - input[0] << "\n";

    return 0;
}

bool compair(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}