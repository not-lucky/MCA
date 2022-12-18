def maximumSubarraySum(arr):
    n = len(arr)
    maxSum = -1e8
    currSum = 0

    for i in range(0, n):
        currSum = currSum + arr[i]
        if (currSum > maxSum):
            maxSum = currSum
        if (currSum < 0):
            currSum = 0

    return maxSum


if __name__ == "__main__":
    # Your code goes here
    print(maximumSubarraySum([-2, -5, -1, -3, -8, -2, -6, -8, -5]))
