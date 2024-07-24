class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def f(x):
            s=str(x)
            r=0
            for c in s:
                r*=10
                r+=mapping[int(c)]
            return r
        nums.sort(key=f)
        
        return nums
        
