//Преобразования модели в набор точек на экране

//#include "stdafx.h"

#include "conversion.h"
#include "canvas.h"
#include "matrix.h"
#include "file.h"


//создаёт матрицу преобразований: сдвиг х ротЗ х ротУ х ротХ х масштаб
double* GetConversationMatr(double *res, sRenderData *data)
{
	double *ShiftMatrix = nullptr;//  = new double[16];
	ShiftMatrix = CreateMatr(4,4);
	if (!ShiftMatrix )
		return nullptr;
	ShiftMatrix = Get3DSdvig(ShiftMatrix, data->dx, data->dy, data->dz);


	double *RotateZMatrix = nullptr;// = new double[16];
	RotateZMatrix = CreateMatr(4,4);
	if (!RotateZMatrix)
	{
		//delete ShiftMatrix;
		ClearMatr(ShiftMatrix);
		return nullptr;
	}
	RotateZMatrix = Get3DRotateMatrZ(RotateZMatrix, data->rotz);
	
	double *matr1 = nullptr;// = new double [16];
	matr1 = CreateMatr(4,4);
	if (!matr1)
	{
		//delete ShiftMatrix;
		//delete RotateZMatrix;
		ClearMatr(ShiftMatrix);
		ClearMatr(RotateZMatrix);
		return nullptr;
	}
	matr1 = MultMatr(matr1, ShiftMatrix, RotateZMatrix, 4);//Shift х RotateZ
	//delete ShiftMatrix;
	//delete RotateZMatrix;
	ClearMatr(ShiftMatrix);
	ClearMatr(RotateZMatrix);
	

	double *RotateYMatrix=nullptr;// = new double [16];
	RotateYMatrix = CreateMatr(4,4);
	if (!RotateYMatrix)
	{
		//delete matr1;
		ClearMatr(matr1);
		return nullptr;
	}
	RotateYMatrix = Get3DRotateMatrY(RotateYMatrix, data->roty);
	
	double *matr2=nullptr;// = new double [16];
	matr2 = CreateMatr(4,4);
	matr2 = MultMatr (matr2, matr1,RotateYMatrix,4);//Shift * RotateZ * RotateY
	if (!matr2)
	{
		//delete matr1;
		//delete RotateYMatrix;
		ClearMatr(matr1);
		ClearMatr(RotateYMatrix);
		return nullptr;
	}
	//delete RotateYMatrix;
	ClearMatr(RotateYMatrix);


	double *RotateXMatrix=nullptr;// = new double [16];
	RotateXMatrix = CreateMatr(4,4);
	if (!RotateXMatrix)
	{
		//delete matr2;
		ClearMatr(matr2);
		return nullptr;
	}
	RotateXMatrix = Get3DRotateMatrX(RotateXMatrix, data->rotx);

	double *matr3=nullptr;// = new double [16];
	matr3 = CreateMatr(4,4);
	if (!matr3)
	{
		//delete matr2;
		//delete RotateXMatrix;
		ClearMatr(matr2);
		ClearMatr(RotateXMatrix);
		return nullptr;
	}
	matr3 = MultMatr (matr3, matr2,RotateXMatrix,4);//Shift * RotateZ * RotateY
	//delete RotateXMatrix;
	ClearMatr(RotateXMatrix);

	

	double *ScaleMatrix=nullptr;// = new double [16];
	ScaleMatrix = CreateMatr(4,4);
	if (!ScaleMatrix)
	{
		//delete matr3;
		ClearMatr(matr3);
		return nullptr;
	}
	ScaleMatrix = Get3DScaleMatr(ScaleMatrix, data->scale);

	res = MultMatr (res, matr3,ScaleMatrix,4);//Shift * RotateZ * RotateY
	//delete ScaleMatrix;
	ClearMatr(ScaleMatrix);

	return res;
}


//преобразование одной точки в точку на экране
sCanvasPoint *ConvertPoint (sPoint3d *p, double *ConvMatr)
{
	double *pVector=nullptr;// = new double[4];
	pVector = CreateVector(4);
	if (!pVector)
		return nullptr;

	pVector[0] = p->x;
	pVector[1] = p->y;
	pVector[2] = p->z;
	pVector[3] = 1;

	//умножаем вектор точки на матрицу преобразований
	//получаем новую точку в векторном представлении
	double *conversion=nullptr;// = new double[4];
	conversion = CreateVector(4);
	if (!conversion) return nullptr;

	conversion = MultMatrVect(conversion, pVector, ConvMatr, 4);
	//delete pVector;
	ClearMatr(pVector);

	
	sCanvasPoint *res = new sCanvasPoint;
	if (!res)
	{
		//delete conversion;
		ClearMatr(conversion);
		return nullptr;
	}

	res->x = (int)conversion[0];
	res->y = (int)conversion[1];
	ClearMatr(conversion);
	//delete conversion;

	return res;
}

//выделение памяти под струтуру и ее поля
sConvertedPoint *AllocateConvertedPoints (int count)
{
	sConvertedPoint *conv = new sConvertedPoint;
	if (!conv)
		return nullptr;

	int *Xs=nullptr;// = new int[count];
	Xs = CreateIntVect(count);
	if (!Xs)
	{
		//delete conv;
		ClearMatr(Xs);
		return nullptr;
	}

	int *Ys = nullptr;// new int [count];
	Ys = CreateIntVect(count);
	if (!Ys)
	{
		delete conv;
		//delete Xs;
		ClearMatr(Xs);
		return nullptr;
	}

	conv->count = count;
	conv->Xs = Xs;
	conv->Ys = Ys;

	return conv;
}


//преобразует трёхмерные точки в точки на экране
sConvertedPoint *Converts (sPointsList *points, sRenderData *params)
{
	sConvertedPoint *conv = AllocateConvertedPoints(points->count);
	if (!conv)
		return nullptr;

	double *ConvMatr =nullptr;// new double[16];
	ConvMatr = CreateMatr(4,4);
	if (!ConvMatr)
	{
		delete conv;
		return nullptr;
	}

	ConvMatr = GetConversationMatr(ConvMatr, params);
	
	//преобразуем из 3д в 2д
	for (int i=0; i<points->count; i++)
	{
		sCanvasPoint *point = ConvertPoint (points->pointsArray+i,ConvMatr);
		conv->Xs[i] = point->x;
		conv->Ys[i] = point->y;
		delete point;
	}
	//delete ConvMatr;
	ClearMatr(ConvMatr);
	return conv;
}

void ClearConvertedPoints (sConvertedPoint *converted)
{
	delete converted->Xs;
	delete converted->Ys;
	delete converted;
}
