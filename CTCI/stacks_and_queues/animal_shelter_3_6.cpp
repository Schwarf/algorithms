//
// Created by andreas on 10.04.22.
//
#include <list>
#include <stdexcept>
#include <iostream>

struct Animal
{
	bool is_dog;
	Animal() = delete;
	int order{};
	explicit Animal(bool is_a_dog, int ord)
	{
		is_dog = is_a_dog;
		order = ord;
	}
};

class Shelter{
private:
	std::list<Animal> shelter;
	bool has_dogs_{false};
	bool has_cats_{false};
public:
	void push(const Animal & animal)
	{
		if(animal.is_dog)
		{
			has_dogs_ = true;
		}
		if(!animal.is_dog)
		{
			has_cats_ = true;
		}
		shelter.push_front(animal);
	}

	Animal dequeueDog()
	{
		if(!has_dogs_ || shelter.empty())
		{
			throw std::invalid_argument("No dogs in shelter");
		}
		if(shelter.back().is_dog) {
			auto animal = shelter.back();
			shelter.pop_back();
			return animal;
		}
		auto it = shelter.rbegin();
		while( it != shelter.rend() ) {
			auto is_dog = (*it).is_dog;
			if (is_dog){
				auto animal = *it;
				it++;
				shelter.erase(it.base());
				return animal;
			}
			it++;
		}
	}

	Animal dequeueCat()
	{
		if(!has_cats_ || shelter.empty())
		{
			throw std::invalid_argument("No cats in shelter");
		}
		if(!shelter.back().is_dog) {
			auto animal = shelter.back();
			shelter.pop_back();
			return animal;
		}
		auto it = shelter.rbegin();
		while( it != shelter.rend() ) {
			auto is_dog = (*it).is_dog;
			if (!is_dog){
				auto animal = *it;
				it++;
				shelter.erase(it.base());
				return animal;
			}
			it++;
		}
	}

	Animal dequeueAny()
	{
		if(shelter.empty())
		{
			throw std::invalid_argument("Shelter is empty");
		}
		auto animal = shelter.back();
		shelter.pop_back();
		return animal;
	}


};



int main()
{
	auto dog1 = Animal(true, 1);
	auto dog2 = Animal(true, 2);
	auto dog3 = Animal(true, 3);
	auto dog4 = Animal(true, 4);
	auto cat1 = Animal(false, 1);
	auto cat2 = Animal(false, 2);
	auto cat3 = Animal(false, 3);
	auto cat4 = Animal(false, 4);
	auto shelter = Shelter();
	shelter.push(dog1);
	shelter.push(dog2);
	shelter.push(cat1);
	shelter.push(dog3);
	shelter.push(dog4);
	shelter.push(cat2);
	shelter.push(cat3);
	shelter.push(cat4);

	std::cout << shelter.dequeueDog().order << std::endl;
	std::cout << shelter.dequeueCat().order << std::endl;
	std::cout << shelter.dequeueAny().order << std::endl;

	return 0;

}