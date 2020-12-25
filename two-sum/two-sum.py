class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff not in hashmap:
                hashmap[num] = i
            else:
                return [i, hashmap[diff]]
