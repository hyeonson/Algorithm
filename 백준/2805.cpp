#include <iostream>

using namespace std;

int n, m;
int tree[1000003];
int ans;
int maxH = 1;
int minH = 0;
int avrH;
long sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		if (maxH < tree[i]) maxH = tree[i];
	}
	
	while(minH <= maxH)
	{
		avrH = (minH + maxH) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if(tree[i] >= avrH) sum += tree[i] - avrH;
		}
		if (sum == m)
		{
			ans = avrH;
			break;
		}
		else if (sum > m)
		{
			ans = avrH;
			minH = avrH + 1;
		}
		else
		{
			maxH = avrH - 1;
		}
	}
	
	cout << ans << endl;

	return 0;
}