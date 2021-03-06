#include <iostream>
#include <string>
#include <map>

//https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem

// aaaabbcc NO
// ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd
// YES



using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	if (s.empty())
		return "NO";

	std::map<char, int> counters;

	for (char a : s)
	{
		auto findIter = counters.find(a);
		if (findIter == counters.end())
			counters[a] = 1;
		else
			counters[a]++;
	}

	std::map<int, int> sequences;
	for (const auto& pair : counters)
	{
		auto findIter = sequences.find(pair.second);
		if (findIter == sequences.end())
			sequences[pair.second] = 1;
		else
			sequences[pair.second]++;
	}

	size_t sizeSequencies = sequences.size();

	if (sizeSequencies > 2)
		return "NO";
	
	if (1 == sizeSequencies)
		return "YES";

	auto firstIter = sequences.begin();
	auto secondIter = ++sequences.begin();

	if (firstIter->second > 1 && secondIter->second > 1)
	{
		return "NO";
	}

	if (firstIter->second == secondIter->second)
	{
		long long firstliterals = firstIter->first * firstIter->second;
		long long secondliterals = secondIter->first * secondIter->second;
		return abs(firstliterals - secondliterals) > 1 ? "NO" : "YES";
	}

	auto minSeq = (firstIter->second < secondIter->second) ? firstIter : secondIter;

	return (minSeq->first > 1 && abs(firstIter->first - secondIter->first) > 1) ? "NO" : "YES";
}

int main()
{
	//string s = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";
	string s = "aaaabbcc";
	//getline(cin, s);

	string result = isValid(s);

	cout << result << "\n";

	return 0;
}