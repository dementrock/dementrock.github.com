#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 3000

using namespace std;

int main() {
    int n, prev, now, dif, is_jolly;
    int appeared[MAXN+1];
    while(scanf("%d", &n) != EOF) {
        if (n <= 0) {
            printf("Not jolly\n");
            continue;
        }
        memset(appeared, 0, sizeof(appeared));
        is_jolly = 1;
        scanf("%d", &prev);
        for (int i = 1; i < n; ++i) {
            scanf("%d", &now);
            if (!is_jolly) {
                continue;
            }
            dif = abs(now - prev);
            if (dif < 1 || dif >= n || appeared[dif]) {
                is_jolly = 0;
            } 
            appeared[dif] = 1;
            prev = now;
        }
        printf(is_jolly ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}

