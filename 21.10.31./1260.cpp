#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return (a[1] < b[1]);
    return (a[0] < b[0]);
}

void DFS(vector<vector<int> > &graph, vector<int> &visit, queue<int> &output, int point) {
    if (visit[point] == 1)
        return ;
    visit[point] = 1;
    output.push(point);
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i][0] == point)
            DFS(graph, visit, output, graph[i][1]);
        else if (graph[i][1] == point)
            DFS(graph, visit, output, graph[i][0]);
    }
}

void BFS(vector<vector<int> > &graph, vector<int> &visit, queue<int> &output, int start) {
    queue<int> queue;
    int point;

    queue.push(start);
    while (queue.empty() != 1) {
        point = queue.front();
        queue.pop();
        if (visit[point] == 0) {
            visit[point] = 1;
            output.push(point);
            for (int i = 0; i < graph.size(); i++) {
                if (point == graph[i][0])
                    queue.push(graph[i][1]);
                else if (point == graph[i][1])
                    queue.push(graph[i][0]);
            }
        }
    }
}

int main() {
    vector<vector<int> > graph;
    vector<int> visit;
    vector<int> vec_tmp;
    vector<int> stack;
    queue<int> output;
    string input1;
    string input2;
    int int_input1;
    int int_input2;
    int N;
    int M;
    int start;
    cin >> N;
    cin >> M;
    cin >> start;

    for (int i = 0; i <= N; i++)
        visit.push_back(0);
    for (int i = 0; i < M; i++) {
        cin >> input1;
        cin >> input2;
        int_input1 = stoi(input1);
        int_input2 = stoi(input2);
        if (int_input1 < int_input2) {
            vec_tmp.push_back(int_input1);
            vec_tmp.push_back(int_input2);
        }
        else {
            vec_tmp.push_back(int_input2);
            vec_tmp.push_back(int_input1);
        }
        graph.push_back(vec_tmp);
        vec_tmp.clear();
    }
    sort(graph.begin(), graph.end(), cmp);

    DFS(graph, visit, output, start);
    while (output.size() > 1) {
        cout << output.front() << " ";
        output.pop();
    }
    cout << output.front() << endl;
    output.pop();
    for (int i = 1; i < visit.size(); i++)
        visit[i] = 0;

    BFS(graph, visit, output, start);
    while (output.size() > 1) {
        cout << output.front() << " ";
        output.pop();
    }
    cout << output.front() << endl;
}