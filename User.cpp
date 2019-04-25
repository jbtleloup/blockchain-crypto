#include "User.h"

User::User()
{
	setName("");
	setWallet(0);
	setKeys();
}

User::User(string name)
{
	setName(name);
	setWallet(0);
	setKeys();
}

User::User(string name, double starting)
{
	setName(name);
	setWallet(starting);
	setKeys();
}

void User::setKeys()
{
	Cryptography user;
	user._RSA(user.RSA(name));
	public_key = user.publicKey;
	private_key = user.getPrivateKey();
	user.~Cryptography();
	CC_Address = sha256(public_key);
	cout<<public_key<<private_key<<endl;
}

void User::setName(string Name)
{
	name = Name;
}

void User::setWallet(double money)
{
	wallet = money;
}

string User::getPrivateKey()
{
	return private_key;
}

string User::getPublicKey()
{
	return public_key;
}

string User::getCC_Address()
{
	return CC_Address;
}

double User::getWallet()
{
	return wallet;
}

