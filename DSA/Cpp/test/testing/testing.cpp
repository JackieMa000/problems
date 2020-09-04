#include "testing.h"

namespace dsa
{
    namespace testing
    {
        void DSATest::EXPECT_ARRAY_EQ(int expected[], int expectedLength, int actual[], int actualLength)
        {
            EXPECT_EQ(expectedLength, actualLength)
                << "Array lengths not equal"
                << "\n expectedLength: " << expectedLength
                << "\n actualLength: " << actualLength;

            if (expectedLength == 0 || actualLength == 0 || expectedLength != actualLength)
                return;

            EXPECT_EQ(expected[expectedLength - 1], actual[actualLength - 1])
                << "Arrays not equal"
                << "\n expected array on index " << expectedLength - 1 << " = " << expected[expectedLength - 1]
                << "\n actual array on index " << actualLength - 1 << " = " << actual[actualLength - 1];

            int newExpectedSize = expectedLength - 1;
            int newExpected[newExpectedSize];
            for (int i = 0; i < newExpectedSize; i++)
            {
                newExpected[i] = expected[i];
            }

            int newActualSize = actualLength - 1;
            int newActual[newActualSize];
            for (int i = 0; i < newActualSize; i++)
            {
                newActual[i] = actual[i];
            }

            EXPECT_ARRAY_EQ(newExpected, newExpectedSize, newActual, newActualSize);
        }

        void DSATest::EXPECT_INT_EQ(int expected, int actual)
        {
            EXPECT_EQ(expected, actual);
        }

    } // namespace testing
} // namespace dsa