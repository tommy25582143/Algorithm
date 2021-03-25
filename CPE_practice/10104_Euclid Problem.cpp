#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>

#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;

int exgcd(int A, int B, int& X, int& Y) {

	if (A % B == 0) {
		X = 0;
		Y = 1;
		return B;
	}

	if (B % A == 0) {
		X = 1;
		Y = 0;
		return A;
	}

	if (A >= B) {
		int x, y;
		int gcd = exgcd(A - B * (A / B), B, x, y);
		X = x;
		Y = y - (A / B) * x;
		return gcd;
	}
	else {
		int x, y;
		int gcd = exgcd(A, B - A * (B / A), x, y);
		X = x - (B / A) * y;
		Y = y;
		return gcd;
	}
}

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int A, B;
	while (cin >> A >> B) {
		int X, Y;
		int value = exgcd(A, B, X, Y);
		cout << X << " " << Y << " " << value << '\n';
	}
	//output.close();
	return 0;
}