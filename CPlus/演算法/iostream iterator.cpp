#include<iostream>
#include<list>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
/*
istream_iterator<T> in(strm);�Ыرq��J�y strm ��Ū�� T ������H��istream_iterator ��H

istream_iterator<T> in; istream_iterator ��H���W�X���ݤ��йB�⾹

ostream_iterator<T> in(strm);�ЫرN T ��������H�g���X�y strm ��ostream_iterator��H

ostream_iterator<T> in(strm, delim);�ЫرN T ��������H�g���X�y strm ��ostream_iterator ����A�b�g�J�L�{���ϥ� delim �@�����������j�Ÿ��Cdelim �O�H�Ŧr���������r���}�C
*/


//int mainIosIter() {
//	istream_iterator<int> cin_it(cin);    // reads ints1 from cin      
//	istream_iterator<int> end_of_stream;  // end iterator value 
//	ostream_iterator<Sales_item> output(outfile, " ");
//	// writes Sales_items from the ofstream named outfile 
//	 // each element is followed by a space	ofstream outfile; 
//
//	//�b�Ы� ostream_iterator ����ɡA�i���ѲĤG�ӡ]�i�諸�^��ѡA���w�N�����g�J��X�y�ɨϥΪ����j�Ÿ��C���j�Ÿ������O C ����r��C�]�����O C ����r��A�ҥH�����H�Ŧr�������F�_�h�A��欰�N�O���w�q���C
//
//
// /////////////////////////////////////////////////////////////////////////
//	istream_iterator<int> in_iter(cin); // read ints from cin 
//	istream_iterator<int> eof; // istream "end" iterator  
//							   // read until end of file, storing what was read in vec 
//	vector<int>vec;
//	while (in_iter != eof)
//		vec.push_back(*in_iter++);
//	// increment advances the stream to the next value 
//	// dereference reads next value from the istream    
///////////�N�W�ҧ�²��///////////////////////////////////////////////////////
//	istream_iterator<int> in_iter(cin); // read ints from cin  
//	istream_iterator<int> eof;      // istream "end" iterator     
//	vector<int> vec(in_iter, eof);  // construct vec from an iterator range
//
//
//	/////////////////////////////////////////////////////////////////////////
//						// write one string per line to the standard output
//	ostream_iterator<string> out_iter(cout, "\n");
//	// read strings from standard input and the end iterator  
//	istream_iterator<string> in_iter(cin), eof;
//	// read until eof and write what was read to the standard output    
//	while (in_iter != eof)
//		// write value of in_iter to standard output 
//	 // and then increment the iterator to get the next value from cin
//		*out_iter++ = *in_iter++;
//
//	/////////////////////////////////////////////////////////////////////////
//	istream_iterator<int> cin_it(cin);    // reads ints from cin     
//	istream_iterator<int> end_of_stream;  // end iterator value 
//										  // initialize vec from the standard input:
//	vector<int> vec(cin_it, end_of_stream);
//	sort(vec.begin(), vec.end());
//	// writes ints to cout using " " as the delimiter   
//	ostream_iterator<int> output(cout, " ");
//	// write only the unique elements in vec to the standard output    
//// unique_copy(vec.begin(), vec.end(), output); 
//
// /************************************************************************/
//
// /*
// �p�G�{������J�O�G
//	 23 109 45 89 6 34 12 90 34 23 56 23 8 89 23
// ��X�h�O�G
//	 6 8 12 23 34 45 56 89 90 109
//*/
//
///************************************************************************/
//
//
//	system("pause");
//	return 0;
//}

