//
// Created by andreas on 31.07.24.
//

#ifndef DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_HEIGHT_BOOK_SHELVES_H
#define DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_HEIGHT_BOOK_SHELVES_H
// Given some (up to 1000) with height and thickness in an array and a shelf width.
// Arrange the books in that way that the height of the all shelves is minimal.
// Each shelf can be max shelf-width wide but does not to filled fully.
// The height of one shelf is determined by the book with maximum height of the shelf.
#include <vector>

int
dp_helper(std::vector<std::vector<int>> &books, int shelf_width, std::vector<std::vector<int>> &memo, int book_index,
          int remaining_width, int maxHeight) {
    auto current_book = books[book_index];
    int newHeight = std::max(maxHeight, current_book[1]);

    if (book_index == books.size() - 1) {
        if (remaining_width >= current_book[0])
            return newHeight;
        else
            return maxHeight + current_book[1];
    }

    if (memo[book_index][remaining_width] != 0)
        return memo[book_index][remaining_width];
    auto remain_on_shelf_height =
            maxHeight + dp_helper(books, shelf_width, memo, book_index + 1, shelf_width - current_book[0],
                                  current_book[1]);
    if (remaining_width >= current_book[0]) {
        int put_new_shel_height = dp_helper(books, shelf_width, memo, book_index + 1,
                                            remaining_width - current_book[0], newHeight);
        memo[book_index][remaining_width] = std::min(remain_on_shelf_height, put_new_shel_height);
        return memo[book_index][remaining_width];
    }
    memo[book_index][remaining_width] = remain_on_shelf_height;
    return memo[book_index][remaining_width];
}

int minimal_height_shelves(std::vector<std::vector<int>> &books, int shelfWidth) {
    std::vector<std::vector<int>> memo(books.size(), std::vector<int>(shelfWidth + 1, 0));
    return dp_helper(books, shelfWidth, memo, 0, shelfWidth, 0);
}


#endif //DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_HEIGHT_BOOK_SHELVES_H
