add_library(sorting_lib STATIC i_sort.h selection_sort/selection_sort.cpp selection_sort/selection_sort.h
        swap.h swap.cpp ./insertion_sort/insertion_sort.h ./insertion_sort/insertion_sort.cpp
        ./merge_sort/merge_sort.cpp ./merge_sort/merge_sort.h ./shell_sort/shell_sort.cpp
        ./shell_sort/shell_sort.h quick_sort/quick_sort.cpp quick_sort/quick_sort.h
        bubble_sort/bubble_sort.cpp bubble_sort/bubble_sort.h heap_sort/heap_sort.cpp heap_sort/heap_sort.h
        counting_sort/counting_sort.h counting_sort/counting_sort.cpp upper_lower_bounds/upper_bound.h
        upper_lower_bounds/lower_bound.h merge_sort/merge_sort_linked_lists.h)