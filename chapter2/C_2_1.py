def insertion_sort(arr):
    i = 1
    while i < len(arr):
        val = arr[i]
        j = i - 1 
        while j >= 0:
            if arr[j] <= val:
                arr[j+1] = val
                break
            else:
                arr[j+1] = arr[j]
            if j == 0:
                arr[0] = val
            j -= 1
        i += 1
    return arr

if __name__ == '__main__':
    result = insertion_sort([6,5,4,3,3,3,3,2,1])
    print(result)
