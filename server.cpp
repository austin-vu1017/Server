#include <iostream>
#include "server.h"
using namespace std;

void server::swapClients() {
	client *temp = sender;
	sender = receiver;
	receiver = temp;
}
