class Solution:
    def resultArray(self, nums: list[int]) -> list[int]:
        # Step 1: Initialize arr1 and arr2 with the first two elements
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        
        # Step 2: Iterate through the rest of the array starting from index 2
        for i in range(2, len(nums)):
            # Compare the last elements of both arrays
            if arr1[-1] > arr2[-1]:
                arr1.append(nums[i])
            else:
                arr2.append(nums[i])
                
        # Step 3: Return the concatenated result
        return arr1 + arr2
