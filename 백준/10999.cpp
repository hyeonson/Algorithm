#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll arr[1000003];
ll tree[3000003];
ll lazy[3000003];
int n, m, k;

ll makeTree(int left, int right, int node)
{
	if (left == right)
	{
		return tree[node] = arr[left];
	}
	int mid = (left + right) / 2;
	return tree[node] = makeTree(left, mid, node * 2) + makeTree(mid + 1, right, node * 2 + 1);
}
void lazy_update(int left, int right, int node)
{
	if (lazy[node] != 0)
	{
		tree[node] += (right - left + 1) * lazy[node];
		if (left != right)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int left, int right, int node, int start, int end, ll mdfy)
{
	lazy_update(left, right, node);
	if (right < start || end < left)
		return;
	if (start <= left && right <= end)
	{
		tree[node] += (right - left + 1) * mdfy;
		if (left != right)
		{
			lazy[node * 2] += mdfy;
			lazy[node * 2 + 1] += mdfy;
		}
		return;
	}
	int mid = (left + right) / 2;
	update(left, mid, node * 2, start, end, mdfy);
	update(mid + 1, right, node * 2 + 1, start, end, mdfy);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(int left, int right, int node, int start, int end)
{
	lazy_update(left, right, node);
	if (end < left || right < start)
		return 0;
	if (start <= left && right <= end)
		return tree[node];
	int mid = (left + right) / 2;
	return sum(left, mid, node * 2, start, end) + sum(mid + 1, right, node * 2 + 1, start, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	makeTree(1, n, 1);

	for (int i = 1; i <= m + k; i++)
	{
		int q;
		int q1, q2;
		ll mdfy;
		cin >> q;
		if (q == 1)
		{
			cin >> q1 >> q2 >> mdfy;
			update(1, n, 1, q1, q2, mdfy);
		}
		else
		{
			cin >> q1 >> q2;
			cout << sum(1, n, 1, q1, q2) << endl;
		}
	}

	return 0;
}