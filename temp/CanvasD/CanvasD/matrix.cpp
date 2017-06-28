//		Вычисления над матрицами
#include "stdafx.h"
#include <math.h>
#include "matrix.h"

double *CreateMatr (int n, int m)
{
	double *matr = new double[n*m];

	return matr;
}


void ClearMatr (double *matr)
{
	if (matr)
		delete [] matr;
}


void ClearMatr(int *matr)
{
	if (matr)
		delete [] matr;
}


double *CreateVector(int n)
{
	double *matr = new double[n];

	return matr;
}

int *CreateIntVect(int n)
{
	int *arr = new int[n];

	return arr;
}
//умножение вектора на матрицу
double  *MultMatrVect (double *res, double *v, double *M, int d)
{
	//double *res = new double[d];
	for (int i = 0; i < d; i++)
	{
		double s = 0;
		for (int j = 0; j < d; j++)
		{
			s += v[j] * M[j*d + i];
		}
		res[i] = s;
	}
	return res;
}


//умножение матрицы на матрицу
double *MultMatr (double *res, double *M1, double *M2, int d)
{
	//double *res = new double[d*d];
	for (int i = 0; i < d; i++)
	{

		for (int j = 0; j < d; j++)
		{
			double s = 0;
			for (int k = 0; k < d; k++)
			{
				s += M1[i*d + k] * M2[k*d + j];
			}
			res[i*d + j] = s;
		}
	}
	return res;
}


//получение матрицы поворота вокруг оси X
double *Get3DRotateMatrX(double *M, double angle)
{	
	M[0] = 1;
	M[1] = 0;
	M[2] = 0;
	M[3] = 0;

	M[4] = 0;
	M[5] = cos(angle);
	M[6] = -sin(angle);
	M[7] = 0;

	M[8] = 0;
	M[9] = sin(angle);
	M[10] = cos(angle);
	M[11] = 0;

	M[12] = 0;
	M[13] = 0;
	M[14] = 0;
	M[15] = 1;
	return M;
}


//получение матрицы поворота вокруг оси Y
double *Get3DRotateMatrY (double *M, double ang)
{
	
	M[0] = cos(ang);
	M[1] = 0;
	M[2] = sin(ang);
	M[3] = 0;

	M[4] = 0;
	M[5] = 1;
	M[6] = 0;
	M[7] = 0;

	M[8] = -sin(ang);
	M[9] = 0;
	M[10] = cos(ang);
	M[11] = 0;

	M[12] = 0;
	M[13] = 0;
	M[14] = 0;
	M[15] = 1;
	return M;
}


//получение матрицы поворота вокруг оси Z
double *Get3DRotateMatrZ(double *M, double angle)
{
	M[0] = cos(angle);
	M[1] = -sin(angle);
	M[2] = 0;
	M[3] = 0;

	M[4] = sin(angle);
	M[5] = cos(angle);
	M[6] = 0;
	M[7] = 0;

	M[8] = 0;
	M[9] = 0;
	M[10] = 1;
	M[11] = 0;

	M[12] = 0;
	M[13] = 0;
	M[14] = 0;
	M[15] = 1;
	return M;
}


//получение матрицы сдвига
double *Get3DSdvig(double *M, double dx, double dy, double dz)
{
	M[0] = 1;
	M[1] = 0;
	M[2] = 0;
	M[3] = 0;

	M[4] = 0;
	M[5] = 1;
	M[6] = 0;
	M[7] = 0;

	M[8] = 0;
	M[9] = 0;
	M[10] = 1;
	M[11] = 0;

	M[12] = dx;
	M[13] = dy;
	M[14] = dz;
	M[15] = 1;
	return M;

}

//получение матрицы масштабирования
double *Get3DScaleMatr(double *M, double scale)
{
	M[0] = scale;
	M[1] = 0;
	M[2] = 0;
	M[3] = 0;

	M[4] = 0;
	M[5] = scale;
	M[6] = 0;
	M[7] = 0;

	M[8] = 0;
	M[9] = 0;
	M[10] = scale;
	M[11] = 0;

	M[12] = 0;
	M[13] = 0;
	M[14] = 0;
	M[15] = 1;
	return M;
}