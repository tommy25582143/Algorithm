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
	//cout.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long long input;
	string number_str[4] = { "kuti", "lakh", "hajar", "shata" };
	long number[4] = { 10000000 , 100000 , 1000, 100 };
	int input_number = 1;
	while (cin >> input) {
		//if (input == -1) {
		//	break;
		//}

		cout << setw(4) << input_number;
		cout << '.';
		
		bool is_tested = false;
		if (input / 10000000 >= 100) {
			int temp = input / 10000000;
			for (int i = 0; i < 4; i++) {
				
				if (temp / number[i] != 0) {
					if (!is_tested) {
						is_tested = true;
					}
					cout << " " << temp / number[i] << " " << number_str[i];
				}
				temp %= number[i];
			}
			if (temp != 0) {
				cout << " " << temp << " " << "kuti";
			}
			else {
				cout << " " << "kuti";
			}
			input %= 10000000;
		}
		for (int i = 0; i < 4; i++) {

			if (input / number[i] != 0) {
				if (!is_tested) {
					is_tested = true;
				}
				cout << " " << input / number[i] << " " << number_str[i];
			}
			input %= number[i];
		}
		if(input != 0){
			cout << " " << input;
		}
		if (input == 0 && !is_tested) {
			cout << " " << input;
		}
		input_number++;
		cout << '\n';
	}
	//cout.close();
	return 0;
}