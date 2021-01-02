// Each digit could be at most 200 digits long. Converting the string to integers and mutiplying wouldn't work here because of overlflow. So the code is based on digit by digit manual multiplication (the one you do by hand)
// Time Complexity - O(log(M + N)) where M and N are the numbers (OR) O(m x n) where m and n are the number of digits in each of the numbers
// Space Complexity - O(1)
​
class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1 == "0" or num2 == "0")
            return "0";
        
        int m = num1.length();
        int n = num2.length();
        int p, curr_sum, carry = 0, num_zeros = 0;
        
        string product(m + n, '0');
        
        for(int i = m - 1; i >= 0; i--) {
            p = m + n - 1 - num_zeros;
            for(int j = n - 1; j >= 0; j--) {
                curr_sum = (num1[i] - '0') * (num2[j] - '0') + (product[p] - '0') + carry; // Instead of going level by level like in manual multiplication, do all the calculations on one line
                product[p--] = (curr_sum % 10) + '0';
                carry = curr_sum / 10;                
                if((i == 0 or j == 0) and carry) {
                    product[p] = ((product[p] - '0') + carry) + '0'; // When there's nowhere to add the carry to, just put the carry one digit back
                    carry = 0; // Reset carry
                }
            }
            num_zeros++; // Used to emulate zeroes added in manual multiplication. Here it just moves p forward (or backward in terms of indices)
        }
        
        if(product[p] != '0')
            return product.substr(p, m + n); // For cases where the size of the new number is m + n 
        return product.substr(p + 1, m + n); // For cases where the size of the new number m + n - 1
    }
};
