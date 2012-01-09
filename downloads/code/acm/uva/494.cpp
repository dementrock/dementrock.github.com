#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int is_letter(char c) {
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z';
}

int main() {
    int is_in_word = 0, cnt_words = 0, cnt_char = 0;
    char c;
    while (scanf("%c", &c) != EOF) {
        if (is_letter(c)) {
            ++cnt_char;
            is_in_word = 1;
        } else {
            if (is_in_word) {
                is_in_word = 0;
                ++cnt_words;
                cnt_char = 0;
            } else {
                if (c == '\n') {
                    printf("%d\n", cnt_words);
                    is_in_word = cnt_words = cnt_char = 0;
                }
            }
        }
    } 
    return 0;
}

