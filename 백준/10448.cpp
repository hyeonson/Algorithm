#include <iostream>
#include <vector>

using namespace std;

int t;
int num;
bool ans;
vector<int> v;

void dfs(int count, int sum)
{
	if (count == 3 && (num == sum))
	{
		ans = 1;
		return;
	}
	if (count >= 3 || (num < sum))
		return;
	for (int i : v)
		dfs(count + 1, sum + i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		cin >> num;
		v.clear();
		ans = 0;
		for (int i = 1;; i++)
		{
			int tmp = i * (i + 1) / 2;
			if (tmp < num)
				v.push_back(tmp);
			else
				break;
		}
		dfs(0, 0);
		cout << ans << endl;
	}

	return 0;
}