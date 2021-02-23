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
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int input = 0;
	int n, m;
	bool first_in = true;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		if (!first_in) {
			cout << '\n';
		}
		else {
			first_in = false;
		}
		input++;
		vector<vector<char>>arr(n, vector<char>(m, '0'));
		for (int i = 0; i < n; i++) {
			char temp;
			for (int j = 0; j < m; j++) {
				cin >> temp;
				if (temp == '*') {
					for (int k = i - 1; k <= i + 1; k++) {
						for (int l = j - 1; l <= j + 1; l++) {

							if (k == i && l == j) {
								arr[k][l] = '*';
								continue;
							}
							if (k >= 0 && l >= 0 && k < n && l < m) {
								if (arr[k][l] != '*') {
									arr[k][l]++;
								}
							}
						}
					}
				}
			}
			getchar(); // discard '\n'
		}
		cout << "Field #" << input << ':';
		for (int i = 0; i < n; i++) {
			cout << '\n';
			for (int j = 0; j < m; j++) {
				cout << arr[i][j];
			}
		}
		cout << '\n';
	}
	//cout.close();
	return 0;
}