//
// Created by andreas on 05.05.24.
//

#ifndef FUN_WITH_STRINGS_COMPARE_VERSION_NUMBERS_H
#define FUN_WITH_STRINGS_COMPARE_VERSION_NUMBERS_H

#include <string>
#include <vector>
#include <sstream>

std::vector<int> parse_version(const std::string& version) {
    std::vector<int> revisions;
    std::string segment;
    std::istringstream version_stream(version);

    while (std::getline(version_stream, segment, '.')) {
        revisions.push_back(std::stoi(segment));  // Convert segment to integer, ignoring leading zeros
    }
    return revisions;
}


int compare_versions(const std::string &version1, const std::string &version2 )
{
    auto revision1 = parse_version(version1);
    auto revision2 = parse_version(version2);

    auto max_size = std::max(revision1.size(), revision2.size());
    for(auto i{0U}; i < max_size; ++i)
    {
        auto value1 = i < revision1.size() ? revision1[i] : 0;
        auto value2 = i < revision2.size() ? revision2[i] : 0;
        if(value1 > value2)
            return 1;
        if(value2 > value1)
            return -1;

    }
    return 0;
}

#endif //FUN_WITH_STRINGS_COMPARE_VERSION_NUMBERS_H
