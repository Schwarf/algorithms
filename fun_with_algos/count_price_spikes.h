//
// Created by andreas on 13.03.25.
//

#ifndef COUNT_PRICE_SPIKES_H
#define COUNT_PRICE_SPIKES_H

//Count Spikes
// A k-Spike is an element that satisfies both the following conditions:
// There are at least k elements from indices (0, i-1) that are less than prices[i] .
// There are at least k elements from indices (i+1, n-1) that are less than prices[i].
// Count the number of k-Spikes in the given array.
#include <queue>
#include <set>
#include <vector>
int count_spikes(std::vector<int> & prices, int k)
{
  int n = prices.size();
  if( k > n/2)
      return 0;
  // sliding window
  int spike_count{};
  for(int i = k; i <n-k; ++i)
  {
      int count_below{};
     for(int j{}; j < i; ++j)
      {
           if(prices[j] < prices[i])
             count_below++;
           if(count_below == k)
             break;
      }
      int count_above{};
      for(int j{i+1}; j < n; ++j)
      {
          if(prices[j] < prices[i])
              count_above++;
          if(count_above == k)
              break;
      }
      if(count_below == k && count_above == k)
        spike_count++;

  }
  return spike_count;
}

int count_spikes_optimized(std::vector<int> & prices, int k)
{
    int n = prices.size();
    if (k > n / 2) return 0;

    std::multiset<int> left, right;

    // Populate the right multiset initially
    for (int i = k; i < n; ++i)
        right.insert(prices[i]);

    for (int i = 0; i < k; ++i) {
        left.insert(prices[i]);
    }

    int spike_count = 0;

    for (int i = k; i < n - k; ++i) {
        if (i > k) {
            // Shift window: move prices[i-1] from right to left
            auto it = right.find(prices[i - 1]);
            if (it != right.end())
                right.erase(it);  // Ensure element exists before erasing
            left.insert(prices[i - 1]);
        }

        // Count elements less than prices[i] in left and right
        int count_below = std::distance(left.begin(), left.lower_bound(prices[i]));
        int count_above = std::distance(right.begin(), right.lower_bound(prices[i]));

        if (count_below >= k && count_above >= k)
            spike_count++;
    }

    return spike_count;
}

#endif //COUNT_PRICE_SPIKES_H
