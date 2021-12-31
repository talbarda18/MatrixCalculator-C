/*include all the calculating functions*/
#include "mat.h"

static mat tmpMat;

/*-------------------------------------------read_mat----------------------------------------------------*/
void read_mat(mat *matrix ,double numArr[] ,int lastOne)
{
	int i,j;
	int t=0;
	
	for (i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{	
			(*matrix)[i][j]=numArr[t];
			t++;
		}
	}
}

/*-------------------------------------------print_mat----------------------------------------------------*/
void print_mat(mat* matrix)
{
	int i,j;
	double num;
	printf("\n");
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			num = (*matrix)[i][j];
			printf("%10.2f",num);
		}
		printf("\n");
	}
}

/*-------------------------------------------add_mat----------------------------------------------------*/
void add_mat(mat* mat1,mat* mat2,mat* mat3)
{
	int i,j;
	double sum;
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			sum = (*mat1)[i][j]+(*mat2)[i][j];
			(*mat3)[i][j]=sum;
		}
	}
}

/*-------------------------------------------sub_mat----------------------------------------------------*/
void sub_mat(mat* mat1,mat* mat2,mat* mat3)
{
	int i,j;
	double diff;
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			diff = (*mat1)[i][j]-(*mat2)[i][j];
			(*mat3)[i][j]=diff;
		}
	}
}	

/*-------------------------------------------mul_mat----------------------------------------------------*/
void mul_mat(mat* mat1,mat* mat2,mat* mat3)
{
	int i,j,t;
	double mulRes;
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			mulRes = 0;
			for(t=0;t<SIZE;t++)
			{
				mulRes += (*mat1)[i][t]*(*mat2)[t][j];
			}
			tmpMat[i][j]=mulRes;
		}
	}
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			(*mat3)[i][j]=tmpMat[i][j];
		}
	}
}
/*-------------------------------------------mul_scalar----------------------------------------------------*/
void mul_scalar(mat* mat1,double scalar,mat* mat2)
{
	int i,j;
	double mulRes;
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			mulRes = scalar * ((*mat1)[i][j]);
			(*mat2)[i][j]=mulRes;
		}
	}
}

/*-------------------------------------------trans_mat----------------------------------------------------*/
void trans_mat(mat* mat1,mat* mat2)
{
	int i,j;
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			tmpMat[j][i] = (*mat1)[i][j];
		}
	}
	
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			(*mat2)[i][j]=tmpMat[i][j];
		}
	}		
}

















