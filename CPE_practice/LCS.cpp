#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int LCS(string& first, string& second) {

	int n = first.size();
	int m = second.size();
	vector<vector<int>>arr(n+1, vector<int>(m+1, 0));
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0) {
				arr[i][j] = 0;
			}
			else {

				if (first[i-1] == second[j-1]) {
					arr[i][j] = arr[i - 1][j - 1] + 1;
				}
				else {
					arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
				}
			}
		}
	}
	return arr[n][m];
}
int main() {

	bool first_in = true;
	string first, second;
	while (cin >> first) {

		cin >> second;
		if (first_in) {
			first_in = false;
		}
		else {
			cout << endl;
		}
		cout << LCS(first, second);
	}

	return 0;
}