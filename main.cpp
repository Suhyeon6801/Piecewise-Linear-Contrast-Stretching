#include"contrast.h"

void main()
{
	Contrast con;
	con.ImageOpen();
	con.ImageContrast();
	//con.Contrast_Stretch();
	con.ImageSave();
}