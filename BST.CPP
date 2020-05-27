#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
typedef struct lklist{
	int info;
	struct lklist*left;
	struct lklist*right;
} node;
void main(){
void insert(node**,int);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int minimum(node*);
int maximum(node*);
node* search(node*,int);
node* root,*loc;
root=NULL;
int choice, item,data;
clrscr();
while(1){
printf("\n Binary Tree");
printf("\n - -- - - - - - - - - - - ");
printf("\n1.Insert node");
printf("\n2.Inorder");
printf("\n 3.preorder");
printf("\n 4.postorder");
printf("\n 5. search");
printf("\n 6.exit");
printf("\n7 Minimum");
printf("\n 8.Maximum");
printf("\n Enter your choice");
scanf("%d",&choice);
switch(choice){
//Insertition
case 1:
	printf("enter element to insert");
	scanf("%d",&item);
	insert(&root,item);
	break;
 //inorder
case 2:

	inorder(root);
	break;
	//preorder
case 3:

	preorder(root);
	break;
	//postorder
case 4:
	postorder(root);
	break;
	//search
case 5:
	printf("\n enter element to search");
	scanf("%d",&item);
      loc=search(root,item);
      if(loc!=NULL)
      printf("\n item found");
      else
      printf("\n item not found");
	break;
	//exit
case 6:
	exit(1);
//minimum
case 7:

      printf("%d",minimum(root));
	break;
case 8:

	printf("%d",maximum(root));
	break;
default:
	exit(1);


}
}
}
void insert(node**root,int item){
	node *ptr,*temp,*loc;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->left=NULL;
	ptr->right=NULL;
	if(*root==NULL)
		*root=ptr;
		temp=*root;
		while(temp!=NULL){
			     loc=temp;
			if(item>temp->info)
			temp=temp->right;
			else
			temp=temp->left;


		}
	       //	loc=temp;
			if(item>loc->info)
			loc->right=ptr;
			else if(item<loc->info)
			loc->left=ptr;


}
void inorder(node *root)
{
    if (root == NULL)
	return;

    inorder(root->left);
    printf("inorder");
    printf(" %d->", root->info);// << "   ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
	return;
	printf("preorder");
	 printf("%d->", root->info);

    preorder(root->left);
   // << "   ";
    preorder(root->right);
}
 void postorder(node *root)
{
    if (root == NULL)
	return;


    postorder(root->left);
   // << "   ";
    postorder(root->right);
    printf("postorder");
    printf("\n %d->", root->info);
}

node* search(node*root, int item)
{    node*cur;
	cur=root;
    while (cur != NULL)
    {   if(item==cur->info)
	 return cur;


	if (item < cur->info)
	    cur = cur->left;
	else
	    cur = cur->right;
    }
    return NULL;
}
int minimum(node*root){


	while(root->left!=NULL){
	       //	if(item<min->info)
		root=root->left;
	}
	return (root->info);
}
int maximum(node*root){


	while(root->right!=NULL){
	       //	if(item<min->info)
		root=root->right;
	}
	return (root->info);
}





