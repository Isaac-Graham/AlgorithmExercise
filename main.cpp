#include <bits/stdc++.h>

using namespace std;


string test() {
    return "sss";
}

int main() {
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    int t = 5;
    while (t--) {
        int top = pq.top();
        pq.pop();
        cout << top << " " << pq.size() << endl;
    }
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    int tt = 7;
    while (tt--) {
        int a = v.front();
        cout << a << endl;
        v.pop_back();
    }
}