from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            if not self.isValidColumn(i, board):
                return False
            if not self.isValidRow(i, board):
                return False
        
        for i in range(0, 3):
            for j in range(0, 3):
                if not self.isValidSquare(i*3, j*3, board):
                    return False

        return True

    def isValidColumn(self, col, board):
        nums = set()
        for i in range(0, 9):
            if board[i][col] != '.':
                    if board[i][col] in nums:
                        return False
                    else:
                        nums.add(board[i][col])
        return True

    def isValidRow(self, row, board):
        nums = set()
        for i in range(0, 9):
            if board[row][i] != '.':
                    if board[row][i] in nums:
                        return False
                    else:
                        nums.add(board[row][i])
        return True


    def isValidSquare(self, x, y, board):
        nums = set()
        for i in range(0, 3):
            for j in range(0, 3):
                print(nums)
                if board[x+i][y+j] != '.':
                    if board[x+i][y+j] in nums:
                        return False
                    else:
                        nums.add(board[x+i][y+j])
        return True