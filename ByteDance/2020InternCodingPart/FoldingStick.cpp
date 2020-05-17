//
// Created by Isaac_Chen on 2020/4/12.
//

#include <bits/stdc++.h>

using namespace std;

class Item {
public:
    int value;
    int internal;

    Item(int value) {
        this->value = value;
        this->internal = 1;
    }

    int getBottomLimit() {
        return value / internal;
    }

    int getUpperLimit() {
        if (value % internal == 0) {
            return value / internal;
        } else {
            return value / internal + 1;
        }
    }
};

int main() {
    int stickNumber = 0;
    cin >> stickNumber;
    vector<Item *> sticks;
    for (int i = 0; i < stickNumber; i++) {
        int input = 0;
        cin >> input;
        sticks.push_back(new Item(input));
    }

    for (int i = sticks.size() - 2; i >= 0; i--) {
        if (sticks[i]->getUpperLimit() <= sticks[i + 1]->getBottomLimit()) {
            continue;
        }
        int right_limit = sticks[i + 1]->getBottomLimit();
        if (sticks[i]->value % right_limit == 0) {
            sticks[i]->internal = sticks[i]->value / right_limit;
        } else {
            sticks[i]->internal = sticks[i]->value / right_limit + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < sticks.size(); i++) {
        sum += (sticks[i]->internal - 1);
    }
    cout << sum << "\n";
}

