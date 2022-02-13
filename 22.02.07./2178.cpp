#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M, x, y;
    // 북, 서, 남, 동
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    string str_tmp;
    vector<int> vec_tmp;
    queue<pair<int, int> > q;
    pair<int, int> cur;
    pair<int, int> pair_tmp;
    cin >> N >> M;

    vector<vector<int> > map(N, vector<int>(M, 0));
    vector<vector<int> > dist(N, vector<int>(M, 0));
    // first = x, second = y
    cur.first = 0;
    cur.second = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> str_tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = stoi(str_tmp.substr(j, 1));
        }
    }

    q.push(cur);
    dist[0][0] = 1;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.first == M - 1 && cur.second == N - 1) {
            cout << dist[cur.second][cur.first] << endl;
            break ;
        }
        for (int i = 0; i < 4; i++) {
            x = cur.first + dx[i];
            y = cur.second + dy[i];
            if (x >= 0 && x < M && y >= 0 && y < N) {
                if (map[y][x] == 1 && dist[y][x] == 0) {
                    dist[y][x] = dist[cur.second][cur.first] + 1;
                    pair_tmp.first = x;
                    pair_tmp.second = y;
                    q.push(pair_tmp);
                }
            }
        }
    }
    return 0;
}