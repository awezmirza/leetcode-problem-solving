class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        sze = len(nums)
        result = [0] * sze

        for i in range(sze):
            if (nums[i] == 0):
                result[i] = nums[i]
            else:
                curr = i
                steps = nums[i]
                if (nums[i] > 0):
                    steps = abs(steps)
                curr += steps
                curr %= sze
                result[i] = nums[curr]
        return result

