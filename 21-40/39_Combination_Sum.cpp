#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    }
};

int main(){
    set<vector<int>>s;
    s.insert({1,2,3,4});
    s.insert({2,1,3,4});
    for(auto item= s.begin(); item != s.end(); item++){
        for(int index = 0; index < (*item).size(); index++){
            cout << (*item)[index] << " ";
        }
        cout << endl;
    }
}