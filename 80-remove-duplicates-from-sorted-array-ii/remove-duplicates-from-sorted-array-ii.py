class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        # If the array has 2 or fewer elements, it already satisfies the condition
        if len(nums) <= 2:
            return len(nums)
        
        # 'write_index' points to where the next valid element should be placed
        write_index = 2
        
        # Iterate through the array starting from the 3rd element
        for i in range(2, len(nums)):
            # Compare current element with the element two positions behind the write pointer
            if nums[i] != nums[write_index - 2]:
                nums[write_index] = nums[i]
                write_index += 1
                
        return write_index
