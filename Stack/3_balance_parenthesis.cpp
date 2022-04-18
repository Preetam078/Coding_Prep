//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    stack<int>st;
    bool isValid(string s) {
         
            for( int i = 0; i < s.length(); i++){
                    char ch = s.at(i);

                    //step1: if open symbols
                    if(ch == '(' || ch == '[' || ch == '{'){
                            st.push(ch);
                    }
                    
                    //step2: if close symbols (important)
                    else{
                         if(st.empty()){
                                 st.push(ch);
                         }
                         else{
                                 int top = st.top();
                                 if(ch == ')' && top == '(' || ch == ']' && top == '[' || ch == '}' && top == '{')
                                         st.pop();
                                 else
                                         st.push(ch);
                         }
                    }
            }
            return st.empty();
    }
};