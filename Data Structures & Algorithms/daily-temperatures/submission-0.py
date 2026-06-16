class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stack = []
        for i, val in enumerate(temperatures):
            while stack and stack[-1][0] < val:
                sV , sI = stack.pop()
                res[sI] = (i - sI)
            stack.append([val, i])
        return res