#pragma once

#include "server.h"
#include <string>
using namespace std;

#ifndef messageServer_h
#define messageServer_h 

class messageServer : public server {
public:
	messageServer();
	void establishConnection(client *, client *);
	string sendMessage(string);
};

#endif // !messageServer_h