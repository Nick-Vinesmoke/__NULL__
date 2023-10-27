#include "explorer.h"



std::vector<File> GetFilesInDir(const std::string& directoryPath)
{
    std::vector<File> txtFiles;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            File file(entry.path().stem().string(), entry.path().string());
            txtFiles.push_back(file);
        }
    }

    return txtFiles;
}

std::vector<Topic> GetDirsInDir(const std::string& directoryPath) 
{
    std::vector<Topic> topics;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_directory()) {
            Topic topic(entry.path().filename().string());
            topics.push_back(topic);
        }
    }

    return topics;
}