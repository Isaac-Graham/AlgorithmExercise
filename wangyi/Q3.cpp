//
// Created by Isc on 2020/8/12.
//

#include <bits/stdc++.h>

using namespace std;

class Operation {
public:
    int time;
    int id;
    int status;
    int cost = 0;

    Operation() {};

    Operation(int t, int id, int s) : time(t), id(id), status(s) {};
};


int main() {
    int testcase = 0;
    cin >> testcase;
    for (int loop = 0; loop < testcase; loop++) {
        int line = 0;
        cin >> line;
        vector<Operation> vec(line);
        for (int i = 0; i < line; i++) {
            int t, id, s;
            cin >> t >> id >> s;
            vec[i] = *new Operation(t, id, s);
        }
        stack<Operation> s;
        int maxTime = INT_MIN;
        int maxId = -1;
        for (int i = 0; i < vec.size(); i++) {
            if (s.empty()) {
                s.push(vec[i]);
                continue;
            }
            Operation top = s.top();
            if (vec[i].id == s.top().id) {
                int time = vec[i].time - s.top().time - s.top().cost;
                int id = vec[i].id;
                s.pop();
                if (!s.empty()) {
                    s.top().cost += vec[i].time - top.time;
                }
                if (time > maxTime) {
                    maxTime = time;
                    maxId = id;
                } else if (time == maxTime) {
                    if (maxId >id) {
                        maxTime = time;
                        maxId = id;
                    }
                }
            } else {
                s.push(vec[i]);
            }
        }
        cout << maxId << endl;

    }
}


