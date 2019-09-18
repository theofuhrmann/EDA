#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cond (pair<int,string> p1, pair<int,string> p2) {

	if (p1.first > p2.first) return true;
	if (p1.first == p2.first) return p1.second < p2.second;
	return false;
}

int main() {

	string op, p1, p2;
	map<string,pair<int,bool>> m;
	map<string,pair<int,bool>>::iterator it, it2; 
	
	while (cin >> op) {

		if (op == "LOGIN") {

			cin >> p1;
			it = m.find(p1);
			if (it != m.end()) {

				if (not it->second.second) it->second.second = true;
			}
			else m.insert({p1,make_pair(1200,true)});
		}
		else if (op == "LOGOUT") {

			cin >> p1;
			it = m.find(p1);
			if (it != m.end()) it->second.second = false;
		}
		else if (op == "PLAY") {

			cin >> p1 >> p2;
			it = m.find(p1);
			if (not it->second.second) cout << "player(s) not connected" << endl;
			else {

				it2 = m.find(p2);
				if (not it2->second.second) cout << "player(s) not connected" << endl;
				else {

					it->second.first += 10;
					if (it2->second.first - 10 >= 1200) it2->second.first -= 10;
				}
			}
		}
		else {

			cin >> p1;
			it = m.find(p1);
			cout << it->first << ' ' << it->second.first << endl;
		}
	}

	cout << endl << "RANKING" << endl;
	vector<pair<int,string>> v;
	for (it = m.begin(); it != m.end(); it++) v.push_back(make_pair(it->second.first, it->first));
	sort(v.begin(), v.end(), cond);
	for (int i = 0; i < v.size(); i++) cout << v[i].second << ' ' << v[i].first << endl;
}
