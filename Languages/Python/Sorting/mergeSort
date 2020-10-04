def mergeSort(nums):
    if len(nums)<=1:
        return nums

    mid = len(nums)//2
    left = nums[:mid]
    right = nums[mid:]

    left = mergeSort(left)
    right = mergeSort(right)

    block = []
    l = r = 0

    while l < len(left) and r < len(right):
        if left[l] < right[r]:
            block.append(left[l])
            l += 1
        else:
            block.append(right[r])
            r += 1

    if l < len(left):
        block += left[l:]
    elif r < len(right):
        block += right[r:]
    return block


nums = []

print('Enter the size of list: ')
n = int(input())

print('Enter the elements of list: ')
for _ in range(n):
    nums.append(int(input()))

sortedList = mergeSort(nums)
print('Sorted list is {}'.format(sortedList))
