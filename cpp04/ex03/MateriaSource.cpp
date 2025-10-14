#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    // std::cout << "MateriaSource default constructor called" << std::endl;
    initInventory();
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    // std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        deleteInventory();
		initInventory();
        copyInventory(rhs);
    }
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    // std::cout << "MateriaSource destructor called" << std::endl;
    deleteInventory();
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    if (!m)
        return;
    while (i < 4 && _inventory[i])
        i++;
    if (i < 4)
	{
		std::cout << SMMAGENTA << "Learning new Materia : \"" << m->getType() << "\",	at index : " << i << RESET << std::endl;
        _inventory[i] = m;
	}
	else
	{
		std::cout << SMRED << "Inventory full capacity reached" << RESET << std::endl;
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type != "cure" && type != "ice")
	{
		std::cout << SMRED << "Error: Trying to create unknown materia : " << type << RESET << std::endl;
		return 0;
	}
    for (int i = 0; i < 4; i++)
    {
        if (i >= 0 && i < 4 && _inventory[i] && _inventory[i]->getType() == type)
		{
			std::cout << SMMAGENTA << "New Materia : \"" << type << "\"	created" << RESET << std::endl;
            return (_inventory[i]->clone());
		}
    }
    return 0;
}

void MateriaSource::initInventory(void)
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

void MateriaSource::deleteInventory(void)
{
	for (int i = 0; i < 4; i++)
    {
		if (_inventory[i])
			delete _inventory[i];
    }
}

void MateriaSource::copyInventory(const MateriaSource& src)
{
    for (int i = 0; i < 4 && src._inventory[i]; i++)
        _inventory[i] = src._inventory[i]->clone();
}

AMateria* MateriaSource::getInventory(int i)
{
    if (i >= 0 && i < 4 && _inventory[i])
        return (_inventory[i]);
    return NULL;
}
