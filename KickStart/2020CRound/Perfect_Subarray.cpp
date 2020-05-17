//
// Created by Isc on 2020/5/17.
//

#include <bits/stdc++.h>

using namespace std;


int mleAlgorithm(const set<int> &possibleSquare) {
    int inputLength = 0;
    cin >> inputLength;
    vector<int> inputValue(inputLength);
    for (int i = 0; i < inputLength; ++i) {
        int input;
        cin >> input;
        inputValue[i] = input;
    }

    vector<vector<int>> dp;
    for (int i = 0; i < inputLength + 1; i++) {
        vector<int> vec(inputLength + 1, 0);
        dp.push_back(vec);
    }


    int cnt = 0;
    for (int index = 0; index < inputLength; index++) {
        dp[index][index] = inputValue[index];
        if (possibleSquare.find(dp[index][index]) != possibleSquare.end()) {
            cnt++;
            cout << index << " " << index << endl;
        }
    }

    for (int i = 0; i < inputLength; i++) {
        for (int j = i + 1; j < inputLength; j++) {
            dp[i][j] = dp[i][j - 1] + inputValue[j];
            if (possibleSquare.find(dp[i][j]) != possibleSquare.end()) {
                cnt++;
                cout << i << " " << j << endl;
            }
        }
    }
    return cnt;
}

int tleAlgorithm(const set<int> &possibleSquare) {
    int inputLength = 0;
    cin >> inputLength;
    vector<int> inputValue(inputLength);
    vector<int> reserveValue(inputLength);
    int res = 0;
    for (int i = 0; i < inputLength; ++i) {
        int input;
        cin >> input;
        if (i == 0)
            inputValue[i] = input;
        else
            inputValue[i] = inputValue[i - 1] + input;
        reserveValue[i] = inputValue[i];
    }
    make_heap(std::begin(inputValue), std::end(inputValue), std::greater<>());
    int totalMinus = 0;
    auto removedIter = inputValue.begin();
    for (int i = 0; i < reserveValue.size(); i++) {
        for (auto iter = inputValue.begin(); iter != inputValue.end(); iter++) {
            if (*iter == reserveValue[i]) {
                removedIter = iter;
            }
            if (possibleSquare.find(*iter - totalMinus) != possibleSquare.end()) {
                res++;
            }
        }
        totalMinus = reserveValue[i];
        inputValue.erase(removedIter);
    }
    return res;
}

int main() {
    set<int> possibleSquare;

    for (int i = 0;; i++) {
        int mul = i * i;
        if (mul > 10000000) {
            break;
        }
        possibleSquare.insert(mul);
    }


    int testCase;
    cin >> testCase;
    for (int loop = 1; loop <= testCase; ++loop) {

    }
}