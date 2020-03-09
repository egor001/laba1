#include<stdio.h>
#include<malloc.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
typedef struct vector{
	void* bukva;
	int size;
	void* buf;
} vector;
void vvod(vector* nov,int n,int k)
{
	
    int count=0;
    int shet;
	nov=(struct vector*)calloc(n,sizeof(struct vector));
	nov->buf =(int*) calloc(k, sizeof(int*));
	if (nov==NULL){
		printf("Не удалось выделить память. Программа завершена.");
		exit(EXIT_FAILURE);
	}
	while(count<n)
	{
		printf("Введите название точки\n");
		nov[count].bukva=getche();
		printf("\n");
		shet=0;
		while (shet<k){
		printf("Введите координату базиса\n ");
		scanf("%d", &nov[count].buf[shet] );
		shet++;
	}
	
		count++;
	}
	count=0;
	shet=0;
	while(count<n){
		shet=0;
		printf("%s,%d,%d\n",&nov[count].bukva);
		while(shet<k){
			printf("%d\n",&nov[count].buf[shet]);
			shet++;
		}
		count++;
    }
    
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
	printf("введите количество точек");
	void* n;
	scanf("%d", &n);
	printf("веведите количество осей");
	void* k;
	scanf("%d", k);
	while(n<1){
	printf("введено некоректное колличество точек");
	scanf("%d", &n);
    }
	struct vector *nov;
	vvod(nov,*(int*)n,*(int*)k);
	return(0);
}

