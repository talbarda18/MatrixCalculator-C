/*includes extra functions that make some background work with input*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "mat.h"


enum{FULL,EMPTY};

int gerFlag = EMPTY,buff;

/*-------------------------------------------getchh----------------------------------------------------*/
int getchh(void)
{
	if(gerFlag  == FULL)
	{
		gerFlag  = EMPTY;
		return buff;
	}
	else
		return getchar();
}
/*-------------------------------------------ungetchh----------------------------------------------------*/
void ungetchh(int current)
{
	if(gerFlag  == EMPTY)
	{
		buff = current;
		gerFlag  = FULL;
	}
}
/*-------------------------------------------get_word----------------------------------------------------*/
/*function that read words till space/comma , print it and return it*/
char *get_word()
{
	int i=0;
	char *word = NULL; 
	int current;
	
	word = (char*)malloc(MAXSIZE*sizeof(char));
	if(!word)/*cant allocate memory*/
	{
		printf("\ncant allocate memory\n");
		return NULL;
	}
	else
	{
		while(isspace(current=getchh()) && (current!='\n') && (current != EOF))
			printf(" ");/*skip all spaces*/
		
		*(word+i)=current;
	
		while(!(isspace(current=getchh()))&& (current!='\n') && (current != EOF) && (current != ','))/**/
		{
			i++;
			*(word+i)=current;
		}
		ungetchh(current);
		
		if(word == NULL)
		{
			return NULL;
		}
		
		if(*word == ',')/*looking for multiple consecutive commas*/
		{
			printf("%s",word);
			check_rest();
			printf("\nIllegal comma\n");
			return NULL;
		}
		if(*word == EOF)
		{
			printf("\nunexpected End Of File\n");
			ungetchh(EOF);
			return NULL;
		}
			
	}
	return word;		
}



/*-------------------------------------------find_comma----------------------------------------------------*/
/*function that assist in finding commas in the command*/
int find_comma()
{
	char current;
	
	while(isspace(current=getchh()) && (current!='\n') && (current != EOF))
		printf(" ");/*skip all spaces*/
	
	if(current == ',')
	{
		printf(",");
		return 1;
	}
	else
	{
		ungetchh(current);
		return 0;
	}			
}

/*-------------------------------------------check_rest----------------------------------------------------*/
/*run to the end of the line till '\n' and print the content when its not empty, and report if its empty or not*/
int check_rest()
{
		int current;
		int inputFlag = 0;
		/*char temp1[MAXSIZE];*/
		char *temp;
		
	temp = (char*)malloc(MAXSIZE*sizeof(char));
	if(!temp)/*cant allocate memory*/
	{
		printf("\ncant allocate memory\n");
		return 0;
	}
	else
	{		
		
		while((current = getchh())!='\n' && current != EOF)
		{
			if(isspace(current))
			{
				printf(" ");
				continue;
			}
			else
			{
				inputFlag = 1;
				printf("%c",current);
				fgets(temp,MAXSIZE,stdin);
				printf("%s",temp);
				break;
			}	
		}
				
		if(current == EOF)
		{
			printf("\nunexpected End Of File\n");
		}
		return inputFlag ;
	}		
}

/*-------------------------------------------get_num----------------------------------------------------*/
/*collect the numbers in the input between 2 commas, turn it from string to double*/
double *get_num()
{
	int i=0,current=0;
	char num[MAXSIZE];
	double *number = NULL;
	
	number = (double *)malloc(sizeof(double));
		if(!number)
	{
		printf("\ncan't allocate memory\n");
		return NULL;
	}	
	
	while((current = getchh())==' ' || current =='\t')
	{
		if(current == ' ')
			printf(" ");
		else
			printf("\t");	
	}
			
	if(!isdigit(current) && current != '.' && current != '-')
	{
		printf("%c",current);
		check_rest();
		return NULL;/*not a number*/
	}
	num[i++]=current;
	if(current == '-')/*collect fraction part*/
		while(isdigit(num[i++] = current = getchh()));	
	if(isdigit(current))/*collect integer part*/
		while(isdigit(num[i++] = current = getchh()));
	if(current == '.')/*collect fraction part*/
		while(isdigit(num[i++] = current = getchh()));
	
	num[--i] = '\0';
	if(current == ',')
		ungetchh(current);
	if(current == '\n')
		ungetchh(current);		
	if(current == EOF)
	{
		printf("\nunexpected End Of File\n");
		return NULL;
	}
	*number = atof(num);
		printf("%s",num);
	return number;	
	
}
/*-------------------------------------------zero_arr----------------------------------------------------*/
/*put zeroes in all array cells*/
void zero_arr(double arr[])
{
	int i;
	
	for(i=0;i<(SIZE*SIZE);i++)
		arr[i]=0;
}














