/*
LR0 parser for the grammar

S'->S
S->AA
S->aA | b

valid strings : aabb,bb , ....

*/
#include<bits/stdc++.h>
using namespace std;
void prinv(vector<char> &c)
{
	for(char ch : c)
		cout << ch;
	cout << '\t';
}
int main()
{
	vector<vector<string> > table = {{"S3","S4","","2","1"},
									{"","","","",""},
									{"S3","S4","","5",""},
									{"S3","S4","","6",""},
									{"A->b","A->b","A->b","",""},
									{"S->AA","S->AA","S->AA","",""},
									{"A->aA","A->aA","A->aA","",""}};
	unordered_map<char,int> ump = {{'a',0},{'b',1},{'$',2},{'A',3},{'S',4}};
	vector<char> stk;
	int i = 0;
	cout << "Enter input string: ";
	string s;
	cin >> s;
	stk.push_back('0');
	s+='$';
	int r,c,r1,c1;
	cout << "Stack\tLookAhead\tAction\n";
	while(!stk.empty() && i < s.length())
	{
		prinv(stk);
		cout << s[i] << '\t';
		if(stk.back() == '1' && i == s.length()-1)
		{
			cout << "\nSTRING ACCEPTED\n";
			break;
		}
		r = stk.back()-'0';
		c = ump[s[i]];
		if(table[r][c].empty())
		{
			cout << "\nString rejected\n";
			break;
		}
		else if(table[r][c].length() == 2)	// shift move
		{
			cout << "Shift "<<table[r][c] << '\n';
			stk.push_back(s[i++]);
			stk.push_back(table[r][c][1]);
		}
		else if(table[r][c].length() > 2)
		{
			cout << "Reduce by " << table[r][c] << "\n";
			int len = table[r][c].length()-3;
			len *= 2;
			while(len--)
				stk.pop_back();
			r1 = stk.back()-'0';
			c1 = ump[table[r][c][0]];
			stk.push_back(table[r][c][0]);
			stk.push_back(table[r1][c1][0]);
		}
	}										
}
