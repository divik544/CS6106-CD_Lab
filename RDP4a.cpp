/*
Recursive Descent Parser with backtracking for
S->aA | aCb
A->ab
C->cd

Valid strings:
aab
acdb
*/
#include<bits/stdc++.h>
using namespace std;
string s;
int val = 0;
bool inrange()
{
	return (val < s.length());
}
bool A()
{
	if(inrange() && s[val] == 'a')
	{
		++val;
		if(inrange() && s[val] == 'b')
		{
			++val;
			return true;
		}
	}
	return false;
}
bool C()
{
	if(inrange() && s[val] == 'c')
	{
		++val;
		if(inrange() && s[val] == 'd')
		{
			++val;
			return true;
		}
	}
	return false;
}
bool S()
{
	if(inrange() && s[val] == 'a')
	{
		++val;
		if(A())
			return true;
		if(C())
		{
			if(inrange() && s[val] == 'b')
			{
				++val;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cout << "Enter I/p string: \n";
	cin >> s;
	int n = s.length();
	if(S())
	{
		if(val == n)
			cout << "Accepted";
		else
			cout << "Rejected";
	}
	else
		cout << "Rejected";
}