#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
    int h, m;
    while(scanf("%d:%d\n", &h, &m)) {
        if (!h && !m) {
            break;
        }
        double ans = h * 30.0 + m * 0.5 - m * 6.0;
        if (ans < 0) {
            ans = -ans;
        }
        if (ans > 180) {
            ans = 360.0 - ans;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}

