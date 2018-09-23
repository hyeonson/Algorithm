#include <iostream>
#include <string>

using namespace std;

char a[3] = { 'A', 'B', 'C' };
char b[4] = { 'B', 'A', 'B', 'C' };
char c[6] = { 'C', 'C', 'A', 'A', 'B', 'B' };

int a_sum, b_sum, c_sum;
string ans;
int ans_size;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> ans_size;
	cin >> ans;

	a_sum = 0;
	b_sum = 0;
	c_sum = 0;
	int best = 0;
	for (int i = 0; i < ans_size; i++)
	{
		if (ans[i] == a[i % 3])
		{
			a_sum++;
			if (best < a_sum) best = a_sum;
		}
		if (ans[i] == b[i % 4])
		{
			b_sum++;
			if (best < b_sum) best = b_sum;
		}
		if (ans[i] == c[i % 6])
		{
			c_sum++;
			if (best < c_sum) best = c_sum;
		}
	}

	cout << best << endl;
	if (best == a_sum)
		cout << "Adrian" << endl;
	if (best == b_sum)
		cout << "Bruno" << endl;
	if (best == c_sum)
		cout << "Goran" << endl;

	return 0;
}