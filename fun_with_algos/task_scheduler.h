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

int time_needed_for_scheduling_tasks(const std::vector<char> & tasks, int n)
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
		int cycle = n+1;
		std::vector<int> store{};
		int task_count{};
		while(cycle-- && !q.empty())
		{
			if(q.top() > 1)
				store.push_back(q.top() -1);
			q.pop();
			task_count++;
			for( auto && x : store )
				q.push(x);
			time += (q.empty() ? task_count : n+1);
		}
	}
	return time;
}

#endif //TASK_SCHEDULER_H
