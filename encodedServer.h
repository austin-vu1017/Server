#pragma once

#include "server.h" 
#include <string>
using namespace std;

#ifndef encodedServer_h
#define encodedServer_h

class encodedServer : public server {
private:
	char key[26] = { 'B','A','D', 'C', 'F', 'E', 'H', 'G', 'J', 'I', 'L', 'K', 'N', 'M',
		'P', 'O', 'R', 'Q', 'T', 'S', 'V', 'U', 'X', 'W', 'Z', 'Y' };
public:
	encodedServer();
	void establishConnection(client *, client *);
	string sendMessage(string);
	string encodeMessage(string);
};

#endif // !encodedServer_h