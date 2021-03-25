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
#include <algorithm>
#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;

struct point {
	int x;
	int y;
};
string turn_to_string(int a) {
	bool is_minus = false;
	if (a < 0) {
		is_minus = true;
		a *= -1;
	}
	if (a == 0) {
		return "0";
	}
	string str = "";
	while (a != 0) {
		char r = (a % 10) + '0';
		str = r + str;
		a /= 10;
	}
	if (is_minus) {
		str = '-' + str;
	}

	return str;
}

int gcd(int a, int b) {
	

	if (a == 0 || b == 0) {
		return 1;
	}
	a = abs(a);
	b = abs(b);
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	while (1) {
		a %= b;
		if (a == 0) {
			return b;
		}
		int temp = a;
		a = b;
		b = temp;
	}
	return b;
}

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int input;
	cin >> input;
	while (input-- > 0) {

		set<string>s ;
		int n;
		cin >> n;
		vector<point> p(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			p[i].x = x;
			p[i].y = y;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				string temp = "";
				int y_cof, x_cof, c;
				y_cof = 2 * (p[j].x - p[i].x);
				x_cof = 2 * (p[j].y - p[i].y);
				c = (p[j].x - p[i].x) * (p[j].y + p[i].y) - (p[j].y - p[i].y) * (p[j].x + p[i].x);
				int cof_gcd;

				if (y_cof < 0) {
					y_cof *= -1;
					x_cof *= -1;
					c *= -1;
				}
				if (x_cof == 0) {
					if (c == 0) {
						y_cof = 1;
					}
					cof_gcd = gcd(y_cof, c);
				}
				else if (y_cof == 0) {
					if (c == 0) {
						x_cof = 1;
					}
					else {
						if (x_cof < 0) {
							x_cof *= -1;
							c *= -1;
						}
					}
					cof_gcd = gcd(x_cof, c);
				}
				else if (c == 0) {
					cof_gcd = gcd(x_cof, y_cof);
				}
				else {
					cof_gcd = gcd(y_cof, gcd(x_cof, c));
				}


				x_cof /= cof_gcd;
				y_cof /= cof_gcd;
				c /= cof_gcd;
				temp = turn_to_string(y_cof) + ' ' + turn_to_string(x_cof) + ' ' + turn_to_string(c);
				if (s.find(temp) == s.end()) {
					s.insert(temp);
				}
			}
		}
		cout << s.size() << '\n';
	}

	//output.close();
	return 0;
}