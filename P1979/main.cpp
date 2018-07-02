#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct Point {
    int x;
    int y;
};

char a[20][20];
bool visited[20][20];
int w, h, startX, startY;

void input(ifstream &cin) {
    char ch;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '@') {
                startX = i;
                startY = j;
            }
            visited[i][j] = true;
        }
}

void solve(ofstream &cout) {

    Point start = {};
    queue<Point> q;

    int answer = 0;
    start.x = startX;
    start.y = startY;
    q.push(start);

    visited[startX][startY] = false;

    while (!q.empty()) {
        Point now = q.front();
        q.pop();
        Point to = {};
        answer++;
        for (int i = 0; i < 4; i++) {
            to.x = now.x + dx[i];
            to.y = now.y + dy[i];
            if (to.x >= 0 && to.x < h && to.y >= 0 && to.y < w && a[to.x][to.y] == '.'
                && visited[to.x][to.y]) {
                visited[to.x][to.y] = false;
                q.push(to);
            }
        }
    }

    cout << answer << endl;
}

int main() {

    ifstream cin("a.in");
    ofstream cout("a.out");

    cin >> w >> h;
    while (w != 0) {
        input(cin);
        solve(cout);
        cin >> w >> h;
    }

    return 0;
}