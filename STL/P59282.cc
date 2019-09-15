#include <iostream>
#include <map>
using namespace std;

int main() {

	cout.setf(ios::fixed);
	cout.precision(4);

	map<int,int> m;
	string op;
	int i;
	map<int,int>::iterator min, max;

	while (cin >> op) {

		if (op == "number") {

			cin >> i;
			if (m.size() != 0 and i == min->first) min->second++;
			else if (m.size() != 0 and i == max->first) max->second++;
			else {

				m.insert({i,1});
				min = m.begin();
				max = prev(m.end());
			}
		}

		else {

			if (min->second > 1) min->second--;
			else min = m.erase(min);
				
		}

		if (m.size() == 0) cout << "no elements" << endl;
		else {

			int n;
			double avg;
			avg	= n = 0;

			for (map<int,int>::const_iterator it = m.begin(); it != m.end(); it++) {

				avg += (it->first * it->second);
				n += it->second;
			}

			avg /= n;

			cout << "minimum: " << min->first << ", maximum: " << max->first;
			cout << ", average: " << avg << endl;
		}
	}
}
