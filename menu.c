#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "base.h"
#include "define_my.h"

void OutputAll(GoodList *L)
{
     GoodList *p;
	 
	 for(p=L;p!=NULL;p=p->next)
	 {
 	    Goodprint(p);	
 	 }
 	 
	 /**
     * 1.���������ݽ��ж�ȡ��Ȼ�������Ʒ��Ϣ
     */
        
}

void info_change(GoodList *L)
{
	 GoodList *p;
	  
	 printf("������Ҫ�޸ĵ���ƷID��-1�˳����ң���");
	 p=info_search(L);
	 //if(p==NULL)
	  //return NULL;
	 printf("��ƷID: ");
	 scanf("%s",p->data.good_id);
	 printf("��Ʒ����:");
	 scanf("%s",p->data.good_name);
	 printf("��Ʒ�۸�: ");
	 scanf("%d",p->data.good_price);
	 printf("��Ʒ�ۿ�: ");
	 scanf("%s",p->data.good_discount);
	 printf("��Ʒ����: ");
	 scanf("%d",p->data.good_amount);
	 printf("��Ʒʣ��: ");
	 scanf("%d",p->data.good_remain);
     
     printf("�޸���Ʒ��Ϣ�ɹ����޸ĺ����ƷΪ��\n");
     Goodprint(p);
	 
	 
	 /**
     * 1.������Ʒ�����ƣ�������ƴ������ӡ��Ʒ��Ϣ
     * 2.Ȼ���û������µ���Ʒ��Ϣ
     * 3.���Ҫ�޸ĵ���Ʒ���ڲ�����Ϣ���������������޸ĳɹ��������´�ӡ�����ѡ�����
     */

}

void info_insert(GoodList *L)
{
	 GoodList *p=L;
	 GoodList *pre=L;
	 GoodList *q;
	 int location,i=0;
	 q=malloc(sizeof(GoodList));
	 
	 printf("������Ҫ�������Ʒ��Ϣ��\n");
	 printf("��ƷID: ");
	 scanf("%s",q->data.good_id);
	 printf("��Ʒ����: ");
	 scanf("%s",q->data.good_name);
	 printf("��Ʒ�۸�: ");
	 scanf("%d",q->data.good_price);
	 printf("��Ʒ�ۿ�: ");
	 scanf("%s",q->data.good_discount);
	 printf("��Ʒ����: ");
	 scanf("%d",q->data.good_amount);
	 printf("R��Ʒʣ��: ");
	 scanf("%d",q->data.good_remain);
	 printf("�������ֱ�����Ҫ�������Ʒλ�ã�0.��Ʒ�б�β�� 1.��Ʒ�б�ͷ�� i.��Ʒ�б��м��i��λ��");
	 scanf("%d",&location);
	 
	 if(location==1)
	   {q->next=L;L=q;}
	 else if(location==0)
	   {for(p=L;p!=NULL;p=p->next);
	 	  p=q;}
     else
 	 {for(i=0;i!=location;i++)
		 	p=p->next;
	 	pre=pre_search(L,p);
 		q->next=pre->next;
        pre->next=q;}
	
	
    /**
     * 1.���������ĳһ����Ʒ����Ϣ������ID�����ơ��۸��ۿۡ�������ʣ��
     * ע������ͨ��scanf()����������������Ʒ��Ϣ��ÿ�������Ի��з���������Ϣ�е�ÿ����Ŀ
     *    �����С��Ʒ��Ϣ�ṹ����ڴ�ռ䣬Ȼ�󽫶�������ݷֱ𿽱����ѷ���õ����ڴ��У�
     *    �����ַ����Ŀ�������ϵͳ����strcpy��
     *    ���⣺����ʹ��ǰ���Զ����read_line�������������ݶ�ȡ
     * 2.�ֱ�ʵ��ͷ�巨��β�巨���м�λ�ò������֣�
     * 3.Ȼ������û�����Ĳ��뷽ʽ������Ӧ�Ľڵ�λ�ò���
     * 4.��ѡ����ID���ڲ����ʱ����Ҫ���в��أ�����Ѿ��и�ID���ˣ���ʾ�ظ�
     */

}

