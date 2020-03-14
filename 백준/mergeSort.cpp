#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
	vector<int> temp;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (v[i] < v[j]) temp.push_back(v[i++]);
		else temp.push_back(v[j++]);
	}
	while (i <= mid) temp.push_back(v[i++]);
	while (j <= end) temp.push_back(v[j++]);
	for (int k = start, k2 = 0; k <= end; k++, k2++)
		v[k] = temp[k2];
}

void mergeSort(vector<int> &v, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(v, start, mid);
		mergeSort(v, mid + 1, end);

		merge(v, start, mid, end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec = { 5, 2, 1, 9, -1, 4, 13, 0, 9 };

	mergeSort(vec, 0, vec.size() - 1);

	for (int i : vec)
		cout << i << endl;

	return 0;
}