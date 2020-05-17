//
// Created by Isaac_Chen on 2020/4/12.
//

#include <bits/stdc++.h>

using namespace std;

class Item {
public:
    int left;
    int right;
    int value;
    int index;

    Item(int value, int index, int left, int right) {
        this->value = value;
        this->index = index;
        this->left = left;
        this->right = right;
    }
};

int main() {
    int testcase;
    cin >> testcase;
    for (int loop = 0; loop < testcase; loop++) {
        int houseNumber = 0;
        cin >> houseNumber;
        vector<Item *> house;
        for (int i = 0; i < houseNumber; i++) {
            int input;
            cin >> input;
            house.push_back(new Item(input, i, 0, houseNumber - 1));
        }
        stack<Item *> s;
        for (int i = 0; i < house.size(); i++) {
            if (s.empty()) {
                s.push(house[i]);
                continue;
            }
            while (!s.empty() && s.top()->value < house[i]->value) {
                Item *item = s.top();
                item->right = i - 1;
                s.pop();
            }
            if (!s.empty()) {
                if (s.top()->value > house[i]->value)
                    house[i]->left = s.top()->index + 1;
                else {
                    house[i]->left = s.top()->left;
                }
            }
            s.push(house[i]);
        }

        for (int i = 0; i < house.size(); i++) {
            cout << house[i]->right - house[i]->left << " ";
        }
        cout << "\n";
    }
}