#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(vector<int>& v, int start, int end)
{
	if (start < end)
	{
		int pivot = start;
		int j = start;
		int i = j + 1;
		for (; i <= end; i++)
		{
			if (v[pivot] > v[i])
			{
				j++;
				swap(v[j], v[i]);
			}
		}
		swap(v[pivot], v[j]);
		quickSort(v, start, pivot - 1);
		quickSort(v, pivot + 1, end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> vec = { 5, 2, 1, 9, -1, 4, 13, 0, 9 };

	quickSort(vec, 0, vec.size() - 1);

	for (int i : vec)
		cout << i << endl;
}