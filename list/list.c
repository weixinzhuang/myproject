/**
*@file list.c
*@brief 实现链表数据的插入
*@version 1.0
*@author 魏心壮
*@date 2019年12月23日
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
* @Description:终端打印帮助信息.
* @param 无参数.
* @return 无返回值.
*/
void help()
{
	printf("*******帮助：help******\n");
	printf("*******插入：insert****\n");
	printf("*******遍历：print*****\n");
	printf("*******删除：delete****\n");
	printf("*******退出：exit******\n");
}

/**
* @Description:链表数据的尾部插入.
* @param head - 指向链表的头节点.
* @param tmp - 要插入的数据.
* @return 成功：返回head.
*/
STU* InsertLink(STU *head, STU tmp)  
{  
	/* 为待插入的节点申请空间 */
    STU *pi = (STU *)calloc(1, sizeof(STU));
	
    /* 将tmp的数据赋值给*pi */ 
    *pi = tmp;  
    pi->next = NULL;
	
    /* 判断链表是否存在 */  
    if (head == NULL)  
	{  
		head = pi;   
	}  
	else  
    {  
		/* 寻找尾节点 */  
        STU *pb = head;  
        while (pb->next != NULL)  
        {  
            pb = pb->next;  
        }
		
        /* 将尾节点的指针域next指向新的pi节点 */  
        pb->next = pi;   
    }  
    return head;  
}  

/**
* @Description:链表数据的遍历.
* @param head - 指向链表的头节点.
* @return 无返回值.
*/
void PrintLink(const STU *head)  
{  
    /* 判断链表 是否存在 */ 
    if (head == NULL)  
    {  
        printf("链表不存在\n");  
        return;  
    }  
    else  
    {  
        const STU *pb = head;  
        while (pb != NULL)  
        {  
            printf("num=%d, name=%s, score=%f\n", pb->num, pb->name, pb->score);  
            pb = pb->next;  
        }  
    }  
} 

/**
* @Description:链表数据的删除.
* @param head - 指向链表的头节点.
* @param score - 要删除的数据.
* @return 成功：返回head.
*/
STU* DeleteLink(STU *head, float score)  
{     
    /* 判断链表是否存在 */ 
    if(head == NULL)  
    {  
        printf("链表不存在\n");  
        return head;  
    }  
    else  
    {  
        /* 逐个节点查询删除点 */ 
        STU *pf = head, *pb = head;  
        while((pb->score != score) && (pb->next != NULL))  
        {  
            pf = pb;  
            pb = pb->next;  
        } 
		
  		/* 找到删除点 */
        if(pb->score == score)  
        {  
            if(pb == head)/* 删除头节点 */ 
            {  
                head = head->next;  
            }  
            else /* 删除中、尾节点 */ 
            {  
                pf->next = pb->next;  
            }  
  
            /* 释放要删除的节点 */
            free(pb);  
            printf("节点删除成功\n");  
            return head;  
        }  
        else 
        {  
            printf("未找到删除点\n");  
            return head;  
        }  
    }  
      
    return head;  
}  

