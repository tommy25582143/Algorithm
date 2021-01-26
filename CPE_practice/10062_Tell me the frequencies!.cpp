#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool compare(const pair<int, int>&a, const pair<int, int>&b) {

	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string temp;
	bool first_in = true;
	while (getline(cin, temp)) {
		if (!first_in) {
			cout << '\n';
		}
		else {
			first_in = false;
		}
		vector<pair<int, int>>a(95, make_pair(0, 10000));
		int i = 0;
		for (auto itr = a.begin(); itr != a.end(); itr++, i++) {
			itr->first = i;
		}

		for (int i = 0; i < temp.size(); i++) {
	
			if (a[temp[i] - 32].second == 10000) {
				a[temp[i] - 32].second = 1;
			}
			else {
				a[temp[i] - 32].second++;
			}
			
		}
		sort(a.begin(), a.end(), compare);
		auto itr = a.begin();
		while (itr->second != 10000) {
			cout << itr->first + 32 << " " << itr->second << '\n';
			itr++;
		}
	}
	return 0;
}