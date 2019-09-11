#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue <int> pq;
    char op;
    int n;

    while (cin >> op) {

        if (op == 'A') {

            if (pq.empty()) cout << "error!" << endl;
            else cout << pq.top() << endl;
        }
        else if (op == 'S') {

            cin >> n;
            pq.push(n);
        }
        else if (op == 'R') {

            if (pq.empty()) cout << "error!" << endl;
            else pq.pop();
        }
        else if (op == 'I') {
            
            cin >> n;
            if (pq.empty()) cout << "error!" << endl;
            else {
                int t = pq.top();
                t += n;
                pq.pop();
                pq.push(t);
            }
        }
        else {

            cin >> n;
            if (pq.empty()) cout << "error!" << endl;
            else {
                int t = pq.top();
                t -= n;
                pq.pop();
                pq.push(t);
            }
        }
    }
}
