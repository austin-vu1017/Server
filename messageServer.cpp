#include <iostream>
#include <string>
#include "messageServer.h"
using namespace std;

messageServer::messageServer() {
	*sender;
	*receiver;
}

void messageServer::establishConnection(client *one, client *two) {
	sender = one;
	receiver = two;
}

string messageServer::sendMessage(string m) {
	return m;
}
