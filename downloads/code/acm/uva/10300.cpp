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
    int n, f, sum, s, a, b;
    cin >> n;
    while (n--) {
        cin >> f;
        sum = 0;
        while (f--) {
            cin >> s >> a >> b;
            sum += s * b;
        }
        cout << sum << endl;
    }
    return 0;
}

