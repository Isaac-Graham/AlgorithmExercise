//
// Created by Isc on 2020/8/24.
//

#include <bits/stdc++.h>

using namespace std;


double calculate(double y) {
    return pow(y, 7) + 0.5 * y;
}


double binarySearch(int x, double begin, double end) {
    if (begin > end) {
        return -1;
    }
    while (begin <= end) {
        double mid = (begin + end) / 2;
        int cal = calculate(mid);
        if (cal < 0) {
            end = mid;
            continue;
        }
        if (abs(x - cal) < 0.001) {
            return mid;
        } else if (cal > x) {
            end = mid;
        } else {
            begin = mid;
        }
    }
    return -1;
}

int main() {
    cout << fixed << setprecision(2) << binarySearch(129, 0, 129) << endl;
}