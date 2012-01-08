#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 26

using namespace std;

int map[MAXN+1][MAXN+1], prev[MAXN+1][MAXN+1];

void floyd(void) {
    memset(prev, 0xff, sizeof(prev));
    for (int k = 0; k < MAXN; ++k) {
        for (int i = 0; i < MAXN; ++i) if (i != k) {
            for (int j = 0; j < MAXN; ++j) if (j != k && j != i) {
                if (map[i][k] > 0 && map[k][j] > 0) {
                    if (map[i][j] == -1 || map[i][k] + map[k][j] < map[i][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                        prev[i][j] = k;
                    }
                }
            }
        }
    }
}

string shortest_path (int from, int to) {
    if (prev[from][to] == -1) {
        return string(1, from + 'A') + string(1, to + 'A');
    } else {
        return shortest_path(from, prev[from][to]) + (shortest_path(prev[from][to], to).substr(1));
    }
}


int main() {
    int times, m, n;
    cin >> times;
    while(times--) {
        cin >> m >> n;
        memset(map, 0xff, sizeof(map));
        while(m--) {
            string s1, s2;
            cin >> s1 >> s2;
            int c1 = s1[0] - 'A';
            int c2 = s2[0] - 'A';
            map[c1][c2] = map[c2][c1] = 1;
        }
        floyd();
        while(n--) {
            string s1, s2;
            cin >> s1 >> s2;
            int c1 = s1[0] - 'A';
            int c2 = s2[0] - 'A';
            cout << shortest_path(c1, c2) << endl;
        }
        if (times) {
            cout << endl;
        }
    }
    return 0;
}
