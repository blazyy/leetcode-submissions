class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        idx_counts = {}
        for i in range(len(nums)):
            idx_counts[i] = 0
            for j in range(len(nums)):
                if nums[j] < nums[i]:
                    idx_counts[i] += 1
        counts = []
        for i in range(len(nums)):
            counts.append(idx_counts[i])
        return counts
        
