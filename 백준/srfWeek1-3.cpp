#include <iostream>

using namespace std;

int s[3];
int c[3];
int cur;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++)
	{
		cin >> s[i] >> c[i];
	}
	cur = 0;
	for (int i = 0; i < 100; i++)
	{
		if (c[cur] > s[(cur + 1) % 3] - c[(cur + 1) % 3])
		{
			c[cur] -= s[(cur + 1) % 3] - c[(cur + 1) % 3];
			c[(cur + 1) % 3] = s[(cur + 1) % 3];
		}
		else
		{
			c[(cur + 1) % 3] += c[cur];
			c[cur] = 0;
		}
		cur = (cur + 1) % 3;
	}
	for (int i = 0; i < 3; i++)
		cout << c[i] << endl;

	return 0;
}