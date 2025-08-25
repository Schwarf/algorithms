//
// Created by andreas on 30.05.24.
//

#ifndef FUN_WITH_ALGOS_LOGGER_RATE_LIMITER_H
#define FUN_WITH_ALGOS_LOGGER_RATE_LIMITER_H

// Design a logger system that receive stream of messages along with its timestamps,
// each message should be printed if and only if it is not printed in the last 10 seconds.
// Given a message and a timestamp (in seconds granularity), return true if the
// message should be printed in the given timestamp, otherwise returns false.
// It is possible that several messages arrive roughly at the same time.
#include <unordered_map>
#include <string>
#include <deque>
#include <unordered_set>

class Logger {
public:
    explicit Logger() = default;

    bool shall_print_message(int timestamp, const std::string &message) {
        // if unordered_map is empty it returns default constructed int
        if (timestamp < last_messages[message])
            return false;
        last_messages[message] = timestamp + 10;
        return true;
    }

private:
    std::unordered_map<std::string, int> last_messages;

};

class LoggerOnly10Seconds {
public:
    explicit LoggerOnly10Seconds() = default;

    bool shall_print_message(int timestamp, const std::string &message) {
        // Remove messages older than 10 seconds
        while (!message_queue.empty()) {
            const auto [old_timestamp, old_message] = message_queue.front();
            if (timestamp < old_timestamp + 10)
                break;
            message_queue.pop_front();
            messages.erase(old_message);
        }
        if (messages.contains(message))
            return false;
        message_queue.emplace_back(timestamp, message);
        messages.insert(message);
        return true;
    }

private:
    std::deque<std::pair<int, std::string>> message_queue;
    std::unordered_set<std::string> messages;

};


#endif //FUN_WITH_ALGOS_LOGGER_RATE_LIMITER_H
