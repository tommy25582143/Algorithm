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
#include <algorithm>

#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;


string turn_to_string(int a) {

	string ans = "";
	bool minus = false;
	if (a < 0) {
		minus = true;
		a *= -1;
	}


	while (true) {
		
		ans = char((a % 10) + '0') + ans;
		a /= 10;
		if (a == 0) {
			break;

		}
	}
	if (minus) {
		ans = '-' + ans;
	}
	return ans;
}

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		map<string, int> m;
		while (n-- > 0) {
			vector<int>input(5);
			for (int i = 0; i < 5; i++) {
				cin >> input[i];
			}
			sort(input.begin(), input.end());

			string combination = "";
			for (int i = 0; i < 5; i++) {
				combination += turn_to_string(input[i]);
			}

			if (m.find(combination) != m.end()) {
				m[combination]++;
			}
			else {
				m[combination] = 1;
			}
		}
		int most_often = 0;
		for (map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
			if (itr->second > most_often) {
				most_often = itr->second;
			}
		}
		int most_appear_times = 0;
		for (map<string, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
			if (itr->second == most_often) {
				most_appear_times++;
			}
		}
		cout << most_often * most_appear_times << '\n';

	}
	//output.close();
	return 0;
}