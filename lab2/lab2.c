#include "bstree.h"
#include "htable.h"
#include "service.h"
#include <stdlib.h>
#include <stdio.h>

#define N 200491
#define M 32

int main(int argc, char *argv[])
{
	int mode_test = atoi(argv[1]), i;

	double t;

	FILE *input_sort = fopen("stest.dat", "r");
	FILE *input_unsort = fopen("utest.dat", "r");
	FILE *output_bs, *output_ht;
	
	if (input_sort == NULL)
	{
		printf("Unable to open file 'stest.dat'!\n");
		return EXIT_FAILURE;
	}
	
	if (input_unsort == NULL)
	{
		printf("Unable to open file 'utest.dat'!\n");
		return EXIT_FAILURE;
	}
	
	char **text = (char **)malloc(N * sizeof(char *));
	if (text != NULL) 
	{
		for(i = 0; i < N; i++) 
		{
			text[i] = (char *)malloc(M * sizeof(char));
		}
	}
	else 
	{
		printf("Can't create buffer!\n");
	}
	
	switch (mode_test)
	{
		case 1: //Experiment #1
			for (i = 0; i < N; i++) 
			{
				fscanf(input_unsort, "%s\n",text[i]);
				//printf ("buf(%d): %s\n", i+1, text[i]);
			}
			
			//binary search tree
			struct bstree *baum_1 = bstree_create(text[0], 0);
			output_bs = fopen("bstree_1.dat", "w");
			if (output_bs == NULL)
			{
				printf("Unable to open file 'bstree_1.dat'!\n");
				return EXIT_FAILURE;	
			}
			i = 1;
			while (i < N)
			{
				bstree_add(baum_1, text[i], i);
				if (i % 10000 == 0)
				{
					char *w = text[getrand(1, i)];
					t = wtime();
					struct bstree *node = bstree_lookup(baum_1, w);
					t = wtime() - t;
					fprintf(output_bs, "%d\t%0.6f\n", i, t);
				}
				i++;
			}
			
			//hash table
			output_ht = fopen("htable_1.dat", "w");
			if (output_ht == NULL)
			{
				printf("Unable to open file 'htable_1.dat'!\n");
				return EXIT_FAILURE;	
			}
			struct listnode *tisch_1[HASH_SIZE];
			hashtab_init(tisch_1);
			i = 1;
			while (i < N)
			{
				hashtab_add(tisch_1, text[i - 1], i);
				if (i % 10000 == 0)
				{
					char *w = text[getrand(1, i)];
					t = wtime();
					struct listnode *node = hashtab_lookup(tisch_1, w);
					t = wtime() - t;
					fprintf(output_ht, "%d\t%0.6f\n", i, t);
				}
				i++;
			}			
			fclose(output_bs);
			fclose(output_ht);
			break;
		case 4: //Experiment #4
			//the worst case
			for (i = 0; i < N; i++) 
			{
				fscanf(input_sort, "%s\n",text[i]);
				//printf ("buf(%d): %s\n", i+1, text[i]);
			}
			struct bstree *baum_4 = bstree_create(text[0], 0);
			output_bs = fopen("bstree_4_worst.dat", "w");
			if (output_bs == NULL)
			{
				printf("Unable to open file 'bstree_4_worst.dat'!\n");
				return EXIT_FAILURE;	
			}
			i = 1;
			while (i < N)
			{
				bstree_add(baum_4, text[i], i);
				if (i % 10000 == 0)
				{
					t = wtime();
					struct bstree *node = bstree_min(baum_4);
					t = wtime() - t;
					fprintf(output_bs, "%d\t%0.6f\n", i, t);
				}
				i++;
			}		
			fclose(output_bs);
			
			//average case
			for (i = 0; i < N; i++) 
			{
				fscanf(input_unsort, "%s\n",text[i]);
				//printf ("buf(%d): %s\n", i+1, text[i]);
			}
			struct bstree *baum_4a = bstree_create(text[0], 0);
			output_bs = fopen("bstree_4_average.dat", "w");
			if (output_bs == NULL)
			{
				printf("Unable to open file 'bstree_4_average.dat'!\n");
				return EXIT_FAILURE;	
			}
			i = 1;
			while (i < N)
			{
				bstree_add(baum_4a, text[i], i);
				if (i % 10000 == 0)
				{
					t = wtime();
					struct bstree *node = bstree_min(baum_4a);
					t = wtime() - t;
					fprintf(output_bs, "%d\t%0.6f\n", i, t);
				}
				i++;
			}		
			fclose(output_bs);
			
			break;
		case 6: //Experiment #6
			//KP hash
			output_ht = fopen("time6_KP.dat", "w");
			if (output_ht == NULL)
			{
				printf("Unable to open file 'time6_KP.dat'!\n");
				return EXIT_FAILURE;	
			}
			struct listnode *tisch_6[HASH_SIZE];
			hashtab_init(tisch_6);
			int kp_collision = 0;
			i = 1;
			while (i < N)
			{
				hashtab_add(tisch_6, text[i - 1], i);
				if (i % 10000 == 0)
				{
					kp_collision = collision(tisch_6);
					char *w = text[getrand(1, i)];
					t = wtime();
					struct listnode *node = hashtab_lookup(tisch_6, w);
					t = wtime() - t;
					fprintf(output_ht, "%d\t%0.6f\t%d\n", i, t, kp_collision);
				}
				i++;
			}
			fclose(output_ht);
			
			//FNV hash
			output_bs = fopen("time6_FNV.dat", "w");
			if (output_bs == NULL)
			{
				printf("Unable to open file 'time6_FNV.dat'!\n");
				return EXIT_FAILURE;	
			}
			struct listnode *tisch_7[HASH_SIZE];
			hashtab_init(tisch_7);
			int fnv_collision = 0;
			i = 1;
			while (i < N)
			{
				hashtab_add_fnv(tisch_7, text[i - 1], i);
				if (i % 10000 == 0)
				{
					fnv_collision = collision(tisch_7);					
					char *w = text[getrand(1, i)];
					t = wtime();
					struct listnode *node = hashtab_lookup(tisch_7, w);
					t = wtime() - t;
					fprintf(output_bs, "%d\t%0.6f\t%d\n", i, t, fnv_collision);
				}
				i++;
			}
			fclose(output_bs);			
			break;
	}
	free(text);
	fclose(input_sort);
	fclose(input_unsort);
	return 0;
}
