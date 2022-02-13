#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int number, int sum, int &result) {
    sum += number;
    if (sum >= n) {
        if (sum == n)
            result++;
        return ;
    }
    dfs(n, 1, sum, result);
    dfs(n, 2, sum, result);
    dfs(n, 3, sum, result);
}

int main() {
    int result;
    int t;
    int n;

    cin >> t;
    for (int i = 0; i < t; i++) {
        result = 0;
        cin >> n;
        dfs(n, 1, 0, result);
        dfs(n, 2, 0, result);
        dfs(n, 3, 0, result);
        cout << result << endl;
    }
}