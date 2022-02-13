#include <iostream>
#include <vector>
#include <queue>
#include <string>

// using namespace std;

struct cmp
{
    bool operator()(unsigned int a, unsigned int b)
    {
        return (a > b);
    }
};

int main() {
    int N;
    unsigned int input_int;
    std::string input_str;
    std::priority_queue<unsigned int, std::vector<unsigned int>, cmp> p_q;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> input_str;
        input_int = std::stoul(input_str);
        if (input_int == 0) {
            if (p_q.empty() == 1) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << p_q.top() << std::endl;
                p_q.pop();
            }
        } else {
            p_q.push(input_int);
        }
    }
}