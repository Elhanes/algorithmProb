#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const pair <int, pair <int, string> > &a, const pair <int, pair <int, string> > &b);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	int age;
	string name;
	vector < pair<int, pair<int, string> > > input;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		input.push_back(make_pair(i, make_pair(age, name)));
	}

	sort(input.begin(), input.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << input[i].second.first << " " << input[i].second.second << "\n";
	}

	return 0;
}

bool compare(const pair <int, pair <int, string> >& a, const pair <int, pair <int, string> >& b)
{
	if (a.second.first == b.second.first) return a.first < b.first;
	else return a.second.first < b.second.first;
}