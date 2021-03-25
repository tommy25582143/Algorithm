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


int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, R;
	int case_number = 1;
	while (cin >> N >> R) {
		if (N == 0 && R == 0) {
			break;
		}
		vector< vector<int> >capacity(N+1, vector<int>(N+1, -1));
		for (int i = 0; i < R; i++) {
			int x, y, limit;
			cin >> x >> y >> limit;
			capacity[x][y] = limit;
			capacity[y][x] = limit;
		}
		int from, to, mans;
		cin >> from >> to >> mans;

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					capacity[i][j] = max(capacity[i][j], min(capacity[i][k], capacity[k][j]));
				}
			}
		}
		cout << "Scenario #" << case_number << '\n';
		cout << "Minimum Number of Trips = " << mans / (capacity[from][to] - 1) + ((mans % (capacity[from][to]-1)  > 0) ? 1 : 0) << "\n\n";
		case_number++;
	}
	//cout.close();
	return 0;
}