class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        bool carry = false;

        for (int i = s.size() - 1; i > 0; --i) {
            
            char bit = s[i]; 
            if (carry) {
                
                if (bit == '0') {
                    bit = '1';
                   
                    carry = false;
                } else
                    bit = '0';
            }

           
            if (bit == '1') {
                
                ++steps;
               
                carry = true;
            }
            
            ++steps;
        }

        
        if (carry) ++steps;

       
        return steps;
        
    }
};