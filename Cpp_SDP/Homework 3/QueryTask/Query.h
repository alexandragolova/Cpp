#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Enter
{
	int startInx;
	int endInx;
};

class Query
{
public:
	Query();
	~Query();

	void SetQueryStrings(string* strs);
	string* GetQueryStrings();

	void SetQuery(string strs);
	string GetQuery();

	void SetCntStrings(int cnt);
	int GetCntStrings()const;

	void SetCntQuery(int cnt);
	int GetCntQuery()const;

	void SetCntExamples(int cnt);
	int GetCntExamples()const;

	void SetEnter(Enter enterInxs);
	Enter GetEnter();

	void QuerySearch();
	void PrintQueryResult();
private:
	int cntResults;
	int cntQuery;
	int cntStrings;
	int cntExamples;
	Enter enter;
	string* queryStrings;
	string query;
};

