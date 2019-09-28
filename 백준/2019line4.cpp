#include <iostream>
#include <algorithm>

using namespace std;

int arr[20003];

int finalIdx = 0;
int maxLeng = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			maxLeng = max(maxLeng, abs(i - finalIdx));
			finalIdx = i;
		}
	}

	int ans = maxLeng / 2;

	cout << ans << endl;

	return 0;
}