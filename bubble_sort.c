#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *p, int *q);
int *create_array(int r);
void print_array(int *tab, int r);
void swap(int *wsk1, int *wsk2);


int main(void)
{
	srand(time(NULL));
	
	int a; //rozmiar tablicy
	
		printf("podaj rozmiar tablicy: ");
			scanf("%d",&a);
	
	int *t1=create_array(a);
	
	//print_array(t1, a);
	
	clock_t start, end;
	double time;
	
	start=clock();
	
	bubble_sort(&t1[0], &t1[a-1]);
	
	end=clock();
	
	time = (double)(end-start) / CLOCKS_PER_SEC;
	
	printf("Execution time: %f seconds",time);
	
	//print_array(t1, a);
	
	free(t1);
	
	return 0;
}

void bubble_sort(int *p, int *q)
{
	int *i; // * ?
	int *j; // * ?
	for(i=p ; i<q ; i++) // przesuwa po kolei do konca tablicy
	{
		for(j=p ; j<q-(i-p) ; j++) // koniec - (i - poczatek) //
		{
			if(*j>*(j+1)) // p+1 ? 
			{
				swap(j,j+1);
			}
		}
	}
	
}

int *create_array(int r)
{
	int *tab=malloc(r*sizeof(int));
	
	int i;
	for(i=0 ; i<r ; i++)
	{
		tab[i]=rand() % (-100 - 100+1)+(-100) ;
	}
	
	return tab;
}

void print_array(int *tab, int r)
{
	int i;
	for(i=0 ; i<r ; i++)
		printf(" %d |",tab[i]);
	
	printf("\n");
}

void swap(int *wsk1, int *wsk2)
{
	int zamiana;
	zamiana=*wsk1;
	*wsk1=*wsk2;
	*wsk2=zamiana;
}

