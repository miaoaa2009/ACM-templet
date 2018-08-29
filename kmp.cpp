#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
void cal_next(char *str,int *next,int len)
{
    next[0]=-1;
    int k=-1;
    for(int q=1;q<len;q++)
    {
        while(k>-1 && str[k+1]!=str[q])
        {
            k=next[k];
        }
        if(str[k+1]==str[q])
            k++;
        next[q]=k;
    }
}
int kmp(char *str, int slen, char*ptr, int plen)
{
    int *next=new int[plen];
    cal_next(ptr,next,plen);
    int k=-1;
    for(int i=0;i<slen;i++)
    {
        while(k>-1 && ptr[k+1]!=str[i])
            k=next[k];
        if(ptr[k+1]==str[i])
            k++;
        if(k==plen-1)
        {
            return i-plen+1;
        }
    }
    return -1;
}
