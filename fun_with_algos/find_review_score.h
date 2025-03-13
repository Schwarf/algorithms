//
// Created by andreas on 13.03.25.
//

#ifndef FIND_REVIEW_SCORE_H
#define FIND_REVIEW_SCORE_H
// A website allows customers to add reviews for the products they bought from their store.
// The review must follow the community guidelines in order to be published.
// Suppose that the website has marked n strings that are prohibited in reviews.
// They assign a score to each review that denotes how well it follows the guidelines.
// The score of a review is defined as the longest contiguous substring of the review which does not
// contain any string among the list of words from the prohibited list, ignoring the case.
// Given a review and a list of prohibited string, calculate the review score.
// Function Description
// Complete the function findReviewScore in the editor.
// findReviewScore has the following parameters:
//    review: a string
//    string prohibitedWords[n]: the prohibited words
//
//    Returns
//    int: the score of the review

// Example 1 :
// Input: review = "GoodProductButScrapAfterWash", prohibitedWords = ["crap", "odpro"]
// Output: 15
// Explanation: Some of the substrings that do not contain a prohibited word are:
// - ProductBut
// - rapAfterWash
// - dProductButScu
// - Wash
// The longest substring is "dProductButScra", return its length, 15.
#include <string>
#include <vector>
int find_review_score(const std::string & review, std::vector<std::string> prohibited_words) {

    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < review.size(); end++) {
        // Check if any prohibited word exists in the current substring
        for (const auto & word : prohibited_words) {
            if (review.substr(start, end - start + 1).find(word) != std::string::npos) {
                start++; // Move start forward to exclude the prohibited word
                break;   // Break early since one violation is enough
            }
        }
        maxLength = std::max(maxLength, end - start + 1); // Update max valid length
    }

    return maxLength;
}
#endif //FIND_REVIEW_SCORE_H
