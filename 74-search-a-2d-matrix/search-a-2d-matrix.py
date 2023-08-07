class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        return [True] in [[True if target in i else False] for i in matrix]