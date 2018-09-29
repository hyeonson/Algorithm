#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int money;
int tmp;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	money = 20000;
	for (int distance; !(ss >> distance).fail(); ) {
		// @todo Write your code here.
		if (distance < 4 || distance > 178)
		{
			cout << money << endl;
			return 0;
		}
		if (distance > 40)
			tmp = (720 + ((distance - 33) / 8) * 80);
		else
			tmp = 720;
		if (money < tmp)
		{
			cout << money << endl;
			return 0;
		}
		else
			money -= tmp;
	}
	// @todo Write your code here.
	cout << money << endl;
	return 0;
}
