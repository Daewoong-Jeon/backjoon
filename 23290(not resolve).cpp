#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// flow
// 1. 상어가 복제 시전 : fish_location -> fish_location_bk
// 2. 물고기 이동 : fish_location.clear() 후 fish_location_bk 기반 이동 후 재입력
// 3. 상어가 연속 세칸을 이동하면서 물고기를 만나면 제외시킴 : dfs로 조건에 맞는 경우 찾기
//  a. 제외시킬 물고기가 많은 경로로 이동
//  b. 경우가 여러개일 경우, 사전순으로 앞서는 방법으로 이동
// 4. 두 번전 남겨진 냄새가 사라짐 : smell 값 1감소
// 5. 제외된 물고기는 해당 격자에 냄새를 남김 : smell에 숫자 2로 표시
// 6. 1에서의 물고기 위치와 정보를 유지한 채 복제 생성완료 : fish_location_bk 값 그대로 fish_location에 재입력
// answer : 연습이 끝난 후, 격자에 남아있는 물고기의 수 리턴

void input_test(map<pair<int, int>, vector<vector<int> > > fish_location) {
    for (map<pair<int, int>, vector<vector<int> > >::iterator it = fish_location.begin(); it != fish_location.end(); ++it) {
        cout << "key : " << it->first.first << " " << it->first.second << '\n';
        for (int i = 0; i < it->second.size(); i++) {
            cout << i << "value : " << it->second[i][0] << " " << it->second[i][1] << " " << it->second[i][2] << '\n';
        }
    }
}

vector<int> move(int x, int y, int dir) {
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    vector<int> result(3, 0);

    result[0] = x + dx[dir - 1];
    result[1] = y + dy[dir - 1];
    result[2] = dir;
    return result;
}

// 1. smell에 값이 잘 안들어가있음
// 2. 1 2 6 => 1 1 3, 3 1 1 => 3 2 7
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int move_validation(int x, int y, int dir, vector<vector<int> > &smell, pair<int, int> &shark) {
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int index;
    int after_x;
    int after_y;

    for (int i = 8; i >= 1; i--) {
        index = (dir + i - 1) % 8;
        after_x = x + dx[index];
        after_y = y + dy[index];
        if (smell.size() >= after_y && after_y >= 1 && smell[0].size() >= after_x && after_x >= 1) {
            if (smell[after_y - 1][after_x - 1] == 0) {
                if (shark.first != after_x || shark.second != after_y) {
                    return index + 1;
                }
            }
        }
    }
    return 0;
}

void move_fish(map<pair<int, int>, vector<vector<int> > > &fish_location,
    map<pair<int, int>, vector<vector<int> > > &fish_location_bk,
    vector<vector<int> > &smell,
    pair<int, int> &shark) {
    pair<int, int> key;
    vector<int> after;
    int after_dir;

    // cout << "==move fish==" << '\n';
    for (map<pair<int, int>, vector<vector<int> > >::iterator it = fish_location_bk.begin(); it != fish_location_bk.end(); ++it) {
        // cout << "key : " << it->first.first << " " << it->first.second << '\n';
        for (int i = 0; i < it->second.size(); i++) {
            // cout << i << "value : " << it->second[i][0] << " " << it->second[i][1] << " " << it->second[i][2] << '\n';
            after_dir = move_validation(it->second[i][0], it->second[i][1], it->second[i][2], smell, shark);
            // cout << "after_dir : " << after_dir << '\n';
            if (after_dir > 0) {
                after = move(it->second[i][0], it->second[i][1], after_dir);
                key.first = after[0];
                key.second = after[1];
                fish_location[key].push_back(after);
            }
        }
    }
}

string vector_to_string(vector<int> input) {
    string result = "";
    for (int i = 0; i < input.size(); i++)
        result += (input[i] + '0');
    return result;
}

// ↑, ←, ↓, →
void shark_dfs(map<pair<int, int>, vector<vector<int> > > &fish_location,
    vector<int> &shark_dir, vector<vector<bool> > visit, int &max,
    int x, int y, vector<int> cur_dir, int cur, int depth) {
    string max_str;
    string cur_str;
    if (depth == 3) {
        cout << "cur : " << cur << '\n';
        if (cur > max) {
            // cout << "max : " << max << "cur : " << cur << '\n';
            max = cur;
            shark_dir = cur_dir;
        }
        else if (cur == max) {
            // cout << "max : " << max << "cur : " << cur << '\n';
            max_str = vector_to_string(shark_dir);
            cur_str = vector_to_string(cur_dir);
            if (cur_str < max_str) {
                max = cur;
                shark_dir = cur_dir;
            }
        }
        // cout << max << '\n';
        return;
    }
    pair<int, int> key;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int after_x;
    int after_y;
    int after_fish;
    
    for (int i = 1; i <= 4; i++) {
        after_x = x + dx[i - 1];
        after_y = y + dy[i - 1];
        if ((after_x >= 1 && after_x <= 4) && (after_y >= 1 && after_y <= 4)
            && visit[after_y - 1][after_x - 1] == false) {
            visit[after_y - 1][after_x - 1] = true;
            key.first = after_x;
            key.second = after_y;
            after_fish = cur + fish_location[key].size();
            cur_dir.push_back(i);
            // cout << key.first << " " << key.second << " : " << after_fish << '\n';
            shark_dfs(fish_location, shark_dir, visit, max, after_x, after_y, cur_dir, after_fish, depth + 1);
            cur_dir.pop_back();
        }
    }
}

