#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int to_10_base(string& a) {
	int ans = 0;
	for (int i = 0, j = a.size() - 1; i < a.size() && j >= 0; i++, j--) {
		ans += ((a[j] - '0') * pow(2, i));
	}
	return ans;
}
int gcd(int a, int b) {
	while ((a %= b) && (b %= a));
	return a + b;
}

int main() {

	ofstream output;
	output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int test = 0;
	while (test++ < n) {
		string temp;
		int a, b;
		cin >> temp;
		a = to_10_base(temp);
		cin >> temp;
		b = to_10_base(temp);
		if (gcd(a, b) != 1) {
			printf("Pair #%d: All you need is love!\n", test);
		}
		else {
			printf("Pair #%d: Love is not all you need!\n", test);
		}
	}

	output.close();
	return 0;
}