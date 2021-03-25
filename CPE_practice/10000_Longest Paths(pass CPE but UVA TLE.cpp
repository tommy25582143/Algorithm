#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;

void dfs(vector< vector<bool> >&adj_list, int& start, int& end, int& len) {

	end = start;
	for (int i = 1; i < adj_list.size(); i++) {
		int temp_end = end, temp_len = 0;
		if (adj_list[start][i]) {
			dfs(adj_list, i, temp_end, temp_len);
			temp_len++; //add length from this point
			if (temp_len > len) {
				len = temp_len;
				end = temp_end;
			}
			else if (temp_len == len) {
				if (temp_end < end) {
					end = temp_end;
					len = temp_len;
				}
			}
		}
	}
	return;
}

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int case_number = 1;
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		int start;
		cin >> start;
		vector< vector<bool> >adj_list(n + 1, vector<bool>(n + 1, false));
		int from, to;
		while (cin >> from >> to) {
			if (from == 0 && to == 0) {
				break;
			}
			adj_list[from][to] = true;
		}
		int end = n + 1, len = 0;
		dfs(adj_list, start, end, len);
		cout << "Case " << case_number << ": The longest path from " << start;
		cout << " has length " << len << ", finishing at " << end << "." << "\n\n";
		case_number++;
	}
	//output.close();
	return 0;
}