void erase_smell(vector<vector<int> > &smell) {
    for (int i = 0; i < smell.size(); i++) {
        for (int j = 0; j < smell[i].size(); j++) {
            if (smell[i][j] > 0)
                smell[i][j]--;
        }
    }
}

void move_shark(map<pair<int, int>, vector<vector<int> > > &fish_location,
    vector<vector<int> > &smell, vector<int> &shark_dir, pair<int, int> &shark) {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    for (int i = 0; i < shark_dir.size(); i++) {
        shark.first += dx[shark_dir[i] - 1];
        shark.second += dy[shark_dir[i] - 1];
        // cout << shark.first << " " << shark.second << '\n';
        if (fish_location[shark].size() > 0)
            smell[shark.second - 1][shark.first - 1] = 2;
        fish_location[shark].clear();
    }
}

void create_copies(map<pair<int, int>, vector<vector<int> > > &fish_location,
    map<pair<int, int>, vector<vector<int> > > &fish_location_bk) {
    for (map<pair<int, int>, vector<vector<int> > >::iterator it = fish_location_bk.begin(); it != fish_location_bk.end(); ++it) {
        for (int i = 0; i < it->second.size(); i++)
            fish_location[it->first].push_back(it->second[i]);
    }
}

void init_visit_arr(vector<vector<bool> > &visit) {
    for (int i = 0; i < visit.size(); i++) {
        for (int j = 0; j < visit[i].size(); j++)
            visit[i][j] = false;
    }
}

int main(void) {
    vector<int> vec_tmp;
    vector<int> shark_dir(3, 0);
    vector<int> smell_tmp(4, 0);
    vector<int> input_tmp(3, 0);
    vector<bool> visit_tmp(4, false);
    vector<vector<int> > smell(4, smell_tmp);
    vector<vector<bool> > visit(4, visit_tmp);
    pair<int, int> pair_tmp;
    pair<int, int> shark;
    map<pair<int, int>, vector<vector<int> > > fish_location;
    map<pair<int, int>, vector<vector<int> > > fish_location_bk;
    int M, S;
    int max = 0;
    int result = 0;
    cin >> M >> S;
    
    // fish_location 초기화
    for (int i = 1; i <= 4; i++) {
        pair_tmp.first = i;
        for (int j = 1; j <= 4; j++) {
            pair_tmp.second = j;
            fish_location[pair_tmp];
        }
    }

    // 초기 물고기 정보 파싱
    for (int i = 0; i < M; i++) {
        cin >> input_tmp[1] >> input_tmp[0] >> input_tmp[2];
        pair_tmp.first = input_tmp[0];
        pair_tmp.second = input_tmp[1];
        fish_location[pair_tmp].push_back(input_tmp);
    }
    
    // 상어 위치 파싱
    cin >> shark.second >> shark.first;
    fish_location[shark].clear();

    // input test
    // input_test(fish_location);

    for (int i = 0; i < S; i++) {
        cout << "========" << i + 1 << "번째 연습========" << '\n';
        // 1. backup location
        cout << "=====backup location=====" << '\n';
        fish_location_bk = fish_location;

        // 2. 물고기 이동
        cout << "=====물고기 이동=====" << '\n';
        fish_location.clear();
        move_fish(fish_location, fish_location_bk, smell, shark);
        cout << "==middle==" << '\n';
        input_test(fish_location);

        // 3. 상어 이동 경우의 수 찾기
        cout << "=====상어 이동 경우의 수 찾기=====" << '\n';
        init_visit_arr(visit);
        shark_dfs(fish_location, shark_dir, visit, max, shark.first, shark.second, vec_tmp, 0, 0);
        cout << "==check shark's direction==" << '\n';
        cout << shark_dir[0] << " " << shark_dir[1] << " " << shark_dir[2] << '\n';

        // 4. 두 번전 냄새 제거
        cout << "=====두 번전 냄새 제거=====" << '\n';
        erase_smell(smell);

        // 5. move shark and eat fish
        cout << "=====move shark and eat fish=====" << '\n';
        move_shark(fish_location, smell, shark_dir, shark);
        cout << "shark location : " << shark.first << " " << shark.second << '\n';
        cout << "==check smell==" << '\n';
        for (int a = 0; a < smell.size(); a++) {
            for (int b = 0; b < smell[a].size(); b++)
                cout << smell[a][b] << " ";
            cout << '\n';
        }

        // 6. 복제 생성
        cout << "=====복제 생성=====" << '\n';
        create_copies(fish_location, fish_location_bk);
        fish_location_bk.clear();
        // cout << "==result==" << '\n';
        // input_test(fish_location);
    }
    // cout << "==result==" << '\n';
    // input_test(fish_location);
    for (map<pair<int, int>, vector<vector<int> > >::iterator it = fish_location.begin(); it != fish_location.end(); ++it)
        result += it->second.size();
    cout << result << '\n';
}