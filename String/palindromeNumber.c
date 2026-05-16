#include<stdbool.h>
bool isPalindrome(int x) {
    int temp=x;
    long int result=0;
    if(x<0){
        return false;
    }
    while(temp!=0){
        int digit=temp%10;
        
        result=(result*10)+digit;
        temp/=10;
    }
    
    return (result==x);
}