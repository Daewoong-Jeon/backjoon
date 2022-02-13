#include <iostream>
#include <utility>

// using namespace std;

int main() {
    int N;
    int M;
    int x = 0;
    int y = 0;
    int direction;
    int flag = 0;
    int rotate = 0;
    int answer = 0;
    std::pair<int, int> cur;
    std::cin >> N >> M;
    std::cin >> cur.second >> cur.first >> direction;
    int map[N][M];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    map[cur.second][cur.first] = 2;
    answer++;
    while (1) {
        flag = 0;
        rotate = 0;
        while (rotate != 4) {
            if (direction == 0) {
                x = -1;
                y = 0;
            } else if (direction == 1) {
                x = 0;
                y = 1;
            } else if (direction == 2) {
                x = 1;
                y = 0;
            } else if (direction == 3) {
                x = 0;
                y = -1;
            }
            direction = (direction + 1) % 4;
            rotate++;
            if (map[cur.second + y][cur.first + x] == 0) {
                flag = 1;
                break ;
            }
        }
        // 4구역 모두 청소했을 때,
        if (flag == 0) {
            if (direction == 0) {
                x = 0;
                y = 1;
            } else if (direction == 1) {
                x = 1;
                y = 0;
            } else if (direction == 2) {
                x = 0;
                y = -1;
            } else if (direction == 3) {
                x = -1;
                y = 0;
            }
            if (map[cur.second + y][cur.first + x] == 1) {
                break ;
            }
            cur.first += x;
            cur.second += y;
        } else if (flag == 1) {
            cur.first += x;
            cur.second += y;
            map[cur.second][cur.first] = 2;
            answer++;
        }
    }
    std::cout << answer << std::endl;
}