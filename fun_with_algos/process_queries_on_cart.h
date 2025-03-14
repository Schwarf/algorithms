//
// Created by andreas on 14.03.25.
//

#ifndef PROCESS_QUERIES_ON_CART_H
#define PROCESS_QUERIES_ON_CART_H
// Build a prototype for a cart management service.
// An array of integers, items, represents the item ids in the cart initially.
// Given another array of q integers, query, your service must perform as follows.
//
//    Each integer is an item id to be added to or removed from the cart.
//    If the query integer is positive, add the integer representing an item id to the back of the cart.
//    If the query integer is negative, remove the first occurrence of the integer from the cart.
//    List the final items present in the cart after all the queries are completed.
//    It is safe to assume that the cart will not end up empty. The queries only ask for removal of items that are present in the cart. There is no 0 in array query.
// Function Description
// Complete the function processQueriesOnCart in the editor below.
// processQueriesOnCart has the following parameters:
//    int items[n] : items initially in the cart
//    int query[q] : items to add or remove
#include <list>
#include <vector>
std::vector<int> process_queries_on_cart(const std::vector<int> & items, const std::vector<int> & queries)
{
    std::list cart(items.begin(), items.end());
    for (const auto query: queries)
    {
        if (query > 0)
            cart.push_back(query);
        else
        {
            int target = -query;
            for (auto it = cart.begin(); it != cart.end(); ++it)
            {
                if (*it == target)
                {
                    cart.erase(it);
                    break;
                }
            }
        }
    }
    return std::vector<int>(cart.begin(), cart.end());
}


#endif //PROCESS_QUERIES_ON_CART_H
