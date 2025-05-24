//
// Created by andreas on 24.05.25.
//

#ifndef DESIGN_IN_MEMORY_FILE_SYSTEM_H
#define DESIGN_IN_MEMORY_FILE_SYSTEM_H
// Design a data structure that simulates an in-memory file system.
// Implement the FileSystem class:
//
//    FileSystem() Initializes the object of the system.
//    List<String> ls(String path)
//        If path is a file path, returns a list that only contains this file's name.
//        If path is a directory path, returns the list of file and directory names in this directory.
//    The answer should in lexicographic order.
//    void mkdir(String path) Makes a new directory according to the given path. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.
//    void addContentToFile(String filePath, String content)
//        If filePath does not exist, creates that file containing given content.
//        If filePath already exists, appends the given content to original content.
//    String readContentFromFile(String filePath) Returns the content in the file at filePath.
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <memory>

class FileSystem
{
private:
    using FileContent = std::string;
    using FileName = std::string;

    struct Directory
    {
        std::unordered_map<std::string, std::unique_ptr<Directory>> dirs;
        std::unordered_map<FileName, FileContent> files;
    };

    std::unique_ptr<Directory> root;

    // Helper: Split a path by "/"
    std::vector<std::string> split(const std::string& path) const
    {
        std::vector<std::string> result;
        std::stringstream stream(path);
        std::string token;
        while (std::getline(stream, token, '/'))
        {
            if (!token.empty())
                result.push_back(token);
        }
        return result;
    }

public:
    FileSystem() : root(std::make_unique<Directory>())
    {
    }

    std::vector<std::string> ls(const std::string& path) const
    {
        Directory* current_dir = root.get();
        std::vector<std::string> tokens = split(path);
        std::vector<std::string> result;

        if (!tokens.empty())
        {
            // walk through the directory tree excluding the last one
            for (size_t i = 0; i < tokens.size() - 1; ++i)
            {
                current_dir = current_dir->dirs[tokens[i]].get();
            }

            const std::string& last = tokens.back();
            // last token points to a single file then we return
            if (current_dir->files.contains(last))
            {
                result.push_back(last);
                return result;
            }
            // otherwise we get the last dir on the path
            current_dir = current_dir->dirs[last].get();
        }
        // list all directories
        for (const auto& [dir_name, _] : current_dir->dirs)
        {
            result.push_back(dir_name);
        }
        // list all files
        for (const auto& [file_name, _] : current_dir->files)
        {
            result.push_back(file_name);
        }
        // order lexicographically
        std::sort(result.begin(), result.end());
        return result;
    }

    void mkdir(const std::string& path)
    {
        Directory* current_dir = root.get();
        for (const auto& dir : split(path))
        {
            if (!current_dir->dirs.count(dir))
                current_dir->dirs[dir] = std::make_unique<Directory>();
            current_dir = current_dir->dirs[dir].get();
        }
    }

    void addContentToFile(const std::string& filePath, const FileContent& content)
    {
        Directory* current_dir = root.get();
        std::vector<std::string> tokens = split(filePath);
        const FileName& file_name = tokens.back();
        for (size_t i = 0; i < tokens.size() - 1; ++i)
        {
            if (!current_dir->dirs.contains(tokens[i]))
            {
                current_dir->dirs[tokens[i]] = std::make_unique<Directory>();
            }
            current_dir = current_dir->dirs[tokens[i]].get();
        }
        current_dir->files[file_name] += content;
    }

    std::string readContentFromFile(const std::string& filePath) const
    {
        Directory* current_dir = root.get();
        std::vector<std::string> tokens = split(filePath);
        const FileName& file_name = tokens.back();
        for (size_t i = 0; i < tokens.size() - 1; ++i)
            current_dir = current_dir->dirs[tokens[i]].get();
        return current_dir->files[file_name];
    }
};

#endif //DESIGN_IN_MEMORY_FILE_SYSTEM_H
