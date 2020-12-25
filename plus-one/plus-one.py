class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] < 9:
            digits[-1] += 1
        else:
            carry = 1
            i = len(digits) - 1
            while i >= 0 or carry:
                cur_sum = digits[i] + carry
                digits[i] = cur_sum % 10
                carry = cur_sum // 10
                if carry and i == 0:
                    digits.insert(0, carry)
                    break
                else:
                    i -= 1
        return digits
