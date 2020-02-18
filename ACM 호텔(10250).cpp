#include <iostream>
#include <vector>

using namespace std;

int findRoom(int height, int width, int num);

int main()
{
    int H, W, N, T;
    cin >> T;
    vector <int> answer;

    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;
        answer.push_back(findRoom(H, W, N));
    }

    for (int i = 0; i < T; i++) cout << answer[i] << "\n";

    return 0;
}

int findRoom(int height, int width, int num)
{
    if (height == 1 && num >= 10) return height * 100 + num;

    int w = num / height + 1;
    int h = num % height;

    if (h == 0)
    {
        h = height;
        w -= 1;
    }

    return w + h * 100;
}