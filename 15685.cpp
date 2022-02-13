#include <iostream>
#include <utility>
#include <vector>

// using namespace std;

void recursive(std::vector<int> &direction_number, int generation, int depth) {
    std::vector<int> tmp;

    if (depth == generation) {
        return ;
    }
    tmp = direction_number;
    while (tmp.empty() != 1) {
        direction_number.push_back((tmp.back() + 1) % 4);
        tmp.pop_back();
    }
    recursive(direction_number, generation, depth + 1);
}

std::vector<std::pair<int, int> > find_coordinate(std::vector<int> direction_number, std::pair<int, int> start) {
    int tmp;
    std::pair<int, int> cur;
    std::vector<std::pair<int, int> > result;
    std::vector<int> vec_tmp;
    
    while (direction_number.empty() == 0) {
        vec_tmp.push_back(direction_number.back());
        direction_number.pop_back();
    }
    cur = start;
    result.push_back(cur);
    while (vec_tmp.empty() != 1) {
        tmp = vec_tmp.back();
        if (tmp == 0) {
            cur.first += 1;
        } else if (tmp == 1) {
            cur.second -= 1;
        } else if (tmp == 2) {
            cur.first -= 1;
        } else if (tmp == 3) {
            cur.second += 1;
        }
        result.push_back(cur);
        vec_tmp.pop_back();
    }
    return result;
}

int main() {
    int N;
    int generation;
    int square = 0;
    int input[4];
    int board[101][101] = {0, };
    std::pair<int, int> tmp;
    std::pair<int, int> start;
    std::vector<int> direction_number;
    std::vector<std::pair<int, int> > coordinate;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> input[j];
        }
        start.first = input[0];
        start.second = input[1];
        direction_number.push_back(input[2]);
        generation = input[3];
        recursive(direction_number, generation, 0);
        coordinate = find_coordinate(direction_number, start);
        while (coordinate.empty() == 0) {
            tmp = coordinate.back();
            board[tmp.second][tmp.first] = 1;
            coordinate.pop_back();
        }
        direction_number.clear();
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (board[i][j] == 1) {
                if (board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1]) {
                    square++;
                }
            }
        }
    }
    std::cout << square << std::endl;
}