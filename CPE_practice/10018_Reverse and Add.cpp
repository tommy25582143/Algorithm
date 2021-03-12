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
	int n;
	cin >> n;
	while (n-- > 0) {
		
		string ans;
		cin >> ans;
		int times = 0;
		while (true) {
			if (test_palin(ans)) {
				break;
			}
			
			int carry = 0;
			string str = "";
			for (int i = ans.size() - 1, j = 0; i >= 0 && j < ans.size(); i--, j++) {
				int temp = ans[i] - '0' + ans[j] - '0' + carry;
				carry = 0;
				while (temp >= 10) {
					carry++;
					temp -= 10;
				}
				str = char(temp + '0') + str;
			}
			if (carry != 0) {
				str = to_string(carry) + str;
			}
			ans = str;
			times++;
		}
		cout << times << " " << ans << '\n';
	}
	//output.close();
	return 0;
}