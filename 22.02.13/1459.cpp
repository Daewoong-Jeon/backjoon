#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int x, y, w, s, gap, tmp;
    int flag = 0;
    long long time = 0;
    cin >> x >> y >> w >> s;

    if (2 * w < s)
        flag = 1;
    else if (w > s)
        flag = 2;

    if (flag == 0) {
        if (x != 0 && y != 0) {
            tmp = (x < y) ? x : y;
            time += ((long long)tmp * (long long)s);
        }
        gap = abs(x - y);
        time += ((long long)gap * (long long)w);
    }
    else if (flag == 1)
        time += (long long)(x + y) * (long long)w;
    else if (flag == 2) {
        if (x != 0 && y != 0) {
            tmp = (x < y) ? x : y;
            time += ((long long)tmp * (long long)s);
        }
        gap = abs(x - y);
        time += (long long)(gap / 2) * (long long)(2 * s);
        time += (long long)(gap % 2) * (long long)w;
    }
    cout << time << endl;
}