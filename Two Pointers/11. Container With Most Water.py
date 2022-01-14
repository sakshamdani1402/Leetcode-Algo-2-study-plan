class Solution:
    def maxArea(self, height: List[int]) -> int:
#       setting 2 pointers at extreme indexes
        left,right=0,len(height)-1
        # init max area
        maxArea=0
        # iterate while l<r as when both become equal they wont trap an water
        while(left<right):
            # max area is max of current area or width * min height of 2 pointers
            maxArea=max(maxArea,min(height[left],height[right])*(right-left))
            # increment the pointer with lesser height as we want to find
            # next height which could result in greater area and is greater than current                    height
            if(height[left]<height[right]):
                left+=1
            else:   right-=1
        return maxArea
            
        