#include <iostream>
#include <string>
#include <vector>

using namespace std;

string rotate(string before, int dir) {
    string after = "";
    // 1 : 시계, -1 : 반시계
    if (dir == 1) {
        after += before[7];
        for (int i = 0; i < 7; i++)
            after += before[i];
    }
    else if (dir == -1) {
        for (int i = 1; i < 8; i++)
            after += before[i];
        after += before[0];
    }
    return after;
}

void check_and_rotate(vector<string> &gear_arr, int gear, int dir, int chk_dir) {
    if (gear < 1 || gear > 4)
        return ;

    // 오른쪽방향 확인
    if (gear != 4 && (chk_dir == 0 || chk_dir == 1)) {
        // 1. 확인
        if (gear_arr[gear - 1][2] != gear_arr[gear][6]) {
            // 2. 회전
            check_and_rotate(gear_arr, gear + 1, dir * -1, 1);
        }   
    }
    // 왼쪽방향 확인
    if (gear != 1 && (chk_dir == 0 || chk_dir == -1)) {
        // 1. 확인
        if (gear_arr[gear - 1][6] != gear_arr[gear - 2][2]) {
            // 2. 회전
            check_and_rotate(gear_arr, gear - 1, dir * -1, -1);
        }
    }
    gear_arr[gear - 1] = rotate(gear_arr[gear - 1], dir);
}

int main(void) {
    vector<string> gear_arr(4, "");
    string first, second, third, forth;
    int K, gear, dir;
    int score = 0;
    cin >> first >> second >> third >> forth;
    cin >> K;
    gear_arr[0] = first;
    gear_arr[1] = second;
    gear_arr[2] = third;
    gear_arr[3] = forth;

    // right : 2, left : 6
    for (int x = 0; x < K; x++) {
        cin >> gear >> dir;
        check_and_rotate(gear_arr, gear, dir, 0);
    }
    // 점수 집계
    int score_tmp = 1;
    for (int i = 0; i < gear_arr.size(); i++) {
        score += (gear_arr[i][0] - 48) * score_tmp;
        score_tmp *= 2;
    }
    cout << score << '\n';
}