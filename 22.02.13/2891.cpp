#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s, r, tmp;
    int result = 0;
    cin >> n >> s >> r;
    vector<int> b(n + 1, 0);
    vector<int> p(n + 1, 0);
    for (int i = 0; i < s; i++) {
        cin >> tmp;
        b[tmp] = 1;
    }
    for (int i = 0; i < r; i++) {
        cin >> tmp;
        p[tmp] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] == 1) {
            if (b[i] == 1)
                b[i] = 0;
            else {
                if (b[i - 1] == 1)
                    b[i - 1] = 0;
                else if (b[i + 1] == 1)
                    b[i + 1] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] == 1)
            result++;
    }
    cout << result << endl;
}