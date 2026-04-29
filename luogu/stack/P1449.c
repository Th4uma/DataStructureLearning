#include <stdio.h>
#include <stdlib.h>

char s[101];
int n,top,num,a[100000];

int main(){
    scanf("%s",s);
    while(s[n]!='@'){
        num=0;
        if(s[n]>='0'&&s[n]<='9'){
            while(s[n]!='.'){
                num=num*10+s[n]-'0';
                n++;
            }
            top++;
            a[top]=num;
        }else if(s[n]=='+'){
            num=a[top-1]+a[top];
            a[top]=0;
            top--;
            a[top]=num;
        }else if(s[n]=='-'){
            num=a[top-1]-a[top];
            a[top]=0;
            top--;
            a[top]=num;
        }else if(s[n]=='*'){
            num=a[top-1]*a[top];
            a[top]=0;
            top--;
            a[top]=num;
        }else if(s[n]=='/'){
            num=a[top-1]/a[top];
            a[top]=0;
            top--;
            a[top]=num;
        }
        n++;
    }

    printf("%d\n",num);
    return 0;
}
