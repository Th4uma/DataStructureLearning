#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n,m,ans;

struct node
{
    int data;
    struct node *l;
    struct node *r;
};

struct link{
    struct node *data;
    struct link *next;
};


int main()
{
    link *head = new link;
    head->next = NULL;
    scanf("%d", &n);
    for (int i = 0;i < n; i++){
        scanf("%d", &m);
        link *p = head;
        while(p->next != NULL && p->next->data->data < m){
            p = p->next;
        }
        link *q = new link;
        q->data = new node;
        q->data->data = m;
        q->data->l = NULL;
        q->data->r = NULL;

        q->next = p->next;
        p->next = q;
    }

    for(int i = 0;i < n-1; i++){
        node *a = new node;
        a->data = head->next->data->data+head->next->next->data->data;
        ans+=a->data;
        a->l= head->next->data;
        a->r = head->next->next->data;
        head->next = head->next->next->next;
        link *p = head;
        while(p->next != NULL && p->next->data->data < a->data){
            p = p->next;    
        }
        link *q = new link;
        q->data = new node;
        q->data = a;
        q->next = p->next;
        p->next = q;

    }

    printf("%d\n", ans);
    return 0;
}

        