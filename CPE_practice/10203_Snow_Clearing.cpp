#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;





int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	while (n-- > 0) {
		int a, b;
		double x1, y1, x2, y2;
		cin >> a >> b;
		string input;
		double dist = 0.0;
		cin.ignore();
		while (getline(cin, input)) {
			if (input == "") {
				break;
			}
			istringstream str(input);
			str >> x1 >> y1 >> x2 >> y2;
			dist += hypot(x1 - x2, y1 - y2);
		}
		dist /= 1000;
		double time = dist * 2 / 20;
		int min = int(round(time * 60));
		cout << min / 60 << ':';
		if (min % 60 < 10) {
			cout << '0' << min % 60;
		}
		else {
			cout << min % 60;
		}
		cout << "\n";
		if (n != 0) {
			cout << '\n';
		}
	}

	//cout.close();
	return 0;
}