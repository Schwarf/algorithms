add_library(stacks_and_queues_lib INTERFACE
        stack_linked_list_based.h
        i_stack.h
        stack_array_based.h
        i_queue.h
        queue_linked_list_based.h
        queue_array_based.h
        lru_cache.h
        monotonic_stack/monotonic_stack.h
        longest_valid_parantheses_string.h)