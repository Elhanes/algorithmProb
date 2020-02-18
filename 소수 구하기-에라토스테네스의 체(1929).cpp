#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	// variables
	int M, N;

	cin >> M >> N;

	vector < bool > cal((N + 1), 1);
	cal[0] = 0;
	cal[1] = 0;

	int key = (int)sqrt(N);

	// algorithm
	for (int i = 2; i * i <= N; i++)
	{
		if (cal[i] == true)
		{
			for (int j = i * i; j <= N; j += i) cal[j] = false;
		}
	}
	
	// output
	for (int i = M; i <= N; i++)
	{
		if (cal[i] == true) cout << i << "\n";
	}

	return 0;
}