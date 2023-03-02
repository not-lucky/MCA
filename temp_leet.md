# leet

## array and hashing

### group_anagram

```python
class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        a = defaultdict(list)

        for s in strs:
            count = [0] * 26

            for c in s:
                count[ord(c) - ord('a')] += 1
            
            f = tuple(count)
            a[f] += [s]
        
        return a.values()
```

### top k frequent elements

```python
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        a = Counter(nums)
        return [i[0] for i in a.most_common(k)]
```

### product of array escept self

```python
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        res = [1] * len(nums)

        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
        
        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
        
        return res
```

### Valid Sudoku

```python
class Solution:

    def isValidSudoku(self, board: list[list[str]]) -> bool:
        rows = defaultdict(set)
        cols = defaultdict(set)
        squares = defaultdict(set)

        for r in range(9):
            for c in range(9):
                key = board[r][c]
                if key == '.':
                    continue
                if (key in rows[r] or key in cols[c]
                        or key in squares[r // 3, c // 3]):
                    return False

                rows[r].add(key)
                cols[c].add(key)
                squares[r // 3, c // 3].add(key)

        return True
```

### longest consecutive sequence

```python
class Solution:

    def longestConsecutive(self, nums: list[int]) -> int:
        if not nums:
            return 0
        numset = sorted(set(nums))
        longest = 0
        temp = 1
        for i, v in enumerate(numset[:-1]):
            if v == numset[i + 1] - 1:
                temp += 1
                continue
            longest = max(longest, temp)
            temp = 1
        return max(longest, temp)
```

## 2 pointers

### 3sum

```python
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        res = []
        nums.sort()

        for i, a in enumerate(nums):
            if i > 0 and a == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1
            while l < r:
                threeSum = a + nums[l] + nums[r]
                if threeSum > 0:
                    r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res

```

### Container most water (Simple 2 pointer)

```python
class Solution:
    def maxArea(self, height: list[int]) -> int:
        maxArea = 0

        l, r = 0, len(height) - 1

        while l < r:
            area = min(height[l], height[r]) * (r - l)
            maxArea = max(maxArea, area)

            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1

        return maxArea
```

### Most Rain Water (Need 2 pointers and leftMax and rightMax)

```python
class Solution:
    def trap(self, height: list[int]) -> int:
        if not height:
            return 0

        l, r = 0, len(height) - 1
        leftMax, rightMax = height[l], height[r]
        res = 0
        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                res += leftMax - height[l]
            else:   
                r -= 1
                rightMax = max(rightMax, height[r])
                res += rightMax - height[r]
        return res
```

## Sliding Window

### stock shit

```python
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        l = 0
        prof = 0

        for r in range(1, len(prices)):
            prof = max(prices[r] - prices[l], prof)
            if prices[r] < prices[l]:
                l = r
        return prof
```

### longest substring no repeat

```python
class Solution:

    def lengthOfLongestSubstring(self, s: str) -> int:
        charset = set()
        l = 0
        res = 0
        for r in range(len(s)):
            while s[r] in charset:
                charset.remove(s[l])
                l += 1
            charset.add(s[r])
            res = max(res, r - l + 1)
        return res
```

### longest repeating char replace

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        res = 0

        count = {}

        for r in range(len(s)):
            count[s[r]] = count.get(s[r], 0) + 1

            while (r - l + 1) - max(count.values()) > k:
                count[s[l]] -= 1
                l += 1

            res = max(res, r - l + 1)

        return res 
```

## tress

### invert binary

```python
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        
        root.left, root.right = root.right, root.left

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root
```

### max depth bin tree

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```

### backtracking

### subsets

```python
class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        res = [] 
        sub = []

        def back(i):
            if i >= len(nums):
                res.append(sub[:])
                return
            
            sub.append(nums[i])
            back(i+1)
            sub.pop()

            back(i+1)
        back(0)

        return res
```

### combination sum

```python
class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        res = []

        def back(i, cur, total):
            if total == target:
                res.append(cur[:])
                return
            if total > target or i >= len(candidates):
                return

            cur.append(candidates[i])
            back(i, cur, total+candidates[i])
            cur.pop()

            back(i+1, cur, total)
        
        back(0, [], 0)

        return res
```

### phone number dictionary

```python
class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        res = []
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(i, curStr):
            if len(curStr) == len(digits):
                res.append(curStr)
                return
            for c in digitToChar[digits[i]]:
                backtrack(i + 1, curStr + c)

        if digits:
            backtrack(0, "")

        return res
```

### n queens

```python
class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        col = set()
        posDiag = set()  # (r + c)
        negDiag = set()  # (r - c)

        res = []
        board = [["."] * n for i in range(n)]

        def backtrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return

            for c in range(n):
                if c in col or (r + c) in posDiag or (r - c) in negDiag:
                    continue

                col.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q"

                backtrack(r + 1)

                col.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
                board[r][c] = "."

        backtrack(0)
        return res
```