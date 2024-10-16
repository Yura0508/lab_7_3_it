#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_3_it/lab_7_3_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestSumRowsWithNegative) {
            int n = 3;
            int** matrix = new int* [n];
            matrix[0] = new int[n] { 1, -2, 3 };
            matrix[1] = new int[n] { 4, 5, 6 };
            matrix[2] = new int[n] { -1, 1, 1 };

            int sum = SumRowsWithNegative(matrix, n);

            Assert::AreEqual(3, sum); // Row 0 sum = 1 + (-2) + 3 = 2, Row 2 sum = -1 + 1 + 1 = 1 => Total = 2 + 1 = 3

            // Cleanup
            for (int i = 0; i < n; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

	};
}
