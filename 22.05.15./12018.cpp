#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, tmp, cur_stu, limit_stu;
    int count = 0;
    vector<int> stu_m;
    vector<int> vec_tmp;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> cur_stu >> limit_stu;
        for (int j = 0; j < cur_stu; j++) {
            cin >> tmp;
            vec_tmp.push_back(tmp);
        }
        sort(vec_tmp.begin(), vec_tmp.end());
        if (cur_stu >= limit_stu)
            stu_m.push_back(vec_tmp[cur_stu - limit_stu]);
        else
            stu_m.push_back(1);
        vec_tmp.clear();
    }
    sort(stu_m.begin(), stu_m.end());

    for (int i = 0; i < stu_m.size(); i++) {
        if (m < stu_m[i])
            break ;
        count++;
        m -= stu_m[i];
    }
    cout << count << endl;
}