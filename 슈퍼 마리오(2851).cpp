#include <iostream>
#include <string.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int input[10];
	int sum[10];
	vector < pair <int, int> > output;

	for (int i = 0; i < 10; i++)
	{
		cin >> input[i];
		sum[i] = 0;
	}

	sum[0] = input[0];
	output.push_back(make_pair(100 - input[0], 0));

	//algorithm
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum[i] = sum[i] + input[j];
		}
		if (sum[i] > 100)
		{
			output.push_back(make_pair(sum[i] - 100, 1));
		}
		else
		{
			output.push_back(make_pair(100 - sum[i], 0));
		}
	}

	sort(output.begin(), output.end());

	if (output[0].first == output[1].first) cout << output[1].first + 100;
	else
	{
		if (output[0].second == 0) cout << 100 - output[0].first;
		else cout << output[0].first + 100;
	}

	return 0;
}