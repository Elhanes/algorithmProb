#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//global variable
	int N, M, A, B;
	string input_dial;
	vector <int> dial(250000);
	vector <int> answer(100000);
	int sum = 0;

	//input
	cin >> N >> M;
	cin >> input_dial;

	//answer.resize(M);

	for (int i = 0; i < input_dial.size(); i++)
	{
		int tmp;
		tmp = input_dial.at(i) - '0';
		dial[i] = tmp;
	}

	//algorithm
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		for (int j = A - 1; j < B; j++)
		{
			sum += dial[j];
			dial[j]++;
		}
		answer[i] = sum;
		sum = 0;
	}

	//output
	for (int i = 0; i < M; i++) cout << answer[i] << "\n";

}