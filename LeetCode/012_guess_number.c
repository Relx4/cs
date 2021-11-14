#include<stdio.h>
#include<stdlib.h>
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num){
    return 0;
}
int guessNumber(int n){
    int left=1;
    int right=n;
    int middle=0;
    do{
        if(left%2==1&&right%2==1)middle=left/2+right/2+1;
        else middle=left/2+right/2;
        if(guess(middle)==-1)right=left+(right-left)/2;
        if(guess(middle)==1)left=right-(right-left)/2;
    }while(guess(middle)!=0);
    return middle;
}
/*WARNING::::请确保不会发生越界的情况！这种二分法的简单题目唯一的陷阱就是在于，
可能left+right正好超越了int的限度！！！！！！*/
