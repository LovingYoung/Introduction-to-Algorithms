def naive_searching(arr, key):
    i = 0
    while i < len(arr):
        if arr[i] == key:
            return i
        i += 1
    return None

if __name__ == '__main__':
    print(naive_searching([1,2,3,4,5], 6))
