#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, y, n;
    cin >> n;
    vector< pair<int, int> > v;
    pair<int, int> tmp;

    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> y;
        tmp.first = x;
        tmp.second = y;
        v.push_back(tmp);
    }
}