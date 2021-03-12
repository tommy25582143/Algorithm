#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string product(int n) {
	string ans = "";
	if (n > 0 && n < 10) {
		ans += char(n + '0');
		return ans;
	}
	for (int i = 9; i >= 2; i--) {
		while (n % i == 0) {
			ans = char(i + '0') + ans;
			if (n / i < 10) {
				ans = char(n / i + '0') + ans;
				return ans;
			}
			n /= i;
		}
	}
	if (n != 0) {
		return "-1";
	}
	else {
		return ans;
	}
}
int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n-- > 0) {
		int input;
		cin >> input;
		cout << product(input) << '\n';
	}

	//cout.close();
	return 0;
}