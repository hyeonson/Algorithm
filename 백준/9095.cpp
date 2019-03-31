#include <iostream>

using namespace std;

int num;
int n;
void dfs(int sum)
{
	if (sum > n)
		return;
	if (sum == n)
	{
		num++;
		return;
	}

	dfs(sum + 1);
	dfs(sum + 2);
	dfs(sum + 3);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		num = 0;
		dfs(0);
		cout << num << endl;
	}
	return 0;
}