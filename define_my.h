#ifndef DEFINE_MY_H
#define DEFINE_MY_H 
//--------------------------------------------------------------------
//��Ʒ���������
//--------------------------------------------------------------------
#define MAX 100
//--------------------------------------------------------------------
//��Ʒ��Ϣ�ṹ�Ķ���
//--------------------------------------------------------------------
#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct {
    char	good_id[MAX_ID_LEN];
    char	good_name[MAX_NAME_LEN];
    int  	good_price;
    char	good_discount[MAX_DISCOUNT_LEN];
    int		good_amount;
    int		good_remain;
}GoodInfo;


//--------------------------------------------------------------------
//ȫ�ֱ������洢��ǰ��Ʒ������
//--------------------------------------------------------------------
extern int CurrentCnt=0;

//--------------------------------------------------------------------
//������Ʒ����Ľ��
//--------------------------------------------------------------------
typedef struct node
{
    GoodInfo data;
    struct node *next;
}GoodList;

#endif