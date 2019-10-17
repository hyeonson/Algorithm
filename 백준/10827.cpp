#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull a, b, c;

ull pow(ull num, ull mtp) {
	if (mtp == 0) {
		return 1;
	}
	else if (mtp == 1) {
		return num % c;
	}
	else {
		if (mtp % 2 == 0) {
			return pow(num, mtp / 2) * pow(num, mtp / 2) % c;
		}
		else {
			return (num % c) * (pow(num, (mtp - 1) / 2) * pow(num, (mtp - 1) / 2) % c) % c;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b >> c;

	cout << pow(a, b) << "\n";


	return 0;
}