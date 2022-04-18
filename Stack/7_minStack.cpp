// optimized approach......
//used a variable to track min value. space O(n) and Time (1) 

class MinStack {
public:
    long mn;
    stack<long> s;
    
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty())
        {
            mn=val;
            s.push(val);
        }
        else if(val>mn)
            s.push(val);
        else
        {
            s.push((long)2*val-mn);
            mn=val;
        }  
    }
    
    void pop() {
        if(s.top()<mn)
            mn=2*mn-s.top();
        
        s.pop();
    }
    
    int top() {
        if(s.top()>=mn)
        return s.top();
        
        return mn;
    }
    
    int getMin() {
        return mn;
    }
};


//Brute Force
/*
  we will use 2 stacks.
  one for pushing all the elements
  another to pushing only the min elements till we visited
*/

class MinStack {
public:
    stack<int>s1,s2;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        
        if(s2.empty() || s2.top() >= val){
            s2.push(val);
        }
    }
    
    void pop() {
       
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};