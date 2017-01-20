# Maximum Subarray
# Devide and Conquer

def maximum_cross_subarray(arr):
    mid = len(arr) // 2
    left_max = arr[mid - 1]
    left_sum = arr[mid - 1]
    left_index = mid - 1
    i = mid - 1
    while i > 0:
        i -= 1
        left_sum += arr[i]
        if left_sum > left_max:
            left_index = i
            left_max = left_sum
    right_max = arr[mid]
    right_sum = arr[mid]
    right_index = mid
    i = mid
    while i < len(arr) - 1:
        i += 1
        right_sum += arr[i]
        if right_sum > right_max:
            right_max = right_sum
            right_index = i
    return left_max + right_max

def maximum_subarray(arr):
    if len(arr) == 1:
        if arr[0] > 0:
            return arr[0] 
        else:
            return 0
    else:
        mid = len(arr) // 2
        return max(maximum_subarray(arr[:mid]), maximum_cross_subarray(arr), maximum_subarray(arr[mid:]))


if __name__ == '__main__':
    result = maximum_subarray([13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7])
    print(result)
