#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#define PI atan(1) * 4
using namespace std;


int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	

	double n;
	while (cin >> n) {

		double square, dot, line;
		square = n*n - (sqrt(3.0) / 4.0 * n*n) - (PI * n*n / 6.0);
		dot = n*n - (PI * n*n / 4.0) - (2.0 * square);
		line = n*n - 4.0 * dot - 4.0 * square;
		cout<< fixed << setprecision(3) << line << " " << 4.0 * dot << " " << 4.0 * square << '\n';
	}
	//cout.close();
	return 0;
}