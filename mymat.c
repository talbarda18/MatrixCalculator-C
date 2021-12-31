/*each "check" function make the validation chekings for each function*/
/*includes the main function and matches each command to its function*/


#include "mat.h"
/*#include "mat.c"
#include "add_func.c"*/


int flag = 1;

static struct matsTable {
				char *name;
				mat *matrix;}mats[6];
				
/*functions declerations*/
void check_read_mat(struct matsTable *mats);
void check_print_mat(struct matsTable *mats);
void check_add_mat(struct matsTable *mats);
void check_sub_mat(struct matsTable *mats);
void check_mul_mat(struct matsTable *mats);
void check_mul_scalar(struct matsTable *mats);
void check_trans_mat(struct matsTable *mats);
void check_stop(struct matsTable *mats);

void zeroize_mat(mat*,mat*,mat*,mat*,mat*,mat*);
void build_mat_struct_arr(mat*,mat*,mat*,mat*,mat*,mat*);
	
mat *get_mat(struct matsTable *mats);



/*-----------------------------------------main----------------------------------------------*/
int main()
{
	char command[30];
	int i;
	struct{
		char *name;
		void (*func)(struct matsTable *mats);
		}cmd[9]={{"read_mat",check_read_mat},{"print_mat",check_print_mat},{"add_mat",check_add_mat},{"sub_mat",check_sub_mat},{"mul_mat",check_mul_mat},{"mul_scalar",check_mul_scalar},{"trans_mat",check_trans_mat},{"stop",check_stop},{"not_valid",NULL}};

	mat MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F;
		
	zeroize_mat(&MAT_A,&MAT_B,&MAT_C,&MAT_D,&MAT_E,&MAT_F);/*set all matrix cells to 0*/
	build_mat_struct_arr(&MAT_A,&MAT_B,&MAT_C,&MAT_D,&MAT_E,&MAT_F);	
	
	printf("\nThis is a Matrix Calculator\n list of commands:\n\t1)read_mat MatName ,num1,...,num16\n\t2)print_mat MatName\n\t3)add_mat FirstMatName,SecondMatName,DestenationMatName\n\t4)sub_mat FirstMatName,SecondMatName,DestenationMatName\n\t5)mul_mat FirstMatName,SecondMatName,DestenationMatName\n\t6)mul_scalar MatName,Scalar,DestenationMatName\n\t7)trans_mat _mat MatName,DestenationMatName\n\t8)stop\n");
	
	while(flag == 1)/*while flag==1 the program is on the run, it stops when it recieve "stop" command*/
	{	
	/*analysing the command*/				
		printf("\nEnter command line:\n");
		if(scanf("%s",command)==1)
		{
			printf("%s",command);
			for(i=0;cmd[i].func!=NULL;i++)
				if(strcmp(command,cmd[i].name)==0)
					break;
				
			if(cmd[i].func==NULL)
			{
				check_rest();
				printf("\nUndefined command name\n");
			}
			else
				(*(cmd[i].func))(mats);	
		}	
	}
		return 0;				
}

/*each "check" function make the validation chekings for each function, and give feedback if invalid*/

