#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1,str2;
	while (cin >> str1 >> str2) {
		if (str1 == "0" && str2 == "0") {
			break;
		}
		vector<int>a(str1.size(), 0);
		vector<int>b(str2.size(), 0);
		for (int i = str1.size() - 1; i >= 0; i--) {
			a[str1.size() - 1 - i] = str1[i] - '0';
		}
		for (int i = str2.size() - 1; i >= 0; i--) {
			b[str2.size() - 1 - i] = str2[i] - '0';
		}

		int i = 0;
		int carry = 0;
		int total = 0;
		for (; i < (str1.size() > str2.size() ? str2.size() : str1.size()); i++) {
			int ans = a[i] + b[i] + carry;
			if (ans >= 10) {
				total++;
				carry = ans / 10;
			}
			else {
				carry = 0;
			}
		}
		if (str1.size() != str2.size()) {
			if (str1.size() > str2.size()) {
				for (int j = i; j < str1.size(); j++) {
					if (a[j] + carry >= 10) {
						carry = (a[j] + carry) / 10;
						total++;
					}
					else {
						break;
					}
				}
			}
			else {
				for (int j = i; j < str2.size(); j++) {
					if (b[j] + carry >= 10) {
						carry = (b[j] + carry) / 10;
						total++;
					}
					else {
						break;
					}
				}
			}
		}
		if (total == 0) {
			cout << "No carry operation." << '\n';
		}
		else if (total == 1) {
			cout << "1 carry operation." << '\n';
		}
		else {
			cout << total << " carry operations." << '\n';
		}
	}
	//cout.close();
	return 0;
}