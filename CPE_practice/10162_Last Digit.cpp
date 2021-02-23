#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <fstream>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {

	//ofstream cout;
	//cout.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int last_digit[20] = { 0, 1, 5, 2, 8, 3, 9, 2, 8, 7,
						7, 8, 4, 7, 3, 8, 4, 1, 5, 4 };

	string input;
	while (cin >> input) {
		if (input == "0") {
			break;	
		}
		int n = input.size();
		int value = input[n - 1] - '0';
		if (n >= 2) {
			value += ((input[n - 2] - '0') * 10);
		}
		cout << (last_digit[value % 20] + (value / 20 * 4)) % 10 << '\n';
	}
	//for (int i = 0; i < 20; i++) {
	//	int temp = 1;
	//	for (int j = 1; j <= i; j++) {
	//		temp = (temp * i) % 10;
	//	}
	//	a.push_back(temp);
	//}
	//for (int i = 0; i < 20; i++) {
	//	cout << a[i] << " ";
	//}
	//cout.close();
	return 0;
}