#include "car.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void AddCar(Car& car, int regNum);

bool IsCarExist(Car* cars, int sizeArray,int regNum);

bool IsOwnerExist(Car* cars, int sizeArray, char* owner);

int GetAvgPower(Car* cars, int sizeArray);

char* TheMostPopularCar(Car* cars, int sizeArray);

int CountCarByOwner(Car* cars, int sizeArray, char* ownerName);

Car* CarByOwner(char* ownerName);

char** OwnerList(Car* cars, int sizeArray);

int OwnerPower(char* ownerName);

void GenerateTxtFile(Car* cars,int size);

bool GenerateBinaryFile(const char* file, Car* cars);

bool IsFileExist(const char *file);

#endif