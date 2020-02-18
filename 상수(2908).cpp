#include <iostream>

using namespace std;

int change(int x);

int main()
{
	int a, b;

	cin >> a >> b;

	if (a % 10 > b % 10)
		change(a);
	else if (a % 10 < b % 10)
		change(b);
	else
	{
		if ((a % 100) / 10 > (b % 100) / 10)
			change(a);
		else if ((a % 100) / 10 > (b % 100) / 10)
			change(b);
		else
		{
			if (a / 100 > b / 100)
				change(a);
			else
				change(b);
		}
	}

	return 0; 
}

int change(int x)
{
	int ans = (x % 10) * 100 + (x % 100 / 10) * 10 + x / 100;
	cout << ans;

	return 0;
}