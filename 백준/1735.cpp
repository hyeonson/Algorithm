#include <iostream>

using namespace std;


int getGCD(int n1, int n2) {
	if (n2 == 0) {
		return n1;
	}
	else {
		return getGCD(n2, n1 % n2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nt, nb;
	int mt, mb;

	cin >> nt >> nb >> mt >> mb;

	int gcd = 1;
	if (nb < mb) gcd = getGCD(mb, nb);
	else gcd = getGCD(nb, mb);


	int anst = nt * mb / gcd + mt * nb / gcd;
	int ansb = nb * mb / gcd;
	
	//if (anst % ansb == 0) cout << anst / ansb << endl;
	//else {
		int gcd2 = 1;
		if (anst < ansb) gcd2 = getGCD(ansb, anst);
		else gcd2 = getGCD(anst, ansb);
		cout << anst / gcd2 << " " << ansb / gcd2 << endl;
	//}

	return 0;
}