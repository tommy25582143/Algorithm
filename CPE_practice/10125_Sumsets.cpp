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

bool find(vector<int>& set, int& ans) {

	for (int i = set.size() - 1; i >= 0; i--) {
		for (int j = 0; j < set.size(); j++) {
			for (int k = j + 1; k < set.size(); k++) {
				for (int l = k + 1; l < set.size(); l++) {
					if (set[i] == set[j] + set[k] + set[l]
						&& i != j && i != k && i != l) {
						ans = set[i];
						return true;;
					}
				}
			}
		}
	}
	return false;
}

int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector<int>set(n);
		for (int i = 0; i < n; i++) {
			cin >> set[i];
		}
		sort(set.begin(), set.end());
		int ans;
		if (find(set, ans)) {
			cout << ans << '\n';
		}
		else {
			cout << "no solution" << '\n';
		}
	}
	//cout.close();
	return 0;
}