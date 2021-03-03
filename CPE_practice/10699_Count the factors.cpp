#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int>prime;
	prime.push_back(2);
	for (int i = 3; i * i <= 1000000; i++) {
		bool is_prime = true;
		for (int j = 0; j < prime.size(); j++) {
			if (i % prime[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			prime.push_back(i);
		}
	}

	int input;
	while ((cin >> input, input) != 0) {
		cout << input << " : ";
		int n = 0;
		for (int i = 0; i < prime.size() && prime[i] <= input; i++) {
			if (input % prime[i] == 0) {
				n++;
				while (input % prime[i] == 0) {
					input /= prime[i];
				}
			}
		}
		if (input != 1) {
			n++;
		}
		cout << n << '\n';
	}
	//cout.close();
	return 0;
}