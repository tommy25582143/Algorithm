#include <iostream>
#include <vector>	
#include <queue>
#include <algorithm>
#include <string>


using namespace std;


int main() {

	int m, n;
	cin >> m >> n;

	vector<int>elements;
	elements.reserve(m);
	vector<int>get;
	get.reserve(n);
	vector<int>black_box;
	black_box.reserve(n);

	
	int temp;
	while (m-- > 0) {
		
		cin >> temp;
		elements.push_back(temp);

	}
	while (n-- > 0) {
		
		cin >> temp;
		get.push_back(temp);

	}

	vector<int>::iterator next_get =  get.begin();
	int i = 0;
	bool first_in = true;
	int counter = 0;
	while (1) {


		if (*next_get == black_box.size()) {
			if (first_in) {
				first_in = false;
			}
			else {
				cout << endl;
			}
			cout << black_box[i];
			next_get++;
			i++;
		}

		if (next_get == get.end()) {
			break;
		}

		
		if (*next_get != counter && counter < elements.size()) {
			black_box.push_back(elements[counter]);
			sort(black_box.begin(), black_box.end());
			counter++;
		}

	}
	return 0;
}