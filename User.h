#include "Blockchain.h"
#include "Cryptography.h"
#include "sha256.h"
class User {
private:
	string name;
	string private_key;
	string public_key;
	string CC_Address; //Cryptocurrency address
	double wallet;

public:
	Blockchain chain;

	User();

	User(string);

	User(string, double);

	void setName(string);

	void setKeys();

	void setWallet(double);

	string getPrivateKey();

	string getPublicKey();

	string getCC_Address();

	double getWallet();

};