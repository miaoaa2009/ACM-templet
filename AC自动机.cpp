#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int kind=26;
struct node
{
    node *fail;
    node *next[kind];
    int cnt;
    node()
    {
        fail=NULL;
        cnt=0;
        memset(next,NULL,sizeof(next));
    }
}*q[500001];
char keyword[51];
char str[1000001];
int head,tail;
void Insert(char *str,node *root)
{
    node *p=root;
    int i=0,index;
    while(str[i])
    {
        index=str[i]-'a';
        if(p->next[index]==NULL)
            p->next[index]=new node();
        p=p->next[index];
        i++;
    }
    p->cnt++;
}
void ac_automation(node *root)
{
    int i;
    root->fail=NULL;
    q[head++]=root;
    while(head!=tail)
    {
        node *temp=q[tail++];
        node *p=NULL;
        for(i=0;i<26;i++)
        {
            if(temp->next[i]!=NULL)
            {
                if(temp==root)
                    temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                        temp->next[i]->fail=root;
                }
                q[head++]=temp->next[i];
            }
        }
    }
}
int query(node *root)
{
    int i=0,cnt=0,index,len=strlen(str);
    node *p=root;
    while(str[i])
    {
        index=str[i]-'a';
        while(p->next[index]==NULL && p!=root)
            p=p->fail;
        p=p->next[index];
        p=(p==NULL)?root:p;
        node *temp=p;
        while(temp!=root && temp->cnt!=-1)
        {
            cnt+=temp->cnt;
            temp->cnt=-1;
            temp=temp->fail;
        }
        i++;
    }
    return cnt;
}
node *root=new node;
int main()
{
    scanf("%s",str);
    for(int i=0;i<5;i++)
    {
        scanf("%s",keyword);
        Insert(keyword,root);
    }
    ac_automation(root);
    printf("%d\n",query(root));
}
