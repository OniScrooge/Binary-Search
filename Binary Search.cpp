#include <array>
#include <cassert>
#include <iostream>
#include <numeric> // for std::midpoint

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max)
{
    assert(array); // make sure array exists

    while (min <= max)
    {
        // implement this iteratively
        int midpoint{ std::midpoint(min, max) };
        // Before C++20
        // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

        if (array[midpoint] > target)
        {
            // if array[midpoint] > target, then we know the number must be in the lower half of the array
            // we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
            max = midpoint - 1;
        }
        else if (array[midpoint] < target)
        {
            // if array[midpoint] < target, then we know the number must be in the upper half of the array
            // we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
            min = midpoint + 1;
        }
        else
        {
            return midpoint;
        }
    }

    return -1;
}

int binaryRecursiveSearch(const int* array, int target, int min, int max)
{
    assert(array); // make sure array exists

    // implement this recursively

    if (min > max)
        return -1;

    int midpoint{ std::midpoint(min, max) };
    // Before C++20
    // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

    if (array[midpoint] > target)
    {
        return binaryRecursiveSearch(array, target, min, midpoint - 1);
    }
    else if (array[midpoint] < target)
    {
        return binaryRecursiveSearch(array, target, midpoint + 1, max);
    }
    else
    {
        return midpoint;
    }
}

int main()
{
    constexpr int x[]{3, 6, 7, 9, 12, 15, 18, 21, 24};

    std::cout << binaryRecursiveSearch(x, 7, 0, 8) << ' ' << binarySearch(x, 7, 0, 8);
    return 0;
}