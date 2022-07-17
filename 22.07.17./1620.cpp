#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int to_integer(string input) {
    int result = 0;
    int divide = 1;
    int size = input.length();

    for (int i = 1; i < size; i++)
        divide *= 10;
    for (int i = 0; i < size; i++) {
        result += ((input[i] - '0') * divide);
        divide /= 10;
    }
    return result;
}

bool isnum(string input) {
    if (isdigit(input[0]))
        return true;
    else
        return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, number;
    string input;
    map<string, int> dic;
    vector<string> vec_dic;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input;
        dic[input] = i + 1;
        vec_dic.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        cin >> input;
        if (isnum(input)) {
            number = to_integer(input);
            cout << vec_dic[number - 1] << '\n';
        }
        else
            cout << dic[input] << '\n';
    }
}