//
// Created by Isaac Graham on 8/7/2019.
//

/**
 * 实现了一波舞蹈链算法，准备会回溯法搞一波题目
 * 可以用于解Q37
 */

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



void remove_node(stack<Node *> &s, Node *n) {
    s.push(n);
    if (n->right != nullptr)
        n->right->left = n->left;
    if (n->left != nullptr)
        n->left->right = n->right;
    if (n->name > 0) {
        if (n->up != nullptr)
            n->up->down = n->down;
        if (n->down != nullptr)
            n->down->up = n->up;
    }
}

void remove_row(stack<Node *> &s, Node *n) {
    remove_node(s, n);
    Node *node = n;
    while ((node = node->left) != nullptr)
        remove_node(s, node);
    node = n;
    while ((node = node->right) != nullptr)
        remove_node(s, node);
}

// 空间会浪费，并且可能造成BUG
void remove(stack<Node *> &s, Node *n) {
    Node *node = n;
    while (node != nullptr) {
        remove_node(s, node);
        remove_node(s, node->col);
        Node *via_node = node;
        while (via_node->up != via_node->col) {
            via_node = via_node->up;
            remove_row(s, via_node);
        }
        via_node = node;
        while ((via_node = via_node->down) != nullptr) { remove_row(s, via_node); }
        node = node->right;
    }

}

void remove_col(stack<Node *> &s, Node *n) {
    if (n->right != nullptr)
        remove_col(s, n->right);
    s.push(n->col);
    if (n->col->left != nullptr)
        n->col->left->right = n->col->right;
    if (n->col->right != nullptr)
        n->col->right->left = n->col->left;
}

stack<Node *> dancing_list(Node *head) {
    stack<Node *> answer_node;
    stack<Node *> delete_node;
    while (head->right != nullptr) {
        Node *node = head->right;
        while (node->down == nullptr) {
            while (delete_node.top() != answer_node.top()) {
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
            if (node->left != nullptr)
                node->left->right = node;
            if (node->right != nullptr)
                node->right->left = node;
            if (node->down != nullptr)
                node->down->up = node;
            if (node->up != nullptr)
                node->up->down = node;
            answer_node.pop();
            delete_node.pop();
        }
        if ((node = node->down) != nullptr) {
            answer_node.push(node);
            remove(delete_node, node);
        }
    }
    return answer_node;
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
//
//
//    Node *head = new Node(0);
//    vector<Node *> node_vector(325);
//    node_vector[0] = head;
//    for (int index = 1; index < node_vector.size(); index++) {
//        node_vector[index] = new Node(-1 * index);
//    }
//    for (int index = 0; index < node_vector.size(); index++) {
//        if (index != 0) {
//            node_vector[index - 1] = node_vector[index]->left;
//        }
//        if (index != node_vector.size() - 1) {
//            node_vector[index + 1] = node_vector[index]->right;
//        }
//    }
//    for (int row = 0; row < 9; row++) {
//        for (int col = 0; col < 9; col++) {
//
//        }
//    }

    Node *head = new Node(), *C1 = new Node(), *C2 = new Node(), *C3 = new Node(), *C4 = new Node(), *C5 = new Node(), *C6 = new Node(), *C7 = new Node(), *N1 = new Node(), *N2 = new Node(), *N3 = new Node(), *N4 = new Node(), *N5 = new Node(), *N6 = new Node(), *N7 = new Node(), *N8 = new Node(), *N9 = new Node(), *N10 = new Node(), *N11 = new Node(), *N12 = new Node(), *N13 = new Node(), *N14 = new Node(), *N15 = new Node(), *N16 = new Node();
    head->initial(nullptr, nullptr, nullptr, C1, nullptr);
    C1->initial(nullptr, N4, head, C2, C1, -2);
    C2->initial(nullptr, N7, C1, C3, C2, -2);
    C3->initial(nullptr, N1, C2, C4, C3, -2);
    C4->initial(nullptr, N5, C3, C5, C4, -2);
    C5->initial(nullptr, N2, C4, C6, C5, -2);
    C6->initial(nullptr, N3, C5, C7, C6, -2);
    C7->initial(nullptr, N6, C6, nullptr, C7, -2);
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

    stack<Node *> answer = dancing_list(head);
    while (!answer.empty()) {
        cout << answer.top()->name << endl;
        answer.pop();
    }

}