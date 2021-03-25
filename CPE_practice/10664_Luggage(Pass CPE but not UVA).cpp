#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	while (n-- > 0) {
		string str;
		getline(cin, str);
		istringstream input(str);
		vector<int>luggage;
		int temp;
		int sum = 0;
		while (input >> temp) {
			luggage.push_back(temp);
			sum += temp;
		}
		if (sum % 2 != 0) {
			cout << "NO" << '\n';
			continue;
		}
		vector<bool>possibleweight(sum + 1, false);
		possibleweight[0] = true;
		for (int i = 0; i < luggage.size(); i++) {
			for (int j = luggage[i]; j <= sum; j++) {
				if (possibleweight[j - luggage[i]]) {
					possibleweight[j] = true;
				}
			}
		}
		if (possibleweight[sum / 2]) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	//output.close();
	return 0;
}