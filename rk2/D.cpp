//D - Сортировка по многим полям

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1234
int perm[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct record
{
	char name[MAX_LEN];
	int val[10];
};

int compare(const void *a, const void *b)
{
	  for (int i = 0; i < 10; i++)
		{
			if ((*(record*)a).val[perm[i]] != (*(record*)b).val[perm[i]])
				return (*(record*)b).val[perm[i]] - (*(record*)a).val[perm[i]];
		}
		return 0;
}


void rec_print(record s)
{
	printf("%s ", s.name);
}

int main()
{
	int n, k;
	if (scanf("%d", &n) != 1)
	{
		return -1;
	}

	if (scanf("%d", &k) != 1)
	{
		return -1;
	}

	if (n > 1000 || k > 10)
	{
		return -2;
	}


	for (int i = 0; i < k; i++)
	{
		int tmp;
		if (scanf("%d", &tmp) != 1)
		{
			return -3;
		}
		perm[i] = tmp-1;
	}

	record *a = new record[n];

	for (int i = 0; i < n; i++)
	{
		if (scanf("%s", a[i].name) == 0)
		{
			printf("name\n");
			return -1;
		}
		for (int j = 0; j < k; j++)
		{
			if (scanf("%d", &a[i].val[j]) != 1)
			{
				printf("val\n");
				return -3;
			}
		}
		
	}

	qsort(a, n, sizeof(record), compare);
	for (int i = 0; i < n; i++)
	{
		rec_print(a[i]);
		printf("\n");
	}

	delete [] a;
	return 0;
}
