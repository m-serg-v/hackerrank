//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isKaprekarNumber( int val )
{
	if (val < 1)
		return false;

	if (val == 1)
		return true;

	long long square = static_cast<long long>(val) * static_cast<long long>(val);
	std::string sqString = std::to_string( square );
	int countDig = static_cast<int>(sqString.size());
	if (countDig < 2)
		return false;

	std::string firstNum, secondNum;
	firstNum.insert(firstNum.end(), sqString.begin(), sqString.begin() + countDig / 2);
	secondNum.insert(secondNum.end(), sqString.begin() + countDig / 2, sqString.end());

	return val == ( std::stoi(firstNum) + std::stoi(secondNum) );
}

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
	if (p >= q || p >= 100000 || q >= 100000 || p < 0 )
	{
		std::cout << "INVALID RANGE" << std::endl;
	}

	bool existValue = false;
	for (int val = p; val <= q; val++)
	{
		if (isKaprekarNumber(val))
		{
			existValue = true;
			std::cout << val << " ";
		}
	}

	if (!existValue)
	{
		std::cout << "INVALID RANGE" << std::endl;
	}
}

int main()
{
	int p;
	cin >> p;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	kaprekarNumbers(p, q);

	return 0;
}