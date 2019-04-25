#include "Helper.h"

#include <math.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Cryptography
{
public:
	Cryptography();
	~Cryptography();

	void CreateKey();
	int CalculateDecryptionKey(int publicKey, int phi);
	
	string RSA(string message);

	string _RSA(string message);

	int publicKey;
	int n;
	int getPrivateKey();

private:
	int privateKey;
};