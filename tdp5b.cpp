/*
Top down table driven Parser for 
T->S#
S->qABC
A->a|bbD
B->a|e
C->b|e
D->c|e

where e denotes "" character
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
void prinv(vector<char> &v)
{
	for(char j : v)
		cout << j;
}
int main()
{
	cout << "Enter I/P string :\n";
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string table[6][6] = {{"","S#","","","",""},
							{"","qABC","","","",""},
							{"","","a","bbD","",""},
							{"e","","a","e","",""},
							{"e","","","b","",""},
							{"e","","e","e","c",""}};
	unordered_map<char,int> nonterm,term;
	nonterm.insert({'T',0});
	nonterm.insert({'S',1});
	nonterm.insert({'A',2});
	nonterm.insert({'B',3});
	nonterm.insert({'C',4});
	nonterm.insert({'D',5});
	term.insert({'#',0});
	term.insert({'q',1});
	term.insert({'a',2});
	term.insert({'b',3});
	term.insert({'c',4});
	term.insert({'$',5});
	vector<char> stk,inp;
	stk.pb('$');
	stk.pb('T');
	inp.pb('$');
	for(char j : s)
		inp.pb(j);
	cout << "Stack\tInput";
	while(true)
	{
		cout << "\n";
		prinv(stk);
		cout << "\t";
		prinv(inp);
		cout << "\t";
		if(stk.back() == '$')
		{
			if(inp.back() == '$')
			{
				cout << "\n\nACCEPTED\n";
			}
			else
			{
				cout << "\n\nREJECTED\n";
			}
			return 0;
		}
		if(stk.back() == 'e')
		{
			cout << "null prodn";
			stk.pop_back();
		}
		// tos is terminal
		else if(term.find(stk.back())!= term.end())
		{
			if(stk.back() == inp.back())
			{
				cout << "pop " << stk.back();
				stk.pop_back();
				inp.pop_back();

			}
			else
			{
				cout << "Rejected";
				return 0;
			}
		}
		else
		{
			char ch = stk.back();
			stk.pop_back();
			int r = nonterm[ch];
			int c = term[inp.back()];
			if(table[r][c].empty())
			{
				cout << "Rejected";
				return 0;
			}
			string temp = table[r][c];
			cout << ch << "->" << temp;
			reverse(temp.begin(), temp.end());
			for(char j : temp)
				stk.pb(j);
			
		}
	}
}