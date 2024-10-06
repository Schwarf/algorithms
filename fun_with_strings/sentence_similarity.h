//
// Created by andreas on 06.10.24.
//

#ifndef FUN_WITH_STRINGS_SENTENCE_SIMILARITY_H
#define FUN_WITH_STRINGS_SENTENCE_SIMILARITY_H
// You are given two strings sentence1 and sentence2, each representing a sentence composed of words.
// A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
// Each word consists of only uppercase and lowercase English characters.
// Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence
// (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.
// For example,
// s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
// s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
// Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.
// #GOOGLE
#include <string>
#include <vector>
#include <sstream>
bool are_sentences_similar(std::string &sentence1, std::string &sentence2) {
    std::stringstream ss1(sentence1), ss2(sentence2);
    std::string word;
    std::vector<std::string> tokens1, tokens2;
    // The >> operator reads and discards any leading whitespace (spaces, newlines, tabs, etc.) from the input stream.
    // Then, it continues to read the input until it encounters more whitespace or reaches the end of the stream.
    // The characters between the whitespaces are considered a single "word".
    while (ss1 >> word)
        tokens1.push_back(word);
    while (ss2 >> word)
        tokens2.push_back(word);
    if(tokens1.size() > tokens2.size())
        return are_sentences_similar(sentence2, sentence1);

    int start{};
    int end1 = tokens1.size()-1;
    int end2 = tokens2.size()-1;

    while(start < tokens1.size() && tokens1[start] == tokens2[start])
        start++;
    while(end1 >= 0 && tokens1[end1] == tokens2[end2])
    {
        end1--;
        end2--;
    }
    return end1 < start;
}

#endif //FUN_WITH_STRINGS_SENTENCE_SIMILARITY_H
