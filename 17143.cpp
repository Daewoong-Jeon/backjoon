#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 정의가 필요한 사항
// 1. 낚시왕의 행동
// 2. 상어의 행동
//  a. 범위를 넘는 경우, 방향 전환(반대 전환)
//  b. 상어의 이동 속도 (칸/초)
//  c. 상어가 겹칠 경우, 크기가 큰 상어 한마리가 나머지 상어들을 모두 먹음

// 각 상어를 숫자로 구분 map<int, vector<int>>, value값엔 상어의 특징 (속력, 이동방향, 크기)
int main(void) {
    int R, C, M;
    cin >> R >> C >> M;

    
}