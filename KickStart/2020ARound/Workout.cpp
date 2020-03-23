//
// Created by Isaac_Chen on 2020/3/22.
//

#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int begin;
    int end;
    int average;
    int fence;

    Interval(int begin, int end) {
        this->begin = begin;
        this->end = end;
        this->average = end - begin;
        this->fence = 1;
    }

    void insert() {
        this->fence++;
        double gap = end - begin;
        this->average = ceil(gap / (float) fence);
    }

    bool operator<(const Interval &interval) const {
        return this->average < interval.average;
    }
};


int main() {
    int testCase;
    scanf("%d", &testCase);
    for (int t = 1; t <= testCase; t++) {
        int elementNumber, fenceNumber;
        scanf("%d%d", &elementNumber, &fenceNumber);
        priority_queue<Interval> pq;
        int begin = -1, end = -1;
        for (int i = 0; i < elementNumber; i++) {
            if (begin == -1) {
                scanf("%d", &begin);
            } else {
                scanf("%d", &end);
                Interval *interval = new Interval(begin, end);
                begin = end;
                pq.push(*interval);
            }
        }

        for (int i = 0; i < fenceNumber; i++) {
            Interval top = pq.top();
            pq.pop();
            top.insert();
            pq.push(top);
        }
        Interval top = pq.top();
        printf("Case #%d: %d\n", t, top.average);
    }
}