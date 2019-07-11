//
// Created by Isaac Graham on 7/10/2019.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(const string &str) {
        bool valid = false, concat = false, end = false;
        queue<char> substr_queue;
        for (int index = 0; index < str.size(); index++) {
            if (!valid) {
                if (str[index] == ' ')
                    continue;
                else if (str[index] != '+' && str[index] != '-' && ((int) str[index] > 57 || (int) str[index] < 48))
                    return 0;
                else {
                    valid = true;
                    if (str[index] != '0')
                        substr_queue.push(str[index]);
                    if ((int) str[index] <= 57 && (int) str[index] > 48)
                        concat = true;
                }
            } else if (!concat) {
                if (str[index] == '0')
                    continue;
                else if ((int) str[index] <= 57 && (int) str[index] >= 48) {
                    concat = true;
                    substr_queue.push(str[index]);
                } else
                    return 0;
            } else if (!end) {
                if ((int) str[index] <= 57 && (int) str[index] >= 48)
                    substr_queue.push(str[index]);
                else
                    end = true;
            }
        }

        string s;
        while (!substr_queue.empty()) {
            s += substr_queue.front();
            substr_queue.pop();
        }
        string min = "-2147483648", max = "2147483647";
        if (s == "+" || s == "-" || s.empty())
            return 0;
        cout << s << endl;
        if (s[0] == '-') {
            if (s.size() > min.size())
                return stoi(min);
            else if (s.size() < min.size())
                return stoi(s);
            else {
                for (int i = 1; i < s.size(); i++) {
                    if (s[i] > min[i])
                        return stoi(min);
                    else if (s[i] < min[i])
                        return stoi(s);
                }
            }
        } else {
            if (s[0] == '+')
                s = s.substr(1, s.size() - 1);
            if (s.size() > max.size())
                return stoi(max);
            else if (s.size() < max.size())
                return stoi(s);
            else {
                for (int i = 0; i < s.size(); i++) {
                    if (s[i] > max[i])
                        return stoi(max);
                    else if (s[i] < max[i])
                        return stoi(s);
                }
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution *s = new Solution();
    cout << s->myAtoi(" 1175109307q7") << endl;
//    string str = "-999999";
//    cout << stoi(str);
//    char c = ' ';
//    cout << (int)c << endl;
}