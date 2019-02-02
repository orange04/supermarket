#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "base.h"
#include "define_my.h"
#include "menu.h"

void OutputAll(GoodList *L)
{
     GoodList *p=L;
     
	 for(;p!=NULL;p=p->next)
	 {
		Goodprint(p);
 	 }
 	 
	 /**
     * 1.���������ݽ��ж�ȡ��Ȼ�������Ʒ��Ϣ
     */
        
}

void info_change(GoodList **L)
{
	 GoodList *p;
	  
	 printf("������Ҫ�޸ĵ���ƷID��-1�˳����ң���");
	 p=info_search(*L);
	 if(p==NULL)
       return NULL;
     printf("�����µ���Ʒ��Ϣ: \n");
	 printf("��ƷID: ");
	 scanf("%s",p->data.good_id);
	 printf("��Ʒ����:");                 
	 scanf("%s",p->data.good_name);
	 printf("��Ʒ�۸�: ");
	 scanf("%d",&(p->data.good_price));
	 printf("��Ʒ�ۿ�: ");
	 scanf("%s",p->data.good_discount);
	 printf("��Ʒ����: ");
	 scanf("%d",&(p->data.good_amount));
	 printf("��Ʒʣ��: ");
	 scanf("%d",&(p->data.good_remain));
     
     printf("�޸���Ʒ��Ϣ�ɹ����޸ĺ����ƷΪ��\n");
     Goodprint(p);
}
	 
	     /**                
		 * 1.������Ʒ�����ƣ�������ƴ������ӡ��Ʒ��Ϣ
         * 2.Ȼ���û������µ���Ʒ��Ϣ
         * 3.���Ҫ�޸ĵ���Ʒ���ڲ�����Ϣ���������������޸ĳɹ��������´�ӡ�����ѡ�����
         */       



void info_insert(GoodList **L)
{
	 GoodList *p=*L;
	 GoodList *pre=*L;
	 GoodList *new;
	 int location,i=0;
	 new=malloc(sizeof(GoodList));
	 
	 printf("������Ҫ�������Ʒ��Ϣ��\n");
	 printf("��ƷID: ");
	 scanf("%s",new->data.good_id);
	 printf("��Ʒ����: ");
	 scanf("%s",new->data.good_name);
	 printf("��Ʒ�۸�: ");
	 scanf("%d",&(new->data.good_price));
	 printf("��Ʒ�ۿ�: ");
	 scanf("%s",new->data.good_discount);
	 printf("��Ʒ����: ");
	 scanf("%d",&(new->data.good_amount));
	 printf("��Ʒʣ��: ");
	 scanf("%d",&(new->data.good_remain));
	 printf("�������ֱ�����Ҫ�������Ʒλ�ã�0.��Ʒ�б�β�� 1.��Ʒ�б�ͷ�� i.��Ʒ�б��м��i��λ��");
	 scanf("%d",&location);
	 
	 if(location==1)
	   {new->next=*L;*L=new;printf("\n");}
	 else if(location==0)
	   {for(p=*L;(p->next)!=NULL;p=p->next);
	 	  p->next=new;
	      printf("\n");}
     else
 	 {for(i=1;i<location;i++)
		 	p=p->next;
	 	pre=pre_search(*L,p);
 		new->next=pre->next;
        pre->next=new;
		printf("\n");}
     CurrentCnt++;
}	
	
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



void info_dele(GoodList **L)  
{
	char command,id[MAX_ID_LEN];
	GoodList *p,*pre;
	
	printf("������Ҫɾ������ƷID(-1�˳�ɾ��)��");
	p=info_search(*L);
	if(p==NULL)
	 {printf("\n");return NULL;}
	strcpy(id,p->data.good_id);
	printf("�Ƿ�ɾ������Ʒ(Y/N):\n");
	scanf(" %c",&command);
	if(command=='y'||command=='Y')
	 {  if(p==*L)
  		{*L=(*L)->next;free(p);}
	  else 
	  {pre=pre_search(*L,p);
	   pre->next=p->next;
	   free(p);
	   printf("Tips:ɾ��IDΪ%s����Ʒ�ɹ�\n",id);
       printf("Tips:��ǰʣ����Ʒ%d��\n\n",CurrentCnt);}
      CurrentCnt--;}
    else
     return NULL;
}
     
     /**
     * 1.������Ʒ�����ƣ�������ƴ�����ɾ����Ʒ��Ϣ�����ͷŶ�Ӧָ����ָ����ڴ棬
     *   ���ҽ���ָ�븳ֵΪ�գ�Ȼ���ӡ��ɾ���ɹ�����ʾ
     * 2.����������Ʒ���Ʋ������������Ʒ�����ڵ���ʾ
     */





