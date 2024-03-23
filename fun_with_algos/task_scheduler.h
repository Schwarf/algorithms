//
// Created by andreas on 19.03.24.
//

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H
// You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n.
// Each cycle or interval allows the completion of one task. Tasks can be completed in any order,
// but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.
// Return the minimum number of intervals required to complete all tasks.
#include <vector>
#include <queue>

int time_needed_for_scheduling_tasks(const std::vector<char> & tasks, int minimum_intervals_between_identical_tasks)
{
	std::vector<int> frequencies(26);
	for (const auto &c: tasks) {
		frequencies[c - 'A']++;
	}
	std::priority_queue<int> q;
	for (const auto & freq: frequencies)
	{
		if(freq)
			q.push(freq);
	}
	int time{};
	while(!q.empty())
	{
		int cycle = minimum_intervals_between_identical_tasks+1;
		std::vector<int> store{};
		int task_count{};
		while(cycle-- && !q.empty())
		{
			if(q.top() > 1)
				store.push_back(q.top() -1);
			q.pop();
			task_count++;
			for( auto  x : store )
				q.push(x);
			time += (q.empty() ? task_count : minimum_intervals_between_identical_tasks+1);
		}
	}
	return time;
}

int time_needed_for_scheduling_tasks_via_sort(const std::vector<char> & tasks, int minimum_intervals_between_identical_tasks)
{
	std::vector<int> frequencies(26);
	for (const auto &c: tasks) {
		frequencies[c - 'A']++;
	}
	std::sort(frequencies.begin(), frequencies.end());
	auto max_frequency = frequencies.back() - 1; // minus one because the last one needs no cooling time
	auto idle_slots = max_frequency * minimum_intervals_between_identical_tasks;
	for(int i{24}; i >= 0 && frequencies[i] > 0; --i)
	{
		idle_slots -= std::min(max_frequency, frequencies[i]);
	}
	return idle_slots > 0 ? idle_slots + tasks.size(): tasks.size();
}


#endif //TASK_SCHEDULER_H
