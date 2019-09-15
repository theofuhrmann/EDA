#include <iostream>
#include <set>
using namespace std;

int main() {

	set <string> s;
	set <string>::const_iterator mid = s.end(); 
	string w;

	while (cin >> w and w != "END") {

		set <string>::const_iterator it = s.insert(w).first; 
		if (mid == s.end()) mid = it;
		else if (s.size()%2 == 0 and w < *mid) mid--;
		else if (s.size()%2 != 0 and w > *mid) mid++;
		cout << *mid << endl;
	}
}
