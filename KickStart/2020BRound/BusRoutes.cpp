//
// Created by Isaac_Chen on 2020/4/22.
//

// TLE
#include <bits/stdc++.h>

#define ll long long
using namespace std;

inline ll getResult(ll dayUpperLimit, int busNumber, vector<ll> &vec) {
    ll newUpperLimit = (dayUpperLimit / vec[busNumber - 1]) * vec[busNumber - 1];
    if (busNumber == 1) {
        return newUpperLimit;
    } else {
        return getResult(newUpperLimit, busNumber - 1, vec);
    }
}

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 1; loop <= testcase; loop++) {
        int busNumber = 0;
        ll daysLimit = 0;
        cin >> busNumber >> daysLimit;
        vector<long long> busDays;
        for (int i = 0; i < busNumber; i++) {
            ll input = 0;
            cin >> input;
            busDays.push_back(input);
        }
        ll res = getResult(daysLimit, busNumber, busDays);

        cout << "Case #" << loop << ": " << res << "\n";
    }
}