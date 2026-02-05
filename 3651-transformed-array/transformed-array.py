class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        sze = len(nums)
        result = []

        for i in range(0, sze):
            if (nums[i] == 0):
                result.append(nums[i])
            else:
                curr = i
                steps = nums[i]
                if (nums[i] > 0):
                    steps = abs(steps)
                curr += steps
                curr %= sze
                result.append(nums[curr])
        return result

