"""
define the bit in index of 0 is the lowest bit
"""
def add_binary_numbers(arr1, arr2):
    len1 = len(arr1)
    len2 = len(arr2)
    result = []
    i = 0
    carry = 0
    while i < max(len1, len2):
        if i < len1 and i < len2:
            result.append(arr1[i] + arr2[i] + carry)
            if result[-1] > 1:
                result[-1] -= 2
                carry = 1
            else:
                carry = 0
        if i < len1 and i >= len2:
            result.append(arr1[i] + carry)
            if result[-1] > 1:
                result[-1] -= 2
                carry = 1
            else:
                carry = 0
        if i >= len1 and i < len2:
            result.append(arr2[i] + carry)
            if result[-1] > 1:
                result[-1] -= 2
                carry = 1
            else:
                carry = 0
        i += 1
    if carry > 0:
        result.append(carry)
    return result

if __name__ == '__main__':
    print(add_binary_numbers([1,0,1], [1, 0, 1]))
