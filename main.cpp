//#include<bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    vector<int> vec = {1, 5, 2, 8, 0, 3, 9};
//    int length = vec.size();
//    priority_queue<int, vector<int>, less<>> pq;
//    for (int i: vec) {
//        pq.push(i);
////        if (pq.size() > length / 2 + 1) {
////            pq.pop();
////        }
//    }
//    cout << pq.top();
//}

/**
 * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */

#include<bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

struct Node {
    int level;
    TreeNode *treenode;

    Node(int l, TreeNode *t) {
        level = l;
        treenode = t;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(new Node(0, root));
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            TreeNode *treenode = node->treenode;
            int level = node->level;
            while (ans.size() <= level) {
                ans.push_back(*new vector<int>());
            }
            ans[level].push_back(treenode->val);
            if (treenode->left != nullptr) {
                q.push(new Node(level + 1, treenode->left));
            }
            if (treenode->right != nullptr) {
                q.push(new Node(level + 1, treenode->right));
            }
        }
        return ans;
    }
};

int main() {
    vector<int> vec = {3, 9, 20, 15, 7};
    vector<TreeNode *> v;
    v.reserve(vec.size());
    for (int i: vec) {
        v.push_back(new TreeNode(i));
    }
    v[0]->left = v[1];
    v[0]->right = v[2];
    v[2]->left = v[3];
    v[2]->right = v[4];
    Solution *s = new Solution();
    vector<vector<int>> res = s->levelOrder(v[0]);
    cout << res.size() << endl;
    for (size_t i = 0; i < res.size(); i++) {
        for (size_t j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}