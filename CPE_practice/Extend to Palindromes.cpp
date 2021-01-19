#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int* make_failure(string& pattern) {

	int m = pattern.size();
	int* failure = (int*)calloc(m, sizeof(int));

	failure[0] = 0;
	int i = 1;
	int len = 0;
	while ( i < m ){

		if (pattern[i] == pattern[len]) {
			len++;
			failure[i] = len;
			i++;
		}

		else {

			if (len != 0) {
				len = failure[i - 1];
			}
			else {
				failure[i] = 0;
				i++;
			}
		}

	}
	return failure;
}

int KMP_search(string& target, string& pattern) {

	int n = target.size();
	int m = pattern.size();
	int* failure = make_failure(pattern);
	int i = 0;
	int j = 0;
	while (i < n) {

		if (target[i] == pattern[j]) {
			i++;
			j++;
		}

		if (j == m) {
			//j = failure[j - 1];
			return j;
		}
		else if (i < n && target[i] != pattern[j]) {

			if (j != 0) {
				j = failure[j - 1];
			}
			else {
				i++;
			}
		}
		
	}
	free(failure);
	return j;
}
int main() {

	string target;
	bool first_in = true;
	while (cin >> target) {

		if (first_in) {
			first_in = false;
		}
		else {
			cout << endl;
		}
		string pattern(target);
		reverse(pattern.begin(), pattern.end());

		int j = KMP_search(target, pattern);
		string ans(target);
		for (int i = j; i < pattern.size(); i++) {
			ans += pattern[i];
		}
		cout << ans;
	}
	
	return 0;
}