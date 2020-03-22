//
// Created by Isc on 2020/1/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int difference = abs((int) a.size() - (int) b.size());
        string dif;
        for (int i = 0; i < difference; i++) {
            dif += "0";
        }
        if (a.size() < b.size()) { a = dif + a; } else { b = dif + b; }
        stack<string> stack1;
        int cin = 0;
        for (int pointer = a.size() - 1; pointer >= 0; pointer--) {
            int A = (int) a[pointer] - (int) '0';
            int B = (int) b[pointer] - (int) '0';
            int sum = A ^B ^cin;
            cin = (A & B) + (A & cin) + (B & cin);
            if (cin >= 2) {
                cin -= 2;
            }
            stack1.push(to_string(sum));
            if (pointer == 0) {
                if (cin == 1) {
                    stack1.push("1");
                }
            }
        }
        string res;
        while (!stack1.empty()) {
            res.append(stack1.top());
            stack1.pop();
        }
        return res;

    }
};

int main() {
    Solution *s = new Solution();
    string a = "1111";
    string b = "1111";
    cout << s->addBinary(a, b) << endl;
}