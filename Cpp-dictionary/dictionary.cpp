#include "dictionary.h"
#include <filesystem>
#include "file.h"
#include "explorer.h"
#include "global.h"
namespace fs = std::filesystem;


bool LoadList(Topic& mainTopic, const std::string& path)
{
	if (fs::exists("DATA"))
	{
		std::vector<File> files;
		std::vector<Topic> topics;
		files = GetFilesInDir(path);
		topics = GetDirsInDir(path);
		for (size_t i = 0; i < files.size(); i++)
		{
			mainTopic.AddContext(files[i]);
		}
		for (size_t i = 0; i < topics.size(); i++)
		{
			LoadList(topics[i], path + '/' + topics[i].GetName());
			mainTopic.AddContext(topics[i]);
		}
		return true;
	}
	else
	{
		if (fs::create_directory("DATA"))
			return true;
		else
			return false;
	}
}