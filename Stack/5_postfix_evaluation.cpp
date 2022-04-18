
int postix_evaluation(string s){

    stack<int>st;

    for( int i = 0; i < s.length(); i++){
        char ch = s[i];

        if(isdigit(ch)){
            st.push(ch-'0');
        }
        else{
                int y = st.top();
                st.pop();

                int x = st.top();
                st.pop();

                switch(ch){

                     case '+': 
                        st.push(x+y);
                        break;
                     case '-': 
                        st.push(x-y);
                        break;
                     case '*': 
                        st.push(x*y);
                        break;
                     case '/': 
                        st.push(x/y);
                        break;
                        

                }
        }
    }

    // at last only single element will be left in the stack, our ans
    int ans = st.top();
}