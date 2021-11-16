#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <climits>
#include <algorithm>

#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;

ull mod(ull base, ull pow, ull divider) {
	if (pow == 0) {
		return 1;
	}
	if (pow == 1) {
		return base % divider;
	}
	else {
		ull temp = mod(base, pow / 2, divider);
		if (pow % 2 == 1) {
			return (temp*temp*base) % divider;
		}
		else {
			return (temp * temp) % divider;
		}
	}
}
int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	ull divider = 1;
	for (int i = 0; i < 9; i++) {
		divider *= 10;
	}
	divider += 9;


	ull n;
	while (cin >> n) {
		ull temp = mod(3, n, divider);
		if (temp < 2) {
			temp += divider;
			temp -= 2;
		}
		else {
			temp -= 2;
		}
		cout << temp << '\n';
	}
	//output.close();
	return 0;
}


