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
    long long a, b;
    while (cin >> a >> b) {
        cout << abs(b - a) << endl;
    }
    return 0;
}