void GoodSearch(GoodList *L)
{
	char name[MAX_NAME_LEN];
	GoodList *p;
	
	printf("������Ҫ���ҵ���Ʒ���ƣ�-1�˳����ң���");
	scanf("%s",name);
	if(strcmp(name,"-1")==0)
	   {printf("\n"); return NULL;}
	for(p=L;p!=NULL;p=p->next)  
	 {
 		if(strcmp(p->data.good_name,name)==0||strcmp(p->data.good_id,name)==0)
 		 {Goodprint(p); 
		  return NULL;} 
 	}
 	printf("��Ҫ��ѯ����Ʒ�����ڣ�\n\n");
    /**
     * 1.������Ʒ�����ƣ�������ƴ������ӡ��Ʒ��Ϣ
     * 2.�����Ʒ����������ʾ��Ʒ������
     */
}


void info_flush(GoodList **L) 
{
	FILE *fp;
	GoodList *p;
	int savecount=0;
	
	fp=fopen("goodinfo.txt", "w");
	for(p=*L;p!=NULL;p=p->next)
	{
		fprintf(fp,"\n%s\t%s\t%d\t%s\t%d\t%d",p->data.good_id,p->data.good_name,
       p->data.good_price,p->data.good_discount,p->data.good_amount,p->data.good_remain);
	        savecount++;
	}
	fclose(fp);
	DestroyGoods(L);
	CurrentCnt = 0;
    if(fp!=NULL)
	printf("Tips��%d����Ʒ��Ϣ����Goodinfo.txt�ļ�\n",savecount);
    else 
	printf("Tips��δд���κ���Ʒ��Ϣ��Goodinfo.txt�ļ�\n");
	exit(0);
}
	
	/**
     * 1.����������д�뵽goodinfo.txt
     * 2.��������
     * 3.��Ʒ������0
     * �ļ���Ϣ�Ķ�д�ɲ���fileIOreferrence����
     */
    //    ������ݲο���
    //    if .... printf("��ʾ��%d����Ʒ��Ϣ����Goodinfo.txt�ļ�\n", savecount);
    //    else printf("��ʾ��δд���κ���Ʒ��Ϣ��Goodinfo.txt�ļ�\n");

void bubble_sort(GoodList **L)
{
	 GoodInfo temp;
	 GoodList *cur1=*L,*cur2,*later;

	 for(cur1=*L;(cur1->next)!=NULL;cur1=cur1->next){
	 	
 		for(cur2=*L;(cur2->next)!=NULL;cur2=later){
 			later=cur2->next;
	        if((cur2->data.good_price)>(later->data.good_price))
              {   temp=cur2->data;
	              cur2->data=later->data;
	              later->data=temp;
		      }
	    }
 	 } 
	 printf("��ǰ��������%d����Ʒ",CurrentCnt);
     OutputAll(*L);
}
	     
     /**
     * 1.����ð���������Ʒ����������򣬰��ռ۸�ӵ͵��߽�������
     * 2.Ȼ�������������Ʒ����
     */




void DelAll(GoodList **L) 
{
	FILE *fp;
	fp = fopen("goodinfo.txt", "w");
	fclose(fp);
	DestroyGoods(L);
	*L=malloc(sizeof(GoodList));
	 
    /**
     * 1.��մ洢��Ʒ���ݵ��ļ�
     * 2.�����Ʒ�����������еĽڵ㣬���½�һ��������ͷ
     */
}


bool check_nullfile(void)
{
    FILE *fp = fopen("goodinfo.txt", "r");
    //file not exist
    if (!fp) {
        printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
        FILE *fp = fopen("goodinfo.txt", "w");
        fclose(fp);
        return false;
    }
        //file already exist
    else {
        int temp;
        //res for try to read file if file null feof() can't determine whether file is null or not
        int res = fscanf(fp, "%d", &temp);
        fclose(fp);
        if (res <= 0)
            return false;
        else
            return true;
    }
}


void info_init(GoodList**L)
{
	FILE *fp;
	GoodList*cur=*L,*later;
	later=NULL;
    if(check_nullfile()){
	fp = fopen("goodinfo.txt", "r");
	for(;!feof(fp);)
 	  {
	 	fscanf(fp, "%s%s%d%s%d%d", 
	        cur->data.good_id,cur->data.good_name,&(cur->data.good_price),
	        cur->data.good_discount,&(cur->data.good_amount),&(cur->data.good_remain));
        later=malloc(sizeof(GoodList));
		cur->next=later;
        later=cur;
        cur=later->next;
        
        CurrentCnt++;
	  }
	  later->next=NULL;
    }
    
}
	/*printf("��Ʒ�������ļ��ѽ�������%d����Ʒ��¼\n", CurrentCnt);
     /**
     * 1.�ж�goodinfo.txt�Ƿ���ڣ����������½�һ��goodinfo.txt
     * 2.��δ�ﵽ�ļ�β������£����ļ��ж�ȡ��Ʒ��Ϣ
     * 3.Ȼ���½�����
     * �ļ���Ϣ�Ķ�д�ɲ���fileIOreferrence����
     */


#endif