#pragma once
#include "main.h"
#include <variant>
#include <vector>
#include "file.h"

class Topic
{
public:
	Topic(const std::string& topicName, const std::string& topicPath);
	void AddContext(File file);
	void AddContext(Topic topic);
	void Print(int tabs = 1) const;
	void ClearContext();
	void Search(std::vector<std::variant<File, Topic>>& results, const std::string& name) const;
	std::string GetName() const;
	std::string GetPath() const;
	~Topic();

private:
	std::string name;
	std::string path;
	std::vector<std::variant<File, Topic>> context;
};