#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int N, W;
string arr[103][103];
string temp[103][103];

void rotate(int idx, int width, int type) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = arr[i][j];
		}
	}
	if(type == 1) {
		for (int i = 0; i < width - 1; i++) {
			//위
			arr[idx][idx + i + 1] = temp[idx][idx + i];
			//아래
			arr[idx + width - 1][idx + width - 1 - i - 1] = temp[idx + width - 1][idx + width - 1 - i];
			//오른쪽
			arr[idx + i + 1][idx + width - 1] = temp[idx + i][idx + width - 1];
			//왼쪽
			arr[idx + width - 1 - i - 1][idx] = temp[idx + width - 1 - i][idx];
		}
	}
	else { // -1
		for (int i = 0; i < width - 1; i++) {
			//위
			arr[idx][idx + width - 1 - i - 1] = temp[idx][idx + width - 1 - i];
			//아래
			arr[idx + width - 1][idx + i + 1] = temp[idx + width - 1][idx + i];
			//오른쪽
			arr[idx + width - 1 - i - 1][idx + width - 1] = temp[idx + width - 1 - i][idx + width - 1];
			//왼쪽
			arr[idx + i + 1][idx] = temp[idx + i][idx];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> W;

	int startType = 1;
	if (W > 0) startType = 1;
	else startType = -1;
	int move = abs(W);
	/*
	if (N % 2 == 0) {
		move = W % surLeng;
	}
	else {
		move = abs(W % surLeng);
	}
	*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	int startI = 0;
	int startWidth = N;
	/*
	if (startWidth % 2 == 0) {
		startType = 1;
	}
	else {
		startType = -1;
	}
	*/
	
	while (true) {
		if (startI >= N / 2 || startWidth < 2) {
			//cout << "break" << endl;
			break;
		}
		//cout << "돌려" << endl;
		int moveReset = move % (startWidth * 4 - 4);
		for (int i = 0; i < moveReset; i++) {
			rotate(startI, startWidth, startType);
		}
		startI += 1;
		startWidth -= 2;
		startType *= -1;
	}
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == N - 1)
				cout << arr[i][j] << endl;
			else
				cout << arr[i][j] << " ";
		}
	}
	
	return 0;
}