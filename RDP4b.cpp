/*
Recursive Descent Parser for the grammar
S->ABC
A->abA | ab
B->b | BC
C-> c | cC
*/
#include <bits/stdc++.h>
using namespace std;
string s;
int val = 0;
int recurdepth = 20;
bool inrange()
{
	return (val < s.length());
}
bool checkdepth()
{
	--recurdepth;
	if(recurdepth <= 0)
	{
		cout << "Recursion Depth Exceeded!!!\n";
		return false;
	}
	return true;
}
bool C()
{
	bool chk = checkdepth();
	if(!chk) return false;
	if(inrange() && s[val] == 'c')
	{
		// cout << "In C c matched\n";
		++val;
		if(val == s.length())
		{
			recurdepth++;
			return true;
		}
		else
			if(C())
			{
				recurdepth++;
				return true;
			}
	}
	recurdepth++;
	return false;
}
bool A()
{
	if(inrange() && s[val] == 'a')
	{
		// cout << "IN A a matched\n";
		++val;
		if(inrange() && s[val] == 'b')
		{
			// cout << "IN A b matched\n";
			++val;
			return true;
		}
	}
	else
		return false;
}
bool B()
{
	bool chk = checkdepth();
	if(!chk) return false;
	if(inrange() && s[val] == 'b')
	{
		// cout << "In B b matched\n";
		++val;
		recurdepth++;
		return true;
	}
	if(B())
		if(C())
			return true;
	return false;
}
bool S()
{
	if(A())
		if(B())
			if(C())
				return true;
	return false;
}
int main()
{
	cout << "Enter I/P string :\n";
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