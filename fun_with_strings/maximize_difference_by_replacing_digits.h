//
// Created by andreas on 15.06.25.
//

#ifndef MAXIMIZE_DIFFERENCE_BY_REPLACING_DIGITS_H
#define MAXIMIZE_DIFFERENCE_BY_REPLACING_DIGITS_H
// You are given an integer num. You will apply the following steps to num two separate times:
//
//    Pick a digit x (0 <= x <= 9).
//    Pick another digit y (0 <= y <= 9). Note y can be equal to x.
//    Replace all the occurrences of x in the decimal representation of num by y.
//
// Let a and b be the two results from applying the operation to num independently.
//
// Return the max difference between a and b.
//
// Note that neither a nor b may have any leading zeros, and must not be 0.
#include <string>
#include <algorithm>
int max_difference_by_replacing_digits(int input){
    std::string min_num = std::to_string(input);
    std::string max_num = std::to_string(input);
    // Find a high position and replace it with 9.
    for (char digit : max_num) {
        if (digit != '9') {
            std::replace(max_num.begin(), max_num.end(), digit, '9');
            break;
        }
    }

    // Replace the most significant digit with 1
    // Or find a high-order digit that is not equal to the highest digit and
    // replace it with 0.
    for (int i = 0; i < min_num.size(); ++i) {
        char digit = min_num[i];
        if (i == 0) {
            if (digit != '1') {
                std::replace(min_num.begin(), min_num.end(), digit, '1');
                break;
            }
        } else {
            if (digit != '0' && digit != min_num[0]) {
                std::replace(min_num.begin(), min_num.end(), digit, '0');
                break;
            }
        }
    }

    return stoi(max_num) - stoi(min_num);
}
#endif //MAXIMIZE_DIFFERENCE_BY_REPLACING_DIGITS_H
