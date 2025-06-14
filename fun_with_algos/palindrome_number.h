//
// Created by andreas on 12.06.25.
//

#ifndef PALINDROME_NUMBER_H
#define PALINDROME_NUMBER_H
// Given an integer x, return true if x is a , and false otherwise.

bool is_palindrome_number(int input)
{
    if (input < 0)
        return false;
    int reversed{};
    int help = input;
    while (true)
    {
        reversed = (input % 10) + reversed * 10;
        input /= 10;
        if (!input)
            break;
    }
    return reversed == help;
}
#endif //PALINDROME_NUMBER_H