/*-----------------------------------------------check_read_mat-----------------------------------------------*/
void check_read_mat(struct matsTable *mats)
{
	int i=0;
	mat *ptr = NULL;
	double *num , numArr[(SIZE*SIZE)];	
	
	zero_arr(numArr);/*put zeros to the numbers*/
		
	if((ptr = get_mat(mats))!= NULL)
	{
			if(!find_comma() && i==0)
			{
				check_rest();
				printf("\nMissing comma\n");	
			}			
			/*while(i<(SIZE*SIZE))
			{
				if(find_comma())
				{
					if((num = get_num()))
					{
						numArr[i] = *num;
						i++;
					}
					else
					{
						printf("\nArgument is not a real number\n");
						return;
					}					
				}
				else
				{
					check_rest();
					break;
				}
			}*/
			do
			{
				if((num = get_num()))
				{
					numArr[i] = *num;
					i++;
				}
				else
				{
					printf("\nArgument is not a real number\n");
					return;
				}
			}
			while(find_comma() && i<(SIZE*SIZE));

		if(!(check_rest()) && i<=(SIZE*SIZE))/*check the check_rest here*/
			read_mat(ptr,numArr,i);
		else
		{
			printf("\nExtraneous text after end of command\n");
			return;
		}
	}
	return;
}
/*-----------------------------------------------check_print_mat-----------------------------------------------*/
void check_print_mat(struct matsTable *mats)
{
	mat *ptr = NULL;
	
	if((ptr = get_mat(mats))!= NULL)
	{
		if(!check_rest())
			print_mat(ptr);
		else
			printf("\nExtraneous text after end of command\n");
	}
	else
		printf("\nMissing argument \n");
			
return;
}
/*-----------------------------------------------check_add_mat-----------------------------------------------*/
void check_add_mat(struct matsTable *mats)
{
	mat *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
	
	if((ptr1 = get_mat(mats))!= NULL)
	{
		if(find_comma())
		{
			if((ptr2 = get_mat(mats))!= NULL)
			{
				if(find_comma())
				{
					if((ptr3 = get_mat(mats))!= NULL)
					{	
						if(!check_rest())
							add_mat(ptr1,ptr2,ptr3);
						else
						{
							printf("\nExtraneous text after end of command\n");
							return;
						}
					}
					else
						printf("\nMissing argument \n");		
				}
				else
				{
					check_rest();	
					printf("\nMissing comma\n");
				}					
			}
			else
				printf("\nMissing argument \n");			
		}
		else
		{
			check_rest();	
			printf("\nMissing comma\n");
		}	
	}
	else
		printf("\nMissing argument \n");

	return;	
}
/*-----------------------------------------------check_sub_mat-----------------------------------------------*/
void check_sub_mat(struct matsTable *mats)
{	
	mat *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
	
	if((ptr1 = get_mat(mats))!= NULL)
	{
		if(find_comma())
		{
			if((ptr2 = get_mat(mats))!= NULL)
			{
				if(find_comma())
				{
					if((ptr3 = get_mat(mats))!= NULL)
					{	
						if(!check_rest())
							sub_mat(ptr1,ptr2,ptr3);
						else
							printf("\nExtraneous text after end of command\n");
					}
					else
						printf("\nMissing argument \n");		
				}
				else
				{
					check_rest();	
					printf("\nMissing comma\n");
				}	
			}
			else
			{
				printf("\nMissing argument \n");
				return;
			}
							
		}
		else
		{
			check_rest();	
			printf("\nMissing comma\n");
		}	
	}
	else
		printf("\nMissing argument \n");
		
	return;
}
/*-----------------------------------------------check_mul_mat-----------------------------------------------*/
void check_mul_mat(struct matsTable *mats)
{
	mat *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
	
	if((ptr1 = get_mat(mats))!= NULL)
	{
		if(find_comma())
		{
			if((ptr2 = get_mat(mats))!= NULL)
			{
				if(find_comma())
				{
					if((ptr3 = get_mat(mats))!= NULL)
					{	
						if(!check_rest())
							mul_mat(ptr1,ptr2,ptr3);
						else
							printf("\nExtraneous text after end of command\n");
					}
					else
						printf("\nMissing argument \n");		
				}
				else
				{
					check_rest();	
					printf("\nMissing comma\n");
				}		
			}
			else
				printf("\nMissing argument \n");			
		}
		else
		{
			check_rest();	
			printf("\nMissing comma\n");
		}		
	}
	else
		printf("\nMissing argument \n");
		
	return;	
}
/*-----------------------------------------------check_mul_scalar-----------------------------------------------*/
void check_mul_scalar(struct matsTable *mats)
{
	mat *ptr1, *ptr2;
	double *scalar;
	scalar = 0;
	
	if((ptr1 = get_mat(mats))!= NULL)
	{
		if(find_comma())
		{
			if((scalar = get_num()))
			{
				if(find_comma())
				{
					if((ptr2 = get_mat(mats))!= NULL)
					{
						if(!check_rest())
							mul_scalar(ptr1,*scalar,ptr2);
						else
							printf("\nExtraneous text after end of command\n");
					}
					else
						printf("\nMissing argument \n");
				}
				else
				{
					check_rest();	
					printf("\nMissing comma\n");
				}											
			}
			else
			{
				printf("\n Argument is not a scalar\n");
			}			
		}
		else
		{
			check_rest();	
			printf("\nMissing comma\n");
		}		
	}
	else
		printf("\nMissing argument \n");	
			
	return;	
}	

