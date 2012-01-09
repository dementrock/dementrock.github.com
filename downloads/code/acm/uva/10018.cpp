#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

long long pal;

int calc(long long x) {
    long long rev = 0, now = x;
    while (now) {
        rev = rev * 10 + now % 10;
        now /= 10;
    }
    if (rev == x) {
        pal = x;
        return 0;
    } else {
        return 1 + calc(x + rev);
    }
}

int main() {
    int n;
    long long x;
    cin >> n;
    while(n--) {
        cin >> x;
        cout << calc(x);
        cout << " " << pal << endl;
    }
    return 0;
}
