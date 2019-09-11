#include <iostream>
#include <map>
using namespace std;

int main() {

	map <string,int> m;
	string s;
	while (cin >> s) {

		if (s == "minimum?") {

			if (m.empty()) cout << "indefinite minimum" << endl;
			else {

				cout << "minimum: " << m.begin()->first << ", ";
				cout << m.begin()->second << " time(s)" << endl;
			}
		}
		else if (s == "maximum?") {

			if (m.empty()) cout << "indefinite maximum" << endl;
			else {

				cout << "maximum: " << m.rbegin()->first << ", ";
				cout << m.rbegin()->second << " time(s)" << endl;
			}
		}
		else if (s == "store") {

			string w;
			cin >> w;
			map <string,int>::iterator it = m.find(w);
			if (it != m.end()) it->second++;
			else m.insert({w, 1});
		}
		else {
			
			string w;
			cin >> w;
			map <string,int>::iterator it = m.find(w);
			if (it != m.end()) it->second--;
			if (it->second == 0) m.erase(it);
		}
	}
}
