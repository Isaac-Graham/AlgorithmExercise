//
// Created by Isc on 2020/8/22.
//

#include <bits/stdc++.h>

using namespace std;

void remove(char *str, char c) {
    char *p = str;
    while (*str) {
        if (*str != c) {
            *p++ = *str;
        }
        str++;
    }
    *p = '\0';
}


int main() {
    char s[100] = "aaaaaaaaaaaaaa";
    remove(s, 'a');
    cout << s << endl;
}