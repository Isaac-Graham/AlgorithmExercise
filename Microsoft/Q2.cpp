//
// Created by Isaac_Chen on 2020/3/25.
//
#include<bits/stdc++.h>

using namespace std;

int points(int input1, int input2[]) {
// Write code and remove the below exception.

    vector<vector<int>> scores(input1, vector<int>(input1));
    for (int i = 0; i < input1; i++) { scores[i][i] = 1; }
    for (int i = 1; i < input1; i++) {
        for (int j = 0; j < input1 - i; j++) {
            int min_score = INT_MAX;
            if (input2[j] == input2[j + i]) { min_score = i > 1 ? scores[j + 1][j + i - 1] : 1; }
            for (int k = 0; k < i; k++) {
                int temp = scores[j][j + k] + scores[j + k + 1][j + i];
                if (temp < min_score) { min_score = temp; }
            }
            scores[j][j + i] = min_score;
        }
    }
    return scores[0][scores.size() - 1];
}

int main() {
}