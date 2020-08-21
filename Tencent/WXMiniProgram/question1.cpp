//
// Created by Isc on 2020/8/21.
//

#include <bits/stdc++.h>

using namespace std;

struct LinkNode {
    int value;
    struct LinkNode *next;

    LinkNode() {};

    LinkNode(int x) : value(x), next(nullptr) {};
};

vector<vector<LinkNode *>> prepareNodes(vector<vector<int>> &vec) {
    vector<vector<LinkNode *>> nodes = {{},
                                        {}};
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].empty()) {
            nodes[i].push_back(nullptr);
        }
        for (int j = 0; j < vec[i].size(); j++) {
            nodes[i].push_back(new LinkNode(vec[i][j]));
        }
        for (int j = 0; j < nodes[i].size(); j++) {
            if (j != nodes[i].size() - 1) {
                nodes[i][j]->next = nodes[i][j + 1];
            }
        }
    }
    return nodes;
}

void printLink(LinkNode *head) {
    if (head == nullptr) {
        cout << "nullptr" << " ";
    }
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

LinkNode *merge(struct LinkNode *firstLink, struct LinkNode *secondLink) {
    if (firstLink == nullptr) {
        return secondLink;
    } else if (secondLink == nullptr) {
        return firstLink;
    }
    auto *l = new LinkNode();
    LinkNode *head = l;
    while (firstLink != nullptr && secondLink != nullptr) {
        l->next = firstLink->value < secondLink->value ? firstLink : secondLink;
        l = l->next;
        (firstLink->value < secondLink->value ? firstLink : secondLink) = ((firstLink->value < secondLink->value
                                                                            ? firstLink : secondLink)->next);
    }
    while (firstLink != nullptr) {
        l->next = firstLink;
        l = l->next;
        firstLink = firstLink->next;
    }
    while (secondLink != nullptr) {
        l->next = secondLink;
        l = l->next;
        secondLink = secondLink->next;
    }
    return head->next;
}

void test01() {
    vector<vector<int>> vec = {{1, 2, 4},
                               {2, 3, 4}};
    vector<vector<LinkNode *>> nodes = prepareNodes(vec);
    LinkNode *head = merge(nodes[0][0], nodes[1][0]);
    printLink(head);
}

void test02() {
    vector<vector<int>> vec = {{1},
                               {1}};

    vector<vector<LinkNode *>> nodes = prepareNodes(vec);
    LinkNode *head = merge(nodes[0][0], nodes[1][0]);
    printLink(head);
}

void test03() {
    vector<vector<int>> vec = {{},
                               {}};

    vector<vector<LinkNode *>> nodes = prepareNodes(vec);
    LinkNode *head = merge(nodes[0][0], nodes[1][0]);
    printLink(head);
}

void test04() {
    vector<vector<int>> vec = {{1, 3, 4,  6,   78, 89},
                               {1, 2, 45, 755, 6655}};

    vector<vector<LinkNode *>> nodes = prepareNodes(vec);
    LinkNode *head = merge(nodes[0][0], nodes[1][0]);
    printLink(head);
}

int main() {
    test01();
    test02();
    test03();
    test04();
}