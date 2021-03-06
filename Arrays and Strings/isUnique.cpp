#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <locale>
#include <sstream>
#include <stdlib.h>
#include <climits>
using namespace std;

bool isUniqueUsingMap(string s)
{
	// time complexity: O(n)
	// space complexity: O(n)
	unordered_map<char, int> myMap;
	for (int i = 0; i < s.length(); ++i)
		myMap[s[i]]++;
	
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		if (it->second > 1)
			return false;
	}
	return true;
}

bool isUniqueUsingSort(string s)
{
	// time complexity: O(nlogn)
	// space complexity: O(1)
	sort(s.begin(), s.end());
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == s[i + 1])
			return false;
	}
	return true;
}

bool isUniqueUsingArray(string s)
{
	// time complexity: O(n)
	// space complexity: O(1)
	vector<bool> visited(256, 0);
	for (int i = 0; i < s.length(); ++i) {
		if (visited[s[i]])
			return false;
		visited[s[i]] = true;
	}
	return true;
}

int main() {
	string s1 = "navyatabawa";
	string s2 = "navy";
	string s3 = "navy etr";
	if (isUniqueUsingMap(s1))
		cout << "String is made up of unique characters"<<endl;
	else 
		cout << "String is not made up of unique characters"<<endl;
	getchar();
	return 0;
}