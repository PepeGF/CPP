#pragma once
#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(std::string* ideas);
    Brain(Brain const &copy);
    virtual ~Brain();

    Brain& operator=(Brain const &rhs);

    void setIdeas(std::string idea);
    std::string getIdea(const int i);
};

