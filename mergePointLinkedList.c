#include<stdlib.h>
#include<stdio.h>
  struct ListNode {
      int val;
      struct ListNode *next;
  };
  
  typedef struct ListNode listnode;
  
  listnode* listnode_new(int val) {
      listnode* node = (listnode *) malloc(sizeof(listnode));
      node->val = val;
      node->next = NULL;
      return node;
}
listnode* createNewNode()
{
   listnode *nn=(listnode *)malloc(sizeof(listnode));
   return nn;
}
 void addAtBeg(listnode **h,int d)
{
        listnode *nn=createNewNode();
        nn->val=d;
        nn->next=*h;
        *h=nn;
}
 int length(listnode *a){
     int count=0;
     while(a){
         count++;
         a=a->next;
     }
     return count;
     
 }
listnode* getIntersectionNode(listnode* A, listnode* B) {
    int i;
    int len1 = length(A);
    int len2 = length(B);
    int d=len2-len1;
    if(len1>len2){
        listnode* temp=A;
        A=B;
        B=temp;
        d=len1-len2;
    }
    
    for(i=0;i<d;i++){
        B=B->next;
    }
    while(A!=NULL &&B!=NULL){
        if(A==B){
            return A;
        }
        A=A->next;
        B=B->next;
    }
    return NULL;
}
int main(){
    listnode *a = NULL;
    listnode *b = NULL;
    addAtBeg(&a,4);
    addAtBeg(&a,2);
    addAtBeg(&a,1);
    addAtBeg(&a,3);
    addAtBeg(&a,6);
    addAtBeg(&b,3);
    addAtBeg(&b,2);
    addAtBeg(&b,5);
    addAtBeg(&b,8);
    listnode *ans=getIntersectionNode(a,b);
    printf("%d",ans->val);

}
