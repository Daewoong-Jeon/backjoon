#include <iostream>
#include <string>
#include <queue>

// using namespace std;

int main() {
    int N;
    int flag;
    std::string input_str;
    std::cin >> N;
    std::queue<char> q;

    for (int i = 0; i < N; i++) {
        flag = 0;
        std::cin >> input_str;
        for (int j = 0; j < input_str.length(); j++) {
            if (input_str[j] == '(') {
                q.push(input_str[j]);
            } else if (input_str[j] == ')') {
                if (q.empty() == 1) {
                    flag = 1;
                    break ;
                } else {
                    q.pop();
                }
            }
        }
        if (flag == 1 || q.empty() == 0) {
            std::cout << "NO" << std::endl;
            while (!q.empty()) {
                q.pop();
            }
        } else if (flag == 0) {
            std::cout << "YES" << std::endl;
        }
    }
}