#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// pair.first : x, pair.second : y
void init_cloud(vector<pair<int, int> > &cloud, int N) {
    pair<int, int> tmp;
    
    tmp.first = 0;
    tmp.second = N - 1;
    cloud.push_back(tmp);
    tmp.first = 1;
    tmp.second = N - 1;
    cloud.push_back(tmp);
    tmp.first = 0;
    tmp.second = N - 2;
    cloud.push_back(tmp);
    tmp.first = 1;
    tmp.second = N - 2;
    cloud.push_back(tmp);
}

// 1 : ←, 2 : ↖, 3 : ↑, 4 : ↗, 5 : →, 6 : ↘, 7 : ↓, 8 : ↙
vector<pair<int, int> > move_cloud(vector<pair<int, int> > &before_cloud, int dir, int dis, int N) {
    vector<pair<int, int> > result;
    pair<int, int> pair_tmp;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int index = dir - 1;

    for (int i = 0; i < before_cloud.size(); i++) {
        pair_tmp.first = (before_cloud[i].first + (dx[index] * dis) + (N * dis)) % N;
        pair_tmp.second = (before_cloud[i].second + (dy[index] * dis) + (N * dis)) % N;
        result.push_back(pair_tmp);
    }
    before_cloud.clear();
    return result;
}

void raining(vector<vector<int> > &basket, vector<pair<int, int> > after_cloud) {
    int x, y;

    for (int i = 0; i < after_cloud.size(); i++) {
        x = after_cloud[i].first;
        y = after_cloud[i].second;
        basket[y][x] += 1;
    }
}

// 1 : ↖, 2 : ↗, 3 : ↘, 4 : ↙
void increase_water(vector<vector<int> > &basket, vector<pair<int, int> > after_cloud) {
    int dx[4] = {-1, 1, 1, -1};
    int dy[4] = {-1, -1, 1, 1};
    int num, x, y, after_x, after_y;
    int N = basket.size();

    for (int i = 0; i < after_cloud.size(); i++) {
        num = 0;
        x = after_cloud[i].first;
        y = after_cloud[i].second;
        for (int j = 0; j < 4; j++) {
            after_x = x + dx[j];
            after_y = y + dy[j];
            if (after_x < N && after_x >= 0 && after_y < N && after_y >= 0) {
                if (basket[after_y][after_x] > 0)
                    num++;
            }
        }
        basket[y][x] += num;
    }
}

vector<pair<int, int> > create_cloud(vector<vector<int> > &basket, vector<pair<int, int> > &after_cloud) {
    pair<int, int> pair_tmp;
    vector<pair<int, int> > result;
    map<pair<int, int>, bool> cloud_map;

    for (int i = 0; i < after_cloud.size(); i++) {
        pair_tmp.first = after_cloud[i].first;
        pair_tmp.second = after_cloud[i].second;
        cloud_map[pair_tmp] = true;
    }

    for (int i = 0; i < basket.size(); i++) {
        for (int j = 0; j < basket[i].size(); j++) {
            if (basket[i][j] >= 2) {
                pair_tmp.first = j;
                pair_tmp.second = i;
                if (cloud_map[pair_tmp] != true) {
                    result.push_back(pair_tmp);
                    basket[i][j] -= 2;
                }
            }
        }
    }    
    after_cloud.clear();
    return result;
}

int sum_water(vector<vector<int> > &basket) {
    int result = 0;

    for (int i = 0; i < basket.size(); i++) {
        for (int j = 0; j < basket[i].size(); j++)
            result += basket[i][j];
    }
    return result;
}

int main(void) {
    int N, M, direction, distance, sum;
    cin >> N >> M;
    
    pair<int, int> pair_tmp;
    vector<int> basket_tmp(N, 0);
    vector<vector<int> > basket(N, basket_tmp);
    vector<pair<int, int> > before_cloud;
    vector<pair<int, int> > after_cloud;

    init_cloud(before_cloud, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> basket[i][j];
    }
    
    for (int i = 0; i < M; i++) {
        cin >> direction >> distance;
        // 1. 구름 이동
        // cout << "===== 1. 구름 이동 =====" << '\n';
        after_cloud = move_cloud(before_cloud, direction, distance, N);
        // cout << "== after_cloud ==" << '\n';
        // for (int a = 0; a < after_cloud.size(); a++)
        //     cout << after_cloud[a].first << " " << after_cloud[a].second << '\n';

        // 2. raining
        // cout << "===== 2. raining =====" << '\n';
        raining(basket, after_cloud);

        // 3. 비 내린 칸 물의 양 증가
        // cout << "===== 3. 비 내린 칸 물의 양 증가 =====" << '\n';
        increase_water(basket, after_cloud);
        // cout << "== basket ==" << '\n';
        // for (int a = 0; a < N; a++) {
        //     for (int b = 0; b < N; b++)
        //         cout << basket[a][b] << " ";
        //     cout << '\n';
        // }

        // 4. 구름 생성 (구름이 사라진 칸x)
        // cout << "===== 4. 구름 생성 =====" << '\n';
        before_cloud = create_cloud(basket, after_cloud);
    }
    sum = sum_water(basket);
    cout << sum << '\n';
}