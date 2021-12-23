#include "transp.h"

double** transp(double** a, int na, int ma, int &nr, int &mr)
{
	if(a==0||na==0||ma==0)
		return 0;
	nr = ma;
	mr = na;
	double** ret = new double*[nr];
	for (int i = 0; i < nr; i++)
		ret[i] = new double[mr];
	
	for (int i = 0; i < nr; i++)
		for (int j = 0; j < mr; j++)
			ret[i][j] = a[j][i];
	return ret;
}