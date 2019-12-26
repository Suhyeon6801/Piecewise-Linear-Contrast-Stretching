#include"contrast.h"

Contrast::Contrast() {}
Contrast::~Contrast() {}

void Contrast::ImageOpen()
{
	FILE* pFile;
	pFile = fopen("lena512.rgb", "rb");

	Image_In = new unsigned char*[nWidth*3];
	for (int h = 0; h < nHeight*3; ++h)
	{
		Image_In[h] = new unsigned char[nHeight*3];
	}

	if (pFile == NULL) // 예외처리
	{
		cout << "File not found!\n";
		return;
	}

	for (int h = 0; h < nHeight*3; h++)
	{
		fread((void*)Image_In[h], sizeof(unsigned char), nWidth*3, pFile);
	}
	fclose(pFile);
}


double Contrast::Contrast_Stretch(int x)
{
	//int r1 = 70, r2 = 250, s1 = 70, s2 =300;
	int r1 = 70, r2 = 250, s1 = 14, s2 = 500;

	double result = 0.0;

	if (0 <= x && x < r1)
	{
		result = (s1 / r1)*x;
	}
	else if (r1 <= x && x < r2)
	{
		result = ((s2 - s1) / (r2 - r1))*(x - r1) + s1;
	}
	else if (r2 <= x && x < 512)
	{
		result = ((512 - s2) / (512 - r2))*(x - r2) + s2;
	}
	else
	{
		result;
	}
	return result;
}

void Contrast::ImageContrast()
{
	Image_Out = new unsigned char*[nWidth*3];
	for (int i = 0; i < nWidth*3; ++i)
	{
		Image_Out[i] = new unsigned char[nHeight*3];
		memset(Image_Out[i], 0, sizeof(unsigned char)*nHeight*3);
	}

	for (int h = 0; h < nHeight*3; h++)
	{
		for (int w = 0; w < nWidth*3; w++)
		{
			double output = Contrast_Stretch((int)Image_In[h][w]);
			Image_Out[h][w] = output;
		}
	}

}

void Contrast::ImageSave()
{
	
	FILE *pFile;
	pFile = fopen("newlena.rgb", "wb");

	for (int h = 0; h < nHeight*3; h++)
	{
		fwrite((const void*)Image_Out[h], sizeof(unsigned char), nWidth*3, pFile);
	}

	//동적 메모리 해제
	for (int h = 0; h < nHeight*3; h++)
	{
		delete[] Image_Out[h];
	}
	delete[] Image_Out;

	fclose(pFile);
}
