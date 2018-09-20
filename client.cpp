#include <iostream>
#include <string>
#include "client.h"
using namespace std;

client::client() { id = 0; }
client::client(int i) { id = i; }

int client::getID() { return id; }
string client::getMessage() {
	return message;
}
bool client::getPossesKey() { return possesKey; }

void client::setID(int i) { id = i; }
void client::setMessage(string m) { message = m; }
void client::setPossesKey(bool p) { possesKey = p; }

string client::decode(string d) {
	string decodeMsg = d;
	int letter, length = d.length();

	for (int i = 0; i < length; i++) {
		letter = d[i] - 'A';
		if (letter >= 0 && letter < 26) {
			decodeMsg[i] = key[letter];
		}
	}
	return decodeMsg;
}
