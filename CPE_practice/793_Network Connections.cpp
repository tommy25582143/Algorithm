#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;





int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int input_number;
	cin >> input_number;
	cin.ignore();
	bool first_in = true;
	while (input_number-- > 0) {

		if (!first_in) {
			cout << '\n';
		}
		else {
			first_in = false;
		}
		int n;
		cin >> n;
		cin.ignore();
		vector<int>arr(n+1);
		for (int i = 0; i < n+1; i++) {
			arr[i] = i;
		}
		string temp;

		int succeed = 0, failed = 0;
		while (getline(cin, temp)) {

			if (temp == "") {
				break;
			}
			istringstream str(temp);
			char command;
			int a, b;
			str >> command >> a >> b;
			if (command == 'c') {
				int group_a = arr[a], group_b = arr[b];
				for (int i = 1; i < n+1; i++) {
					if (arr[i] == group_a || arr[i] == group_b) {
						arr[i] = min(group_a, group_b);
					}
				}
			}
			else {
				if(arr[a] == arr[b]){
					succeed++;
				}
				else {
					failed++;
				}
			}
		}
		cout << succeed << "," << failed << '\n';
	}
	//cout.close();
	return 0;
}