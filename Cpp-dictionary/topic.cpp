#include "topic.h"
#include "global.h"

Topic::Topic(const std::string& topicName)
{
    this->name = topicName;
}

Topic::~Topic()
{
    this->name = "";
    this->context.clear();
}

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
    for (size_t i = 0; i < this->context.size(); i++)
    {
        for (size_t i = 0; i < tabs; i++)
        {
            std::cout << "   ";
        }

        if (std::holds_alternative<File>(this->context[i]))
        {
            const File& file = std::get<File>(this->context[i]);
            SetConsoleTextAttribute(global::hConsole, 8);
            std::cout <<"* " << file.GetName() << std::endl;
        }
        else if (std::holds_alternative<Topic>(this->context[i]))
        {
            SetConsoleTextAttribute(global::hConsole, 9);
            const Topic& subTopic = std::get<Topic>(this->context[i]);
            std::cout << "* ";
            subTopic.Print(tabs+1);
        }
    }
    SetConsoleTextAttribute(global::hConsole, 7);
}

void Topic::ClearContext()
{
    this->context.clear();
}

//still error here
void Topic::Search(std::vector<std::variant<File, Topic>>& results, const std::string& name) const
{
    for (size_t i = 0; i < this->context.size(); i++)
    {
        if (std::holds_alternative<File>(this->context[i]))
        {
            const File& file = std::get<File>(this->context[i]);
            if (file.GetName().find(name) >= 0 && file.GetName().find(name) < 18446744073709551615)
            {
                results.push_back(file);
            }
        }
        else if (std::holds_alternative<Topic>(this->context[i]))
        {
            const Topic& topic = std::get<Topic>(this->context[i]);
            if (topic.GetName().find(name)>= 0 && topic.GetName().find(name) < 18446744073709551615)
            {
                results.push_back(topic);
            }
            topic.Search(results, name);
        }
    }
}

std::string Topic::GetName() const { return this->name; }