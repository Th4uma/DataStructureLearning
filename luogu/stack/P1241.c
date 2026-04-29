#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int y;
    char c;
}node;
char s[101],a[100];
node p[101];
int n,top,x[101];


int main(){
    scanf("%s",s);
    for(int i=0;i<=100;i++) p[i].y=0;
    while(s[n]){
        p[n].c=s[n];
        if(s[n]=='('||s[n]=='['||s[n]=='{'){
            top++;
            a[top]=s[n];
            x[top]=n;
        }else if(s[n]==')'){
            if(a[top]=='('){
                p[x[top]].y=1;
                p[n].y=1;
                top--;
            }
        }else if(s[n]==']'){
            if(a[top]=='['){
                p[x[top]].y=1;
                p[n].y=1;
                top--;
            }
        }else if(s[n]=='}'){
           if(a[top]=='{'){
                p[x[top]].y=1;
                p[n].y=1;
                top--;
            }
        }
        n++;
    }
    for(int i=0;i<n;i++){
        if(p[i].y==1){
            printf("%c",p[i].c);
        }else if(p[i].c=='('||p[i].c==')'){
            printf("()");
        }else if(p[i].c=='['||p[i].c==']'){
            printf("[]");
        }else if(p[i].c=='{'||p[i].c=='}'){
            printf("{}");
        }
    }
    return 0;
}
