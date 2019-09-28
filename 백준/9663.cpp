#include <iostream>

using namespace std;

int n;
int arr[16];
int num = 0;

void dfs(int cur)
{
	if (cur == n)
	{
		num++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[cur] = i;
		bool isSolve = 1;
		for (int j = cur - 1; j >= 0; j--)
		{
			if (cur - arr[cur] == j - arr[j] || cur + arr[cur] == j + arr[j])
				isSolve = 0;
			if (arr[j] == arr[cur])
				isSolve = 0;
		}
		if (isSolve == 1)
		{
			dfs(cur + 1);
		}
	}
	//arr[cur] = 1;
}

int main()
{
	cin >> n;
	dfs(0);
	cout << num << endl;
	return 0;
}