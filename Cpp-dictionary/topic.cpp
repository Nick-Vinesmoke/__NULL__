#include "topic.h"

Topic::Topic(const std::string& topicName)
{
    this->name = topicName;
}

Topic::~Topic()
{}

void Topic::AddContext(File file) 
{
    this->context.push_back(file);
}

void Topic::AddContext(Topic topic)
{
    this->context.push_back(topic);
}

std::string Topic::GetName() { return this->name; }