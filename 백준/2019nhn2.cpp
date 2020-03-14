#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
multiset<int> ms;
vector<int> vec;
int maxNum;
int maxIdx;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	maxNum = 1;
	maxIdx = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "enqueue") {
			int num;
			cin >> num;
			vec.push_back(num);
			ms.insert(num);
			if (maxNum < ms.count(num)) {
				maxNum = ms.count(num);
				if (vec.at(maxIdx) == num) {
					//그대로
				}
				else {
					//maxIdx 바꿈
					for (int j = 0; j < vec.size(); j++) {
						if (vec.at(j) == num) {
							maxIdx = j;
							break;
						}
					}
				}
			}
			//maxNum = max(maxNum, (int)ms.count(num));
		}
		//dequeue
		else {
			if (vec.empty()) {
				//cout << -1 << endl;
				ans.push_back(-1);
			}
			else {
				int removeNum = vec[maxIdx];
				//cout << removeNum << endl;
				ans.push_back(removeNum);
				vec.erase(vec.begin() + maxIdx);
				/*
				for (auto it = ms.begin(); it != ms.end(); it++) {
					if (*it == removeNum) {
						ms.erase(it);
						break;
					}
				}
				*/
				ms.erase(ms.lower_bound(removeNum));

				//maxIdx, maxNum 갱신
				if (vec.empty()) {
					maxIdx = 0;
					maxNum = 1;
				}
				else {
					maxIdx = 0;
					maxNum = ms.count(vec.at(maxIdx));
					for (int num : vec) {
						if (maxNum < ms.count(num)) {
							maxNum = ms.count(num);
							if (vec.at(maxIdx) == num) {
								//그대로
							}
							else {
								//maxIdx 바꿈
								for (int j = 0; j < vec.size(); j++) {
									if (vec.at(j) == num) {
										maxIdx = j;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) cout << ans.at(i);
		else cout << ans.at(i) << " ";
	}

	return 0;
}