#include "det.h"

double det(double** a, int na, int ma)
{
	if(a==0||na==0||ma==0)
		return 0;
	if(na!=ma)
		return 0;
	int n = na;
	double tmp, ret;
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = -a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] += a[k][j] * tmp;
            }
        }
    }
	ret=1;
	for (int i = 0; i < n; i++) {
        ret *= a[i][i];
    }

	return ret;
}