#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int dp[27][27][352];

void build() {

	dp[0][0][0] = 1;
	for (int i = 1; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			for (int k = 0; k < 352; k++) {
				if (k - i >= 0 && j > 0) {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j-1][k - i];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k];
				}
			}
		}
	}
}
int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int L, S;
	int case_number = 1;
	build();
	while (cin >> L >> S) {
		if (L == 0 && S == 0) {
			break;
		}
		if (L <= 26 && S <= 351) {
			cout << "Case " << case_number << ": " << dp[26][L][S] << '\n';
		}
		else {
			cout << "Case " << case_number << ": " << 0 << '\n';
		}
		case_number++;
	}

	//cout.close();
	return 0;
}