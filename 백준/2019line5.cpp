#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int R, C;
int RE, CE;
unsigned long long combi[51][51] = {};


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> RE >> CE;

	combi[1][0] = 1;
	combi[1][1] = 1;
	for (int i = 2; i <= 51; i++) {
		combi[i][0] = 1;
		for (int j = 1; j <= 51; j++) {
			combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
		}
	}

	if (RE >= R || RE < 0 || CE >= C || CE < 0) {
		cout << "fail\n";
		return 0;
	}

	int total = RE + CE;
	cout << RE + CE << "\n";
	cout << combi[total][RE] << "\n";

	return 0;
}