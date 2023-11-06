//
// Created by andreas on 06.11.23.
//

#ifndef SEAT_RESERVATION_MANAGER_H
#define SEAT_RESERVATION_MANAGER_H
// Design a system that manages the reservation state of n seats that are numbered from 1 to n.
//	SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n.
//	All seats are initially available.
//  int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
//  void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.
#include <vector>
#include <queue>

class SeatManager
{
private:
	std::priority_queue<int, std::vector<int>, std::greater<>> seats_available;
	int min;
public:

	SeatManager(int n)
		: min(1)
	{
	}

	int reserve()
	{
		if (!seats_available.empty()) {
			int seatNumber = seats_available.top();
			seats_available.pop();
			return seatNumber;
		}
		int seatNumber = min;
		min++;
		return seatNumber;
	}

	void unreserve(int seatNumber)
	{
		seats_available.push(seatNumber);
	}
};

#endif //SEAT_RESERVATION_MANAGER_H

