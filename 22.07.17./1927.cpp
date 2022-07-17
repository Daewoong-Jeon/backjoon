#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct cmp
{
    bool operator()(unsigned int a, unsigned int b)
    {
        return (a > b);
    }
};

int main() {
    priority_queue<unsigned int, vector<unsigned int>, cmp> p_q;
    int n, x;
    // cin스트림, cout스트림 분리
    // c의 stdio와 c++의 iostream 동기화 해제
    // 멀티 쓰레드 환경에서는 사용 자제
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (p_q.empty() == 1)
                cout << "0" << '\n'; // endl의 버퍼 비워주는 과정 생략
            else {
                cout << p_q.top() << '\n';
                p_q.pop();
            }
        }
        else
            p_q.push(x);
    }
}