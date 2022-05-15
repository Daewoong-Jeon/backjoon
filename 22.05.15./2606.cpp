#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> > &relation, vector<int> &virus_com, int cur) {
    for (int i = 0; i < relation.size(); i++) {
        if (relation[i][2] == 1) {
            if (cur == relation[i][0]) {
                virus_com[relation[i][1] - 1] = 1;
                relation[i][2] = 0;
                dfs(relation, virus_com, relation[i][1]);
            }
            else if (cur == relation[i][1]) {
                virus_com[relation[i][0] - 1] = 1;
                relation[i][2] = 0;
                dfs(relation, virus_com, relation[i][0]);
            }
        }
    }
}

int main() {
    int n, links, tmp;
    int count = 0;
    vector<int> vec_tmp;
    vector<vector<int> > relation;

    cin >> n >> links;

    vector<int> virus_com(n, 0);

    for (int i = 0; i < links; i++) {
        cin >> tmp;
        vec_tmp.push_back(tmp);
        cin >> tmp;
        vec_tmp.push_back(tmp);
        vec_tmp.push_back(1);
        relation.push_back(vec_tmp);
        vec_tmp.clear();
    }
    dfs(relation, virus_com, 1);
    for (int i = 1; i < n; i++) {
        if (virus_com[i] == 1)
            count++;
    }
    cout << count << endl;
}