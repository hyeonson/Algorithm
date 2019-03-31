#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;
int m;

int main()
{
	cin >> m;

	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(3, 3));

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		int temp = mp[x];
		mp[x] = mp[y];
		mp[y] = temp;
	}
	for (int i = 1; i <= 3; i++)
	{
		if (mp[i] == 1)
		{
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}