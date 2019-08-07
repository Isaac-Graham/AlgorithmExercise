//
// Created by Isaac Graham on 8/7/2019.
//

#include <bits/stdc++.h>

using namespace std;
struct Node;
typedef Node Column;

struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    Node *up = nullptr;
    Node *down = nullptr;
    Column *col = nullptr;
    int name = -1;
    int size;

//    Node(Node *up, Node *down, Node *left, Node *right, Node *col, int name) : left(left), right(right), up(up),
//                                                                               down(down), col(col), name(name) {};
//
//    Node(Node *up, Node *down, Node *left, Node *right, Node *col) : left(left), right(right), up(up), down(down),
//                                                                     col(col) {};

    void initial(Node *up, Node *down, Node *left, Node *right, Node *col, int name) {
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
        this->col = col;
        this->name = name;
    };

    void initial(Node *up, Node *down, Node *left, Node *right, Node *col) {
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
        this->col = col;
    };

    Node() {}

};

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {

    }
};

// 空间会浪费，并且可能造成BUG
void remove(stack<Node *> &s, Node *n, Node *answer_node) {
    static vector<bool> visited(17);
    int a = n->name;
    visited[a] = true;;
    cout << "Removed node:  " << a << endl;
    // if(n->up != nullptr && n-> up-> name % 100 != 0){
    //     remove(s, n->up, answer_node);
    // }
    // if(n->down != nullptr){
    //     remove(s, n->down, answer_node);
    // }
    if (n->down != nullptr && !visited[n->down->name]&& n -> down -> name % 100 != 0)
        remove(s, n->down, answer_node);
    if (n->right != nullptr&& !visited[n->right->name]&& n -> right -> name % 100 != 0)
        remove(s, n->right, answer_node);
    if (n-> up != nullptr && !visited[n->up->name] && n -> up -> name % 100 != 0)
        remove(s, n-> up, answer_node);
    if (n->left !=nullptr && !visited[n->left->name]&& n -> left -> name % 100 != 0)
        remove(s, n->left, answer_node);
    if (n->col == answer_node->col && n->col->left->right == n->col) {
       s.push(n->col);
       n->col->left->right = n->col->right;
   }
    s.push(n);
    if (n->left != nullptr)
        n->left->right = n->right;
    if (n->right != nullptr)
        n->right->left = n->left;
    // if(n->name == 2){
    //     cout <<"n==2  " << n->up->name << endl;
    // }
    if (n->up != nullptr)
        n->up->down = n->down;
    // if (n->name == 2){
    //     if(n->up->down != nullptr)
    //         cout << "n==2  " <<n->up->down->name;
    //     else
    //         cout << "n==2 down is null " << endl;
    // }
    if (n->down != nullptr)
        n->down->up = n->up;
}

void remove_col(stack<Node *> &s, Node *n) {
    if (n->right != nullptr)
        remove_col(s, n->right);
    s.push(n->col);
    if (n->col->left != nullptr)
        n->col->left->right = n->col->right;
    if (n->col->right != nullptr)
        n->col->right->left = n->col->left;
//    if (n->up != nullptr)
//        n->up->down = n->down;
//    if (n->down != nullptr)
//        n->down->up = n->up;

}

