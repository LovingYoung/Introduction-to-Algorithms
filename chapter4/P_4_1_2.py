# Maximum Subarray (Brute-Force)

def maximum_subarray(arr):
    brr = [0]
    for i in arr:
        brr.append(brr[-1]+i)
    i = 0
    max_left = 0
    max_right = 0
    max_val = 0
    while i < len(brr):
        j = i
        while j < len(brr):
            if i != j and brr[j] - brr[i] > max_val:
                max_val = brr[j] - brr[i]
                max_left = i
                max_right = j
            j += 1
        i += 1
    return (max_left, max_right, max_val)

if __name__ == '__main__':
    result = maximum_subarray([13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7])
    print(result)
