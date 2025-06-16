//
// Created by andreas on 16.06.25.
//

#ifndef LONGEST_BIT_SEQUENCE_WITH_FLIP_H
#define LONGEST_BIT_SEQUENCE_WITH_FLIP_H
// You have an integer and you can flip exactly one bit from a 0 to a 1, Write code to
// find the length of the longest sequence of Is you could create.
int longest_bit_sequence_with_flip(int input)
{
    int max_size{};
    int current_size{};
    int count{1};
    for (int i = 0; i < 31; ++i)
    {
        if (input & (1 << i))
        {
            current_size++;
            count = 1;
        }
        else if (count == 1 && current_size > 0)
        {
            current_size++;
            count = 0;
        }
        else
            current_size = 0;
        max_size = std::max(max_size, current_size);
    }
    return max_size;
}
#endif //LONGEST_BIT_SEQUENCE_WITH_FLIP_H
