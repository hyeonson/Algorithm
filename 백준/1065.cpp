#include <iostream>

using namespace std;

int num;
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> num;
	ans = 0;
	if (num < 100)
	{
		ans += num;
	}
	else
	{
		for (int i = 100; i <= num; i++)
		{
			int s1 = i / 100;
			int s2 = (i % 100) / 10;
			int s3 = i % 10;
			if (s1 - s2 == s2 - s3)
				ans++;
		}
		ans += 99;
	}
	cout << ans << endl;
	return 0;
}