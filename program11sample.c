#include<stdio.h>
int p[50],r[50];
void make_set(int x);
int find_set(int x);
void union_set(int x,int y);
int main()
{
int n,x,y,i,root1,root2,op1,a[50];
printf("\nEnter the number of elements : ");
scanf("%d",&n);
printf("Enter the elements : ");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
make_set(p[i]);
}
do
{
printf("\nUnion : ");
printf("\nEnter the elements for union : ");
scanf("%d %d",&x,&y);
root1=find_set(x);
root2=find_set(y);
if(root1==root2)
printf("\nCan't perform union ,both have same reprasenative");
else
{
union_set(root1,root2);
printf("\nIndex array : ");
for(i=0;i<n;i++)
printf("%d ",i);
("\nParent array : ");
for(i=0;i<n;i++)
printf("%d ",p[i]);
printf("\nRank array : ");
for(i=0;i<n;i++)
printf("%d ",r[i]);
}
printf("\n\nDo you want to continue 1/0 : ");
scanf("%d",&op1);
}while (op1!=0);
return 0;
}
void make_set(int x)
{
p[x]=x;
r[x]=0;
return;
}
int find_set(int x)
{
if(p[x]==x)
return p[x];
else
return p[x]=find_set(p[x]);
}
void union_set(int root1,int root2)
{
if(r[root1]>r[root2])
p[root2]=root1;
else
{
p[root1]=root2;
if(r[root1]==r[root2])
r[root2]=r[root2]+1;
}
return;
}
