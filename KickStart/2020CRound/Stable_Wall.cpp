//
// Created by Isc on 2020/5/17.
//


#include <bits/stdc++.h>

using namespace std;

struct Item {
    char name;
    set<Item *> outItems;
    int inDegree;

    Item(char name) {
        this->name = name;
        inDegree = 0;
    }

    void add(Item *item) {
        if (outItems.find(item) == outItems.end()) {
            outItems.insert(item);
            item->inDegree++;
        }
    }

};


inline int getIndex(char c) {
    return (int) c - (int) 'A';
}

Item *findNoInDegree(const vector<Item *> &items) {
    for (Item *item:items) {
        if (item == nullptr) {
            continue;
        } else if (item->inDegree == 0) {
            return item;
        }
    }
    return nullptr;
}

bool checkEmpty(const vector<Item *> &items) {
    for (Item *item:items) {
        if (item != nullptr) {
            return false;
        }
    }
    return true;
}

int main() {
    int testCase;
    cin >> testCase;
    for (int loop = 1; loop <= testCase; ++loop) {
        int row, col;
        cin >> row >> col;
        vector<Item *> items(26, nullptr);
        vector<vector<char>> inputGraph;
        for (int i = 0; i < row; ++i) {
            string newRow;
            cin >> newRow;
            vector<char> vec;
            vec.reserve(newRow.length());
            for (int j = 0; j < newRow.length(); ++j) {
                vec.push_back(newRow[j]);
                if (items[getIndex(newRow[j])] == nullptr) {
                    items[getIndex(newRow[j])] = new Item(newRow[j]);
                }
            }
            inputGraph.push_back(vec);
        }


        for (int i = 0; i < inputGraph.size() - 1; i++) {
            for (int j = 0; j < inputGraph[i].size(); j++) {
                char c = inputGraph[i][j];
                int index = getIndex(c);
                char nextChar = inputGraph[i + 1][j];
                int nextIndex = getIndex(nextChar);
                if (index != nextIndex) {
                    items[nextIndex]->add(items[index]);
                }
            }
        }
        string res;
        while (true) {
            Item *item = findNoInDegree(items);
            if (item == nullptr) {
                break;
            }
            set<Item *> next = item->outItems;
            for (auto top = next.begin(); top != next.end(); top++) {
                (*top)->inDegree--;
            }
            res = res + item->name;
            int index = getIndex(item->name);
            items[index] = nullptr;
        }
        if (!checkEmpty(items)) {
            res = "-1";
        }

        cout << "Case #" << loop << ": " << res << endl;
    }
}