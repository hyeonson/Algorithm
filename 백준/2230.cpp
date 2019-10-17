#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100003];
int ans = 2e9 + 3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int left = 0;
	int right = 0;
	while (left <= right && right < n) {
		if (abs(arr[left] - arr[right]) > m) {
			ans = min(abs(arr[left] - arr[right]), ans);
			left++;
		}
		else if (abs(arr[left] - arr[right]) < m) {
			right++;
		}
		else {
			ans = m;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}