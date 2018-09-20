#pragma once

#include <iostream>
#include <string>
using namespace std;

#ifndef client_h
#define client_h

class client {
private:
	int id;
	string message;
	bool possesKey;
	char key[26] = { 'B','A','D', 'C', 'F', 'E', 'H', 'G', 'J', 'I', 'L', 'K', 'N', 'M',
		'P', 'O', 'R', 'Q', 'T', 'S', 'V', 'U', 'X', 'W', 'Z', 'Y'};
public:
	client();
	client(int);
	int getID();
	string getMessage();
	bool getPossesKey();
	void setID(int);
	void setMessage(string);
	void setPossesKey(bool);

	string decode(string);
};

#endif // client_h