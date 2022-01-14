class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        res=[]
#       if any one of the list is empty there cannot be any intersection
#       so return empty list
        if(not firstList or not secondList):
            return res
        
        i,j=0,0
#       traverse until any one ends cuz there cannot be any intersection if 1 list ended
        while(i<len(firstList) and j<len(secondList)):
#       find the starting point of the intersection
            startPoint = max(firstList[i][0],secondList[j][0])
#       find the endpoint of intersection
            endPoint =  min(firstList[i][1],secondList[j][1])
#       intersection can only happen if start point is less or equal to endpoint
#       if there is a intersection then append it into result list
            if(startPoint<=endPoint):
                res.append([startPoint,endPoint])
#           if endpoint of 1st list is smaller then it cannot form further intersections
#           so increment i and move to the next elem in 1st list
            if firstList[i][1]<secondList[j][1]: i+=1
#           else move ahead in second list
            else: j+=1
        
        return res
        
        