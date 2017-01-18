# Binary Search
# Note: the right side of range is impossible.

def binary_search(arr, key):
    left = 0
    right = len(arr)
    while right - left > 1:
        mid = (left + right) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            left = mid + 1
        else:
            right = mid
    # right - left == 1
    if arr[left] == key:
        return left
    else:
        return None

if __name__ == '__main__':
    result = binary_search([1,4,6,7,8,12,51,52,63], 8)
    print(result)
