def insertion_sort_recursive(arr, n):
    # arr[n] is the last element of the sorted list
    if len(arr) - 1 == n:
        return arr
    else:
        key = arr[n+1]
        i = n
        while i >= 0:
            if key < arr[i]:
                arr[i+1] = arr[i]
                i -= 1
            else:
                arr[i+1] = key
                break
        if i == -1:
            arr[0] = key
        return insertion_sort_recursive(arr, n+1)

def insertion_sort(arr):
    return insertion_sort_recursive(arr, 0)

if __name__ == '__main__':
    result = insertion_sort([6,3,1,4,5,2,1])
    print(result)
