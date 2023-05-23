class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        res = [-1*i for i in nums]
        heapify(res)
        while k>1:
            heappop(res)
            k-=1
        return -1*heappop(res)