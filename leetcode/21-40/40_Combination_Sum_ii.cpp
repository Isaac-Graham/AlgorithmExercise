//
// Created by Isaac Graham on 2019/8/21.
//
/**
 * DP魔改
 * 保证唯一性就直接用index来代替值就好了
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<set<vector<int>>> array(target + 1);
        for (int index = 0; index < candidates.size(); index++) {
            int c = candidates[index];
            if (c > target)
                continue;
            else {
                vector<int> v = {index};
                array[c].insert(v);
            }
        }

        for (int index = 1; index < (target + 1); index++) {
            for (int i = 1, j = index - i; i <= index / 2; i++, j--) {
                for (auto v1:array[i]) {
                    for (auto v2 : array[j]) {
                        vector<int> v = merge(v1, v2);
                        if (!v.empty())
                            array[index].insert(v);
                    }
                }
            }
        }

        set<vector<int>> set1;
        for (auto vec : array[target]) {
            vector<int> vv;
            for (int ve : vec) {
                vv.push_back(candidates[ve]);
            }
            set1.insert(vv);
        }

        vector<vector<int>> v;
        for (auto &vec : set1) {
            v.push_back(vec);
        }
        return v;


    }

    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        vector<int> v;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] > v2[j]) {
                v.push_back(v2[j++]);
            } else if (v1[i] < v2[j]) {
                v.push_back(v1[i++]);
            } else {
                vector<int> vv;
                return vv;
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
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    Solution *s = new Solution();
    s->combinationSum2(v, 8);
}