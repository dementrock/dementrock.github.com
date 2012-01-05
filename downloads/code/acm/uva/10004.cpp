#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200

using namespace std;

int map[MAXN+1][MAXN+1], color[MAXN+1], vis[MAXN+1], n;

void set_color (int cur, int c) {
    color[cur] = c;
    vis[cur] = 1;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] && map[cur][i]) {
            set_color(i, 1 - c);
        }
    }
}

int is_bicolor(void) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] && color[i] == color[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    while (scanf("%d", &n)) {
        if(!n) {
            break;
        }
        int l, a, b;
        scanf("%d", &l);
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < l; ++i) {
            scanf("%d%d", &a, &b);
            map[a][b] = map[b][a] = 1;
        }
        set_color(0, 0);
        printf(is_bicolor() ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }
    return 0;
}
