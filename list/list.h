/*************************************************
Copyright © Fanvil Technologies Co., Ltd. 1998-2019. All rights reserved.
File name: list.h
Author：魏心壮 
ID：BJ0083 
Version: 1.0
Date: 2019年12月23日
Description: 定义链表节点类型声明函数
Function：STU* InsertLink(STU *head, STU tmp)：此函数实现链表数据的尾部插入
		  PrintLink(const STU *head)：此函数实现链表数据的遍历
*************************************************/

#pragma once

/* 定义一个链表节点类型 */
typedef struct stu
{
	/* 数据域 */
	int num;
	char name[32];
    float score;
	
    /* 指针域 */
    struct stu *next;
}STU;

/**
* @Description:链表数据的尾部插入.
* @param head - 指向链表的头节点.
* @param tmp - 要插入的数据.
* @return 成功：返回head.
*/
extern STU* InsertLink(STU *head, STU tmp);

/**
* @Description:链表数据的遍历.
* @param head - 指向链表的头节点.
* @return 无返回值.
*/
extern void PrintLink(const STU *head);

/**
* @Description:链表数据的删除.
* @param head - 指向链表的头节点.
* @param score - 要删除的数据.
* @return 成功：返回head.
*/
extern STU* DeleteLink(STU *head,float score);


