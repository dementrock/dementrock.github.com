#include<iostream>
#include<stdio.h>
#include<string.h>
#define INF 0x7fffffff
using namespace std;

int f[100][100], c[100], l, n;

int input(){
    memset(f, 0xff, sizeof(f));
    memset(c, 0, sizeof(c));
    scanf("%d", &l);
    if (!l) {
        return 0;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    c[0] = 0, c[n + 1] = l;
    return 1;
}

int dp(int left, int right) {
    if (f[left][right] != -1) {
        return f[left][right];
    }
    f[left][right] = INF;
    if (left + 1 > right - 1) {
        return f[left][right] = 0;
    }
    for (int i = left + 1; i <= right - 1; ++i) {
        f[left][right] = min(f[left][right], dp(left, i) + dp(i, right) + c[right] - c[left]);
    }
    return f[left][right];
}

int calc() {
    return dp(0, n + 1);
}

int main() {
    while(input()){
        printf("The minimum cutting is %d.\n", calc());
    }
    return 0;
}
