#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef struct vector {
	char bukva; //название вектора?
	int size; //не используется
	void* buf;
} vector;

void vvod(vector* nov, int n, int k)
{

	int count = 0;
	int shet;
	//выделение места для одного vector , который будет содержать вектора
	nov = (vector*)calloc(1, sizeof(vector));
	//выделение места для n векторов
	nov->buf = (vector*)calloc(n, sizeof(vector));
	//выделение места для k точек в векторах 
	int i;
	for( i = 0; i < n; ++i)
		((vector*)nov->buf + i)->buf = (int*)calloc(k, sizeof(int));
	if (nov == NULL) {
		printf("Не удалось выделить память. Программа завершена");
		exit(EXIT_FAILURE);
	}
	while (count < n)
	{
		printf("Введите название точки\n");
		((vector*)nov->buf + count)->bukva = _getche();
		printf("\n");
		shet = 0;
		while (shet < k) {
			printf("Введите название базиса\n ");
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
	//Освобождение памяти для точек
	
	for ( i = 0; i < n; ++i)
		free(((vector*)nov->buf + i)->buf);
	//Освобождение памяти для точек
	if(nov->buf)
		free(nov->buf);
	//Освобождение для самого vector
	if(nov)
		free(nov);
}
/*  void find_skalar(struct vector* nov,int n) //С„СѓРЅРєС†РёСЏ РЅР°С…РѕР¶РґРµРЅРёСЏ СЃРєР°Р»СЏСЂРЅРѕРіРѕ РїСЂРѕРёР·РІРµРґРµРЅРёСЏ РґРІСѓС… РІРµРєС‚РѕСЂРѕРІ
{
	printf("РІС‹Р±РµСЂРµС‚Рµ РґРІРµ Р±СѓРєРІС‹");
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
	printf("Введите количство точек");
	int n;
	scanf("%d", &n);
	printf("Введите количество осей");
	int k;
	scanf("%d", &k);
	while (n < 1) {
		printf("Введено некоректное количство точек");
		scanf("%d", &n);
	}
	vector *nov = NULL;
	vvod(nov, n, k);
	return(0);
}

