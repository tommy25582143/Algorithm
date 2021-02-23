#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <fstream>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long s, d;
	while (cin >> s) {
		cin >> d;
		while (d > 0) {
			d -= s;
			s++;
		}
		cout << s - 1 << '\n';
	}
	//cout.close();
	return 0;
}