### Dynamic Programming

Optimization problems belong to the most challenging algorithmic problems. Best example, travelling salesman
problem (TSP). It is easy to "propose" algorithm that generate reasonable-looking solutions (for TSP) but do not
always produce the minimum cost tour.
Algorithms for optimization problems require proof that they always return the best possible solution.

1. Greedy algorithms: Make the best local decision at each step but usually do not guarantee global optimality.
2. Exhaustive search algorithms: Try all possibilities and select the best always produce the optimum result, but
   usually at a prohibitive cost in terms of time complexity.

Dynamic programming combines the best of both worlds: Searching all possibilities and storing results to avoid
recomputing. By storing the consequences of all possible decisions and using this information in a systematic way,
the total amount of work is minimized.

Dynamic programming is a technique for efficiently implementing a recursive algorithm by storing partial results.
The trick is seeing whether the naive recursive algorithm computes the same sub-problems over and over again. If
so storing the answer for each sub-problem in a table to look-up instead of recompute can lead to an efficient
algorithm.
