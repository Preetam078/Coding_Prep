
//step1: (important) know the precedence of operator
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

string infix_postfix(string s){

    stack<char>st;
    string res;

    for( int i = 0; i < s.length(); i++){
        char ch = s[i];

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            res+= ch;
        }

        else if(ch == '('){
            st.push(ch);
        }

        // print all the operator between ( and )
        else if(ch == ')'){
            while(!st.empty() && st.top()!= '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
           
           //VVI if the precedence is high then print and pop()
            while(!st.empty() && precedence(st.top()) > precedence(ch)){
                res+= st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }
}