#include <iostream>
#include <fstream>

# define RESET "\033[0m"
# define RED "\033[1;31m"

void    replaceFunc(std::ifstream& myFile, std::ofstream& myReplace, std::string to_find, std::string replace)
{
    std::string line;
    std::string tmp;
    std::size_t pos;

    while (getline(myFile,line))
    {
        pos = 0;
        tmp = line;
        while ((pos = tmp.find(to_find, pos)) != std::string::npos)
        {
            tmp.erase(pos, to_find.size());
            tmp.insert(pos, replace);
            pos += replace.size();
        }
        myReplace << tmp << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << RED << "Error: please follow this format : <filename> <string_to_replace> <string_to_replace_with>" << RESET << std::endl;
        return 1;
    }

    if (!av[1] || !av[2])
    {
        std::cout << RED << "Error: <filename> and <string_to_replace> cannot be empty" << RESET << std::endl;
        return 1;
    }
    std::ifstream myFile(av[1]);
    std::string filename = av[1];
    std::string addReplace = filename + ".replace";
	
    if (!myFile.is_open())
    {
        std::cout << RED << "Error: \"" << av[1] << "\" is not a valid file" << RESET << std::endl;
        return 1;
    }

    std::ofstream myReplace(addReplace.c_str());

    replaceFunc(myFile, myReplace, av[2], av[3]);
    myFile.close();
    myReplace.close();
    return 0;
}
