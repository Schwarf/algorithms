Notes:  
Probabilistic algorithms covered so far
- Reservoir sampling
- Simulated annealing

Reservoir sampling is tested statistically. 

Simulated annealing is tested against travelling salesman problem and compared 
to the exact solution using implementation of Held-Karp algorithm. Two versions of 
simulated annealing are implemented. The second one uses one function template
that receives all needed functors (perturbation function, object function ...).

ToDo's: 
- Reservoir smapling is not really tested on large datasets
- Other applications of simulated annealing need to be tested e.g. knapsack problem.
- Probably the current "concept overloaded" implementation of simulated annealing is not suitable for these cases.
- Many more probabilistic algorithms are missing: Bloom filter, Monte Carlo, Genetic algorithms... reimplement Lepage's VEGAS? 


