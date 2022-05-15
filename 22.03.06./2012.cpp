#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n, rank;
    long long result = 0;
    cin >> n;
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        cin >> rank;
        stack.push_back(rank);
    }
    sort(stack.begin(), stack.end());

    for (int i = 0; i < n; i++)
        result += abs((i + 1) - stack[i]); // data type 조심
    cout << result << endl;

    // int n, rank;
    // long long result = 0;
    // cin >> n;
    // vector<bool> check_rank(n + 1, false);
    // vector<int> overlap_rank;

    // for (int i = 0; i < n; i++) {
    //     cin >> rank;
    //     if (check_rank[rank] == false)
    //         check_rank[rank] = true;
    //     else
    //         overlap_rank.push_back(rank);
    // }
    // sort(overlap_rank.begin(), overlap_rank.end());

    // for (int i = n; i > 0; i--) {
    //     if (check_rank[i] == false && !overlap_rank.empty()) {
    //         result += abs(i - overlap_rank.back()); // data type 조심
    //         overlap_rank.pop_back();
    //     }
    // }
    // cout << result << endl;

    // 주어진 n값 바깥의 값을 예상등수로 삼는 케이스가 있는듯.
}