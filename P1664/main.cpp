#include <iostream>
#include <fstream>

using namespace std;

int solve(int m, int n) {
    if (m < 0) return 0;
    if (m == 0 || n == 1) return 1;
    return solve(m - n, n) + solve(m, n - 1);
}

int main() {

    ifstream cin("a.in");
    ofstream cout("a.out");

    int t, n, m, f[11][11] = {0};
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cout << solve(m, n) << endl;
    }
    return 0;
}