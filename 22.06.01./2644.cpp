#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int> > asso, int a, int b, int m) {
    queue<vector<int> > q;
    queue<bool> q_bool;
    vector<int> vec_tmp(3, 0);
    bool bool_tmp;

    for (int i = 0; i < asso.size(); i++) {
        if (a == asso[i][0]) {
            asso[i][2]++;
            asso[i][3]++;
            q.push(asso[i]);
            q_bool.push(true);
        }
        else if (a == asso[i][1]) {
            asso[i][2]++;
            asso[i][4]++;
            q.push(asso[i]);
            q_bool.push(false);
        }
    }

    while (!q.empty()) {
        vec_tmp = q.front();
        bool_tmp = q_bool.front();
        q.pop();
        q_bool.pop();
        if (vec_tmp[2] > m)
            break ;

        if (bool_tmp == true) {
            if (vec_tmp[1] == b) {
                return vec_tmp[2];
            }
            for (int i = 0; i < asso.size(); i++) {
                if (vec_tmp[1] == asso[i][0] && asso[i][4] == 0) {
                    asso[i][2] = vec_tmp[2] + 1;
                    asso[i][4]++;
                    q.push(asso[i]);
                    q_bool.push(true);
                }
                else if (vec_tmp[1] == asso[i][1] && asso[i][4] == 0) {
                    asso[i][2] = vec_tmp[2] + 1;
                    asso[i][4]++;
                    q.push(asso[i]);
                    q_bool.push(false);
                }
            }
        }
        else {
            if (vec_tmp[0] == b) {
                return vec_tmp[2];
            }
            for (int i = 0; i < asso.size(); i++) {
                if (vec_tmp[0] == asso[i][0] && asso[i][3] == 0) {
                    asso[i][2] = vec_tmp[2] + 1;
                    asso[i][3]++;
                    q.push(asso[i]);
                    q_bool.push(true);
                }
                else if (vec_tmp[0] == asso[i][1] && asso[i][3] == 0) {
                    asso[i][2] = vec_tmp[2] + 1;
                    asso[i][3]++;
                    q.push(asso[i]);
                    q_bool.push(false);
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int n, a, b, m, result;
    int min = -1;
    vector<int> vec_tmp(5, 0);
    vector<vector<int> > asso;

    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> vec_tmp[0];
        cin >> vec_tmp[1];
        asso.push_back(vec_tmp);
    }

    result = bfs(asso, a, b, m);
    cout << result << endl;
}