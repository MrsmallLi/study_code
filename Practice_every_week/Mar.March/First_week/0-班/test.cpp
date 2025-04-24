/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Mar 2025 10:58:27 PM CST
 ************************************************************************/



#include <cstdio>
int n,a[310];
char map[310][310];//存0、1图
int pre[310];//父节点
int find(int x)
{
	int r=x;
	while(r!=pre[r])
	{
		r=pre[r];
	}
	int k=x,t;
	while(k!=r)//路径压缩
	{
		t=pre[k];
		pre[k]=r;
		k=t;
	}
	return r;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);//储存初始序列
	}
	for(int i=0;i<n;i++)//初始化父节点
	{
		pre[i]=i;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
		for(int j=0;j<n;j++)
		{
			if(map[i][j]=='1')//是1，那么a[i]和a[j]能互相交换，把他们放到一个即合理
			{
				int fx=find(a[i]);
				int fy=find(a[j]);
				if(fx!=fy)
				{
					pre[fx]=fy;
				}
			}
		}
	}
	for(int i=0;i<n;i++)//类似于冒泡排序
	{
		for(int j=i+1;j<n;j++)
		{
			if(find(a[i])==find(a[j])&&a[i]>a[j])//在一个集合里（可以交换），且顺序不是升序的，那么交换
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	return 0;
}

