#include <iostream>
#include <string>
#include <vector>

using namespace std;

string checkPaper(string paper_info, int start_idx, int length) {
    if (length <= 1)
        return "YES";
    int center = length / 2;
    char com1 = paper_info[start_idx + center / 2];
    char com2 = paper_info[start_idx + center + (center / 2) + 1];
    // cout << "com1 : " << com1 << ", com2 : " << com2 << ", start_idx : " << start_idx << ", length : " << length << endl;
    if (com1 == com2) {
        cout << "check" << endl;
        return "NO";
    }
    if (checkPaper(paper_info, start_idx, length / 2) == "YES"
        && checkPaper(paper_info, start_idx + length / 2 + 1, length / 2) == "YES")
        return "YES";
    else
        return "NO";
}

int main(void) {
    int t, info_length;
    bool flag;
    string paper_info;
    vector<string> result;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        flag = false;
        cin >> paper_info;
        info_length = paper_info.length();
        // cout << info_length << endl;
        if (info_length % 2 == 0)
            result.push_back("NO");
        else if (info_length <= 1)
            result.push_back("YES");
        else {
            result.push_back(checkPaper(paper_info, 0, info_length));
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}