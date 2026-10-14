#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 5.3/Project 5.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            double x = 1.5; // |1.5| >= 1

            // Очікуване значення за формулою: (sin(x) + cos(x)) / (sin^2(x) + exp(x))
            double expected = (sin(x) + cos(x)) / (pow(sin(x), 2) + exp(x));

            double result = p(x);

            Assert::AreEqual(expected, result, 0.0001);
        }

        // Тест для випадку |x| < 1
        TEST_METHOD(TestP_LessThanOne)
        {
            double x = 0.5; // |0.5| < 1

            // Обчислення очікуваного значення за алгоритмом із коду
            double S = 1.0;
            double a = 1.0;
            for (int j = 1; j <= 4; j++)
            {
                double R = -(x * x) / ((2 * j - 1) * (2 * j));
                a *= R;
                S += a;
            }
            double expected = (1.0 / cos(x)) * S;

            double result = p(x);

            Assert::AreEqual(expected, result, 0.0001);
		}
	};
}
