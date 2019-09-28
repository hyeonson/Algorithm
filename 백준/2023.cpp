#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;


int n;
vector<int> ans;

bool isPrime(int num) {
	if (num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void dfs(int idx, int result) {
	if (idx >= n)
		return;
	for (int i = 1; i <= 9; i++) {
		int sum = result * 10 + i;

		bool prime = isPrime(sum);
		if (prime) {
			if (idx == n - 1) {
				ans.push_back(sum);
			}
			else {
				dfs(idx + 1, sum);
			}
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dfs(0, 0);
	for (int s : ans)
		cout << s << endl;

	return 0;
}

