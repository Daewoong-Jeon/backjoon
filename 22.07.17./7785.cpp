#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, size;
    string key, value;
    map<string, bool> employee;
    vector<string> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        cin >> value;
        if (value == "enter")
            employee[key] = true;
        else
            employee[key] = false;
    }

    // for (map<string, bool>::iterator it = employee.begin(); it != employee.end(); ++it) {
    //     if (it->second == true)
    //         v.push_back(it->first);
    // }
        
    // while (!v.empty()) {
    //     cout << v.back() << '\n';
    //     v.pop_back();
    // }

    if (!employee.empty()) {
        map<string, bool>::iterator tmp = employee.end();
        map<string, bool>::iterator it;
        for (it = --tmp; it != employee.begin(); it--) {
            if (it->second == true)
                cout << it->first << '\n';
        }
        if (it->second == true)
            cout << it->first << '\n';
    }
}