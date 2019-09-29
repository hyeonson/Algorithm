#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string name[1003];
int cnt[1003];
int num;
int need;
int maxNum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	num = 0;
	need = 0;
	maxNum = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		//fflush(stdin);
		bool isThere = false;
		for (int i = 0; i < num; i++) {
			if (s == name[i]) {
				cnt[i]++;
				maxNum = max(cnt[i], maxNum);
				isThere = true;
				break;
			}
		}
		if (isThere == false) {
			name[num] = s;
			cnt[num] = 1;
			num++;
		}
		
	}

	for (int i = 0; i < num; i++) {
		if (cnt[i] != maxNum) {
			if (need == 0) {
				if (cnt[i] + 1 == maxNum) {
					need = 1;
				}
			}
			else {
				cout << "N" << endl;
				cout << n << endl;
				cout << num << endl;
				return 0;
			}
		}
	}
	
	cout << "Y" << endl;
	cout << n + need << endl;
	cout << num << endl;
	return 0;
}