//
// Created by Isc on 2020/8/21.
//

#include <bits/stdc++.h>

using namespace std;

void find(vector<string> strlist, string &strmin, string &strmax) {
    if (strlist.empty()) {
        strmin = nullptr;
        strmax = nullptr;
        return;
    }
    strmin = strlist[0];
    strmax = strlist[0];
    for (int i = 0; i < strlist.size(); i++) {
        strmin = (strmin < strlist[i]) ? strmin : strlist[i];
        strmax = (strmax > strlist[i]) ? strmax : strlist[i];
    }
}
