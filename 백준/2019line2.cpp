#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int arr[10];
int numLeng;
int seq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int numLeng = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i += 2) {
		int data = s[i] - '0';
		arr[numLeng++] = data;
	}
	/*
	do {
		cin >> arr[numLeng];
		numLeng++;
	} while (getc(stdin) == ' ');
	*/

	//cout << s << endl;
	/*
	for (int i = 0; i < s.size(); i + 2) {
		arr[numLeng] = s[i] - '0';
		numLeng++;
	}
	cout << numLeng << endl;
	*/
	/*
	for (int i = 0; i < numLeng; i++) {
		cout << arr[i];
	}
	*/

	cin >> seq;
	
	sort(arr, arr + numLeng);

	for (int i = 0; i < seq - 1; i++) {
		next_permutation(arr, arr + numLeng);
	}

	for (int i = 0; i < numLeng; i++) {
		cout << arr[i];
	}
	cout << endl;

	return 0;
}