#include <queue>
#include <iostream>
#include <string>

// using namespace std;

std::vector<std::string> split(std::string str) {
    std::vector<std::string> result;
    std::string tmp = "";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            result.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    result.push_back(tmp);
    return result;
}

int main() {
    int N;
    std::string input_string;
    std::queue<int> queue;
    std::vector<std::string> input;
    std::cin >> N;
    std::cin.ignore();
    
    for (int i = 0; i < N; i++) {
        getline(std::cin, input_string);
        input = split(input_string);
        if (input[0] == "push") {
            queue.push(std::stoi(input[1]));
        } else if (input[0] == "front") {
            if (queue.empty() == 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << queue.front() << std::endl;
            }
        } else if (input[0] == "back") {
            if (queue.empty() == 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << queue.back() << std::endl;
            }
        } else if (input[0] == "size") {
            std::cout << queue.size() << std::endl;
        } else if (input[0] == "empty") {
            std::cout << queue.empty() << std::endl;
        } else if (input[0] == "pop") {
            if (queue.empty() == 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << queue.front() << std::endl;
                queue.pop();
            }
        }
    }
}