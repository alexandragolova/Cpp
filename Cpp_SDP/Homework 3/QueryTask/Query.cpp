#include<iostream>
#include<string>
#include"Query.h"
using namespace std;

Query::Query()
{
	cntResults = 0;
	cntQuery = 0;
	cntStrings = 0;
	cntExamples = 0;
	enter.endInx = 0;
	enter.startInx = 0;
	queryStrings = NULL;
}

Query::~Query()
{
	delete[] queryStrings;
}

void Query::SetQueryStrings(string* strs)
{
	queryStrings = strs;
}

string* Query::GetQueryStrings()
{
	return queryStrings;
}

void Query::SetQuery(string strs)
{
	query = strs;
}

string Query::GetQuery()
{
	return query;
}

void Query::SetCntStrings(int cnt)
{
	cntStrings = cnt;
}

int Query::GetCntStrings()const
{
	return cntStrings;
}

void Query::SetCntQuery(int cnt)
{
	cntQuery = cnt;
}

int Query::GetCntQuery()const
{
	return cntQuery;
}

void Query::SetCntExamples(int cnt)
{
	cntExamples = cnt;;
}

int Query::GetCntExamples()const
{
	return cntExamples;
}

void Query::SetEnter(Enter enterInxs)
{
	enter.endInx = enterInxs.endInx;
	enter.startInx = enterInxs.startInx;
}

Enter Query::GetEnter()
{
	return enter;
}

void Query::QuerySearch()
{
	cntResults = 0;
	//Linear search
	for (int i = enter.startInx; i <= enter.endInx; i++)
	{
		string temp = queryStrings[i].substr(0, query.length());
		if (temp.compare(query) == 0)
			cntResults++;
	}
}

void Query::PrintQueryResult()
{
	QuerySearch();
	cout << "Query result: " << cntResults << endl;
}
