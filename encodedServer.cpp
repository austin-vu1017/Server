#include <iostream>
#include <string>
#include "encodedServer.h"
using namespace std;

encodedServer::encodedServer() {
	*sender;
	*receiver;
}

void encodedServer::establishConnection(client *one, client *two) {
	sender = one;
	receiver = two;
}

string encodedServer::sendMessage(string m) {
	return m;
}

string encodedServer::encodeMessage(string e) {
	string reMessage = e;
	int length = e.length();

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 26; j++) {
			if (key[j] == e[i]) {
				reMessage[i] = 'A' + j;
				break;
			}
		}
	}
	return reMessage;
}