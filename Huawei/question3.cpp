//
// Created by Isc on 2020/8/26.
//

#include<bits/stdc++.h>

#include <utility>

using namespace std;

class InputInfo {
public:
    string str;
    int right;
    int wrong;

    InputInfo(string str, int right, int wrong) : str(str), right(right), wrong(wrong) {};
};

class Tire {
public:
    char value;
    vector<Tire *> sons;

    Tire() {
        vector<Tire *> son(26, nullptr);
        this->sons = son;
    }

    Tire(char c) : value(c) {
        vector<Tire *> son(26, nullptr);
        this->sons = son;
    };

    void insert(Tire *t) {
        this->sons[t->value - 'a'] = t;
    }

    void insert(char c) {
        if (this->getSon(c) != nullptr) {
            return;
        }
        Tire *t = new Tire(c);
        this->sons[c - 'a'] = t;
    }

    Tire *getSon(char c) {
        return this->sons[c - 'a'];
    }

    void traverse() {
        cout << this->value << ": ";
        for (int i = 0; i < this->sons.size(); i++) {
            if (this->sons[i] == nullptr) {
            } else {
                cout << this->sons[i]->value << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < this->sons.size(); i++) {
            if (this->sons[i] == nullptr) {
                continue;
            }
            this->sons[i]->traverse();
        }
    }
};

Tire *buildTree(const vector<InputInfo *> &vec) {
    Tire *root = new Tire();
    if (vec.empty())
        return nullptr;
    vector<unordered_map<char, Tire *>> nodes(vec[0]->str.size());
    for (int i = 0; i < vec.size(); i++) {
        Tire *node = root;
        string str = vec[i]->str;
        for (int j = 0; j < str.size(); j++) {
            Tire *t;
            if (nodes[j].find(str[j]) == nodes[j].end()) {
                t = new Tire(str[j]);
                nodes[j][str[j]] = t;
                node->insert(t);
                node = node->getSon(str[j]);
            } else {
                t = nodes[j][str[j]];
                node->insert(t);
                node = node->getSon(str[j]);
            }
        }
    }
    return root;
}

bool check(const vector<char> &vec, const vector<InputInfo *> &inputInfos) {
    bool res = true;
    set<char> charSet;
    for (int i = 0; i < vec.size(); i++) {
        charSet.insert(vec[i]);
    }
    for (int i = 0; i < inputInfos.size(); i++) {
        int rightNum = 0;
        int wrongNum = 0;
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] == inputInfos[i]->str[j]) {
                rightNum++;
            } else {
                if (charSet.find(inputInfos[i]->str[j]) != charSet.end()) {
                    wrongNum++;
                }
            }
        }
        if (rightNum != inputInfos[i]->right || wrongNum != inputInfos[i]->wrong) {
            res = false;
            break;
        }
    }
    return res;
}

string dfs(Tire *root, int length, const vector<InputInfo *> &inputInfos) {
    vector<char> vec(length, ' ');
    stack<Tire *> s;
    s.push(root);
    int pointer = 0;
    vector<set<Tire *>> nodes(length);
    while (!s.empty()) {
        int level = s.size() - 1;
        if (level == length - 1) {
            if (check(vec, inputInfos)) {
                string str = "";
                for (int i = 0; i < vec.size(); i++) {
                    str += vec[i];
                }
                return str;
            }
        }
        Tire *top = s.top();
        bool allMeet = true;
        for (int i = 0; i < top->sons.size(); ++i) {
            if (top->sons[i] == nullptr) {
                continue;
            }
            if (nodes[level].find(top->sons[i]) == nodes[level].end()) {
                s.push(top->sons[i]);
                vec[pointer++] = top->sons[i]->value;
                nodes[level].insert(top->sons[i]);
                allMeet = false;
                break;
            }
        }
        if (!allMeet) {
            continue;
        } else {
            s.pop();
            vec[pointer--] = ' ';
        }
    }
    return "";
}

//5
//5
//cloxy 3 0
//cxmnu 1 1
//kcotd 2 1
//apqud 2 0
//bldwz 1 1
int main() {
    int p = 0;
    int n = 0;
    cin >> p >> n;
    vector<InputInfo *> vec;
    for (int i = 0; i < n; i++) {
        string str;
        int right = 0;
        int wrong = 0;
        cin >> str >> right >> wrong;
        vec.push_back(new InputInfo(str, right, wrong));
    }
    Tire *root = buildTree(vec);
    cout << dfs(root, p, vec) << endl;
}