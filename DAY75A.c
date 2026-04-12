def longest_zero_sum_subarray(arr):
    prefix_sum = 0
    max_length = 0
    sum_map = {}

    for i in range(len(arr)):
        prefix_sum += arr[i]

     
        
        if prefix_sum == 0:
            max_length = i + 1

        
        if prefix_sum in sum_map:
            max_length = max(max_length, i - sum_map[prefix_sum])
        else:
            sum_map[prefix_sum] = i

    return max_length



arr = [15, -2, 2, -8, 1, 7, 10, 23]


print(longest_zero_sum_subarray(arr))