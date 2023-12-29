//
// Created by andreas on 29.12.23.
//

#ifndef MINIMUM_DIFFICULTY_JOB_SCHEDULE_H
#define MINIMUM_DIFFICULTY_JOB_SCHEDULE_H
#include <vector>
#include <algorithm>
#include <numeric>
// You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job,
// you have to finish all the jobs j where 0 <= j < i).
// You have to finish at least one task every day. The difficulty of a job schedule is the sum of
// difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.
// You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
// Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.

int min_difficulty_job_schedule(const std::vector<int> &jobDifficulty, int d)
{
	int n = jobDifficulty.size();
	if (n < d)
		return -1;
	if (n == d)
		return std::accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(d + 1, 1000000));
	dp[0][0] = 0;
	for (int day{1}; day <= d; ++day) {
		for (int i{day}; i <= n; ++i) {
			int maxDiff = 0;
			for (int k = i; k >= day; --k) {
				maxDiff = std::max(maxDiff, jobDifficulty[k - 1]);
				dp[i][day] = std::min(dp[i][day], dp[k - 1][day - 1] + maxDiff);
			}
		}
	}
	return dp[n][d];
}

#endif //MINIMUM_DIFFICULTY_JOB_SCHEDULE_H
