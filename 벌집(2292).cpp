#include <iostream>

using namespace std;

int main()
{
	int input, ans = 1, n = 1;

	cin >> input;

	if (input < 1 || input > 1000000000)
		return 0;

	while(1)
	{
		if (input == 1)
			break;
		else
		{
			if (input >= 1 + 3 * n * n - 2 * n - (n - 1) && input <= 1 + 3 * n * n + 3 * n)
			{
				ans = n + 1;
				break;
			}
		}
		n++;
	}

	cout << ans;

	return 0; 
}