#include<iostream>
#include<queue>
using namespace std;
struct location{
int x;
int y;
int step;//��¼����
};//��¼��ÿһ���ϵ�״̬
char labyrinth[][7]={
{'B','O','O','O','O','O','O'},
{'O','X','X','X','X','X','O'},
{'O','O','O','O','O','X','O'},
{'O','O','O','O','O','O','O'},
{'X','X','X','O','O','O','O'},
{'O','O','O','O','X','O','X'},
{'X','O','O','O','O','O','E'}
};//�Թ�����

int pass[8][8]={0};//��¼�Թ��ϵ�ÿһ���Ƿ��߹�
int dir[][2]={{0,-1},{0,1},{-1,0},{1,0}};//��¼x,y�����ϣ��£�����
bool judge(int x,int y)//�ж�(x,y)�ܲ�����
{
if(x<0||x>6||y<0||y>6){return false;}//Խ�񣬲�����
if(labyrinth[x][y]=='X'){return false;}//����"X��������
if(pass[x][y]){return false;}//�߹��ĸ��Ӳ�����
return true;
}

int BFS(location B){
if(labyrinth[B.x][B.y]=='E'){return 0;}//ע�⣬Ҫ�ж�����ǲ��� ͬʱΪ�յ�
queue<struct location>que;
que.push(B);
location saveData;//�������Զ��׵�����
while(!que.empty()){
saveData=que.front();
que.pop();
for(int i=0;i<4;i++){
    location middle=saveData;//middle������������Ȼ���ƶ�
    middle.x+=dir[i][0];
    middle.y+=dir[i][1];//�ƶ�
if(judge(middle.x,middle.y))//���(x,y)����
{
if(labyrinth[middle.x][middle.y]=='E')
{return middle.step+1;}//�ҵ��յ㣬���ز���
    middle.step++;//��¼�������ȼ��˺�Ŷ���
    que.push(middle);//û�ҵ�����Ѹø��ӷŵ����У��ȴ���һ���ƶ�
    pass[middle.x][middle.y]=1;//����¼��������
}
}}}
int main()
{
location B;//���λ��
B.x=0;B.y=0;B.step=0;
cout<<BFS(B)<<endl;
for(int i=0;i<7;i++){
	for(int j=0;j<7;j++){
		cout<<pass[i][j]<<" ";
	}
	cout<<endl;
}
return 0;
}

