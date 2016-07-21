#pragma once
#include "Image.h"
class PGM :
	public Image
{
private:
	int MaxGray;
	int** Content;
	int* BinaryContent;
public:
	PGM();
	~PGM();

	int GetMaxGray();
	void SetMaxGray(int maxGray);

	int** GetContent()const;
	void SetContent(int** content);

	int* GetBinaryContent()const;
	void SetBinaryContent(int*);

	void ReadBinary(string fileName);
	void ReadASCII(string fileName);

	void WriteBinary();
	void WriteASCII();
};

