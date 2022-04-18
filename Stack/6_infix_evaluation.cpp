//brute force -
/*
  1-> convert infix to postfix
  2-> evaluate the postfix
*/


//in this approach we evaluated in a single pass using 2 stacks.

class Solution {
private:
   int precedence(char c){
 
    //power has high precedence hence retured 3
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
   }
    
    //oprtion done whenever we pop operator from the stack
    int operation( int x, int y, char opr){
        
        if(opr == '+'){
            return x+y;
        }
        else if(opr == '-'){
            return x-y;
        } 
        else if(opr == '*'){
            return x*y;
        } 
        else{
            return x/y;
        }
    }
public:
    int calculate(string s) {
        
        stack<char>optor;
        stack<int>oprend;
        
        for( int i = 0; i < s.length(); i++){       
            char ch = s[i];
            
            if(ch == '('){
                optor.push(ch);
            }
            else if(isdigit(ch)){
                oprend.push(ch-'0');
            }
            else if(ch == ')'){
                
                while(optor.top()!= '('){
                    char opr = optor.top();
                    optor.pop();
                    int y = oprend.top();
                    oprend.pop();
                    int x = oprend.top();
                    oprend.pop();
                    
                    int newVal = operation(x,y,opr);
                    oprend.push(newVal);
                }
                optor.pop();
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                
                while(!optor.empty() && optor.top()!= '(' && precedence(ch) <= precedence(optor.top())){
                    char opr = optor.top();
                    optor.pop();
                    int y = oprend.top();
                    oprend.pop();
                    int x = oprend.top();
                    oprend.pop();
                    
                      
                    int newVal = operation(x,y,opr);
                    oprend.push(newVal);
                }
                optor.push(ch);
            }
        }
        while(!optor.empty()){
              char opr = optor.top();
                    optor.pop();
                    int y = oprend.top();
                    oprend.pop();
                    int x = oprend.top();
                    oprend.pop();
            
              
                    int newVal = operation(x,y,opr);
                    oprend.push(newVal);
        }
        return oprend.top();
    
    }
};