#include <iostream>
#include <map>
using namespace std;

int main() {

    int n;
    string name, op;
    map <string, int> m;

    while (cin >> name) {

        map <string, int>::iterator it;
        it = m.find(name);
        cin >> op;

        if (op == "enters") {

            if (it != m.end()) cout << name << " is already in the casino" << endl;
            else m.insert(m.end(), {name, 0});
        }

        else if (op == "wins") {

            cin >> n;

            if (it != m.end()) it->second += n;
            else cout << name << " is not in the casino" << endl;
        }

        else if (op == "leaves") {

                if (it != m.end()) {

                    cout << it->first << " has won " << it->second << endl;
                    m.erase(it);
                }
                else cout << name << " is not in the casino" << endl;
            }
        }

    cout << "----------" << endl;

    for (map<string,int>::iterator it = m.begin(); it != m.end(); it++) {

        cout << it->first << " is winning " << it->second << endl;
    }
}
