/*
6
E->E+T
E->T
T->T*F
T->F
F->(E)
F->a

Expected Outcome:
E->TE'
E'->+TE'|null
T->FT'
T'->*FT'|null
F->(E)
F->a

*/
#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
int main()
{
	cout << "Enter No. of Productions :\n";
	int n;
	cin >> n;
	vector<string> prod(n),alpha,beta;
	vector<string> asis,res;
	vector<char> recur;
	for(int i = 0; i < n; i++)
	{
		cin >> prod[i];
	}
	for(int i = 0; i < n; i++)
	{
		// Left recursion is present
		if(prod[i][0] == prod[i][3])
		{
			recur.push_back(prod[i][0]);
			alpha.push_back(prod[i].substr(4));
			i++;
			beta.push_back(prod[i].substr(3));
		}
		else
			asis.push_back(prod[i]);
	}
	int nofre = recur.size();
	string temp = "";
	// watch(nofre);
	for(int i = 0; i < nofre; i++)
	{
		// watch(alpha[i]);
		// watch(beta[i]);
		temp = "";
		temp += recur[i];
		temp += "->";
		temp.append(beta[i]);
		temp += recur[i];
		temp += '\'';
		res.push_back(temp);
		temp = recur[i];
		temp += "'->";
		temp.append(alpha[i]);
		temp += recur[i];
		temp += "'|null";
		res.push_back(temp);
	}
	cout << "\nNew Set of Productions are: \n";
	for(string &s : res)
		cout << s << '\n';
	for(string &s : asis)
		cout << s << '\n';
}