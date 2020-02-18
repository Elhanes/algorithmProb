#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

void roll(vector<int> &w, int a);

int main() 
{

	vector<int> w1;
	vector<int> w2;
	vector<int> w3;
	vector<int> w4;

	int k; //count
	int tmp_input;
	int tmp_input2;
	string tmp_string;
	int answer = 0;
	vector< pair<int, int> > input; // pair.first is number of wheel, pair.second is the direction of rotation
	w1.reserve(8);
	w2.reserve(8);
	w3.reserve(8);
	w4.reserve(8);
	input.reserve(101);

	//input

	getline(cin, tmp_string, '\n');
	//cout << tmp_string << endl;
	for (unsigned int i = 0; i < tmp_string.length(); i++)
	{
		w1.push_back((tmp_string.at(i)) - '0');
	}

	getline(cin, tmp_string, '\n');
	for (unsigned int i = 0; i < tmp_string.length(); i++)
	{
		w2.push_back((tmp_string.at(i)) - '0');
	}

	getline(cin, tmp_string, '\n');
	for (unsigned int i = 0; i < tmp_string.length(); i++)
	{
		w3.push_back((tmp_string.at(i)) - '0');
	}

	getline(cin, tmp_string, '\n');
	for (unsigned int i = 0; i < tmp_string.length(); i++)
	{
		w4.push_back((tmp_string.at(i)) - '0');
	}

	/*
	for (int i = 0; i < 8; i++)
	{
		cin >> tmp_input;
		w1.push_back(tmp_input);
	}

	for (int i = 0; i < 8; i++)
	{
		cin >> tmp_input;
		w2.push_back(tmp_input);
	}

	for (int i = 0; i < 8; i++)
	{
		cin >> tmp_input;
		w3.push_back(tmp_input);
	}

	for (int i = 0; i < 8; i++)
	{
		cin >> tmp_input;
		w4.push_back(tmp_input);
	}*/

	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> tmp_input >> tmp_input2;
		input.push_back(pair<int, int> (tmp_input, tmp_input2));
	}
	
	//algorithm
	for (int i = 0; i < k; i++)
	{
		//cout << "debug at k = " << k << endl;

		if (input[i].first == 1)
		{
			if (w1[2] != w2[6])
			{
				if (w2[2] != w3[6])
				{
					if (w3[2] != w4[6])
					{
						//cout << "debug start of roll 4" << endl;
						if (input[i].second == 1) roll(w4, -1);
						else roll(w4, 1);
					}
					//cout << "debug start of roll 3" << endl;
					if (input[i].second == 1) roll(w3, 1);
					else roll(w3, -1);
				}
				//cout << "debug start of roll 2" << endl;
				if (input[i].second == 1) roll(w2, -1);
				else roll(w2, 1);
			}
			//cout << "debug start of roll 1" << endl;
			roll(w1, input[i].second);
		}
		else if (input[i].first == 2)
		{
			if (w1[2] != w2[6])
			{
				//cout << "debug start of roll 1" << endl;
				if (input[i].second == 1) roll(w1, -1);
				else roll(w1, 1);
			}

			if (w2[2] != w3[6])
			{
				if (w3[2] != w4[6])
				{
					//cout << "debug start of roll 4" << endl;
					if (input[i].second == 1) roll(w4, 1);
					else roll(w4, -1);
				}
				//cout << "debug start of roll 3" << endl;
				if (input[i].second == 1) roll(w3, -1);
				else roll(w3, 1);
			}
			//cout << "debug start of roll 2" << endl;
			roll(w2, input[i].second);
		}
		else if (input[i].first == 3)
		{
			if (w3[2] != w4[6])
			{
				//cout << "debug start of roll 4" << endl;
				if (input[i].second == 1) roll(w4, -1);
				else roll(w4, 1);
			}

			if (w3[6] != w2[2])
			{
				if (w2[6] != w1[2])
				{
					//cout << "debug start of roll 1" << endl;
					if (input[i].second == 1) roll(w1, 1);
					else roll(w1, -1);
				}
				//cout << "debug start of roll 2" << endl;
				if (input[i].second == 1) roll(w2, -1);
				else roll(w2, 1);
			}
			//cout << "debug start of roll 3" << endl;
			roll(w3, input[i].second);
		}
		else if (input[i].first == 4)
		{
			if (w4[6] != w3[2])
			{
				if (w3[6] != w2[2])
				{
					if (w2[6] != w1[2])
					{
						//cout << "debug start of roll 1" << endl;
						if (input[i].second == 1) roll(w1, -1);
						else roll(w1, 1);
					}
					//cout << "debug start of roll 2" << endl;
					if (input[i].second == 1) roll(w2, 1);
					else roll(w2, -1);
				}
				//cout << "debug start of roll 3" << endl;
				if (input[i].second == 1) roll(w3, -1);
				else roll(w3, 1);
			}
			//cout << "debug start of roll 4" << endl;
			roll(w4, input[i].second);
		}
	}

	//calculate answer

	if (w1[0] == 1) answer += 1;
	if (w2[0] == 1) answer += 2;
	if (w3[0] == 1) answer += 4;
	if (w4[0] == 1) answer += 8;
	cout << answer;

	//clear vector
	w1.clear();
	w2.clear();
	w3.clear();
	w4.clear();
	input.clear();

	return 0;
}

void roll(vector<int> &w, int a)
{
	int tmp;
	vector<int>::iterator iter;

	if (a == 1)
	{
		tmp = w[7];
		for (int i = 7; i > 0 ; i--)
		{
			w[i] = w[i - 1];
		}
		w[0] = tmp;
		/*cout << "debug 1 of roll" << endl;
		for (iter = w.begin(); iter != w.end(); iter++)
		{
			cout << *iter << " ";
		}*/
		//cout << endl;
	}

	else if (a == -1)
	{
		tmp = w[0];
		for (int i = 0; i < 7; i++)
		{
			w[i] = w[i + 1];
		}
		w[7] = tmp;
		/*cout << "debug -1 of roll" << endl;
		for (iter = w.begin(); iter != w.end(); iter++)
		{
			cout << *iter << " ";
		}*/
		//cout << endl;
	}
}