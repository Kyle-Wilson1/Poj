#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream cin("a.in");
    ofstream cout("a.out");

    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;

    int i;
    for (i = 0; i < 10000; ++i) {
        if ((x + i * m) % l == (y + i * n) % l) {
            cout << i << endl;
            break;
        }
    }

    if (i == 10000) {
        cout << "Impossible" << endl;
    }
    cin.close();
    cout.close();

    return 0;
}