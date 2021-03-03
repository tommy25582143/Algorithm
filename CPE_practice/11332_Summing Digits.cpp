#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

long sum_digit(string n) {
	if (n.size() == 1) {
		return n[0] - '0';
	}
	else {
		long sum = 0;
		for (int i = 0; i < n.size(); i++) {
			sum += n[i] - '0';
		}
		return sum_digit(to_string(sum));
	}
}
int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string n;
	while ((cin >> n, n) != "0") {
		cout << sum_digit(n) << '\n';
	}


	//cout.close();
	return 0;
}