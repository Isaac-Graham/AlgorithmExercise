//
// Created by Isc on 2020/9/7.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string str = "A1B21C";
    string strips = "121";
    cin >> str >> strips;
    string newStr(2 * str.size() - strips.size(), '\0');
    for (int i = 0, j = str.size() - 1, k = 0, l = 0; i <= j;) {
        if (str[i] != strips[k]) {
            newStr[l] = str[i];
            newStr[newStr.size() - l - 1] = str[i++];
        } else {
            newStr[l] = str[j];
            newStr[newStr.size() - l - 1] = str[j];
            if (str[j] == strips[k]) {
                i++;
                k++;
            }
            j--;
        }
        l++;
    }
    cout << newStr << endl;
}