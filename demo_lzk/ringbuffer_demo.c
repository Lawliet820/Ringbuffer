#include<stdio.h>
#include<stdlib.h>



typedef struct List
{
	int data;
	struct List *next;
}rblinklist,*p_rblinklist;

int max_len=10;
rblinklist *wr;
rblinklist *re;
int num_need_to_write=11;
char write_or_read;

void creat_rblinklist(rblinklist **p)
{
	int i;
	rblinklist *temp;
	rblinklist *target;
	(*p)=(rblinklist *)malloc(sizeof(rblinklist));
	(*p)->data=1;
	(*p)->next=*p;
	target=*p;
	for(i=1;i<max_len;i++,target=target->next)
	{
		temp=(rblinklist *)malloc(sizeof(rblinklist));
		target->next=temp;
		temp->next=*p;
		temp->data=i+1;
	}
}

void get_head_and_tail(rblinklist *p)
{
	rblinklist *target;
	rblinklist *head_node;
	rblinklist *tail_node;
	for(target=p;target->next!=p;target=target->next);
	re=p;
	wr=target;
}

void show(rblinklist *p)
{
	rblinklist *temp;
	temp=p;
	do
	{
		printf("%5d",temp->data);
		temp=temp->next;	
	}
	while(temp!=p);
	printf("\n");
}

void write()
{
	while(wr->next!=re)
	{
		wr->data=num_need_to_write;
		wr=wr->next;
		num_need_to_write = num_need_to_write+1;
	}
}

void read()
{
	int num_by_read;
	if(re!=wr)
	{
		num_by_read=(re->data);
		re->data=0;
		printf("读出的数据为%d：",num_by_read);
		re=re->next;
	}
	else
	{
		printf("缓存已用完！");
	}
}

void main()
{
	rblinklist *head=NULL;
	creat_rblinklist(&head);
	printf("原始的链表：");
	show(head);
	get_head_and_tail(head);
	while(1)
	{
		printf("输入要执行的操作'w'或'r'：");
		scanf("%c",&write_or_read);
		if(write_or_read=='w')
		{
			write();
			printf("更新后的链表值：");
			show(head);
		}
		if(write_or_read=='r')
		{
			
			read();
			printf("更新后的链表值：");
			show(head);
		}
		printf("\n");
	}
}
