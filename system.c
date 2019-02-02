#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "base.h"
#include "menu.h"

int main()
{   
    int command;
    GoodList *L;

    L=malloc(sizeof(GoodList));
    if(L==NULL)
     {printf("����ռ�ʧ��!");exit(0);}
    check_nullfile();
    info_init(&L);
    
    for(;;){
    	printf("��Ʒ�������ļ��ѽ�������%d����Ʒ��¼\n", CurrentCnt);
    	printf("������Ʒ����ϵͳ");
        printf("\n****************************************\n");
        printf("1.��ʾ������Ʒ����Ϣ��\n"
               "2.�޸�ĳ����Ʒ����Ϣ��\n"
		       "3.����ĳ����Ʒ����Ϣ��\n"
		       "4.ɾ��ĳ����Ʒ����Ϣ��\n"
		       "5.����ĳ����Ʒ����Ϣ��\n"
		       "6.��Ʒ���̲��˳�ϵͳ��\n"
		       "7.����Ʒ�۸��������\n"
		       "8.�����ã�ɾ���������ݣ�\n"
		       "����.�����̲��˳�ϵͳ��\n");
        printf("****************************************\n");
        printf("��������ѡ��");
        scanf("%d",&command);

 switch (command){
     	   case 1: OutputAll(L);break;
     	   case 2: info_change(&L);break;
     	   case 3: info_insert(&L);break;
     	   case 4: info_dele(&L);break;
     	   case 5: GoodSearch(L);break;
     	   case 6: info_flush(&L);break;
     	   case 7: bubble_sort(&L);break;
     	   case 8: DelAll(&L);break;
     	   default: exit(0);
     }
    }
	return 0;
    
}