#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	// variables
	string input = "";
	string answer = "";
	stack <char> reverse;
	queue <char> copy;
	char tmp;
	bool inner = false;
	
	// input 

	getline(cin, input);

	// algorithm

	for (int i = 0; i < input.size(); i++)
	{
		tmp = input[i];

		if (inner == false)
		{
			if (tmp == ' ')
			{
				while (!reverse.empty())
				{
					answer += reverse.top();
					reverse.pop();
				}
				answer += ' ';
			}
			else if (tmp == '<')
			{
				inner = true;
				while (!reverse.empty())
				{
					answer += reverse.top();
					reverse.pop();
				}
				copy.push(tmp);
			}
			else reverse.push(tmp);

			if (i == input.size() - 1)
			{
				while (!reverse.empty())
				{
					answer += reverse.top();
					reverse.pop();
				}
			}
		}
		else
		{
			if (tmp == '>')
			{
				inner = false;
				while (!copy.empty())
				{
					answer += copy.front();
					copy.pop();
				}
				answer += '>';
			}
			else copy.push(tmp);
		}
	}




	// output

	cout << answer << endl;

	return 0;
}