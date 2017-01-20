"""
1. Sort the set S. T(S1) = O(nlgn)
2. For every n, find x - n in S. T(S2) = n * O(lgn)
"""

import C_2_3_1
import P_2_3_5

def find_elements(s, x):
    result = []
    arr = C_2_3_1.merge_sort(list(s))
    i = 0
    length = len(arr)
    while i < length:
        j = P_2_3_5.binary_search(arr, x - arr[i])
        if j is not None and j != i:
            result.append((i, j))
        i += 1
    return result

if __name__ == '__main__':
    result = find_elements({3,1,4,6,2,5,9}, 13)
    print(result)
