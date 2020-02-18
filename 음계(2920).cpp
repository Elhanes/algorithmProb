#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string a;
	getline(cin, a);

	if (a == "1 2 3 4 5 6 7 8")
		cout << "ascending\n";
	else if (a == "8 7 6 5 4 3 2 1")
		cout << "descending\n";
	else
		cout << "mixed\n";

	return 0; 
}