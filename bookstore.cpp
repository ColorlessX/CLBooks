#include <bits/stdc++.h>
#include "users.hpp"
#include "order.hpp"
#include "dataB.hpp"
#include "books.hpp"
using namespace std;


int main()
{
	fstream Command;
	char x[220];
	Command.open("command.txt",ios::in);
	if (!Command) return 0;
	users U("UMain.bin","URoad.bin");
	books B("BMain.bin","BRoad.bin");
	Finance F("Fi.bin");
	while (!Command.eof())
	{try{
			//cout<<"xstat\n";
			Command.getline(x,200);
			if (strcmp(x,"exit")==0) return 0;
			Processline(x,strlen(x),U,B,F);
			//cout<<"xend\n";
		}
	catch(...){
			cout<<"Invalid"<<endl;
		}
	}

	return 0;
}