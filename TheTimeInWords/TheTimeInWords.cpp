#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

std::string numInWord(int h)
{
	switch (h)
	{
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	case 10:
		return "ten";
	case 11:
		return "eleven";
	case 12:
		return "twelve";
	case 13:
		return "thirteen";
	case 14:
		return "fourteen";
	case 15:
		return "fifteen";
	case 16:
		return "sixteen";
	case 17:
		return "seventeen";
	case 18:
		return "eighteen";
	case 19:
		return "nineteen";
	case 20:
		return "twenty";
	case 30:
		return "thirty";
	case 40:
		return "fourty";
	case 50:
		return "fifty";
	case 60:
		return "sixty";
	default:
		break;
	}

	return "";
}

int nextHour( int hour)
{
	if (hour < 12)
		return ++hour;

	return 1;
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
	if (h > 12 || h < 1 || m < 0 || m > 60)
		return "INPUT_ERROR";

	if (0 == m)
	{
		return numInWord(h) + " o' clock";
	}

	if (30 >= m)
	{
		if (15 == m)
		{
			return string("quarter past ") + numInWord(h);
		}

		if (30 == m)
		{
			return string("half past ") + numInWord(h);
		}

		if (1 == m)
		{
			return string("one minute past ") + numInWord(h);
		}
		
		if (20 >= m)
		{
			return numInWord(m) + " minutes past " + numInWord(h);
		}

		return numInWord(int(m / 10) * 10) + " " + numInWord(m % 10) + " minutes past " + numInWord(h);
	}
	
	if (45 == m)
	{
		return string("quarter to ") + numInWord(nextHour(h));
	}

	int b = 60 - m;
	if (1 == b)
	{
		return string("one minute to ") + numInWord(nextHour(h));
	}

	if (20 >= b)
	{
		return numInWord(b) + " minutes to " + numInWord(nextHour(h));
	}

	return numInWord(int(b / 10) * 10) + " " + numInWord(b % 10) + " minutes to " + numInWord(nextHour(h));
}

int main()
{
	int h;
	cin >> h;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = timeInWords(h, m);

	cout << result << "\n";

	return 0;
}