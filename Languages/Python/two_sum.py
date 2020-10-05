def two_sum(nums, k):
    if not nums:
        return False

    ht = {}

    for i in range(len(nums)):
        if nums[i] in ht:
            return [ht[nums[i]], i]

        else:
            ht[k - nums[i]] = i
    return False


print(two_sum([10, 15, 3, 7], 17))
