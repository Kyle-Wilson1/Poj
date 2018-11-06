#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define MAX_NODE 201

int map[MAX_NODE][MAX_NODE], pre[MAX_NODE];
int n, m, answer = 0;

int bfs(int m) {

    int queue[MAX_NODE] = {0};
    bool visited[MAX_NODE] = {false};
    int flow[MAX_NODE];//flow[i]表示路径中到点i的最小可流通量
    memset(flow, 0xff, sizeof(flow));

    int head = 0, tail = 1, current;
    queue[head] = 1;
    visited[1] = true;
    flow[1] = 0x7fffffff;

    while (head < tail) {

        // 取队首
        current = queue[head++];
        // 如果已经到达汇点，证明已经找到了路
        if (current == m) {
            return flow[m];
        }
        for (int i = 1; i <= m; ++i) {
            if (!visited[i] && map[current][i] > 0) {
                queue[tail++] = i;
                pre[i] = current;
                flow[i] = min(flow[current], map[current][i]);
                visited[i] = true;
            }
        }
    }
    return 0;
}

void ek(int m) {

    int max_flow = bfs(m);
    int from, to;

    while (max_flow > 0) {
        answer += max_flow;
        // 增广
        to = m;
        while (pre[to] != 0) {
            from = pre[to];
            map[from][to] -= max_flow;
            map[to][from] += max_flow;
            to = from;
        }
        max_flow = bfs(m);
    }
}

int main() {

    ifstream fin("a.in");
    ofstream fout("a.out");
    int from, to, flow;

    while (fin >> n >> m) {
        // 数组初始化
        memset(map, 0, sizeof(map));
        memset(pre, 0, sizeof(pre));
        answer = 0;

        for (int i = 0; i < n; ++i) {
            fin >> from >> to >> flow;
            map[from][to] += flow;
        }
        ek(m);
        fout << answer << endl;
    }
    return 0;
}