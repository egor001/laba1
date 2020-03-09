#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef struct vector {
	char bukva; //�������� �������?
	int size; //�� ������������
	void* buf;
} vector;

void vvod(vector* nov, int n, int k)
{

	int count = 0;
	int shet;
	//��������� ����� ��� ������ vector , ������� ����� ��������� �������
	nov = (vector*)calloc(1, sizeof(vector));
	//��������� ����� ��� n ��������
	nov->buf = (vector*)calloc(n, sizeof(vector));
	//��������� ����� ��� k ����� � �������� 
	int i;
	for( i = 0; i < n; ++i)
		((vector*)nov->buf + i)->buf = (int*)calloc(k, sizeof(int));
	if (nov == NULL) {
		printf("�� ������� �������� ������. ��������� ���������");
		exit(EXIT_FAILURE);
	}
	while (count < n)
	{
		printf("������� �������� �����\n");
		((vector*)nov->buf + count)->bukva = _getche();
		printf("\n");
		shet = 0;
		while (shet < k) {
			printf("������� �������� ������\n ");
			scanf("%d", &((int*)((vector*)nov->buf + count)->buf)[shet]);
			shet++;
		}

		count++;
	}
	count = 0;
	shet = 0;
	while (count < n) {
		shet = 0;
		printf("%c\n", ((vector*)nov->buf + count)->bukva);
		while (shet < k) {
			printf("%d\n", ((int*)((vector*)nov->buf + count)->buf)[shet]);
			shet++;
		}
		count++;
	}
	//������������ ������ ��� �����
	
	for ( i = 0; i < n; ++i)
		free(((vector*)nov->buf + i)->buf);
	//������������ ������ ��� �����
	if(nov->buf)
		free(nov->buf);
	//������������ ��� ������ vector
	if(nov)
		free(nov);
}
/*  void find_skalar(struct vector* nov,int n) //функция нахождения скалярного произведения двух векторов
{
	printf("выберете две буквы");
	int count=0;
	int i=0;
	double skal_pr,tochka1,tochka2,prx1,prx2,pry1,pry2;
	tochka1=getche();
	printf("\n");
	tochka2=getche();
	printf("\n");
	while(count < n)
	{
		if(*(double*)nov[count].bukva==tochka1)
		{
			prx1=*(double*)nov[count].x;
			pry1=nov[count].y;
			i++;
		}
		if(nov[count].bukva=tochka2)
		{
			prx2=nov[count].x;
			pry2=nov[count].y;
			i++;
		}
		if(i=2)
		break;
	}
	skal_pr=prx1*prx2+pry1*pry2;
	printf("%f",skal_pr);
	}
*/
int main(void)
{
	setlocale(LC_ALL, "Rus");
	printf("������� ��������� �����");
	int n;
	scanf("%d", &n);
	printf("������� ���������� ����");
	int k;
	scanf("%d", &k);
	while (n < 1) {
		printf("������� ����������� ��������� �����");
		scanf("%d", &n);
	}
	vector *nov = NULL;
	vvod(nov, n, k);
	return(0);
}

