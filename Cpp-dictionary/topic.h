#pragma once
#include "main.h"
#include <variant>
#include <vector>
#include "file.h"

class Topic
{
public:
	Topic(const std::string& topicName);
	void AddContext(File file);
	void AddContext(Topic topic);
	void Print(int tabs = 1) const;
	void ClearContext();
	std::string GetName() const;
	~Topic();

private:
	std::string name;
	std::vector<std::variant<File, Topic>> context;
};