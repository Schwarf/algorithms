//
// Created by andreas on 08.04.24.
//

#ifndef DATA_STRUCTURES_HOW_MANY_CAN_NOT_EATING_LUNCH_H
#define DATA_STRUCTURES_HOW_MANY_CAN_NOT_EATING_LUNCH_H
// The school cafeteria offers two dishes at lunch break, referred to by numbers 0 and 1 respectively.
// All students stand in a queue. Each student either prefers square or circular sandwiches.
// The number of dishes in the cafeteria is equal to the number of students.
// The dishes are placed in a stack. At each step:
// If the student at the front of the queue prefers the dish on the top of the stack, they will take it and leave the queue.
// Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top dish and are thus unable to eat.
// You are given two integer arrays students and dishes where dishes[i] is the type of the ith dish in the
// stack (i = 0 is the top of the stack) and students[j] is the preference of the jth student in the
// initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.
#include <queue>
#include <stack>
#include <vector>

int count_hungry_students(const std::vector<int> &students, const std::vector<int> &dishes) {
    int n = students.size();
    std::stack<int> st;
    std::queue<int> qu;
    for (int i{}; i < n; ++i) {
        st.push(dishes[n - 1 - i]);
        qu.push(students[i]);

    }
    int last_served{};
    while (!qu.empty() && last_served < qu.size()) {
        if (st.top() == qu.front()) {
            last_served = 0;
            st.pop();
            qu.pop();
        } else {
            last_served++;
            qu.push(qu.front());
            qu.pop();
        }
    }
    return qu.size();
}

#endif //DATA_STRUCTURES_HOW_MANY_CAN_NOT_EATING_LUNCH_H

