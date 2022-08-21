//
// Created by andreas on 21.08.22.
//
#include <stack>
#include <exception>
#include <stdexcept>
class Tower{
private:
	std::stack<int> disks_;
public:

	void add(int disk)
	{
		if(!disks_.empty() && disks_.top() <= disk)
		{
			throw std::length_error("Disk to big!");
		}
		disks_.push(disk);
	}
	void move_top_to(Tower tower)
	{
		int top = disks_.top();
		tower.add(top);
		disks_.pop();
	}

	void move_disks(int number_of_disks, Tower &destination, Tower &buffer)
	{
		if (number_of_disks < 1)
			return;
		move_disks(number_of_disks-1, buffer, destination);
		move_top_to(destination);


	}
};

