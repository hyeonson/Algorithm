#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll arr[1000003];
ll tree[3000003];
int n, m, k;

ll makeTree(int left, int right, int node)
{
	if (left == right)
	{
		return tree[node] = arr[left];
	}
	int mid = (left + right) / 2;
	tree[node] += makeTree(left, mid, node * 2);
	tree[node] += makeTree(mid + 1, right, node * 2 + 1);

	return tree[node];
}

void update(int left, int right, int node, int idx, ll value)
{
	if (!(left <= idx && idx <= right))return;
	tree[node] += value;
	int mid = (left + right) / 2;
	if (left != right)
	{
		update(left, mid, node * 2, idx, value);
		update(mid + 1, right, node * 2 + 1, idx, value);
	}
}
ll sum(int left, int right, int node, int curL, int curR)
{
	if (left > curR || right < curL)
	{
		return 0;
	}
	else if (curL <= left && right <= curR)
	{
		return tree[node];
	}
	int mid = (left + right) / 2;
	return sum(left, mid, node * 2, curL, curR) + sum(mid + 1, right, node * 2 + 1, curL, curR);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	memset(tree, 0, sizeof(tree));

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	makeTree(1, n, 1);

	for (int i = 1; i <= m + k; i++)
	{
		ll q1, q2, q3;
		cin >> q1 >> q2 >> q3;
		if (q1 == 1)
		{
			ll modify = q3 - arr[q2];
			arr[q2] = q3;
			update(1, n, 1, q2, modify);
		}
		else
		{
			cout << sum(1, n, 1, q2, q3) << endl;
		}
	}

	return 0;
}