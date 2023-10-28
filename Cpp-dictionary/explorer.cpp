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

std::string DelDoc(const std::string& path) 
{
    if (path.find("DATA") == 0 || path.find("data") == 0)
    {
        if (fs::exists(path + ".txt"))
        {
            if (std::filesystem::remove(path + ".txt"))
            {
                return "done";
            }
            else
                return "failed to delete the doc";
        }
        else
            return "path is incorrectly written or non-existent";

    }
    else
    {
        return "path should start from \"DATA\"";
    }
}

std::string DelTopic(const std::string& path)
{
    if (path.find("DATA") == 0 || path.find("data") == 0)
    {
        if (fs::exists(path))
        {
            try {
                std::filesystem::remove_all(path);
                return "done";
            }
            catch (...) 
            {
                return "failed to delete the topic";
            }
        }
        else
            return "path is incorrectly written or non-existent";

    }
    else
    {
        return "path should start from \"DATA\"";
    }
}

std::string RenameDoc(const std::string& oldName, const std::string& name)
{
    if (oldName.find("DATA") == 0 || oldName.find("data") == 0){
        if (fs::exists(oldName+".txt") && fs::is_regular_file(oldName + ".txt")) {
            try {
                fs::path filePath(oldName + ".txt");
                std::string path = filePath.parent_path().string();
                fs::rename(oldName + ".txt", path+'/'+name + ".txt");
                return "done";
            }
            catch (...) 
            {
                return "failed to rename the doc";
            }
        }
        else
            return "path is incorrectly written or non-existent";
    }
    else
    {
        return "path should start from \"DATA\"";
    }
}

std::string RenameTopic(const std::string& oldName, const std::string& name)
{
    if (oldName.find("DATA") == 0 || oldName.find("data") == 0) 
    {
        if (fs::exists(oldName) && fs::is_directory(oldName) && oldName!= "DATA" && oldName != "DATA/" && oldName != "data" && oldName != "data/") {
            try 
            {
                fs::path folderPath(oldName);
                std::string path = folderPath.parent_path().string();
                fs::rename(oldName, path+'/'+name);
                return "done";
            }
            catch (...) 
            {
                return "failed to rename the topic";
            }
        }
        else 
            return "path is incorrectly written or non-existent";
    }
    else
    {
        return "path should start from \"DATA\"";
    }
}

std::string OpenInEditor(const std::string& path)
{
    if (path.find("DATA") == 0 || path.find("data") == 0)
    {
        if (fs::exists(path + ".txt"))
        {
            std::string command = "notepad " + path + ".txt";
            int result = system(command.c_str());

            if (result == 0) {
                return "done";
            }
            else {
                return "failed to open the doc in the editor";
            }
        }
        else
            return "path is incorrectly written or non-existent";
    }
    else
    {
        return "path should start from \"DATA\"";
    }
}

std::string Read(const std::string& path) 
{
    if (path.find("DATA") == 0 || path.find("data") == 0)
    {
        if (fs::exists(path + ".txt")) 
        {
            std::ifstream file(path + ".txt");
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line))
                {
                    std::cout << line << std::endl;
                }
                file.close();
            }
            else
            {
                return "failed to read the doc";
            }
        }
        else
            return "path is incorrectly written or non-existent";
    }
    else
    {
        return "path should start from \"DATA\"";
    }
}