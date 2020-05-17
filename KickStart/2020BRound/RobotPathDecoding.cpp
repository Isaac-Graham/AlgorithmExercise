//
// Created by Isaac_Chen on 2020/4/22.
//

#include<bits/stdc++.h>

#define ll long long
const int MAX = 1e9;
using namespace std;

// Solution 1 -> MLE
string getExpandCommand(const string &originalCommand) {
    stack<string> s;
    for (int i = 0; i < originalCommand.length(); i++) {
        if (originalCommand[i] == ')') {
            stringstream strStream;
            stack<string> reverseStack;
            while (s.top() != "(") {
                reverseStack.push(s.top());
                s.pop();
            }
            while (!reverseStack.empty()) {
                strStream << reverseStack.top();
                reverseStack.pop();
            }
            s.pop();
            int times = s.top()[0] - '0';
            s.pop();
            stringstream res;
            string str = strStream.str();
            for (int j = 0; j < times; j++) {
                res << str;
            }
            s.push(res.str());
        } else {
            string ss(1, originalCommand[i]);
            s.push(ss);
        }
    }

    string res;
    while (!s.empty()) {
        res = s.top() + res;
        s.pop();
    }
    return res;
}

// Solution 2 -> AC
inline bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

class Item {
public:
    ll e = 0;
    ll n = 0;
    ll s = 0;
    ll w = 0;
    int val = 0;

    void add(Item *item) {
        this->e += item->e;
        this->n += item->n;
        this->s += item->s;
        this->w += item->w;
    }

    void multiple(ll times) {
        this->e = e * times % MAX;
        this->n = n * times % MAX;
        this->s = s * times % MAX;
        this->w = w * times % MAX;
    }
};

Item *leftBrackets = new Item();
Item *rightBrackets = new Item();

Item *getResult(const string &command) {
    vector<Item *> vec;
    for (int i = 0; i < command.length(); i++) {
        if (command[i] == '(') {
            vec.push_back(leftBrackets);
        } else if (command[i] == ')') {
            vec.push_back(rightBrackets);
        } else if (isNumber(command[i])) {
            Item *num = new Item();
            num->val = command[i] - '0';
            vec.push_back(num);
        } else {
            Item *item = new Item();
            while (i < command.length()) {
                if (command[i] == 'W') {
                    item->w++;
                } else if (command[i] == 'E') {
                    item->e++;
                } else if (command[i] == 'S') {
                    item->s++;
                } else if (command[i] == 'N') {
                    item->n++;
                } else {
                    i--;
                    break;
                }
                i++;
            }
            vec.push_back(item);
        }
    }

    stack<Item *> s;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == rightBrackets) {
            Item *item = new Item();
            while (s.top() != leftBrackets) {
                item->add(s.top());
                s.pop();
            }
            s.pop();
            ll num = s.top()->val;
            s.pop();
            item->multiple(num);
            s.push(item);
        } else {
            s.push(vec[i]);
        }
    }

    Item *item = new Item();
    while (!s.empty()) {
        item->add(s.top());
        s.pop();
    }
    return item;
}

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 1; loop <= testcase; loop++) {
        string command;
        cin >> command;
        Item *item = getResult(command);
//        command = getExpandCommand(command);
//        ll w = 0;
//        ll e = 0;
//        ll n = 0;
//        ll s = 0;
//        for (ll i = 0; i < command.length(); i++) {
//            switch (command[i]) {
//                case 'W':
//                    w++;
//                    break;
//                case 'E':
//                    e++;
//                    break;
//                case 'N':
//                    n++;
//                    break;
//                case 'S':
//                    s++;
//                    break;
//                default:
//                    break;
//            }
//        }
        ll horizontal = (item->e - item->w) % MAX;
        ll vertical = (item->s - item->n) % MAX;
        ll x = (horizontal + 1 + MAX) % MAX == 0 ? MAX : (horizontal + 1 + MAX) % MAX;
        ll y = (vertical + 1 + MAX) % MAX == 0 ? MAX : (vertical + 1 + MAX) % MAX;
        cout << "Case #" << loop << ": " << x << " " << y << "\n";
    }
}