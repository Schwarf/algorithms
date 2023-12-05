#ifndef MISC_LIBRARY_H
#define MISC_LIBRARY_H
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string& str, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream token_stream(str);

	while (std::getline(token_stream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}


#endif //MISC_LIBRARY_H
