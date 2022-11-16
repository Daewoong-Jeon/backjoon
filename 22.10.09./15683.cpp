#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc_blind(vector<vector<bool> > &blind_yn) {
    int result = 0;
    for (int i = 0; i < blind_yn.size(); i++) {
        for (int j = 0; j < blind_yn[i].size(); j++) {
            if (blind_yn[i][j] == true)
                result++;
        }
    }
    return result;
}

// 1 : 북, 2 : 동, 3 : 남, 4 : 서
void check_straight(vector<vector<int> > &map, vector<vector<bool> > &blind_yn, int start_n, int start_m, int dir) {
    int dn[5] = {-1, 0, 1, 0};
    int dm[5] = {0, 1, 0, -1};
    int n = start_n;
    int m = start_m;

    while (1) {
        if (n >= blind_yn.size() || m >= blind_yn[start_n].size())
            break;
        if (map[n][m] == 6)
            break;
        blind_yn[n][m] = false;
        n += dn[dir];
        m += dm[dir];
    }
}

// 1 : 북, 2 : 동, 3 : 남, 4 : 서
void check_blind(vector<vector<int> > &map, vector<vector<bool> > &blind_yn, int cctv, int n, int m, int dir) {
    if (cctv == 1) { // 1개 방향
        check_straight(map, blind_yn, n, m, dir - 1);
    }
    else if (cctv == 2) { // 2개 방향
        check_straight(map, blind_yn, n, m, dir - 1);
        check_straight(map, blind_yn, n, m, (dir + 1) % 4);
    }
    else if (cctv == 3) { // 2개 방향
        check_straight(map, blind_yn, n, m, dir - 1);
        check_straight(map, blind_yn, n, m, dir % 4);
    }
    else if (cctv == 4) { // 3개 방향
        check_straight(map, blind_yn, n, m, dir - 1);
        check_straight(map, blind_yn, n, m, dir % 4);
        check_straight(map, blind_yn, n, m, (dir + 2) % 4);
    }
    else if (cctv == 5) { // 4개 방향
        check_straight(map, blind_yn, n, m, dir - 1);
        check_straight(map, blind_yn, n, m, dir % 4);
        check_straight(map, blind_yn, n, m, (dir + 1) % 4);
        check_straight(map, blind_yn, n, m, (dir + 2) % 4);
    }
}

// 1 : 북, 2 : 동, 3 : 남, 4 : 서
void dfs(vector<vector<int> > &map, vector<vector<bool> > blind_yn, int &min, int n, int m) {
    int blind;
    // map위치 최적화
    if (map[0].size() <= m) {
        n++;
        m = 0;
    }
    // 최솟값 갱신
    if (map.size() <= n) {
        blind = calc_blind(blind_yn);
        if (blind < min)
            min = blind;
        return;
    }
    vector<vector<bool> > back_up = blind_yn;

    if (map[n][m] == 0 || map[n][m] == 6) // 사무실 빈 공간
        dfs(map, blind_yn, min, n, m + 1);
    else if (map[n][m] == 1) { // 1번 cctv (경우의 수 4개)
        for (int i = 1; i <= 4; i++) {
            check_blind(map, blind_yn, 1, n, m, i);
            dfs(map, blind_yn, min, n, m + 1);
            blind_yn = back_up;
        }
    }
    else if (map[n][m] == 2) { // 2번 cctv (경우의 수 2개)
        for (int i = 1; i <= 2; i++) {
            check_blind(map, blind_yn, 2, n, m, i);
            dfs(map, blind_yn, min, n, m + 1);
            blind_yn = back_up;
        }
    }
    else if (map[n][m] == 3) { // 3번 cctv (경우의 수 4개)
        for (int i = 1; i <= 4; i++) {
            check_blind(map, blind_yn, 3, n, m, i);
            dfs(map, blind_yn, min, n, m + 1);
            blind_yn = back_up;
        }
    }
    else if (map[n][m] == 4) { // 4번 cctv (경우의 수 4개)
        for (int i = 1; i <= 4; i++) {
            check_blind(map, blind_yn, 4, n, m, i);
            dfs(map, blind_yn, min, n, m + 1);
            blind_yn = back_up;
        }
    }
    else if (map[n][m] == 5) { // 5번 cctv (경우의 수 1개)
        check_blind(map, blind_yn, 5, n, m, 1);
        dfs(map, blind_yn, min, n, m + 1);
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;
    int min = N * M;
    vector<int> vec_tmp(M, 0);
    vector<vector<int> > map(N, vec_tmp);
    vector<bool> vec_tmp2(M, true);
    vector<vector<bool> > blind_yn(N, vec_tmp2);

    // 1. 맵 파싱
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 6)
                blind_yn[i][j] = false;
        }
    }

    // 2. 깊이우선탐색
    dfs(map, blind_yn, min, 0, 0);
    cout << min << '\n';
}