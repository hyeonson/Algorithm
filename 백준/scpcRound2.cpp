/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double Answer;
double R, S, E;
double N;
const double pie = 3.14159265358979323;

int main(int argc, char** argv)
{
	int T, test_case;

	//freopen("input.txt", "r", stdin);
	cout << setprecision(30);
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> R >> S >> E;
		Answer = E - S;
		cin >> N;
		double l, r, h;
		for (int i = 0; i < N; i++)
		{
			cin >> l >> r >> h;
			//cout << "l: " << l << endl;
			//cout << "r: " << r << endl;
			//cout << "h: " << h << endl;
			if (R <= h)
			{
				Answer -= 2.0 * R;
				Answer += 2.0 * (h - R);
				Answer += pie * R;
			}
			else if (R > h)
			{
				//cout << "R: " << R << endl;
				//cout << "h: " << h << endl;
				double theta = acos((R - h) / R);
				//Answer -= 2.0 * (R - h) * tan(theta);
				//cout << theta << endl;
				//cout << sin(theta) << endl;
				Answer -= 2.0 * R * sin(theta);
				Answer += 2.0 * R * theta;
			}
		}

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}