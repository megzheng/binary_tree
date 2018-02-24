#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int father;

typedef struct _tree_node
{
    int data;
    struct _tree_node *left_child;
    struct _tree_node *right_child;
}tree_node;

tree_node *create_tree_node(int data)//creat a tree node
{
    tree_node *pTreenode = NULL;
    pTreenode = (tree_node*)malloc(sizeof(tree_node));
    assert(NULL != pTreenode);

    memset(pTreenode,0,sizeof(tree_node));
    pTreenode->data=data;
    return pTreenode;
}

void insert_node(tree_node *p,int data)//insert data to *p
{
    tree_node *pArr;
    pArr = malloc(sizeof(tree_node));
    pArr->data=data;
    pArr->left_child=NULL;
    pArr->right_child=NULL;
    while(p->left_child != pArr && p->right_child != pArr)
    {
        while(data>p->data)
        {
            if(p->right_child==NULL)
            {
                p->right_child=pArr;
                return;
            }
            else
            {
                p=p->right_child;
            }
        }
        while(data<p->data)
        {
            if(p->left_child==NULL)
            {
                p->left_child=pArr;
                return;
            }
            else
            {
                p=p->left_child;
            }
        }
        if(data==p->data)
        {
            return;
        }
    }
    return;
}

void inorder_tree(tree_node *p)//zhongxu
{
    if(p==NULL)
    {
        return;
    }
    inorder_tree(p->left_child);
    printf("%d ",p->data);
    inorder_tree(p->right_child);
}

tree_node *search_key(tree_node *p,int data)
{
    if(p==NULL)
    {
      return 0;
    }
    else
    {
        if(data==p->data)
        {
            return p;
        }
        else
        {
            if(data<p->data)
            {
                father=p->data;
                return search_key(p->left_child,data);
            }
            else if(data>p->data)
            {
                father=p->data;
                return search_key(p->right_child,data);
            }
            else
            {
                return 0;
            }
        }
    }
}

int main()
{
    int data[100];
    //int num;
    int i;
    int len=0;
    int search_data;
    tree_node *pTreenode = NULL;
    tree_node *psearch = NULL;
    memset(data,0,100);
//    printf("Please input len:\n");
//    scanf("%d",&num);
    printf("please input numbers\n");
    while (scanf("%d",&data[len++]) != EOF && getchar() != '\n'); //循环读入多组整型数据，都以空格分隔。
    for(i=0;i<len;i++)
    {
        //scanf("%d",&data[i]);
        if(i==0)
        {
        pTreenode=create_tree_node(data[0]);
        }
        else
        {
         insert_node(pTreenode,data[i]);
        }
    }

    inorder_tree(pTreenode);
    printf("\n");
    while(1)
    {
     printf("inputvalue:");
    scanf("%d",&search_data);
    psearch=search_key(pTreenode,search_data);
    if(psearch==0)
    {
        return 0;
    }
    else
    {
          if(father==0)
        {
        printf("no father\n");
        }
        else
        {
         printf("fathernodevalue:%d\n",father);
        }

        if(psearch->left_child!=NULL)
        {
        printf("leftchildnode:%d\n",psearch->left_child->data);
        }
        else
        {
        printf("no left child\n");
        }
        if(psearch->right_child!=NULL)
        {
        printf("rightchildnode:%d\n",psearch->right_child->data);
        }
        else
        {
        printf("no right child\n");
        }
    }
    }
    return 0;
}
