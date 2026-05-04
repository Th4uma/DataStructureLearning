#include <stdio.h>
#include <stdlib.h>

int n=1,x;
char front[1000001],behind[1000001];

int main(){
    scanf("%s%s",front,behind);
    while(behind[x]>='a'&&behind[x]<='z') x++;
    for(int i=0;i<x-1;i++){
        for(int j=0;j<x-1;j++){
            if(front[i]==behind[j+1]&&front[i+1]==behind[j]) n*=2;
        }
    }
    printf("%d\n",n);
    return 0;
}
