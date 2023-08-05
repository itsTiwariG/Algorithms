#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int * a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int min(int a,int b){
    if (a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

typedef struct Node Node;
struct Node
{
    int data;
    int len;
    Node* next;
};

Node* insert(Node* end,int num,int p){
    Node *k=new Node;
    k->data=num;
    k->next=NULL;
    k->len=p;
    end->next=k;
    return k;
}

int * Heapify(int * arr,int n,int * d){
    for (int i=0;i<n/2;i++)
    {
        // printf("1");
        if ((2*i+2)!=n)
        {
            if (d[arr[i]]>d[arr[2*i+2]] )
            {
                swap(&arr[i],&arr[2*i+2]);
            }
        }
        if (d[arr[i]]>d[arr[2*i+1]])
        {
            // printf("1");
            swap(&arr[i],&arr[2*i+1]);
        }
        // printf("%d ",i);
        // printf("1 ");
    }
    // printf("1");
    return arr;
}

int Extract_min(int * arr, int n, int* d){
    int temp= arr[0];
    arr[0]=arr[n-1];
    Heapify(arr,n-1,d);
    return temp;
}