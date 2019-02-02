#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "define_my.h"


/*��ӡ������Ʒ��Ϣ*/ 
void Goodprint(GoodList *p)
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ID:%s\tName:%s\tPrice:%s\tDiscount:%s\tAmount:%d\tRemain:%d\n",
	       p->data.good_id,p->data.good_name,p->data.good_price,p->data.good_discount,p->data.good_amount,p->data.good_remain);
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    
}

/*����p*/ 
GoodList *info_search(GoodList *L)
{
	char *name;
	GoodList *p;
	
	/*printf("������Ҫ���ҵ���Ʒ���ƣ�-1�˳����ң���");*/
	scanf("%s",name);
	if(strcmp(name,"-1")==0)
	   return NULL;
	for(p=L;p!=NULL;p=p->next)  
	 {
 		if(strcmp(p->data.good_name,name)==0||strcmp(p->data.good_id,name)==0)
 		 {Goodprint(p); 
		  return p;} 
 	}
 	/*printf("��Ҫ��ѯ����Ʒ�����ڣ�");*/
	return NULL;
    /**
     * 1.������Ʒ�����ƣ�������ƴ������ӡ��Ʒ��Ϣ
     * 2.�����Ʒ����������ʾ��Ʒ������
     */
}

/*����pre*/ 
GoodList *pre_search(GoodList *L,GoodList *p)
{
	GoodList *pre=L;
	
	while((pre!=NULL)&&(pre->next!=p)) 
		 pre=pre->next;
    return pre;
}
