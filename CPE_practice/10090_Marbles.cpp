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

ll exgcd(ll A, ll B, ll& X, ll& Y) {

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
		ll x, y;
		ll gcd = exgcd(A - B * (A / B), B, x, y);
		X = x;
		Y = y - (A / B) * x;
		return gcd;
	}
	else {
		ll x, y;
		ll gcd = exgcd(A, B - A * (B / A), x, y);
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
	ll n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		ll c1, c2, n1, n2;
		ll x, y;
		cin >> c1 >> n1;
		cin >> c2 >> n2;
		ll g = exgcd(n1, n2, x, y);
		ll lower = ceil(-1.0 * n * x /  n2);
		ll higher = floor(1.0 * n * y /  n1);
		if (n % g != 0 || lower > higher) {
			cout << "failed" << '\n';
			continue;
		}
		if (c1 * n2 < c2 * n1) {
			x = n * x / g + n2 / g * higher;
			y = n * y / g - n1 / g * higher;
			cout << x << " " << y << '\n';
		}
		else {
			x = n * x / g + n2 / g * lower;
			y = n * y / g - n1 / g * lower;
			cout << x << " " << y << '\n';
		}
	}
	//output.close();
	return 0;
}