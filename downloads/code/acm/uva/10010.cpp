#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 50

using namespace std;

int m, n;

char grid[MAXN+1][MAXN+1];

char tolower (char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    } else {
        return c;
    }
}

string tolower (string s) {
    string news = "";
    for (int i = 0; i < s.length(); ++i) {
        news += tolower(s[i]);
    }
    return news;
}

char get_char_at (int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return 0;
    } else {
        return grid[x][y];
    }
}

int is_found (string s, int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            string nows = "";
            for (int k = 0; k < s.length(); ++k) {
                nows += get_char_at(x + i * k, y + j * k);
            }
            if (s == nows) {
                return 1;
            }
        }
    }
    return 0;
}

void get_position (string s) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (is_found(tolower(s), i, j)) {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
}

int main() {
    int times, k;
    cin >> times;
    while (times--) {
        cin >> m >> n;
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                grid[i][j] = tolower(s[j]);
            }
        }
        cin >> k;
        for (int i = 0; i < k; ++i) {
            string s;
            cin >> s;        
            get_position(s);
        }
        if (times) {
            cout << endl;
        }
    }
    return 0;
}
