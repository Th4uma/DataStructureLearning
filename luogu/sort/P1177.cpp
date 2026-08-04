#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a,x;
int n,m;

void px(vector<int>& a,int start,int end){
    int i=start,j=(end+start)/2+1,k=start;
    while(i<=(end+start)/2&&j<=end){
        if(a[i]<a[j]){
            x[k]=a[i];
            i++;
        }else{
            x[k]=a[j]; 
            j++;
        }
        k++;
    }
    while(i<=(end+start)/2){
        x[k]=a[i];
        i++;
        k++;
    }
    while(j<=end){
        x[k]=a[j];
        j++;
        k++;
    }
    for(int i=start;i<=end;i++){
        a[i]=x[i];
    }
}

void sep(vector<int> &a,int start,int end){
    if(end<=start) return;
    sep(a,start,(end+start)/2);
    sep(a,(end+start)/2+1,end);
    px(a,start,end);
}

int main(){
    scanf("%d",&n);
    a.resize(n + 1);
    x.resize(n + 1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sep(a,1,n);
    for(int i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
    return 0;
}
