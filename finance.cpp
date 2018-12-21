//
// Created by 18146 on 2018/12/21.
//

#include "finance.h"
Finance::Finance(const char Fmain[])
{
	FM=Fmain;
	mainway.open(FM,fstream::in);
	if (!mainway) init();
	else mainway.close();
}

void Finance::init()
{
	mainway.close();
	mainway.open(FM,ios::binary|ios_base::out);
	mainway.seekp(0,ios::beg);
	int x=1;
	mainway.write((reinterpret_cast<char * > (&x)), sizeof(int));
	Fi X;
	mainway.write((reinterpret_cast<char * > (&X)), sizeof(Fi));
	mainway.close();
}
void Finance::AddF(int pla,double m)
{
	mainway.open(FM,ios::binary|ios_base::out|ios::in);
	mainway.seekg(0,ios::beg);
	int num;
	Fi X;
	mainway.read((reinterpret_cast<char * > (&num)), sizeof(int));
	mainway.seekg((num-1)*sizeof(Fi)+sizeof(int),ios::beg);
	mainway.read((reinterpret_cast<char * > (&X)), sizeof(Fi));
	if (m>0) X.MoneyA+=m; else X.MoneyB-=m;
	X.userpla=pla;
	mainway.seekp(num*sizeof(Fi)+sizeof(int),ios::beg);
	num++;
	mainway.write((reinterpret_cast<char * > (&X)), sizeof(Fi));
	mainway.seekp(0,ios::beg);
	mainway.write((reinterpret_cast<char * > (&num)), sizeof(int));
	mainway.close();
}

void Finance::GetLas(int las)
{
	mainway.open(FM,ios::binary|ios_base::out|ios::in);
	mainway.seekg(0,ios::beg);
	int num;
	Fi X1,X2;
	mainway.read((reinterpret_cast<char * > (&num)), sizeof(int));
	mainway.seekg((num-1)*sizeof(Fi)+sizeof(int),ios::beg);
	mainway.read((reinterpret_cast<char * > (&X1)), sizeof(Fi));
	if (las==-1)mainway.seekg(sizeof(int),ios::beg);
	else mainway.seekg((num-las-1)*sizeof(Fi)+sizeof(int),ios::beg);
	mainway.read((reinterpret_cast<char * > (&X2)), sizeof(Fi));
	mainway.close();
	double A,B;
	A=X1.MoneyA-X2.MoneyA;
	B=X1.MoneyB-X2.MoneyB;
	cout.setf(ios::fixed);
	cout<<" + "<<fixed<<setprecision(2)<<A;
	cout<<" - "<<fixed<<setprecision(2)<<B<<endl;
}
