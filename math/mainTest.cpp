#include <gtest/gtest.h>
#include "../dopF.h"
#include "transp.h"
#include "det.h"

class TestSerialization : public ::testing::Test {
public:
    double** A = 0;
    int nA = 0, mA = 0;
    TestSerialization() { 
        /* init protected members here */
        nA = 3;
        mA = 4;
        A = createM(nA, mA);
        for (int i = 0; i < nA; i++)
        {
            for (int j = 0; j < mA; j++)
            {
                A[i][j] = i + j + 1;
            }
        }
    }
    ~TestSerialization() { 
        /* free protected members here */ 
        deleteM(A, nA, mA);
    }
    void SetUp() { /* called before every test */ }
    void TearDown() { /* called after every test */ }

protected:
    /* none yet */
};


TEST_F(TestSerialization, transp) {
    int nC, mC;
    double **C = transp(A,nA,mA,nC,mC);
    
	double **D = createM(mA, nA);
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < mA; j++)
		{
			D[j][i] = i + j + 1;
		}
	}

    for (int i = 0; i < nC; i++)
        for (int j = 0; j < mC; j++)
            ASSERT_EQ(D[i][j], C[i][j]);
    deleteM(C, nC, mC);
    deleteM(D, mA, nA);
}


TEST_F(TestSerialization, det) {
	double d = det(A,nA,nA);//берется только часть матрицы A, т.к. нужна квадратная
    
	ASSERT_EQ(0,d);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
