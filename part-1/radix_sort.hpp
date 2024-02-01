#ifndef __radix_sort__
#define __radix_sort__

#include <algorithm>
#include <limits>
#include <cmath>

template <typename I>
static constexpr int num_digits_v =
    std::numeric_limits<typename I::value_type>::digits;

template <typename I>
void counting_sort_for_radix(I begin, I end, int exp) {
    std::vector<typename I::value_type> output(std::distance(begin, end));
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (I it = begin; it != end; ++it) {
        count[(*it / exp) % 10]++;
    }

    // Change count so that count now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (I it = end - 1; it >= begin; --it) {
        output[count[(*it / exp) % 10] - 1] = *it;
        count[(*it / exp) % 10]--;
    }

    // Copy the output array to original array
    std::copy(output.begin(), output.end(), begin);
}

template <typename I>
void radix_sort(const I &begin, const I &end,
                int digit = num_digits_v<I>)
{
    // Find the maximum number to know the number of digits
    typename I::value_type maxVal = *std::max_element(begin, end);
    
    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        counting_sort_for_radix(begin, end, exp);
    }
}

#endif // __radix_sort__
