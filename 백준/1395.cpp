//#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//int arr[100003];
int tree[400003];
int lazy[400003];
int n, m;

void lazy_update(int left, int right, int num)
{
	if (lazy[num])
	{
		tree[num] = right - left + 1 - tree[num];
		//cout << "tree[num]: " << tree[num] << endl;
		if (left != right)
		{
			lazy[num * 2] ^= 1;
			lazy[num * 2 + 1] ^= 1;
		}
		lazy[num] = 0;
	}
}

void convert(int left, int right, int num, int start, int end)
{
	//cout << "convert " << left << " " << right << endl;
	lazy_update(left, right, num);
	if (right < start || left > end)
		return;
	if (start <= left && right <= end)
	{
		lazy[num] ^= 1;
		lazy_update(left, right, num);
		return;
	}
	int mid = (left + right) >> 1;
	convert(left, mid, num * 2, start, end);
	convert(mid + 1, right, num * 2 + 1, start, end);
	tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

int getNum(int left, int right, int num, int start, int end)
{
	lazy_update(left, right, num);
	if (right < start || left > end)
		return 0;
	if (start <= left && right <= end)
		return tree[num];
	int mid = (left + right) >> 1;
	return getNum(left, mid, num * 2, start, end) + getNum(mid + 1, right, num * 2 + 1, start, end);
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	//memset(arr, 0, sizeof(arr));
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int q, start, end;
		scanf("%d%d%d", &q, &start, &end);
		if (q == 0)
		{
			convert(1, n, 1, start, end);
		}
		else
		{
			printf("%d\n", getNum(1, n, 1, start, end));
		}
	}

	return 0;
}