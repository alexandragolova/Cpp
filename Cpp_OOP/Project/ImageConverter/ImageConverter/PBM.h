#pragma once
#include "Image.h"
class PBM :
	public Image
{

private:
	int* BinaryContent;
	int** Content;
public:
	PBM();
	~PBM();

	int* GetBinaryContent()const;
	void SetBinaryContent(int*);

	int** GetContent()const;
	void SetContent(int** content);

	void ReadBinary(string fileName);
	void ReadASCII(string fileName);

	void WriteBinary();
	void WriteASCII();
};

