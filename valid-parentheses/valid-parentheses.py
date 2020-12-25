class Solution:
    def isValid(self, s: str) -> bool:
        openers = '({['
        closers = ')}]'
        stack = []
        for ch in s:
            if ch in openers:
                stack.append(ch)
            else:
                if len(stack) > 0 and closers.index(ch) == openers.index(stack[-1]):
                    stack.pop()
                else:
                    return False
        return len(stack) == 0
