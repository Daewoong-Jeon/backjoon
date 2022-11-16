#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 0 : 북, 1 : 동, 2 : 남, 3 : 서
void move_dise(vector<vector<int> > &dise, pair<int, int> &cur, int &dir, int N, int M) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int tmp;
    pair<int, int> after;

    after.first = cur.first + dx[dir];
    after.second = cur.second + dy[dir];
    if (after.first >= M || after.first < 0
        || after.second >= N || after.second < 0) {
        dir = (dir + 2) % 4;
        after.first = cur.first + dx[dir];
        after.second = cur.second + dy[dir];
    }
    cur = after;

    if (dir == 0) {
        tmp = dise[3][1];
        dise[3][1] = dise[0][1];
        dise[0][1] = dise[1][1];
        dise[1][1] = dise[2][1];
        dise[2][1] = tmp;
    }
    else if  (dir == 1) {
        tmp = dise[3][1];
        dise[3][1] = dise[1][2];
        dise[1][2] = dise[1][1];
        dise[1][1] = dise[1][0];
        dise[1][0] = tmp;
    }
    else if (dir == 2) {
        tmp = dise[0][1];
        dise[0][1] = dise[3][1];
        dise[3][1] = dise[2][1];
        dise[2][1] = dise[1][1];
        dise[1][1] = tmp;
    }
    else if (dir == 3) {
        tmp = dise[3][1];
        dise[3][1] = dise[1][0];
        dise[1][0] = dise[1][1];
        dise[1][1] = dise[1][2];
        dise[1][2] = tmp;
    }
}

void init_dise(vector<vector<int> > &dise) {
    dise[0][1] = 2;
    dise[1][0] = 4;
    dise[1][1] = 1;
    dise[1][2] = 3;
    dise[2][1] = 5;
    dise[3][1] = 6;
}

void init_visit(vector<vector<bool> > &visit) {
    for (int i = 0; i < visit.size(); i++) {
        for (int j = 0; j < visit[i].size(); j++)
            visit[i][j] = false;
    }
}

void dfs(vector<vector<int> > &map, vector<vector<bool> > &visit, pair<int, int> cur, int &value, int &num) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    pair<int, int> after;

    for (int i = 0; i < 4; i++) {
        after.first = cur.first + dx[i];
        after.second = cur.second + dy[i];
        if (after.first < visit[0].size() && after.first >= 0 && after.second < visit.size() && after.second >= 0) {
            if (map[after.second][after.first] == value) {
                if (visit[after.second][after.first] == false) {
                    visit[after.second][after.first] = true;
                    num++;
                    dfs(map, visit, after, value, num);
                }
            }
        }
    }
}

int check_dir(vector<vector<int> > &dise, vector<vector<int> > &map, pair<int, int> &cur, int dir) {
    int A = dise[3][1];
    int B = map[cur.second][cur.first];

    if (A > B)
        return ((dir + 1) % 4);
    else if (A < B)
        return ((dir + 3) % 4);
    else if (A == B)
        return dir;
    return dir;
}

int main(void) {
    int N, M, K, B, C;
    int score = 0;
    int dir = 1;
    cin >> N >> M >> K;
    pair<int, int> cur; // x, y
    vector<int> map_tmp(M, 0);
    vector<int> dise_tmp(3, 0);
    vector<bool> visit_tmp(M, false);
    vector<vector<int> > map(N, map_tmp);
    vector<vector<int> > dise(4, dise_tmp);
    vector<vector<bool> > visit(N, visit_tmp);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    }
    init_dise(dise);
    cur.first = 0;
    cur.second = 0;

    for (int i = 0; i < K; i++) {
        // 1. 주사위 이동
        move_dise(dise, cur, dir, N, M);

        // 2. 점수 계산
        visit[cur.second][cur.first] = true;
        B = map[cur.second][cur.first];
        C = 1;
        dfs(map, visit, cur, B, C);
        score += B * C;
        init_visit(visit);

        // 3. 방향 결정
        dir = check_dir(dise, map, cur, dir);
    }
    cout << score << '\n';
}