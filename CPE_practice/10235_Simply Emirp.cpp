#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

bool is_prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string input;
	while (cin >> input) {
		int n = 0, reverse_n = 0;
		int times = 1;
		for (int i = input.size() - 1; i >= 0; i--) {
			n += (input[i] - '0') * times;
			times *= 10;
		}
		times = 1;
		for (int i = 0; i < input.size(); i++) {
			reverse_n += (input[i]-'0') * times;
			times *= 10;
		}
		if (!is_prime(n)) {
			cout << n << " is not prime.\n";
		}
		else {
			if (n != reverse_n && is_prime(reverse_n)) {
				cout << n << " is emirp.\n";
			}
			else {
				cout << n << " is prime.\n";
			}
		}
	}
	//cout.close();
	return 0;
}