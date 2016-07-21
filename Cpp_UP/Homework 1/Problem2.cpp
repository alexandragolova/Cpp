//Problem 2
#include<iostream>
using namespace std;

//Проверяваме дали годината е високосна
bool IsLeapYear(int year)
{
	if(((year%4) == 0) && (((year%100)!=0) || ((year%400) == 0)))
		return true;
	return false;
}

//Проверяваме дали дните са коректни според месеца, деня и годината
bool IsCorrectDate(int day,int month, int year)
{
	if(year>0)
	{
		switch (month)
		{
			//Проверка за месеците, които имат 31 дни
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(day <= 31)
					return true;
				break;
			//Проверка за февруари и дали годината е високосна
			case 2:
				if(day<=28 && IsLeapYear(year)==false)
					return true;
				if(day==29 && IsLeapYear(year)==true)
					return true;
				break;
			//Проверка за месеците, които имат 30 дни
			case 4:
			case 6:
			case 9:
			case 11:
				if(day<=30)
					return true;
				break;
			default: return false;
		}
	}
	return false;
}

//Намираме предходния ден според месеца
int CalculateDay( int prevMonth, int year, int prevDay){

	if(prevMonth==1||prevMonth==3||prevMonth==5||prevMonth==7||prevMonth==8||prevMonth==10||prevMonth==12)
		prevDay=31;

	else if(prevMonth== 2 && IsLeapYear(year)==true)
		prevDay=29;

	else if(prevMonth ==2 && IsLeapYear(year)==false)
		prevDay=28;

	else if(prevMonth== 4 || prevMonth==6|| prevMonth==9||prevMonth==11)
		prevDay=30;

	return prevDay;
}

//Намираме предходната дата и показваме в конзолата
void CalculateDate(int day,int month,int year)
{
	int prevDay=day;
	int prevMonth=month;
	int prevYear=year;

	prevDay--;
	if (prevDay < 1)
	{
		prevMonth--;
		prevDay=CalculateDay(prevMonth,prevYear,prevDay);

		if ( prevMonth < 1 ) 
		{ 
			prevMonth=12; 
			prevYear--;
			if(prevYear < 1)
			{
				cout<<"Invalid date, "<<prevYear<<" < 1 !";
				return;
			}
		}
	}
	cout << "Previous date is " <<  prevDay << "/" <<  prevMonth << "/" <<  prevYear << endl;
}

int main()
{
	int day,month,year;

	cout<<"Day=";
	cin>>day;

	cout<<"Month=";
	cin>>month;

	cout<<"Year=";
	cin>>year;

	if(IsCorrectDate(day,month,year))
	{
		CalculateDate(day,month,year);
	}
	else
	{
		cout<<"Incorrect date!";
	}
	return 0;
}