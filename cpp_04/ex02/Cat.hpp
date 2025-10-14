#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		~Cat(void);
		void makeSound(void) const;
		Brain* getBrain(void) const;
		
	private:
		Brain*  _brain;
};

#endif
