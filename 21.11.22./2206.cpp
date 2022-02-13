#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int dx[4] = {0, -1, 0, 1}; // 북, 서, 남, 동
    int dy[4] = {-1, 0, 1, 0};
    int answer = -1;
    queue<vector<int> > q;
    vector<int> cur(3, 0); // x, y, break
    vector<int> tmp(3, 0);
    string str;
    int N;
    int M;
    cin >> N;
    cin >> M;
    vector<vector<int> > map(N, vector<int>(M, 0));
    vector<vector<int> > distance(N, vector<int>(M, 0));
    distance[cur[1]][cur[0]] = 1;
    q.push(cur);

    // parsing map
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            map[i][j] = str[j] - '0';
    }

    int num = 0;
    // bfs
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        // cout << "x : " << cur[0] << ", y : " << cur[1] << ", break : " << cur[2] << ", distance : " << distance[cur[1]][cur[0]] << endl;
        if (cur[2] == 0)
            map[cur[1]][cur[0]] = 2;
        for (int i = 0; i < 4; i++) {
            tmp[0] = cur[0] + dx[i];
            tmp[1] = cur[1] + dy[i];
            tmp[2] = cur[2];
            if (tmp[0] == M - 1 && tmp[1] == N - 1) {
                answer = distance[cur[1]][cur[0]] + 1;
                break ; // 발견
            }
            if (tmp[0] >= 0 && tmp[0] < M && tmp[1] >= 0 && tmp[1] < N) {
                if (map[tmp[1]][tmp[0]] == 0) {
                    q.push(tmp);
                    distance[tmp[1]][tmp[0]] = distance[cur[1]][cur[0]] + 1;
                }
                else if (cur[2] == 0 && map[tmp[1]][tmp[0]] != 2) {
                    tmp[2] = 1;
                    distance[tmp[1]][tmp[0]] = distance[cur[1]][cur[0]] + 1;
                    q.push(tmp);
                }
            }
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << answer << endl;
}