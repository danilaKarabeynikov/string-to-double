#include "pch.h"
#include "../Let4Karabejnikov/StringToDouble.hpp"

TEST(StringToDoubleTests, Test1)
{
	char str[] = "-64";
	ASSERT_NEAR(StringToDouble(str, 8), -52, 0.0000001);
}

TEST(StringToDoubleTests, Test2)
{
	char str[] = "-b2a.a";
	ASSERT_NEAR(StringToDouble(str, 13), -1895.769230, 0.0001);
}