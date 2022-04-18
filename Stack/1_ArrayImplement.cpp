#include<bits/stdc++.h>
using namespace std;


//array implementation
class Stack {
    int capacity;
    int top; 
    int *arr;

    public:
    void createStack(int capacity){

        this->capacity = capacity;
        this->top = -1;
        this->arr = new int[capacity];
        cout<<capacity<<endl;
    }

    void push(int num){
      
      top++;
      if(top > capacity-1){
          cout<<"stack overload"<<endl;
          top--;
      }
      arr[top] = num;
    }

    void pop(){
        if(top < 0){
            cout<<"stack underflow"<<endl;
        }
        else{
            cout<<"pop -->"<<arr[top]<<endl;
            top--;
        }
    }

    void Top(){
        cout<<"top element --> "<<arr[top]<<endl;
    }

};

//main function 
int main(){

    Stack stk;
    stk.createStack(5);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.Top();
    stk.pop();
    stk.push(4);
    stk.push(6);
    stk.push(5);
    stk.push(7);
    stk.Top();
 

}