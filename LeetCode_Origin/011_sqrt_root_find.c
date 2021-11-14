#include<stdio.h>
#include<stdlib.h>
int mySqrt(int x){
   int min=0;
   int max=x;
   int middle=min+(max-min)/2;
   while(min<=max){
       middle=min+(max-min)/2;
       long value=(long)middle*middle;
       if(x<value)max=middle-1;
       else if(x>value)min=middle+1;
       else if(x==value)return middle;
   }
   return (long)middle*middle<x?middle:middle-1;
}
/*from leetbook*/
