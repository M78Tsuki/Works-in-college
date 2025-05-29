#include<stdio.h>

typedef struct{
   int*data;
   int rear;
   int front;
   int length;
}sqQueue;        //�������

sqQueue* initsqQueue(int size)
{
   sqQueue*s=(sqQueue*)malloc(sizeof(sqQueue));
   s->data=(int*)malloc(sizeof(int)*size);
   s->length=size;
   s->rear=0;
   s->front=0;

   for(int i=0;i<s->length;i++)
   s->data[i]=i+1;                //���

   return s;
}                        //���г�ʼ��

int pop(sqQueue*s)
{
   int outsq;
   outsq=s->data[s->front];
   s->front=(s->front+1)%s->length;
   s->rear=(s->rear+1)%s->length;     //�����ǻ��ڳ�ʼ��ʱȷ�����ӷ�����βָ�����ͷָ�룬��һ��Ȧ��ͣ��ת��ȡֵ����˲���Ҫ�����пգ��Ӷ�ʵ��ÿ����Ժ���˰����ӵ�˳���ٲμ���һ�����
   return outsq;
}                                    //����
void Match(sqQueue*m,sqQueue*w,int n)
{
   for(int i=0;i<n;i++)
   {
      printf("%d��%dһ��\n",pop(m),pop(w));
   }

}
int main()
{
   int manNum,womanNum;
   int session;

   printf("��Ů��������<20\n");
   printf("����������������:\n");
   scanf("%d",&manNum);
   sqQueue*man=initsqQueue(manNum);
   printf("������Ů��������:\n");
   scanf("%d",&womanNum);
   sqQueue*woman=initsqQueue(womanNum);
   printf("����ƥ�����\n");
   scanf("%d",&session);

   Match(man,woman,session);
   free(man->data);
   free(woman->data);
   free(man);
   free(woman);     //�ǵ��ͷ��ڴ�
   return 0;
}



