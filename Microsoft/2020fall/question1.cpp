//
// Created by Isaac_Chen on 2020/9/21.
//

#include <bits/stdc++.h>
using namespace  std;

int missingMarble(int input1, int input2[]) {
    int sum = 0;
    for (int i =0; i < input1; i++) {
        sum += input2[i];
    }
    return (input2[0] + input2[input1 - 1]) * (input1 / 2) - sum;
}

int main() {
    int input2[] = {1, 3, 5, 9, 11};
    cout << missingMarble(5, input2) << endl;
}