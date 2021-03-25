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


	int round_biggest[184] = { 1 };
	int temp = 1;
	for (int i = 1, j = 6; i < 184 ; i++) {
		temp += i * j;
		round_biggest[i] = temp;
	}
	
	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << "0 0" << '\n';
			continue;
		}

		int round;
		for (int i = 1; i < 184; i++) {
			if (n <= round_biggest[i]) {
				round = i;
				break;
			}
		}
		int x = round-1, y = 1;
		int remainder = n - (round_biggest[round - 1] + 1) ;
		//-------------------------------------------------------
		for (int i = 0; i < round-1; i++) {
			if (remainder == 0) {
				break;
			}
			x--;
			y++;
			remainder--;
		}

		if (remainder == 0) {					
			cout << x << " " << y << '\n';
			continue;
		}
		//-------------------------------------------------------
		for (int i = 0; i < round; i++) {
			if (remainder == 0) {
				break;
			}
			x--;
			remainder--;
		}

		if (remainder == 0) {
			cout << x << " " << y << '\n';
			continue;
		}
		//-------------------------------------------------------
		for (int i = 0; i < round; i++) {
			if (remainder == 0) {
				break;
			}
			y--;
			remainder--;
		}
		if (remainder == 0) {
			cout << x << " " << y << '\n';
			continue;
		}
		//-------------------------------------------------------
		for (int i = 0; i < round; i++) {
			if (remainder == 0) {
				break;
			}
			x++;
			y--;
			remainder--;
		}
		if (remainder == 0) {
			cout << x << " " << y << '\n';
			continue;
		}
		//-------------------------------------------------------
		for (int i = 0; i < round; i++) {
			if (remainder == 0) {
				break;
			}
			x++;
			remainder--;
		}
		if (remainder == 0) {
			cout << x << " " << y << '\n';
			continue;
		}
		//-------------------------------------------------------
		for (int i = 0; i < round; i++){
			if (remainder == 0) {
				break;
			}
			y++;
			remainder--;
		}
		if (remainder == 0) {
			cout << x << " " << y << '\n';
			continue;
		}
	}
	//cout.close();
	return 0;
}