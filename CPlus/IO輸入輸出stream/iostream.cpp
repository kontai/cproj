#include<iostream>
#include <fstream>

//std::ofstream print(std::ofstream );ERROR!	 �ǻ� �H�� ��^  stream , �u��z�L point �M reference
std::ofstream& print(std::ofstream &);

int mainIOStream() {
	std::ofstream out1, out2;
	//	 out1 = out2;  //ERROR!	 stream����L�k���

	/*	while(print(out1))
		{
		}
	*/

	system("pause");
	return 0;
}