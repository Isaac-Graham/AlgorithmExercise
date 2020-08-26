//
// Created by Isc on 2020/8/23.
//

#include<bits/stdc++.h>

using namespace std;

int weishu(long long number) {
    int res = 0;
    while (number != 0) {
        number /= 10;
        res++;
    }
    return res;
}

long long getRes(int weishu) {
    long long res = 0;
    while (weishu > 1) {
        res *= 10;
        res += 9;
        weishu--;
    }
    return res;
}

int getBitSum(long long number) {
    int res = 0;
    while (number != 0) {
        res += number % 10;
        number /= 10;
    }
    return res;
}

int main() {
    int testcase = 0;
    scanf("%d", &testcase);
    for (int loop = 0; loop < testcase; loop++) {
        long long number = 0L;
        scanf("%lld", &number);
        int length = weishu(number);
        long long res1 = getRes(length);
        cout << getBitSum(res1) + getBitSum(number - res1) << endl;
    }
}