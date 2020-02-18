#include <string>
#include <iostream>

using namespace std;

int main()
{
	// variables
	long long k = 0;
	int prev, now = 0;
	int j1, j2 = -11;
	bool cute = 1;

	cin >> k;

	prev = k % 10;
	k = k - (k % 10);

	while (k > 0)
	{
		now = (k / 10) % 10;
		k = (k / 10) - now;

		j1 = now - prev;
		
		if (j2 == j1 || j2 == -11)
		{
			prev = now;
			j2 = j1;
		}
		else
		{
			cute = 0;
			break;
		}
	}
	
	if (cute) cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << endl;
	else cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << endl;

	return 0;
}

//문자열로 받으면 훨씬 편하다.