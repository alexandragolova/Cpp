#ifndef FUNCTIONS
#define FUNCTIONS
#include<string>
#include<fstream>
using namespace std;

bool WriteCookieToBinary(const Cookie& p, const char* fileName);

bool ReadCookieFromBinary(const char* file, int position, Cookie cookie);

void AddCookieToJar(Jar jar, int cookiesCount, const char* fileName);

void DeleteCookieFromJar(Jar jar, Cookie cookies[], int allCookies, int pos);
#endif