#include <iostream>

using namespace std;

int main() {
    int E;
    int S;
    int M;
    int x;
    cin >> E;
    cin >> S;
    cin >> M;

    if (E == 15)
        E = 0;
    if (S == 28)
        S = 0;
    if (M == 19)
        M = 0;
    for (x = 1; x < 2147483647; x++) {
        if (x % 15 == E && x % 28 == S && x % 19 == M)
            break ;
    }
    cout << x << endl;
}