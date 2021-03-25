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
#define ull unsigned long long
using namespace std;

int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ull money[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	float input;
	ull dp[30001];

	for (int i = 1; i <= 30000; i++) {
		dp[i] = 0;
	}

	dp[0] = 1;

	for (int i = 0; i <	11; i++) {
		for (ull j = money[i]; j <= 30000; j++) {
			dp[j] += dp[j - money[i]];
		}
	}
	int part1, part2;
	while (scanf("%d.%d", &part1, &part2)) {
		if (part1 == 0 && part2 == 0) {
			break;
		}
		printf("%3d.%02d%17lld\n", part1, part2, dp[100 * part1 + part2]);
	}

	//cout.close();
	return 0;
}