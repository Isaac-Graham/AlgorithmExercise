//
// Created by Isc on 2020/8/26.
//

#include <bits/stdc++.h>

using namespace std;

stack<int> cache;

int random(int num) {
    return rand() % num + 1;
}

pair<int, int> advertise(int num, vector<int> randomVector) {
    int ad1 = 0;// = random(randomVector.size());
    int ad2 = 0;// = random(randomVector.size());
    if (!cache.empty()) {
        ad1 = cache.top();
        ad2 = random(randomVector.size());
    } else {
        ad1 = random(randomVector.size());
        ad2 = random(randomVector.size());
        // 这里如果不加上这个if的话直接进入下面的while会损失一次精度
        if (randomVector[ad1 - 1] == randomVector[ad2 - 1]) {
            cache.push(ad2);
        }
    }
    while (randomVector[ad1 - 1] == randomVector[ad2 - 1]) {
        cache.push(ad2);
        ad2 = random(randomVector.size());
    }
    if (!cache.empty()) {
        cache.pop();
    }
    return pair<int, int>(randomVector[ad1 - 1], randomVector[ad2 - 1]);
}

vector<int> initialRandomVector(int num) {
    vector<int> randomVector;
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < i; j++) {
            randomVector.push_back(i);
        }
    }
    return randomVector;
}

void test01() {
    int num = 4;
    vector<int> randomVector = initialRandomVector(num);
    vector<int> vec(num + 1, 0);
    for (int i = 0; i < 1000000; i++) {
        pair<int, int> p = advertise(num, randomVector);
        vec[p.first]++;
        vec[p.second]++;
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned) time(NULL));
    test01();
}