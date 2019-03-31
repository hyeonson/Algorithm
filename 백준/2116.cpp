#include <iostream>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
map<int, int> mp[10003];
int sum = 0;
int maxSum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int d[6];
		for (int i = 0; i < 6; i++)
			cin >> d[i];
		mp[i].insert(make_pair(d[0], d[5]));
		mp[i].insert(make_pair(d[5], d[0]));
		mp[i].insert(make_pair(d[1], d[3]));
		mp[i].insert(make_pair(d[3], d[1]));
		mp[i].insert(make_pair(d[2], d[4]));
		mp[i].insert(make_pair(d[4], d[2]));
	}
	
	int front, back;

	for (int i = 1; i <= 6; i++)
	{
		sum = 0;

		front = i;
		back = mp[0][i];
		for (int k = 6; k >= 1; k--)
		{
			if (k == mp[0][front] || k == mp[0][back])
				continue;
			else
			{
				sum += k;
				break;
			}
		}
		for (int j = 1; j < n; j++)
		{
			front = back;
			back = mp[j][front];
			for (int k = 6; k >= 1; k--)
			{
				if (k == mp[j][front] || k == mp[j][back])
					continue;
				else
				{
					sum += k;
					break;
				}
			}
		}
		maxSum = max(sum, maxSum);
	}
	cout << maxSum << endl;
	return 0;
}