#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    priority_queue<unsigned int, vector<unsigned int> > p_q;
    int n, num;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > 0)
            p_q.push(num);
        else {
            if (p_q.empty())
                cout << 0 << '\n';    
            else {
                cout << p_q.top() << '\n';
                p_q.pop();
            }
        }
    }
}