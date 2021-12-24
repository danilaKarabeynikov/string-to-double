#include "stdafx.h"
#include "StringToDouble.hpp"
int LengthOfStr(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int PositiveOrNegativeNumber(char* str)
{
	if (str[0] == '-')
	{
		return -1;
	}
	else
		return 1;
}

int LengthOfIntPart(const char* str)
{
	int i = 0;
	while (str[i] != '.' && str[i] != '\0')
	{
		++i;
	}
	return i;
}

int ValueOfIntPart(const char* str, const int numberSystem)
{
	int countOfIntDigits = LengthOfIntPart(str);
	if (*str == '+' || *str == '-')
	{
		++str;
		--countOfIntDigits;
	}
	int valueOfIntPart = 0;
	int p = 1;
	for (int i = countOfIntDigits - 1; i >= 0; --i)
	{
		int digit = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			digit = str[i] - 'a' + 10;
		}
		valueOfIntPart += digit * p;
		p *= numberSystem;
	}
	return valueOfIntPart;
}

double ValueOfFractionalPart(const char* str, const int numberSystem)
{
	int countOfIntDigits = LengthOfIntPart(str);
	if (str[countOfIntDigits] == '\0')
		return 0;
	double valueOfFractionalPart = 0;
	double power = 1. / numberSystem;
	for (int i = countOfIntDigits + 1; str[i] != '\0'; i++)
	{
		int digit = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			char c = str[i];
			digit = c - '0';
		}
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			char c = str[i];
			digit = c - 'a' + 10;
		}
		valueOfFractionalPart += digit * power;
		power /= numberSystem;
	}
	return valueOfFractionalPart;
}

double StringToDouble(char* str, const int numberSystem)
{
	int sign = PositiveOrNegativeNumber(str);
	return (ValueOfIntPart(str, numberSystem) + ValueOfFractionalPart(str, numberSystem))*sign;
}