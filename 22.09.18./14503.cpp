#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// 0 : 청소(x), 벽(x)
// 1 : 청소(x), 벽(o)
// 2 : 청소(o), 벽(x)

void parse_cur(vector<int> &cur) {
    int n, m, c;
    cin >> n >> m >> c;

    cur[0] = n;
    cur[1] = m;
    cur[2] = c;
}

void parse_map(vector<vector<int> > &map, int N, int M) {
    vector<int> vec_tmp;
    int value;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> value;
            vec_tmp.push_back(value);
        }
        map.push_back(vec_tmp);
        vec_tmp.clear();
    }
}

bool check_cleanYN(vector<int> &cur, vector<vector<int> > &map, int dirX[], int dirY[], int left_dir) {
    int x = cur[1] + dirX[left_dir];
    int y = cur[0] + dirY[left_dir];

    if (map[y][x] == 2 || map[y][x] == 1)
        return true;
    return false;
}

bool check_moveYN(vector<int> &cur, vector<vector<int> > &map, int dirX[], int dirY[], int back_dir) {
    int x = cur[1] + dirX[back_dir];
    int y = cur[0] + dirY[back_dir];

    if (map[y][x] == 1)
        return false;
    return true;
}

int main(void) {
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {-1, 0, 1, 0};
    int N, M, back_dir, left_dir;
    int rotate_count = 0;
    int clean_count = 1;
    cin >> N >> M;
    bool flag = true;

    vector<vector<int> > map;
    vector<int> cur(3, 0);
    
    parse_cur(cur);
    parse_map(map, N, M);
    map[cur[0]][cur[1]] = 2;

    while (flag) {
        if (rotate_count == 4) {
            back_dir = (cur[2] + 2) % 4;
            if (check_moveYN(cur, map, dirX, dirY, back_dir)) {
                cur[1] = cur[1] + dirX[back_dir];
                cur[0] = cur[0] + dirY[back_dir];
                rotate_count = 0;
            }
            else {
                flag = false;
                break;
            }
        }
        else {
            left_dir = (cur[2] + 3) % 4;
            if (check_cleanYN(cur, map, dirX, dirY, left_dir)) {
                cur[2] = left_dir;
                rotate_count++;
            }
            else {
                cur[1] = cur[1] + dirX[left_dir];
                cur[0] = cur[0] + dirY[left_dir];
                cur[2] = left_dir;
                map[cur[0]][cur[1]] = 2;
                clean_count++;
                rotate_count = 0;
            }
        }
    }
    cout << clean_count << '\n';
}

// using namespace std;

// int main() {
//     int N;
//     int M;
//     int x = 0;
//     int y = 0;
//     int direction;
//     int flag = 0;
//     int rotate = 0;
//     int answer = 0;
//     std::pair<int, int> cur;
//     std::cin >> N >> M;
//     std::cin >> cur.second >> cur.first >> direction;
//     int map[N][M];
    
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             std::cin >> map[i][j];
//         }
//     }
//     map[cur.second][cur.first] = 2;
//     answer++;
//     while (1) {
//         flag = 0;
//         rotate = 0;
//         while (rotate != 4) {
//             if (direction == 0) {
//                 x = -1;
//                 y = 0;
//             } else if (direction == 1) {
//                 x = 0;
//                 y = 1;
//             } else if (direction == 2) {
//                 x = 1;
//                 y = 0;
//             } else if (direction == 3) {
//                 x = 0;
//                 y = -1;
//             }
//             direction = (direction + 1) % 4;
//             rotate++;
//             if (map[cur.second + y][cur.first + x] == 0) {
//                 flag = 1;
//                 break ;
//             }
//         }
//         // 4구역 모두 청소했을 때,
//         if (flag == 0) {
//             if (direction == 0) {
//                 x = 0;
//                 y = 1;
//             } else if (direction == 1) {
//                 x = 1;
//                 y = 0;
//             } else if (direction == 2) {
//                 x = 0;
//                 y = -1;
//             } else if (direction == 3) {
//                 x = -1;
//                 y = 0;
//             }
//             if (map[cur.second + y][cur.first + x] == 1) {
//                 break ;
//             }
//             cur.first += x;
//             cur.second += y;
//         } else if (flag == 1) {
//             cur.first += x;
//             cur.second += y;
//             map[cur.second][cur.first] = 2;
//             answer++;
//         }
//     }
//     std::cout << answer << std::endl;
// }