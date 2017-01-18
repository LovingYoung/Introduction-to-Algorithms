def selection_sort(arr):
    i = 0
    while i < len(arr) - 1:
        j = i
        min = -1
        min_value = None
        while  j < len(arr):
            if min_value is None or arr[j] < min_value:
                min = j
                min_value = arr[j]
            j += 1
        arr[min] = arr[i]
        arr[i] = min_value
        i += 1
    return arr

if __name__ == '__main__':
    result = selection_sort([3,2,4,5,1,6,3,7])
    print(result)
