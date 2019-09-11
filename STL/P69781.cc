#include <iostream>
#include <vector>
using namespace std;

void collatz(int& n, int &x, int &y) {

	if (n%2 == 0) n = n/2 + x;
	else n = 3*n + y;
}

int main() {

	int n, x, y;

	while (cin >> x >> y >> n) {

		vector<int> v;
		bool found = false;
		
		v.push_back(n);

		while (not found) {

			collatz(n,x,y);
			v.push_back(n);

			if (n > 100000000) {

				cout << n << endl;
				found = true;
			}

			for (int i = 0; i < v.size()-1; i++) {

				if (v[i] == n) {

					cout << v.size()-1 - i << endl;
					found = true;
				}
			}
		}
	}
}
