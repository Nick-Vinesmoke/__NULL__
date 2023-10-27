#include "topic.h"
#include "global.h"

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

void Topic::Print(int tabs) const
{
    SetConsoleTextAttribute(global::hConsole, 9);
    std::cout << this->name << '\n';
    for (size_t i = 0; i < context.size(); i++)
    {
        for (size_t i = 0; i < tabs; i++)
        {
            std::cout << "   ";
        }

        if (std::holds_alternative<File>(context[i]))
        {
            const File& file = std::get<File>(context[i]);
            SetConsoleTextAttribute(global::hConsole, 8);
            std::cout <<"* " << file.GetName() << std::endl;
        }
        else if (std::holds_alternative<Topic>(context[i]))
        {
            SetConsoleTextAttribute(global::hConsole, 9);
            const Topic& subTopic = std::get<Topic>(context[i]);
            std::cout << "* ";
            subTopic.Print(tabs+1);
        }
    }
    SetConsoleTextAttribute(global::hConsole, 7);
}

std::string Topic::GetName() const { return this->name; }