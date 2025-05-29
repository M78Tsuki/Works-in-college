#include<stdio.h>

typedef struct{
   int*data;
   int rear;
   int front;
   int length;
}sqQueue;        //定义队列

sqQueue* initsqQueue(int size)
{
   sqQueue*s=(sqQueue*)malloc(sizeof(sqQueue));
   s->data=(int*)malloc(sizeof(int)*size);
   s->length=size;
   s->rear=0;
   s->front=0;

   for(int i=0;i<s->length;i++)
   s->data[i]=i+1;                //编号

   return s;
}                        //队列初始化

int pop(sqQueue*s)
{
   int outsq;
   outsq=s->data[s->front];
   s->front=(s->front+1)%s->length;
   s->rear=(s->rear+1)%s->length;     //这里是基于初始化时确定将队放满，尾指针跟随头指针，像一个圈不停的转来取值，因此不需要判满判空，从而实现每轮配对后的人按出队的顺序再参加下一轮配对
   return outsq;
}                                    //出队
void Match(sqQueue*m,sqQueue*w,int n)
{
   for(int i=0;i<n;i++)
   {
      printf("%d和%d一队\n",pop(m),pop(w));
   }

}
int main()
{
   int manNum,womanNum;
   int session;

   printf("男女生总人数<20\n");
   printf("请输入男生的人数:\n");
   scanf("%d",&manNum);
   sqQueue*man=initsqQueue(manNum);
   printf("请输入女生的人数:\n");
   scanf("%d",&womanNum);
   sqQueue*woman=initsqQueue(womanNum);
   printf("输入匹配次数\n");
   scanf("%d",&session);

   Match(man,woman,session);
   free(man->data);
   free(woman->data);
   free(man);
   free(woman);     //记得释放内存
   return 0;
}



