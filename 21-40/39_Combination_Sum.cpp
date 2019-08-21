
/**
 * 动态规划
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<set<vector<int>>> array(target + 1);
        for (int c : candidates) {
            if (c > target)
                continue;
            else {
                vector<int> v = {c};
                array[c].insert(v);
            }
        }

        for (int index = 1; index < (target + 1); index++) {
            for (int i = 1, j = index - i; i <= index / 2; i++, j--) {
                for (auto v1:array[i]) {
                    for (auto v2 : array[j]) {
                        array[index].insert(merge(v1, v2));
                    }
                }
            }
        }
        vector<vector<int>> v;
        for(auto vector : array[target]){
            v.push_back(vector);
        }
        return v;


//        for (auto &s : array) {
//            for (auto p = s.begin(); p != s.end(); p++) {
//                cout << "[ ";
//                for (auto e : (*p)) {
//                    cout << e << " ";
//                }
//                cout << "]";
//            }
//            cout << endl;
//        }
    }

    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        vector<int> v;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] > v2[j]) {
                v.push_back(v2[j++]);
            } else {
                v.push_back(v1[i++]);
            }
        }
        while (i < v1.size()) {
            v.push_back(v1[i++]);
        }
        while (j < v2.size()) {
            v.push_back(v2[j++]);
        }
        return v;
    }
};

int main() {
    vector<int> v = {2, 3, 6, 7};
    Solution *s = new Solution();
    s->combinationSum(v, 7);
}