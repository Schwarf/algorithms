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
          int remaining_width, int max_height) {
    auto current_book = books[book_index];
    int new_height = std::max(max_height, current_book[1]);

    if (book_index == books.size() - 1) {
        if (remaining_width >= current_book[0])
            return new_height;
        else
            return max_height + current_book[1];
    }

    if (memo[book_index][remaining_width] != 0)
        return memo[book_index][remaining_width];
    auto put_on_new_shelf_height =
            max_height + dp_helper(books, shelf_width, memo, book_index + 1, shelf_width - current_book[0],
                                   current_book[1]);
    if (remaining_width >= current_book[0]) {
        int remain_on_shelf_height = dp_helper(books, shelf_width, memo, book_index + 1,
                                               remaining_width - current_book[0], new_height);
        memo[book_index][remaining_width] = std::min(put_on_new_shelf_height, remain_on_shelf_height);
        return memo[book_index][remaining_width];
    }
    memo[book_index][remaining_width] = put_on_new_shelf_height;
    return memo[book_index][remaining_width];
}

int minimal_height_shelves_top_down(std::vector<std::vector<int>> &books, int shelfWidth) {
    std::vector<std::vector<int>> memo(books.size(), std::vector<int>(shelfWidth + 1, 0));
    return dp_helper(books, shelfWidth, memo, 0, shelfWidth, 0);
}


int minimal_height_shelves_bottom_up(std::vector<std::vector<int>> &books, int shelfWidth) {
    std::vector<int> dp(books.size() + 1, 0);

    // Base cases
    dp[0] = 0;
    dp[1] = books[0][1];

    for (int i = 1; i <= books.size(); ++i) {
        // new shelf built to hold current book
        int remaining_shelf_width = shelfWidth - books[i - 1][0];
        int max_height = books[i - 1][1];
        dp[i] = dp[i - 1] + max_height;

        int j = i - 1;
        // calculate the height when previous books are added onto a new
        // shelf
        while (j > 0 && remaining_shelf_width - books[j - 1][0] >= 0) {
            remaining_shelf_width -= books[j - 1][0];
            max_height = std::max(max_height, books[j - 1][1]);
            dp[i] = std::min(dp[i], dp[j - 1] + max_height);
            j--;
        }
    }

    return dp[books.size()];
}

#endif //DYNAMIC_PROGRAMMING_SAMPLES_MINIMAL_HEIGHT_BOOK_SHELVES_H
