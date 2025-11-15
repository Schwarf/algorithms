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

struct Job
{
    int start;
    int end;
    int profit;
};

int find_next_job(const std::vector<Job>& jobs, int current_end)
{
    int low = 0;
    int high = jobs.size();
    while (low < high)
    {
        const int mid = (low + high) / 2;
        if (jobs[mid].start >= current_end)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

// Binary search to find the last job that doesn't overlap
int find_last_non_conflicting(const std::vector<Job>& jobs, int job_index)
{
    int low = 0;
    int high = job_index - 1;
    while (low <= high)
    {
        const int mid = (low + high) / 2;
        if (jobs[mid].end <= jobs[job_index].start)
        {
            if (jobs[mid + 1].end <= jobs[job_index].start)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }
    return -1;
}

int dp(int job_index, const std::vector<Job>& jobs, std::vector<int>& memo)
{
    if (job_index >= jobs.size())
        return 0;
    if (memo[job_index] != -1)
        return memo[job_index];
    int next = find_next_job(jobs, jobs[job_index].end);
    int take_next_job = jobs[job_index].profit + dp(next, jobs, memo);
    int skip_next_job = dp(job_index + 1, jobs, memo);

    return memo[job_index] = std::max(take_next_job, skip_next_job);
}

// top-down approach
int job_scheduling(std::vector<int>& start_time, std::vector<int>& end_time, std::vector<int>& profit)
{
    int n = start_time.size();
    if (n == 0)
        return 0;
    std::vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {start_time[i], end_time[i], profit[i]};
    }
    std::sort(jobs.begin(), jobs.end(), [](const Job& j1, const Job& j2)
    {
        return j1.start < j2.start;
    });
    std::vector<int> memo(n, -1);
    return dp(0, jobs, memo);
}

// bottom-up approach
int job_scheduling_bottom_up(std::vector<int>& start_time, std::vector<int>& end_time, std::vector<int>& profit)
{
    int n = start_time.size();
    if (n == 0)
        return 0;
    std::vector<Job> jobs(n);
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {start_time[i], end_time[i], profit[i]};
    }
    std::sort(jobs.begin(), jobs.end(), [](const Job& j1, const Job& j2)
    {
        return j1.end < j2.end;
    });
    std::vector<int> dp(n);
    dp[0] = jobs[0].profit;
    for (int job_index = 1; job_index < n; ++job_index)
    {
        int profit_if_taken = jobs[job_index].profit;

        int last_compatible_index = find_last_non_conflicting(jobs, job_index);
        if (last_compatible_index != -1)
        {
            profit_if_taken += dp[last_compatible_index];
        }

        dp[job_index] = std::max(dp[job_index - 1], profit_if_taken);
    }

    return dp[n - 1];
}


int compact_top_down(const std::vector<int> & start, const std::vector<int> & end, std::vector<int> & profit)
{
    struct Job
    {
        int s;
        int e;
        int p;
    };
    int n = start.size();
    std::vector<Job> jobs(n);
    for (int i{}; i < n; ++i)
    {
        jobs[i] = {start[i], end[i], profit[i]};
    }
    std::sort(jobs.begin(), jobs.end(), [](const Job& j1, const Job& j2){ return j1.s < j2.s; });
    std::vector<int> sorted_starts(n);
    for (int i{}; i < n; ++i)
    {
        sorted_starts[i] = jobs[i].s;
    }
    std::vector<int> memo(n ,-1);

    std::function<int(int)> dfs = [&](int i)-> int
    {
        if (i>n-1)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        int best = dfs(i+1);
        int j = int(std::lower_bound(sorted_starts.begin(), sorted_starts.end(), jobs[i].e) - sorted_starts.begin());
        best = std::max(best, jobs[i].p + dfs(j));
        return memo[i] = best;
    };
    return dfs(0);
}


int compact_bottom_up(const std::vector<int> & start, const std::vector<int> & end, std::vector<int> & profit)
{
    struct Job
    {
        int s;
        int e;
        int p;
    };
    int n = start.size();
    std::vector<Job> jobs(n);
    for (int i{}; i < n; ++i)
    {
        jobs[i] = {start[i], end[i], profit[i]};
    }
    std::sort(jobs.begin(), jobs.end(), [](const Job& j1, const Job& j2){ return j1.e < j2.e; });

    std::vector<int> sorted_ends(n);
    for (int i{}; i < n; ++i)
    {
        sorted_ends[i] = jobs[i].e;
    }
    auto pred = [&](int i)-> int
    {
        return int(std::upper_bound(sorted_ends.begin(), sorted_ends.end(), jobs[i].s) - sorted_ends.begin()) - 1;
    };
    std::vector<int> dp(n+1, 0);
    for (int i{}; i <= n; ++i)
    {
        int j =pred(i-1);
        int take = jobs[i-1].p + dp[j+1];
        dp[i] = std::max(dp[i-1], take);
    }
    return dp[n];
}

#endif //MAX_PROFIT_IN_JOB_SCHEDULING_H
