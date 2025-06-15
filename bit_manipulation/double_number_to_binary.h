//
// Created by andreas on 15.06.25.
//

#ifndef DOUBLE_NUMBER_TO_BINARY_H
#define DOUBLE_NUMBER_TO_BINARY_H
// Binary to String: Given a reai number between 0 and 1 (e.g., 0.72) that is passed in as a double, print
// the binary representation. If the number cannot be represented accurately in binary with at most 32
// characters, print "ERROR."
#include <string>

std::string double_number_to_binary(double number)
{
    if (number >= 1.0 || number <= 0.0)
    {
        return "ERROR";
    }

    std::string result = "0.";
    while (number > 0.0)
    {
        if (result.size() >= 32)
        {
            // too many characters => non-terminating in 32 bits
            return "ERROR";
        }
        if (double scaled_value = number * 2; scaled_value >= 1.0)
        {
            result.push_back('1');
            number = scaled_value - 1.0;
        }
        else
        {
            result.push_back('0');
            number = scaled_value;
        }
    }
    return result;
}

#endif //DOUBLE_NUMBER_TO_BINARY_H
