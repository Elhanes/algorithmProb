#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// variables
	string input = "";
	vector <string> answer;
	string tmp = "";
	char tmp_at;
	int T, R;
	
	// input 

	cin >> T;

	// algorithm

	for (int i = 0; i < T; i++)
	{
		cin >> R >> input;
		for (int j = 0; j < input.size(); j++)
		{
			tmp_at = input[j];
			for (int k = 0; k < R; k++) tmp += tmp_at;
		}
		answer.push_back(tmp);
		tmp = "";
	}

	// output

	for (int i = 0; i < T; i++) cout << answer[i] << endl;

	return 0;
}