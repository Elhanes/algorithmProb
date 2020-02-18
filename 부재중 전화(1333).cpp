#include <iostream>

using namespace std;

int main()
{
	int n, l, d, playtime, i = 1, j = 1;

	cin >> n >> l >> d;

	playtime = (l + 5) * n - 5;

	while(1)
	{
		if (d * i >= (l + 5) * j - 5 && d * i < (l + 5) * j)
		{
			cout << d * i;
			break;
		}
		else if (d * i < (l + 5)*j)
			i++;
		else
			j++;
		 
		if (d*i > playtime)
		{
			cout << d * i;
			break;
		}
	}

	return 0; 
}