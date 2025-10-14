#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain& src);
        Brain& operator=(const Brain& rhs);
        ~Brain(void);
        std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);

    private:
        std::string _ideas[100];
};

#endif
