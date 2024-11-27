#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.2/lab11.2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_CapitalizationAfterDot)
        {
            std::string input = "this is. a test. example.";
            std::string expected = "this is. A test. Example.";
            capitalizeAfterDot(input);
            Assert::AreEqual(expected, input);

        }
    };
}