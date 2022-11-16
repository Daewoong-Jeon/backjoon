#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 경사로 활용 조건
// 1. 높이 1 (gap == 1 || gap == -1)
// 2. 경사로는 겹치지 않을 것
// 3. 길이 L만큼의 공간이 확보될 것 (flat >= L)
// 경사로가 사용 가능한 상태 : (runway_possible == true)
// 반드시 경사로가 필요한 상태 : runway_need
bool check_column(vector<vector<int> > &map, int index, int L) {
    int gap;
    int flat = 1;
    int before = map[0][index];
    bool runway_possible = false;
    bool runway_need = false;

    if (L == 1)
        runway_possible = true;
    for (int i = 1; i < map.size(); i++) {
        gap = map[i][index] - before;
        if (gap == 0)
            flat++;
        else if (gap == 1) {
            if (runway_need == true)
                return false;
            if (runway_possible != true)
                return false;
            flat = 1;
            runway_need = false;
            runway_possible = false;
        }
        else if (gap == -1) {
            if (runway_need == true)
                return false;
            flat = 1;
            runway_need = true;
            runway_possible = false;
        }
        else if (gap >= 2 || gap <= -2)
            return false;
        if (flat >= L) {
            runway_possible = true;
            if (runway_need == true) {
                runway_possible = false;
                runway_need = false;
                flat = 0;
            }
        }
        before = map[i][index];
    }
    if (runway_need == true && runway_possible == false)
        return false;
    // cout << "column : " << index << '\n';
    return true;
}

bool check_rows(vector<vector<int> > &map, int index, int L) {
    int gap;
    int flat = 1;
    int before = map[index][0];
    bool runway_possible = false;
    bool runway_need = false;

    if (L == 1)
        runway_possible = true;
    for (int i = 1; i < map[index].size(); i++) {
        gap = map[index][i] - before;
        if (gap == 0)
            flat++;
        else if (gap == 1) {
            if (runway_need == true)
                return false;
            if (runway_possible != true)
                return false;
            flat = 1;
            runway_need = false;
            runway_possible = false;
        }
        else if (gap == -1) {
            if (runway_need == true)
                return false;
            flat = 1;
            runway_need = true;
            runway_possible = false;
        }
        else if (gap >= 2 || gap <= -2)
            return false;
        if (flat >= L) {
            runway_possible = true;
            if (runway_need == true) {
                runway_possible = false;
                runway_need = false;
                flat = 0;
            }
        }
        before = map[index][i];
    }
    if (runway_need == true && runway_possible == false)
        return false;
    // cout << "rows : " << index << '\n';
    return true;
}

int main(void) {
    int N, L;
    cin >> N >> L;
    vector<int> vec_tmp(N, 0);
    vector<vector<int> > map(N, vec_tmp);
    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < N; i++) {
        if (check_rows(map, i, L))
            result++;
    }
    for (int i = 0; i < N; i++) {
        if (check_column(map, i, L))
            result++;
    }
    std::cout << result << '\n';
}

// 채점중 80%까지 도달
// bool check_column(vector<vector<int> > &map, int index, int L) {
//     int gap;
//     int l = 1;
//     bool wait_fail = false;
//     bool fail_flag = true;

//     for (int i = 1; i < map.size(); i++) {
//         gap = map[i][index] - map[i - 1][index];
//         if (gap >= 2 || gap <= -2)
//             return false;
//         if (gap == 1) { // 1 증가
//             if (wait_fail) {
//                 // cout << "wait_fail rows : " << index << ", gap : "<< gap << '\n';
//                 return false;
//             } // wait_fail이 켜지면 gap이 0만 나와야 됨
//             if (fail_flag && L != 1) {
//                 // cout << "fail_flag rows : " << index << ", gap : "<< gap << '\n';
//                 return false;
//             } // fail_flag는 l(gap 0의 횟수)이 L보다 작을 때 켜짐
//             fail_flag = true;
//             l = 1;
//         }
//         else if (gap == -1) { // 1 감소
//             if (wait_fail) {
//                 // cout << "wait_fail rows : " << index << ", gap : "<< gap << '\n';
//                 return false;
//             } // wait_fail이 켜지면 gap이 0만 나와야 됨
//             else
//                 wait_fail = true;
//             fail_flag = true;
//             l = 1;
//         }
//         else if (gap == 0) { // 동일
//             l++;
//             if (l >= L) {
//                 if (wait_fail) {
//                     wait_fail = false;
//                     l = l - L;
//                     if (l < L)
//                         fail_flag = true;
//                     else
//                         fail_flag = false;
//                 }
//                 else
//                     fail_flag = false;
//             }
//         }
//     }
//     if (wait_fail) {
//         // cout << "wait_fail rows : " << index << ", gap : "<< gap << '\n';
//         return false;
//     }
//     // cout << "column : " << index << '\n';
//     return true;
// }

// bool check_rows(vector<vector<int> > &map, int index, int L) {
//     int gap;
//     int l = 1;
//     bool wait_fail = false;
//     bool fail_flag = true;

//     for (int i = 1; i < map[index].size(); i++) {
//         gap = map[index][i] - map[index][i - 1];
//         if (gap >= 2 || gap <= -2)
//             return false;
//         if (gap == 1) { // 1 증가
//             if (wait_fail) {
//                 // cout << "wait_fail rows : " << index << ", gap : "<< gap << '\n';
//                 return false;
//             } // wait_fail이 켜지면 gap이 0만 나와야 됨
//             if (fail_flag && L != 1) {
//                 // cout << "fail_flag rows : " << index << ", gap : "<< gap << '\n';
//                 return false;
//             } // fail_flag는 l(gap 0의 횟수)이 L보다 작을 때 켜짐    
//             fail_flag = true;
//             l = 1;
//         }
//         else if (gap == -1) { // 1 감소
//             if (wait_fail && L != 1) {
//                 // cout << "wait_fail rows : " << index << ", gap : "<< gap << '\n';
//                 return false;
//             } // wait_fail이 켜지면 gap이 0만 나와야 됨
//             else
//                 wait_fail = true;
//             fail_flag = true;
//             l = 1;
//         }
//         else if (gap == 0) { // 동일
//             l++;
//             if (l >= L) {
//                 if (wait_fail) {
//                     wait_fail = false;
//                     l = l - L;
//                     if (l < L)
//                         fail_flag = true;
//                     else
//                         fail_flag = false;
//                 }
//                 else
//                     fail_flag = false;
//             }
//         }
//     }
//     if (wait_fail) {
//         // cout << "wait_fail rows : " << index << ", gap : "<< gap << '\n';
//         return false;
//     }
//     // cout << "rows : " << index << '\n';
//     return true;
// }

// int main(void) {
//     int N, L;
//     cin >> N >> L;
//     vector<int> vec_tmp(N, 0);
//     vector<vector<int> > map(N, vec_tmp);
//     int result = 0;

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++)
//             cin >> map[i][j];
//     }

//     for (int i = 0; i < N; i++) {
//         if (check_rows(map, i, L))
//             result++;
//     }
//     for (int i = 0; i < N; i++) {
//         if (check_column(map, i, L))
//             result++;
//     }
//     cout << result << '\n';
// }