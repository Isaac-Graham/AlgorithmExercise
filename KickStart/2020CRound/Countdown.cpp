//
// Created by Isc on 2020/5/17.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int testCase;

    cin >> testCase;
    for (int loop = 1; loop <= testCase; ++loop) {
        int n, k;
        cin >> n >> k;
        int currentNeed = k;
        int cnt = 0;
//        vector<int> inputValue;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
//            inputValue.push_back(input);
            if (input == currentNeed) {
                currentNeed--;
                if (currentNeed == 0) {
                    cnt++;
                    currentNeed = k;
                }
            } else {
                currentNeed = k;
                if (input == currentNeed) {
                    currentNeed--;
                    if (currentNeed == 0) {
                        cnt++;
                        currentNeed = k;
                    }
                }
            }
        }

        cout << "Case #" << loop << ": " << cnt << endl;


    }
}