#include <iostream>
#include <string>
#include <fstream>
#include "client.h"
#include "server.h"
#include "encodedServer.h"
#include "messageServer.h"
using namespace std;

int main() {
	ofstream outputFile;
	string fileName = "out.txt", input;
	char inputC1, inputC2, connectS;
	int client1ID;
	client *client1 = new client(), *client2 = new client(2);

	cout << "Enter Client ID Number:";
	cin >> client1ID;
	client1->setID(client1ID);
	cout << "Client " << client1->getID() << ", make a connection?(y/n)";
	cin >> inputC1;
	cout << "Client " << client2->getID() << ", make a connection?(y/n)";
	cin >> inputC2;

	outputFile.open(fileName);
	
	if (!outputFile.is_open()) {
		cerr << "-----ERROR OPENING FILE-----";
		
		delete client1;
		delete client2;
		exit(1);
	}
	else {
		if (inputC1 == 'y' && inputC2 == 'y') {
			cout << "Encrypted Connection?(y/n)";
			cin >> connectS;
			
			if (connectS == 'y') {
				encodedServer encode;

				encode.establishConnection(client1, client2);

				cout << "Client " << client1->getID() << ", does Client " << client2->getID() << " get the key?(y/n)";
				cin >> inputC1;
					
				if (inputC1 == 'y') {
					client2->setPossesKey(true);
				}
				else if (inputC1 == 'n') {
					client2->setPossesKey(false);
				}
				else {
					cerr << "-----ERROR INPUT FOR KEY ACCESS-----" << endl;

					delete client1;
					delete client2;
					exit(1);
				}

				cout << "Client " << client2->getID() << ", does Client " << client1->getID() << " get the key?(y/n)";
				cin >> inputC2;
				
				if (inputC2 == 'y') {
					client1->setPossesKey(true);
				}
				else if (inputC2 == 'n') {
					client1->setPossesKey(false);
				}
				else {
					cerr << "-----ERROR INPUT FOR KEY ACCESS-----" << endl;
					
					delete client1;
					delete client2;
					exit(1);
				}

				while (getline(cin, input)) {
					cout << "Client " << client1->getID() << ":";
					getline(cin, input);

					if (input == "") {
						break;
					}

					encode.encodeMessage(input);
					client1->setMessage(input);

					if (client2->getPossesKey() == true) {
						client1->decode(input);
						client1->setMessage(input);
					}

					outputFile << "Client " << client1->getID() << ":" << encode.sendMessage(client1->getMessage()) << endl;

					cout << "Client " << client2->getID() << ":";
					getline(cin, input);

					if (input == "") {
						break;
					}
					
					encode.encodeMessage(input);
					client2->setMessage(input);

					if (client1->getPossesKey() == true) {
						client2->decode(input);
						client2->setMessage(input);
					}
					outputFile << "Client " << client2->getID() << ":" << encode.sendMessage(client2->getMessage()) << endl;
				}
			}
			else if (connectS == 'n') {
				messageServer noEncode;
				
				noEncode.establishConnection(client1, client2);
				while (getline(cin, input)) {
					cout << "Client " << client1->getID() << ":";
					getline(cin, input);

					if (input == "") {
						break;
					}

					client1->setMessage(input);
					
					outputFile << "Client " << client1->getID() << ":" << noEncode.sendMessage(client1->getMessage()) << endl;
										
					cout << "Client " << client2->getID() << ":";
					getline(cin, input);

					if (input == "") {
						break;
					}

					outputFile << "Client " << client2->getID() << ":" << noEncode.sendMessage(client2->getMessage()) << endl;
				}
			}
			else {
				cerr << "-----ERROR INVALID INPUT-----";

				delete client1;
				delete client2;
				exit(1);
			}
		}
		else {
			outputFile << "No connection made.";
		}

		delete client1;
		delete client2;
		outputFile.close();
	}

	return 0;
}