#pragma once
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(std::string* ideas);
    Brain(const Brain &copy);
    virtual ~Brain();

    Brain& operator=(const Brain &rhs);

    void setIdeas(std::string idea);
    std::string getIdea(const int i);
};

