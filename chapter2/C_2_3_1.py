# Divide and Conquer
# Merge Sort

def merge_sort(arr):
    length = len(arr)
    if length == 1:
        return arr
    else:
        left = merge_sort(arr[:length//2])
        right = merge_sort(arr[length//2:])
        result = []
        i = 0
        j = 0
        len_left = len(left)
        len_right = len(right)
        while i < len_left and j < len_right:
            if left[i] > right[j]:
                result.append(right[j])
                j += 1
            else:
                result.append(left[i])
                i += 1
        if i == len_left:
            while j < len_right:
                result.append(right[j])
                j += 1
        else:
            while i < len_left:
                result.append(left[i])
                i += 1
        return result

def main():
    print(merge_sort([3,4,5,2,1,4,6,4,6,2,6,7,8,5,2,12,31,52,5]))

if __name__ == '__main__':
    main()
