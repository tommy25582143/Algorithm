#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define PI atan(1) * 4
#define ull unsigned long long
using namespace std;

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n) {
		queue<int>q;

		int m = 1;
		while (true) {

			for (int i = 2; i <= n; i++) {
				q.push(i);
			}
			for (int i = 0; i < n - 2; i++) {
				int temp = -1;
				for (int j = m; j > 0; j--) {
					if (temp != -1) {
						q.push(temp);
					}
					temp = q.front();
					q.pop();
				}
			}
			if (q.front() == 13) {
				cout << m << '\n';
				break;
			}
			q.pop();
			m++;
		}

	}

	//output.close();
	return 0;
}