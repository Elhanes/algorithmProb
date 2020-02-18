#include <iostream>

using namespace std;

int main()
{
	int input, x, ans1 = 1, ans2 = 1, n = 1;

	cin >> input;

	if (input < 1 || input > 1000000000)
		return 0;

	while(1)
	{
		if (input == 1)
			break;
		else
		{
			if (input > (n - 1) * n / 2 && input <= n * (n + 1) / 2)
			{
				if (n % 2 == 0)
				{
					x = input - (n - 1) * n / 2;
					ans2 = n + 1 - x;
					ans1 = ans1 + x - 1;
				}
				else
				{
					x = input - (n - 1) * n / 2;
					ans1 = n + 1 - x;
					ans2 = ans2 + x - 1;
				}
				break;
			}
		}
		n++;
	}

	cout << ans1 << "/" << ans2;

	return 0; 
}