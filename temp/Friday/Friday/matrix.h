#pragma once

double *CreateMatr (int n, int m);
double *CreateVector(int n);
int *CreateIntVect(int n);

void ClearMatr (double *matr);
void ClearMatr(int *matr);


double  *MultMatrVect (double *res, double *v, double *M, int d);
double *MultMatr (double *res, double *M1, double *M2, int d);
double *Get3DRotateMatrX(double *M, double angle);
double *Get3DRotateMatrY (double *M, double angle);
double *Get3DRotateMatrZ(double *M, double angle);
double *Get3DSdvig(double *M, double dx, double dy, double dz);
double *Get3DScaleMatr(double *M, double scale);