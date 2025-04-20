//
// Created by andreas on 20.04.25.
//

#ifndef REORDER_LOG_FILES_H
#define REORDER_LOG_FILES_H
// You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
// There are two types of logs:
//    Letter-logs: All words (except the identifier) consist of lowercase English letters.
//    Digit-logs: All words (except the identifier) consist of digits.
// Reorder these logs so that:
//    The letter-logs come before all digit-logs.
//    The letter-logs are sorted lexicographically by their contents. If their contents are the same,
//      then sort them lexicographically by their identifiers.
//    The digit-logs maintain their relative ordering.
//
// Return the final order of the logs.
#include <vector>
#include <string>
#include <algorithm>
std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
    std::vector<std::string> letter_logs;
    std::vector<std::string> digit_logs;

    for (const auto& log : logs) {
        int pos = log.find(' ');
        if (isdigit(log[pos + 1])) {
            digit_logs.push_back(log);
        } else {
            letter_logs.push_back(log);
        }
    }

    // Custom sort for letter logs
    std::sort(letter_logs.begin(), letter_logs.end(), [](const std::string& str1, const std::string& str2) {
        int after_id_str1 = str1.find(' ');
        int after_if_str2 = str2.find(' ');
        std::string id_str1 = str1.substr(0, after_id_str1);
        std::string content_str1 = str1.substr(after_id_str1 + 1);
        std::string id_str2 = str2.substr(0, after_if_str2);
        std::string content_str2 = str2.substr(after_if_str2 + 1);
        if (content_str1 == content_str2) {
            return id_str1 < id_str2;
        }
        return content_str1 < content_str2;
    });

    // Append digit logs after letter logs
    letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
    return letter_logs;
}

#endif //REORDER_LOG_FILES_H
