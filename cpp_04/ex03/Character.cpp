#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void): _floor(NULL),  _name("NoName")
{
	// std::cout << "Character default constructor called" << std::endl;
	initInventory();
}

Character::Character(std::string const &name): _floor(NULL), _name(name)
{
	// std::cout << "Character constructor called with name : " << name << std::endl;
	initInventory();
}

Character::Character(const Character& src): ICharacter(src)
{
	// std::cout << "Character copy constructor called" << std::endl;
	_floor = NULL;
	initInventory();
	*this = src;
}

Character& Character::operator=(const Character& rhs)
{
	// std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		deleteInventory();
		initInventory();
		copyInventory(rhs);
		cleanFloor();
		copyFloor(rhs._floor);
	}
	return *this;
}

Character::~Character(void)
{
	// std::cout << "Character destructor called" << std::endl;
	cleanFloor();
	deleteInventory();
}

void Character::initInventory(void)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if (!m)
	{
		std::cout << SMRED << "Error: Trying to equip with unexisting materia" << RESET << std::endl;
		return;
	}
	while (i < 4 && _inventory[i])
	{
		if (_inventory[i] == m)
		{
			std::cout << SMMAGENTA << "Materia : \"" << m->getType() << " is already in invetory !" << RESET << std::endl;
			return;
		}
		i++;
	}
	if (i < 4)
	{
		std::cout << SMMAGENTA << _name << " added materia : \"" << m->getType() << "\" to it's inventory" << RESET << std::endl;
		_inventory[i] = m;
	}
	else
	{
		std::cout << SMRED << "Inventory full capacity reached" << RESET << std::endl;
		delete m;
	} 
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && _inventory[idx])
	{
		std::cout << SMMAGENTA << _name << " dropped Materia \"" << _inventory[idx]->getType() << "\" at index : " << idx << RESET << std::endl;
		addToFloor(_inventory[idx]);
		shiftTabLeft(idx);
	}
	else
		std::cout << SMRED << "Error: No materia at index : " << idx << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << SMRED << "No materia at index : " << idx << RESET << std::endl;

}

void Character::addToFloor(AMateria* m)
{
	t_floor* newNode = new t_floor;
	newNode->ptr = m;
	newNode->next = NULL;

	if (!_floor)
		_floor = newNode;
	else
	{
		t_floor* tmp = _floor;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newNode;
	}
}

void Character::shiftTabLeft(int idx)
{
	for (int i = idx; i < 3; i++)
		_inventory[i] = _inventory[i + 1];
	_inventory[3] = NULL;
}

void Character::deleteInventory(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void Character::cleanFloor(void)
{
	t_floor* tmp ;
	t_floor* head = _floor ;

	if (!head)
		return;
	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp->ptr;
		delete tmp;
	}
}

void Character::copyFloor(t_floor* src)
{
	while (src)
	{
		AMateria *copy = src->ptr->clone();
		addToFloor(copy);
		src = src->next;
	}
}

void Character::copyInventory(const Character& src)
{
	for (int i = 0; i < 4 && src._inventory[i]; i++)
		_inventory[i] = src._inventory[i]->clone();
}
