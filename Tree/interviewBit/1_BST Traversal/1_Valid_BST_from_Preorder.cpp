
//preorder = root left right 
/* 
find the first number in the array and if we find small element after the first large number then return false.
use stack to track the largest element. 

 TC = O(n) for array traversal
 SC = O(n) for the stack

*/



int Solution::solve(vector<int> &arr) {

    stack<int>st;
    int root = INT_MIN;

    for( int i =0 ; i < arr.size(); i++){

        while(!st.empty() && arr[i] > st.top()){

            root = st.top();
            st.pop();
        }
        if(arr[i] < root){
            return 0;
        }
        st.push(arr[i]);
    }

    return 1;

}