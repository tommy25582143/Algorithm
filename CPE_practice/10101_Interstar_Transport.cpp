#include <iostream>
#include <vector>	
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

void transport(int from, int to, vector<vector<int>>&adj_matrix) {
	vector<int>predecesor(adj_matrix.size(), -1);
	vector<int>color(adj_matrix.size(), 0);
	vector<int>distance(adj_matrix.size(), INT_MAX);
	queue<int>q;

	q.push(from);
	distance[from] = 0;
	color[from] = 1;

	while (!q.empty()) {

		int i = q.front();
		for (int j = 0; j < adj_matrix.size(); j++) {
			if (adj_matrix[i][j] != INT_MAX) {
				if (color[j] == 0) {
					q.push(j);
					distance[j] = distance[i] + adj_matrix[i][j];
					predecesor[j] = i;
					color[j] = 1;
					continue;
				}

				if (distance[j] > distance[i] + adj_matrix[i][j]) {
					distance[j] = distance[i] + adj_matrix[i][j];
					predecesor[j] = i;
				}
			}
		}
		color[i] = 2;
		q.pop();
	}
	string ans("");
	int temp = to;
	while (predecesor[temp] != -1) {
		
		
		ans += (char)(temp + 'A');
		ans += ' ';
		temp = predecesor[temp];
	}
	ans += (char)(from + 'A');
	reverse(ans.begin(), ans.end());

	cout << ans;
	return;
	
}

int main() {

	int n, e;
	cin >> n >> e;
	vector<vector<int>>adj_matrix(n, vector<int>(n, INT_MAX));
	char from, to;
	int cost;
	while (e-- > 0) {
		cin >> from >> to >> cost;
		adj_matrix[from - 'A'][to - 'A'] = cost;
		adj_matrix[to - 'A'][from - 'A'] = cost;
	}
	int test_case;
	bool first_in = true;
	cin >> test_case;
	while (test_case-- > 0) {
		if (first_in) {
			first_in = false;
		}
		else {
			cout << endl;
		}
		cin >> from >> to;
		transport(from - 'A', to - 'A', adj_matrix);
	}
	return 0;
}