void info_dele(GoodList *L)  
{
	char command;
	GoodList *p,*pre;
	
	printf("������Ҫɾ������ƷID(-1�˳�ɾ��)��");
	p=info_search(L);
	//f(p==NULL)
	 //return NULL;
	printf("�Ƿ�ɾ������Ʒ(Y/N):\n");
	scanf("%c",&command);
	if(command=='y'||command=='Y')
	  {pre=pre_search(L,p);
	  pre->next=p->next;
	  free(p);
	  printf("Tips:ɾ��IDΪ%d����Ʒ�ɹ�");
      printf("Tips:��ǰʣ����Ʒ%d��");}
    //else
     //return NULL;
     
     
     /**
     * 1.������Ʒ�����ƣ�������ƴ�����ɾ����Ʒ��Ϣ�����ͷŶ�Ӧָ����ָ����ڴ棬
     *   ���ҽ���ָ�븳ֵΪ�գ�Ȼ���ӡ��ɾ���ɹ�����ʾ
     * 2.����������Ʒ���Ʋ������������Ʒ�����ڵ���ʾ
     */

}



GoodList *GoodSearch(GoodList *L)
{
	char *name;
	GoodList *p;
	
	printf("������Ҫ���ҵ���Ʒ���ƣ�-1�˳����ң���");
	scanf("%s",name);
	if(strcmp(name,"-1")==0)
	   return NULL;
	for(p=L;p!=NULL;p=p->next)  
	 {
 		if(strcmp(p->data.good_name,name)==0||strcmp(p->data.good_id,name)==0)
 		 {Goodprint(p); 
		  return p;} 
 	}
 	printf("��Ҫ��ѯ����Ʒ�����ڣ�");
	return NULL;
    /**
     * 1.������Ʒ�����ƣ�������ƴ������ӡ��Ʒ��Ϣ
     * 2.�����Ʒ����������ʾ��Ʒ������
     */
}


void info_flush(GoodList *L) 
{
	FILE *fp;
	GoodList *p;
	int savecount=0;
	
	fp=fopen("goodinfo.txt", "r");
	for(p=L;p!=NULL;p=p->next)
	{
		fprintf(fp,"%s\t%s\t%d\t%s\t%d\t%d\n",p->data.good_id,p->data.good_name,p->data.good_price,
	        p->data.good_discount,p->data.good_amount,p->data.good_remain);
	        savecount++;
	}
	fclose(fp);
	//DestroyGoods(L);
	CurrentCnt = 0;
    if(fp!=NULL)
	printf("Tips��%d����Ʒ��Ϣ����Goodinfo.txt�ļ�\n",savecount);
    else 
	printf("Tips��δд���κ���Ʒ��Ϣ��Goodinfo.txt�ļ�\n");
	exit(0);
  
	
	/**
     * 1.����������д�뵽goodinfo.txt
     * 2.��������
     * 3.��Ʒ������0
     * �ļ���Ϣ�Ķ�д�ɲ���fileIOreferrence����
     */
    //    ������ݲο���
    //    if .... printf("��ʾ��%d����Ʒ��Ϣ����Goodinfo.txt�ļ�\n", savecount);
    //    else printf("��ʾ��δд���κ���Ʒ��Ϣ��Goodinfo.txt�ļ�\n");
}

void bubble_sort(GoodList *L)
{
	 GoodInfo temp;
	 GoodList *p,*q;
	 
	 
	 for(q=L;q!=NULL;q=q->next){
 		for(p=L;p!=NULL;p=p->next){
	        if(p->data.good_price>((p->next)->data.good_price))
              {   temp=p->data;
	              p->data=(p->next)->data;
	              (L->next)->data=temp;}
	    }
 	 } 
	 printf("��ǰ��������%d����Ʒ",CurrentCnt);
     OutputAll(L);
	     
     /**
     * 1.����ð���������Ʒ����������򣬰��ռ۸�ӵ͵��߽�������
     * 2.Ȼ�������������Ʒ����
     */
}



void DelAll(GoodList *L) 
{
	//GoodList *p;
	
	FILE *fp;
	fp = fopen("goodinfo.txt", "w");
	//DestroyGoods(L);
	p=malloc(sizeof(GoodList));
	 
    /**
     * 1.��մ洢��Ʒ���ݵ��ļ�
     * 2.�����Ʒ�����������еĽڵ㣬���½�һ��������ͷ
     */
}
