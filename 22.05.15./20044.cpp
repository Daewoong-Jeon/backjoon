#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int tmp;
    int min = -1;
    vector<int> s;

    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(), s.end());

    for (int i = 0; i < (2 * n) - i - 1; i++) {
        tmp = s[i] + s[(2 * n) - i - 1];
        if (min == -1 || tmp < min)
            min = tmp;
    }
    cout << min << endl;
}