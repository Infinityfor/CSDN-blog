#include <bits/stdc++.h>
using namespace std;

int num[10];  //�洢��������� 
int record[10]; //��¼ʹ������������ʼֵΪ 0  
int sum=0;      //�������ĺ� 
int n,k;
int p[10];      //������ֹ���ظ���������� 

int print()
{
	for(int i=1;i<=n;i++)
	{
		if(record[i]==1)
		{
			cout<<num[i]<<" ";
		}
	}
	cout<<endl;
}

void dfs(int i)  //�ֵ��ڼ�λ�� 
{
	if(i==k+1)   //������������ 
	{
		if(sum%2!=0){    //���������������� 
			print();
		} 
		return ;
	}
	else{
		for(int j=1;j<=n;j++) //Ϊ�ڼ�λ��ѡ���� 
		{
			if(record[j]==0  && num[j]>p[i-1] )  //û�б�ѡ�����ż���ȥ�����������Ҫ����һλ �����У� 
			{                                    // ѡ������󣬲�Ȼ������ظ������� 
				p[i]=num[j];                     //��ʾ��ǰѡ����� 
				sum+=num[j];                     //��������� 
				record[j]=1;                     //��¼��ѡ���� 
				dfs(i+1);                        //����ѡ����һλ�� 
				record[j]=0;                     //��ͷ�������¼ 
				sum-=num[j];                     //��ҲҪ��ͷ����Ȼ�Ͷ��� 
			}
		}
	}
}


int main()
{
	cin>>n>>k;
    for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	dfs(1); //�ӵ�һλ��ʼ 
	return 0;
}
