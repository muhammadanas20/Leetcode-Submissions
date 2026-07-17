class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int sum = 0;

        for (int num : nums) {
            // Handle negative numbers if applicable, or process magnitude
            int temp = std::abs(num); 
            
            int minDigit = 9;
            int maxDigit = 0;
            
            // Extract digits to find the range
            if (temp == 0) {
                minDigit = 0;
                maxDigit = 0;
            } else {
                while (temp > 0) {
                    int digit = temp % 10;
                    if (digit < minDigit) minDigit = digit;
                    if (digit > maxDigit) maxDigit = digit;
                    temp /= 10;
                }
            }
            
            int currentRange = maxDigit - minDigit;
            
            // Track the maximum range and update the sum dynamically
            if (currentRange > maxRange) {
                maxRange = currentRange;
                sum = num; // Reset sum to the new max-range element
            } else if (currentRange == maxRange) {
                sum += num; // Add to existing sum
            }
        }
        
        return sum;
    }
};