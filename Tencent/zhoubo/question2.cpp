//
// Created by Isc on 2020/8/22.
//

#include <bits/stdc++.h>

std::string minus(const std::string &A, const std::string &B) {
    if (A == B) {
        return "0";
    }
    std::vector<int> bits(A.size(), 0);
    int jiewei = 0;
    int difference = 0;
    for (int i = A.size() - 1, j = B.size() - 1; i >= 0; i--, j--) {
        int valA = A[i] - '0';
        int valB = j >= 0 ? B[j] - '0' : 0;
        difference = valA - valB - jiewei + 10;
        jiewei = difference >= 10 ? 0 : 1;
        bits[i] = difference % 10;
    }

    std::stringstream ss;
    bool meetFirstNonZero = false;
    for (int i = 0; i < bits.size(); i++) {
        if (!meetFirstNonZero && bits[i] == 0) {
            continue;
        } else if (!meetFirstNonZero && bits[i] != 0) {
            ss << bits[i];
            meetFirstNonZero = true;
        } else if (meetFirstNonZero) {
            ss << bits[i];
        }
    }
    return ss.str();
}


std::string minus_hp(const std::string &A, const std::string &B) {
    if (A.size() < B.size()) {
        // A is less than b
        return "-" + minus(B, A);
    } else if (A.size() == B.size()) {
        if (A < B) {
            return "-" + minus(B, A);
        } else {
            return minus(A, B);
        }
    } else {
        return minus(A, B);
    }
}

int main() {
    std::string A = "1234156781234156781234156781234156789";
    std::string B = "1234156781234156781234156781234156789";
    std::cout << minus_hp(A, B) << std::endl;
}