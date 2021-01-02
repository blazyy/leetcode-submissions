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
            for(int j = n - 1; j >=0; j--) {
                curr_sum = (num1[i] - '0') * (num2[j] - '0') + (product[p] - '0') + carry;
                product[p--] = (curr_sum % 10) + '0';
                carry = curr_sum / 10;                
                if((i == 0 or j == 0) and carry) {
                    product[p] = ((product[p] - '0') + carry) + '0'; // At last digit, where there's nowhere to add the carry to.
                    carry = 0;
                }
            }
            num_zeros++;
        }
        if(product[p] != '0')
            return product.substr(p, m + n);
        return product.substr(p + 1, m + n);
    }
};
