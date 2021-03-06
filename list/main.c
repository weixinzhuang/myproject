#include <stdio.h>
#include <string.h>
#include "list.c"

int main()
{
	/* 终端打印命令帮助信息 */
	help();
	
	while(1)
	{
		/* 定义一个链表的头节点 */
		static STU *head = NULL;
		printf("请输入要执行的命令：\n");
		char cmd[] = "";
		scanf("%s", cmd);
		
		if (strcmp("insert", cmd)==0)
		{
			printf("请输入一个学生的信息num name score：\n");
			STU tmp;
			scanf("%d %s %f", &tmp.num, tmp.name, &tmp.score);
			
			/* 调用链表插入函数 */
			head = InsertLink(head, tmp); 
		}
		else if (strcmp("print", cmd)==0)
		{
			/* 调用链表遍历函数 */
			PrintLink(head);
		}
		else if (strcmp("exit", cmd)==0)
		{
			exit(0);
		}
		else if (strcmp("delete", cmd)==0)
		{
			printf("请输入要删除的score:\n");
			float score;
			scanf("%f", &score);
			
			/* 调用链表删除函数 */
			head = DeleteLink(head, score);
		}
		else if (strcmp("help", cmd)==0)
		{
			help();	
		}
	}
	   
    return 0;

}
