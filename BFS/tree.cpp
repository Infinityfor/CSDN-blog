#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
struct tree{
char saveChar;
int step;
struct tree*L;
struct tree*R;
};
struct tree*c;
struct tree*f;
struct list {
struct tree*head;
};
void putin(struct tree*p,struct tree*prep){
if(p->saveChar<prep->saveChar){
    if(prep->L!=NULL){putin(p,prep->L);}
    else{prep->L=p;return;}
}
if(p->saveChar>prep->saveChar){
    if(prep->R!=NULL){putin(p,prep->R);}
    else{prep->R=p;return;}
}
}
void ShowAndRecord(struct tree*p){
    if(p!=NULL){
    if(p->saveChar=='d'){c=p;}
    if(p->saveChar=='g'){f=p;}
    //cout<<p->saveChar<<endl;
    }
if(p->L!=NULL){
    ShowAndRecord(p->L);
}
if(p->R!=NULL){
    ShowAndRecord(p->R);
}
}
//-----------չʾ����--------
//struct tree//�ڵ��ģ��
//{
//char saveChar;//����ĸ
//struct tree*L;//��ڵ���ߵĽڵ�
//struct tree*R;//��ڵ��ұߵĽڵ�
//};

struct tree*used[50];//��¼�Ž���������Ľڵ�
int UsedCount;//��¼�Ž�ȥ���Ľڵ���

bool Used(struct tree*p)//�жϽڵ���û�зŽ����У�����û�б�̽�ù������򷵻�true,����false
{
    for(int i=0;i<UsedCount;i++){
        if(p==used[i]){return true;break;}
    }
    return false;
}

void bfs(struct tree*root,char Find)//��������,������ڵ��Ҫ������ĸ
{
queue<struct tree*>que;//����һ������
que.push(root);//����һ���ڵ�Ž����У�׼����������ѿ��
used[UsedCount++]=root;//��¼�ù��Ľڵ�,���ｫ��һ���ڵ�Ž�ȥ
struct tree*saveNode;//��������Ӷ������ó����Ľڵ�
int steps=0;//��¼����ڵ�ĸ���
int ok=0;//�ж��Ƿ����ҵ�
while(!que.empty())//һֱ����ֱ���������Ѿ�û�нڵ㣬������ÿһ���ڵ��Ѿ���������
{
        saveNode=que.front();//ȡ�������е�һ���ڵ�
        que.pop();//ȡ���˶����ﵱȻ��û��
if(Find==saveNode->saveChar)//���Ҫ�ҵ���ĸ�����ǽڵ���洢����ĸ
{
     cout<<"�ҵ���"<<endl;
     cout<<"һ��������"<<steps+1<<"���ڵ�"<<endl;
     ok=1;//�ҵ��˾ͱ��
     break;//�ҵ��˾��뿪ѭ��������Ѱ��
}
else{
    cout<<Find<<" �� "<<saveNode->saveChar<<endl;//�������,��һ�����ں�˭�Ƚϣ�׼���ߵ�������һ��
    if(saveNode->L!=NULL&&!Used(saveNode->L))//����ڵ���߻��нڵ㣬���һ�û�Ž�������
    {
    que.push(saveNode->L);//�ǾͷŽ�ȥ��
    used[UsedCount++]=saveNode->L;//��¼
    }
    if(saveNode->R!=NULL&&!Used(saveNode->R))//�ұ�����ɽڵ㣬ͬ��
    {
     que.push(saveNode->R);
     used[UsedCount++]=saveNode->R;
    }
}
steps++;//һ��ѭ��һ���ڵ㣬�������
}
if(!ok){cout<<"�Ҳ���"<<endl;}
return;
}

//-----------չʾ����--------
int main()
{
//����
//6
//e
//b
//g
//a
//d
//c
//��һ��Ҫ�ҵ���ĸ

   int n;
   cin>>n;
   char input;
   struct tree *p;
   struct list L;
   L.head=NULL;
   for(int i=0;i<n;i++){
        p=(struct tree*)malloc((sizeof(struct tree)));
        cin>>input;
        p->saveChar=input;
        p->L=NULL;
        p->R=NULL;
        if(L.head==NULL){
            L.head=p;
        }else{
            struct tree *prep=L.head;
           putin(p,prep);
        }
   }
ShowAndRecord(L.head);
 p=(struct tree*)malloc((sizeof(struct tree)));
        p->saveChar='f';
        p->L=NULL;
        p->R=NULL;
c->R=p;
f->L=p;
char Find;
cout<<"������ҪѰ�ҵ���ĸ��";
cin>>Find;
bfs(L.head,Find);


   return 0;


}
