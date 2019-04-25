//
// Created by Jean baptiste Tamas leloup on 2019-02-19.
//

#include <sstream>
#include "Block.h"


Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

time_t Block::get_tTime() const {
    return _tTime;
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty) {
	char cstr[nDifficulty+1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    return sha256(ss.str());
}

void Block::showAll()
{
	cout << "Index: " << _nIndex << endl
		<< "Nonce: " << _nNonce << endl
		<< "Data: " << _sData << endl
		<< "Hash: " << _sHash << endl
		<< "Timestamp: " << _tTime << endl;
}

uint32_t Block::getIndex()
{
	return _nIndex;
}