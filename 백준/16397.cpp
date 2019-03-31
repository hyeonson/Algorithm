#include <iostream>
#include <cstring>
#include <queue>

#define pii pair<int, int>

using namespace std;

int n, t, g;
int visited[100000];
queue<pii> q;

int m2m1(int num)
{
	int digit = 1;
	num *= 2;
	while (num / digit)
		digit *= 10;
	digit /= 10;
	return num - digit;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n >> t >> g;

	q.push(make_pair(n, 0));
	memset(visited, 0, sizeof(visited));
	visited[n] = 1;
	while (!q.empty())
	{
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt > t)
		{
			cout << "ANG" << endl;
			return 0;
		}
		if (now == g)
		{
			cout << cnt << endl;
			return 0;
		}
		int m2m1Num = m2m1(now);
		if (now < 50000 && !visited[m2m1Num])
		{
			q.push({ m2m1Num, cnt + 1 });
			visited[m2m1Num] = 1;
		}
		if (now < 100000 && !visited[now + 1])
		{
			q.push({ now + 1, cnt + 1 });
			visited[now + 1] = 1;
		}
	}
	cout << "ANG" << endl;

	return 0;
}