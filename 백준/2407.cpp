#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

string arr[103][103];

string addStr(string n1, string n2) {
	string ans = "";

	int ret = 0;
	while (!n1.empty() || !n2.empty() || ret) {
		if (!n1.empty() && !n2.empty()) {
			int sum = (n1.back() - '0') + (n2.back() - '0') + ret;
			n1.pop_back();
			n2.pop_back();
			ans.push_back(sum % 10 + '0');
			ret = sum / 10;
		}
		else if (!n1.empty()) {
			int sum = (n1.back() - '0') + ret;
			n1.pop_back();
			ans.push_back(sum % 10 + '0');
			ret = sum / 10;
		}
		else if (!n2.empty()) {
			int sum = (n2.back() - '0') + ret;
			n2.pop_back();
			ans.push_back(sum % 10 + '0');
			ret = sum / 10;
		}
		else {
			ans.push_back(ret + '0');
			ret = 0;
		}
		
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			arr[i][j] = "1";
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m && j < i; j++) {
			arr[i][j] = addStr(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}
	cout << arr[n][m] << endl;
	
	return 0;
}