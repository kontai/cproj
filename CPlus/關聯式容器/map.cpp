#include<iostream>
#include<string>
#include<map>

using namespace std;

/*
 * map�S�Q�٬����p���e��
 * map��value�O�g��key����,����array�O�Ѧbarray������m���o
 * �w�qmap�������Wkey,value���O
 * �Q��key(����)���p�B����value(������),�N�p�r���
 */
int mainMap_Multimap()
{
	map<int, string>a;
	//�H�U��map�w�q�覡
															// key�� , value��
	a.insert(map<int, string>::value_type(1, "one"));
	a.insert(make_pair(2, "two"));
	a.insert(pair<int, string>(3, "three"));
	a.insert(pair<int,string>(3,"duplicate value three"));  //map ��,key�u�����p�@��value
	a[4] = "four";  
	//�Parray or vector���P , map�|���j�Mkey value"4",�p�䤣��,�h�إ�,�ê�l�Ƭ�value
	//�Q�Φ��S��,��J��r�òέp���Ʀ���....
	map<string, int>word_count;
	string word;
	cout << "�п�J���N��r=>" << endl;
	while (cin >> word) {
		++word_count[word]; //�p�L��key,�إ�;�p��즹key,value+1;
		cout <<"word count=>   "<<word<<"   x"  << word_count[word] << endl;
	}


	cout << "��²��map�d��:\t" << a[2] << endl;

	cout << "map�j�p:" << a.size() << "\n\n" << "map���e��:" << endl;
	map<int, string>::iterator i = a.begin();
	while(i!=a.end())
	{
		cout << i->first << "," << i->second << endl;
		i++;
	}

	multimap<int, string>ma;
	ma.insert(multimap<int, string>::value_type(1, "one"));
	ma.insert(make_pair(2,"two"));
	ma.insert(pair<int,string>(3,"three"));
	ma.insert(pair<int,string>(3,"duplicate value three")); //multimap ��,key�����p�h��value
	ma.insert(pair<int,string>(3,"duplicate more value three")); //multimap ��,key�����p�h��value
	//ma[4] = "four";		 multimap ���䴩�ϥΤU�Ф覡!
	cout << "multimap�j�p:" << ma.size() << "\n\n" << "mutlimap���e��:" << endl;
multimap<int, string>::iterator mi = ma.begin();

	while(mi!=ma.end())
	{
		cout << mi->first << "," << mi->second << endl;
		mi++;
	}

	  cout << "���e��three���ƶq=" << ma.count(3)<<endl;

	multimap<int, string>::const_iterator fi = ma.find(3);
	if (fi != ma.end()) {
		size_t n = ma.count(3);
		if (n > 1) {
			for(size_t i=0;i!=n;i++)
			{
				cout << "key= " << fi->first << "\tvalue[" << i << "]=" << fi->second << endl;
			++fi;
			}
		}
	//	cout << (ma.find(3))->first<<(ma.find(3))->second << endl;
	}
	else
		cout << "�S���" << endl;
//erase 1
	if (ma.erase(1) > 0)
		cout << "�R��1���\" << endl;
	else
		cout << "�R������" << endl;

//erase 2
	multimap<int, string>::iterator  map_erase = ma.find(2);
	if(map_erase!=ma.end())
	{
		ma.erase(2);
		cout << "�R��2���\" << endl;
	}
	else
	cout << "�R������" << endl;

//erase 3
	ma.erase(ma.lower_bound(3), ma.upper_bound(3));  //�R���d��(key���@�ӥH�Wvalue)


	system("pause");
	return 0;
}


