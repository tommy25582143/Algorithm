#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>



using namespace std;



int count(int input) {
	int total = 0;
	while (input > 0) {
		total += input % 10;
		input /= 10;
	}
	return total;
}

int main() {

	//ofstream cout;
	//cout.open("cout.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int not_prime[40000] = {1, 1, 0};
	int prime_cost[40000];
	for (int i = 2; i < 40000; i++) {
		if (!not_prime[i]) {
			for (int j = i + i; j < 40000; j *= i) {
				not_prime[j] = 1;
			}
		}
	}

	int n;
	cin >> n;
	while (n-- > 0) {
		int smith_number;
		cin >> smith_number;
		smith_number++;
		while(true){
			int left_sum = 0;
			int right_sum = 0;
			left_sum = count(smith_number);

			int temp = smith_number;
			for (int i = 2; i * i <= smith_number; i++) {
				if (!not_prime[i]) {
					while (temp % i == 0) {
						right_sum += count(i);
						temp /= i;
					}
				}
			}

			if (temp != smith_number) {
				if (temp > 1) {
					right_sum += count(temp);
				}
			}

			if (left_sum == right_sum) {
				break;
			}
			smith_number++;
		}
		cout << smith_number << '\n';
	}

	//cout.close();
	return 0;
}