/*-----------------------------------------------check_trans_mat-----------------------------------------------*/
void check_trans_mat(struct matsTable *mats)
{
	mat *ptr1,*ptr2;
	
	if((ptr1 = get_mat(mats))!= NULL)
	{
		if(find_comma())
		{
			if((ptr2 = get_mat(mats))!= NULL)
			{
				if(!check_rest())
					trans_mat(ptr1,ptr2);
				else
					printf("\nExtraneous text after end of command\n");
			}
			else
				printf("\nMissing argument \n");					
		}
		else
		{
			check_rest();
			printf("\nMissing comma\n");
		}	
	}
	else
	printf("\nMissing argument \n");
	

}	
	
/*-----------------------------------------------check_stop-----------------------------------------------*/	
void check_stop(struct matsTable *mats)
{
	if(!check_rest())
		flag = 0;
	else
		printf("\nExtraneous text after end of command\n");	
}	
	
/*-----------------------------------------------zeroize_mat-----------------------------------------------*/		
/*put all the matrixes cells to zeroes*/
void zeroize_mat(mat* matA,mat* matB,mat* matC,mat* matD,mat* matE,mat* matF)
{
	int i,j;
	
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
		{
			(*matA)[i][j]=0;
			(*matB)[i][j]=0;
			(*matC)[i][j]=0;
			(*matD)[i][j]=0;
			(*matE)[i][j]=0;
			(*matF)[i][j]=0;
		}
}

/*-------------------------------------------get_mat----------------------------------------------------*/
/*assistance function that analys the matrix names and return the matrix itself*/
mat *get_mat(struct matsTable *mats)
{
	char *matName = NULL;
	int i;
	
	matName = (char*)malloc(MAXSIZE*sizeof(char));
	if(!matName)/*cant allocate memory*/
	{
		printf("\ncant allocate memory\n");
		return NULL;
	}
	else
	{
		matName = get_word();
		if(matName)
		{
			printf("%s",matName);
			for(i=0;i<6;i++)
			{
				if(strcmp(matName,mats[i].name)==0)
					return (mats[i].matrix);
			}
			check_rest();
			printf("\nUndefined matrix name\n");
			return NULL;	

		}
		else
			return NULL;
			/*printf("\nMissing argument \n");*/
	}	
	return NULL;	
}	
	
	
/*-------------------------------------------build_mat_struct_arr----------------------------------------------*/
/*function puts all the matrixes in mats type array for ease access*/	
void build_mat_struct_arr(mat* matA,mat* matB,mat* matC,mat* matD,mat* matE,mat* matF)	
{	
	mats[0].name="MAT_A";
	mats[0].matrix = matA;
	mats[1].name="MAT_B";
	mats[1].matrix = matB;
	mats[2].name="MAT_C";
	mats[2].matrix = matC;
	mats[3].name="MAT_D";
	mats[3].matrix = matD;
	mats[4].name="MAT_E";
	mats[4].matrix = matE;
	mats[5].name="MAT_F";
	mats[5].matrix = matF;

}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

