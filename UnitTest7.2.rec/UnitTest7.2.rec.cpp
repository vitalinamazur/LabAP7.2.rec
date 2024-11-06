#include "pch.h" // Це включення додає Visual Studio автоматично для тестових проєктів
#include "CppUnitTest.h"
#include "../LabAP7.2.rec/LabAP7.2.rec.cpp" // Шлях до основного файлу з реалізаціями функцій

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(MatrixTest)
    {
    public:

        TEST_METHOD(CreateTest)
        {
            const int n = 3;
            const int Low = -10;
            const int High = 50;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            Create(a, n, Low, High);

            bool withinRange = true;
            for (int i = 0; i < n && withinRange; i++) {
                for (int j = 0; j < n && withinRange; j++) {
                    if (a[i][j] < Low || a[i][j] > High)
                        withinRange = false;
                }
            }

            Assert::IsTrue(withinRange);

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(PlaceMaxOnDiagonalTest)
        {
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            a[0][0] = 5; a[0][1] = 2; a[0][2] = 3;
            a[1][0] = 1; a[1][1] = 6; a[1][2] = 4;
            a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

            PlaceMaxOnDiagonal(a, n);

            Assert::AreEqual(a[0][0], 5);
            Assert::AreEqual(a[1][1], 6);
            Assert::AreEqual(a[2][2], 9);

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }

    };
}
