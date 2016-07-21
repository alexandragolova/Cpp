#ifndef CAR_H
#define CAR_H

enum CarType
{
	LambordginiMurcielago,
	MercedesAMG,
	PaganiZondaR,
	BugattiVeyron ,
	None,
};

class Car
{
private:
	char OwnerName[23];
	int ID=0;
	int RegNum=0;
	CarType Type;
	int Power=0;

public:	
	int GetPower();
	char* GetOwnerName();
	int GetRegNum();
	int GetId();
	CarType GetCarType();

	void SetOwnerName(char* ownerName);
	void SetRegNum(int regNum);
	void SetId(int id);
	void SetCarType(int type);

};
#endif