#include <iostream>
#include <vector>
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
    std::vector<std::string> input;
    std::vector<int> stack;
    std::string input_string;
    std::cin >> N;
    std::cin.ignore();
    
    for (int i = 0; i < N; i++) {
        getline(std::cin, input_string);
        input = split(input_string);
        if (input[0] == "push") {
            stack.push_back(std::stoi(input[1]));
        } else if (input[0] == "top") {
            if (stack.empty() == 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << stack.back() << std::endl;
            }
        } else if (input[0] == "size") {
            std::cout << stack.size() << std::endl;
        } else if (input[0] == "empty") {
            std::cout << stack.empty() << std::endl;
        } else if (input[0] == "pop") {
            if (stack.empty() == 1) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << stack.back() << std::endl;
                stack.pop_back();
            }
        }
    }
}