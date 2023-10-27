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

std::string AddTopic(const std::string& path)
{
    if (path.find("DATA") == 0 || path.find("data") == 0)
    {
        if (fs::create_directory(path))
            return "done";
        else
            return "path is incorrectly written or non-existent/already exists";
    }
    else 
    {
        return "path should start from \"DATA\"";
    }
    
}
std::string AddDoc(const std::string& path)
{
    if (path.find("DATA") == 0 || path.find("data") == 0)
    {
        if (!fs::exists(path + ".txt"))
        {
            std::ofstream outFile(path + ".txt");
            if (!outFile.is_open())
            {
                return "path is incorrectly written or non-existent/already exists";
            }
            outFile.close();
            return "done";
        }
        else
            return "path is incorrectly written or non-existent/already exists";

    }
    else
    {
        return "path should start from \"DATA\"";
    }

}