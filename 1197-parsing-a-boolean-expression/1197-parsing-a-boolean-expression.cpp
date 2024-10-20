class Solution {
public:
    bool parseBoolExpr(string expression) {
         stack<char> st;
        
        for (char ch : expression) {
            if (ch == ',' || ch == ' ') {
                // Ignore commas and spaces
                continue;
            }
            if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
                st.push(ch); // Push booleans and operators
            } else if (ch == ')') {
                vector<char> values;
                while (!st.empty() && st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop(); // Remove the opening '('
                
                char operatorChar = st.top();
                st.pop(); // Remove the operator (!, &, |)
                
                // Evaluate the expression based on the operator
                char result;
                if (operatorChar == '!') {
                    result = values[0] == 't' ? 'f' : 't';
                } else if (operatorChar == '&') {
                    result = 't';
                    for (char val : values) {
                        if (val == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } else if (operatorChar == '|') {
                    result = 'f';
                    for (char val : values) {
                        if (val == 't') {
                            result = 't';
                            break;
                        }
                    }
                }
                
                st.push(result); // Push the result back to the stack
            } else {
                st.push(ch); // Push '(' to the stack
            }
        }
        
        return st.top() == 't';
    }
};