int main() {
//    Solution *s = new Solution();
//    vector<vector<char>> v = {
//            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
//            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//    };

    Node *head = new Node(), *C1 = new Node(), *C2 = new Node(), *C3 = new Node(), *C4 = new Node(), *C5 = new Node(), *C6 = new Node(), *C7 = new Node(), *N1 = new Node(), *N2 = new Node(), *N3 = new Node(), *N4 = new Node(), *N5 = new Node(), *N6 = new Node(), *N7 = new Node(), *N8 = new Node(), *N9 = new Node(), *N10 = new Node(), *N11 = new Node(), *N12 = new Node(), *N13 = new Node(), *N14 = new Node(), *N15 = new Node(), *N16 = new Node();
    head->initial(nullptr, nullptr, nullptr, C1, nullptr);
    C1->initial(nullptr, N4, head, C2, C1, 100);
    C2->initial(nullptr, N7, C1, C3, C2, 200);
    C3->initial(nullptr, N1, C2, C4, C3, 300);
    C4->initial(nullptr, N5, C3, C5, C4, 400);
    C5->initial(nullptr, N2, C4, C6, C5, 500);
    C6->initial(nullptr, N3, C5, C7, C6, 600);
    C7->initial(nullptr, N6, C6, nullptr, C7, 700);
    N1->initial(C3, N8, nullptr, N2, C3, 1);
    N2->initial(C5, N15, N1, N3, C5, 2);
    N3->initial(C6, N9, N2, nullptr, C6, 3);
    N4->initial(C1, N10, nullptr, N5, C1, 4);
    N5->initial(C4, N11, N4, N6, C4, 5);
    N6->initial(C7, N13, N5, nullptr, C7, 6);
    N7->initial(C2, N12, nullptr, N8, C2, 7);
    N8->initial(N1, nullptr, N7, N9, C3, 8);
    N9->initial(N3, nullptr, N8, nullptr, C6, 9);
    N10->initial(N4, nullptr, nullptr, N11, C1, 10);
    N11->initial(N5, N14, N10, nullptr, C4, 11);
    N12->initial(N7, nullptr, nullptr, N13, C2, 12);
    N13->initial(N6, N16, N12, nullptr, C7, 13);
    N14->initial(N11, nullptr, nullptr, N15, C4, 14);
    N15->initial(N2, nullptr, N14, N16, C5, 15);
    N16->initial(N13, nullptr, N15, nullptr, C7, 16);
    vector<Node *> Col = {C1, C2, C3, C4, C5, C6, C7};
    vector<Node *> v = {head, C1, C2, C3, C4, C5, C6, C7, N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, N12, N13, N14,
                        N15, N16};

    stack<Node *> answer_node;
    stack<Node *> delete_node;
    while (head->right != nullptr) {
        cout << 1 << endl;
        Node *col = head->right;
        Node *node = col;
        Node *test_node = head;
        // while ((test_node = test_node->right) != nullptr) {
        //     Node *n = test_node;
        //     cout << "Col: " << n->name << " ";
        //     while ((n = n->down) != nullptr) {
        //         cout << n->name << " ";
        //     }
        //     cout << endl;
        // }
       cout << "Before Call Back: " << node->down->name << endl;
        if (node->down == nullptr) {
            // 回溯
            cout << "Begin to call back" << endl;
            cout << delete_node.size() << endl;
            cout << answer_node.size() << endl;
            while (delete_node.top() != answer_node.top()) {
                cout << 2 << endl;
                Node *d = delete_node.top();
                if (d->left != nullptr)
                    d->left->right = d;
                if (d->right != nullptr)
                    d->right->left = d;
                if (d->down != nullptr)
                    d->down->up = d;
                if (d->up != nullptr)
                    d->up->down = d;
                delete_node.pop();
            }
            node = answer_node.top();
            answer_node.pop();
            delete_node.pop();
        }
        if ((node = node->down) != nullptr) {
            cout << "Begin to delete nodes: " << endl;
            cout << "answer note: " << node->name << endl;
            answer_node.push(node);
            Node *n = node;
//            while (n != nullptr && n->col->left->right == n->col) {
//                cout << "被删除的Col节点: " << n->col->name << endl;
//                n->col->left->right = n->col->right;
//                n = n->right;
//            }
            // cout << n->name << endl;
            remove_col(delete_node, n);
            // cout << n->name << endl;

            remove(delete_node, node, node);
        }
    }
    cout << endl;

    while (!answer_node.empty()) {
        cout << answer_node.top()->name << " ";
        answer_node.pop();
    }
    cout << endl;

    cout << "end" << endl;

}