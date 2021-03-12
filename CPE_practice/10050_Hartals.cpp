#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool test_palin(string& ans) {

	bool is_palin = true;

	for (int i = 0, j = ans.size() - 1; i <= j; i++, j--) {
		if (ans[i] != ans[j]) {
			is_palin = false;
			break;
		}
	}
	return is_palin;

}

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int input;
	cin >> input;
	while (input-- > 0) {

		int N;
		cin >> N;
		int n;
		cin >> n;
		vector<int>party(n, 0);
		vector<int>next_day(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> party[i];
			next_day[i] += party[i];
		}

		int days = 0;
		for (int i = 1; i <= N; i++) {
			bool is_occupied = false;
			for (int j = 0; j < n; j++) {
				if (i == next_day[j]) {

					if (!is_occupied) {
						if (!((i - 6) % 7 == 0 || (i - 7) % 7 == 0)) {
							days++;
						}
						is_occupied = true;
					}
					next_day[j] += party[j];
				}
			}
		}
		cout << days << '\n';
	}
	//output.close();
	return 0;
}