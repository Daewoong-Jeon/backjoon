#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
    int n, k;
    int seconds = 0;
    cin >> n >> k;

    queue<vector<int> > q;
    vector<int> vec_tmp(3, 0);      // vector temp 변수
    vector<int> front;              // 수빈의 현재 위치
    vector<int> chk(200000, 0);     // 방문 좌표

    // queue 초기화
    chk[n] = 1;
    vec_tmp[0] = n;
    vec_tmp[1] = seconds;
    q.push(vec_tmp);

    // main logic
    while (!q.empty()) {
        front = q.front();
        q.pop();
        cout << front[0] << endl;

        // 동생 찾기 성공
        if (front[0] == k) {
            seconds = front[1];
            break ;
        }

        // 1초 증가
        vec_tmp[1] = front[1] + 1;

        // 순간이동 후에도 동생 위치보다 적을 경우, if문으로 분기
        // 순간이동 후에 동생 위치보다 많을 경우, else문으로 분기
        if (chk[front[0] * 2] == 0 && 2 * front[0] <= k) {
            vec_tmp[2] = 0;                     // 1 감소한 위치가 아님
            vec_tmp[0] = front[0] * 2;          // 2배 순간이동
            chk[vec_tmp[0]] = 1;                // 방문 표시
            q.push(vec_tmp);
        }
        else {
            // 1 감소
            if (chk[front[0] - 1] == 0) {
                vec_tmp[2] = 1;
                vec_tmp[0] = front[0] - 1;
                chk[vec_tmp[0]] = 1;
                q.push(vec_tmp);
            }
            // 1 증가 or 2배 순간이동
            if (front[0] < k) {
                if (chk[front[0] + 1] == 0 && front[2] != 1
                    && abs(front[0] * 2 - k) >= abs(k - front[0])) {
                    vec_tmp[2] = 0;
                    vec_tmp[0] = front[0] + 1;
                    chk[vec_tmp[0]] = 1;
                    q.push(vec_tmp);
                }
                else if (chk[front[0] * 2] == 0) {
                    vec_tmp[2] = 0;
                    vec_tmp[0] = front[0] * 2;
                    chk[vec_tmp[0]] = 1;
                    q.push(vec_tmp);
                }
            }
        }
    }
    cout << seconds << endl;
}