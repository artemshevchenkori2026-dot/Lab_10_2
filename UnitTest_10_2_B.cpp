#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_2_B/Lab_10_2_B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest102
{
    TEST_CLASS(UnitTest102)
    {
    public:
        TEST_METHOD(TestSortAndBinSearch)
        {
            const int N = 3;
            Student s[N];

            s[0] = { "Ivanenko", 1, KN, 5, 5, { 5 } };   // avg = 5.0
            s[1] = { "Sydorenko", 1, ME, 3, 4, { 5 } };  // avg = 4.0
            s[2] = { "Petrenko", 2, INF, 4, 4, { 4 } };  // avg = 4.0

            // Перевірка індексного сортування (масив s залишається незмінним)
            int* idx = IndexSort(s, N);
            Assert::AreEqual(2, idx[0]); // Petrenko (avg 4.0, INF=1)
            Assert::AreEqual(1, idx[1]); // Sydorenko (avg 4.0, ME=2)
            Assert::AreEqual(0, idx[2]); // Ivanenko (avg 5.0, KN=0)
            delete[] idx;

            // Перевірка фізичного сортування та бінарного пошуку
            Sort(s, N);
            Assert::AreEqual(string("Petrenko"), s[0].prizv);
            Assert::AreEqual(string("Sydorenko"), s[1].prizv);
            Assert::AreEqual(string("Ivanenko"), s[2].prizv);

            int pos = BinSearch(s, N, "Sydorenko", ME, 4.0);
            Assert::AreEqual(1, pos);
            Assert::AreEqual(-1, BinSearch(s, N, "Unknown", KN, 5.0));
        }
    };
}