#include <iostream>
#include <map>
using namespace std;

int main() {

	cout.setf(ios::fixed);
	cout.precision(4);

	map<int,int> m;
	string op;
	map<int,int>::iterator it;
	int i,n,s;
	n = s = 0;

	while (cin >> op) {

		if (op == "number") {

			cin >> i;
			it = m.find(i);
			if (it != m.end()) it->second++;
			else m.insert({i,1});
			s += i;
			n++;
		}

		else {

			if (not m.empty()) {

				n--;
				s -= m.begin()->first;

				if (m.begin()->second > 1) m.begin()->second--;
				else m.erase(m.begin());
			}
		}

		if (m.empty()) cout << "no elements" << endl;
		else {

			cout << "minimum: " << m.begin()->first << ", maximum: " << prev(m.end())->first;
			cout << ", average: " << double(s)/n << endl;
		}
	}
}
