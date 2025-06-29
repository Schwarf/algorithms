//
// Created by andreas on 29.06.25.
//

#ifndef MAX_PROFIT_IN_JOB_SCHEDULING_H
#define MAX_PROFIT_IN_JOB_SCHEDULING_H
// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no
// two jobs in the subset with overlapping time range.
// If you choose a job that ends at time X you will be able to start another job that starts at time X.
#include <vector>
#include <algorithm>
struct Job {
  int start;
  int end;
  int profit;
};

int find_next_job(const std::vector<Job>& jobs, int current_end)
{
  int low = 0;
  int high = jobs.size();
  while(low < high)
  {
    int mid = (low + high) / 2;
    if(jobs[mid].start >= current_end)
      high = mid;
    else
      low = mid + 1;
  }
  return low;
}

int dp(int job_index, const std::vector<Job>& jobs, std::vector<int> & memo)
{
  if (job_index >= jobs.size())
    return 0;
  if(memo[job_index] != -1)
    return memo[job_index];
  int next = find_next_job(jobs, jobs[job_index].end);
  int take_next_job = jobs[job_index].profit + dp(next, jobs, memo);
  int skip_next_job = dp(job_index + 1, jobs, memo);

  return memo[job_index] = std::max(take_next_job, skip_next_job);
}

int job_scheduling(std::vector<int>& start_time, std::vector<int>& end_time, std::vector<int>& profit)
{
     int n = start_time.size();
     std::vector<Job> jobs(n);
     for (int i = 0; i < n; i++) {
       jobs[i] = {start_time[i], end_time[i], profit[i]};
     }
     std::sort(jobs.begin(), jobs.end(), [](const Job & j1, const Job & j2) {
       return j1.start < j2.start;
     });
     std::vector<int> memo(n, -1);
     return dp(0, jobs, memo);
}
#endif //MAX_PROFIT_IN_JOB_SCHEDULING_H
