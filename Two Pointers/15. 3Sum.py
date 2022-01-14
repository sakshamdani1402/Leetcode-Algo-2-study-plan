class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res=list()
        # since  i != j, i != k, and j != k if len <3 return
        if len(nums)<3:
            return res
        # imp for sum comparison and moving pointers
        nums.sort()
        # len-2 cuz rest 2 spaces would be there for j and k
        for i in range(len(nums)-2):
            # to prevent duplicates caused due to prev elem at i
            #i>0 cuz there wouldnt be any elem before that
            if(i>0 and nums[i]==nums[i-1]):
                continue
            j,k=i+1,len(nums)-1 #setting at 2 corner points
            while(j<k):
                if(nums[i]+nums[j]+nums[k]==0):
                    res.append((nums[i],nums[j],nums[k]))
                    #to prevent duplicates for j
                    while(j<k and nums[j]==nums[j+1]):j+=1                                                     #to prevent duplicates for k
                    while(j<k and nums[k]==nums[k-1]):k-=1
                    j+=1 #normal increment
                    k-=1
                elif(nums[i]+nums[j]+nums[k]<0): # sum is less so we want a greater no
                    j+=1
                else:
                    k-=1    #sum is more so we want a lesser no
        return res