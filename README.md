# Algorithms & data structures
ToDo's and open points: 
- Check if string matching in dynamic programming is covered
- Problems that use greedy, divide-and-conquer, ... are not properly tagged.
- Check-out algorithms to solve the bin-packing problem.

```
cmake --preset gcc-debug
cmake --build --preset gcc-debug -j
ctest  --preset all-gcc-debug --output-on-failure

# Or with Clang
cmake --preset clang-debug
cmake --build --preset clang-debug -j
ctest  --preset all-clang-debug
```