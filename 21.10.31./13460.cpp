#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define STOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void move_ball(vector<string> &map, pair<int, int> red, pair<int, int> blue,
    int direction, int move, int &result) {
    pair<int, int> tmp1;
    pair<int, int> tmp2;
    int fail = 0;
    int success = 0;
    int flag = 0;
    if (direction == UP) {
        if (red.first <= blue.first) {
            tmp1 = red;
            tmp2 = blue;
            flag = 1;
        }
        else {
            tmp1 = blue;
            tmp2 = red;
            flag = 2;
        }
        while (tmp1.first >= 0) {
            if (map[tmp1.first][tmp1.second] == 'O') {
                if (flag == 1)
                    success = 1;
                else
                    fail = 1;
                break ;
            }
            else if (map[tmp1.first][tmp1.second] == '#') {
                tmp1.first++;
                break ;
            }
            tmp1.first--;
        }
        while (tmp2.first >= 0) {
            if (map[tmp2.first][tmp2.second] == 'O') {
                if (flag == 1)
                    fail = 1;
                else
                    success = 1;
                break ;
            }
            else if (map[tmp2.first][tmp2.second] == '#') {
                tmp2.first++;
                break ;
            }
            else if (tmp2.first == tmp1.first && tmp2.second == tmp1.second) {
                tmp2.first++;
                break ;
            }
            tmp2.first--;
        }
    }
    else if (direction == DOWN) {
        if (red.first <= blue.first) {
            tmp1 = blue;
            tmp2 = red;
            flag = 2;
        }
        else {
            tmp1 = red;
            tmp2 = blue;
            flag = 1;
        }
        while (tmp1.first <= map.size()) {
            if (map[tmp1.first][tmp1.second] == 'O') {
                if (flag == 1)
                    success = 1;
                else
                    fail = 1;
                break ;
            }
            else if (map[tmp1.first][tmp1.second] == '#') {
                tmp1.first--;
                break ;
            }
            tmp1.first++;
        }
        while (tmp2.first <= map.size()) {
            if (map[tmp2.first][tmp2.second] == 'O') {
                if (flag == 1)
                    fail = 1;
                else
                    success = 1;
                break ;
            }
            else if (map[tmp2.first][tmp2.second] == '#') {
                tmp2.first--;
                break ;
            }
            else if (tmp2.first == tmp1.first && tmp2.second == tmp1.second) {
                tmp2.first--;
                break ;
            }
            tmp2.first++;
        }
    }
    else if (direction == LEFT) {
        if (red.second <= blue.second) {
            tmp1 = red;
            tmp2 = blue;
            flag = 1;
        }
        else {
            tmp1 = blue;
            tmp2 = red;
            flag = 2;
        }
        while (tmp1.second >= 0) {
            if (map[tmp1.first][tmp1.second] == 'O') {
                if (flag == 1)
                    success = 1;
                else
                    fail = 1;
                break ;
            }
            else if (map[tmp1.first][tmp1.second] == '#') {
                tmp1.second++;
                break ;
            }
            tmp1.second--;
        }
        while (tmp2.second >= 0) {
            if (map[tmp2.first][tmp2.second] == 'O') {
                if (flag == 1)
                    fail = 1;
                else
                    success = 1;
                break ;
            }
            else if (map[tmp2.first][tmp2.second] == '#') {
                tmp2.second++;
                break ;
            }
            else if (tmp2.first == tmp1.first && tmp2.second == tmp1.second) {
                tmp2.second++;
                break ;
            }
            tmp2.second--;
        }
    }
    else if (direction == RIGHT) {
        if (red.second <= blue.second) {
            tmp1 = blue;
            tmp2 = red;
            flag = 2;
        }
        else {
            tmp1 = red;
            tmp2 = blue;
            flag = 1;
        }
        while (tmp1.second <= map[0].length()) {
            if (map[tmp1.first][tmp1.second] == 'O') {
                if (flag == 1)
                    success = 1;
                else
                    fail = 1;
                break ;
            }
            else if (map[tmp1.first][tmp1.second] == '#') {
                tmp1.second--;
                break ;
            }
            tmp1.second++;
        }
        while (tmp2.second <= map[0].length()) {
            if (map[tmp2.first][tmp2.second] == 'O') {
                if (flag == 1)
                    fail = 1;
                else
                    success = 1;
                break ;
            }
            else if (map[tmp2.first][tmp2.second] == '#') {
                tmp2.second--;
                break ;
            }
            else if (tmp2.first == tmp1.first && tmp2.second == tmp1.second) {
                tmp2.second--;
                break ;
            }
            tmp2.second++;
        }
    }
    if (fail == 1)
        return ;
    if (success == 1) {
        if (result == -1 || move < result)
            result = move;
        return ;
    }
    if (flag == 1) {
        red = tmp1;
        blue = tmp2;
    }
    else if (flag == 2) {
        red = tmp2;
        blue = tmp1;
    }
    if (direction != DOWN && direction != UP && map[red.first - 1][red.second] != '#')
        move_ball(map, red, blue, UP, move + 1, result);
    if (direction != UP && direction != DOWN && map[red.first + 1][red.second] != '#')
        move_ball(map, red, blue, DOWN, move + 1, result);
    if (direction != RIGHT && direction != LEFT && map[red.first][red.second - 1] != '#')
        move_ball(map, red, blue, LEFT, move + 1, result);
    if (direction != LEFT && direction != RIGHT && map[red.first][red.second + 1] != '#')
        move_ball(map, red, blue, RIGHT, move + 1, result);
}

int main() {
    int N;
    int M;
    int result = -1;
    string tmp;
    pair<int, int> red;
    pair<int, int> blue;
    vector<string> map;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++) {
            if (tmp[j] == 'R') {
                red.first = i;
                red.second = j;
            }
            else if (tmp[j] == 'B') {
                blue.first = i;
                blue.second = j;
            }
        }
        map.push_back(tmp);
    }
    move_ball(map, red, blue, STOP, 0, result);
    cout << result << endl;
}