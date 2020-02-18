#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	// variables
	string input = "";
	vector < int > answer;
	int T, counter = 0;
	bool check = 0;
	
	// input & algorithm

	cin >> T;
	cin.ignore(32767, '\n');

	for (int i = 0; i < T; i++)
	{
		getline(cin, input);
		stack<char> s;

		if (input.at(0) == ')' || input.at(input.length() - 1) == '(')
		{
			answer.push_back(0);
			input = "";
			continue;
		}

		for (int j = 0; j < input.length(); j++)
		{
			if(input.at(j) == '(') s.push(input.at(j));
			else
			{
				if (s.empty())
				{
					check = 1;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}

		if (s.empty() && check == 1) answer.push_back(0);
		else if (s.empty() && check == 0) answer.push_back(1);
		else if (!s.empty()) answer.push_back(0);

		check = 0;
		input = "";
	}

	// output

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer.at(i) == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}