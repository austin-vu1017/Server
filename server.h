#pragma once

#include "client.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef server_h
#define server_h


class server {
protected:
	client *sender, *receiver;
public:
	virtual void establishConnection(client *, client *) = 0;
	virtual string sendMessage(string) = 0;
	void swapClients();
};

#endif // server_h