//
// Created by Jean baptiste Tamas leloup on 2019-02-19.
//

#include <sstream>
#include "Block.h"


Block::Block(uint32_t nIndexIn, const string &sDataIn, const string &receiver, const string &sender)
        : _nIndex(nIndexIn), _sData(sDataIn), _receiver(receiver), _sender(sender) {
    _nNonce = -1;
    _tTime = time(nullptr);
}

const string &Block::get_sender() const {
    return _sender;
}

const string &Block::get_receiver() const {
    return _receiver;
}

time_t Block::get_tTime() const {
    return _tTime;
}

string Block::GetHash() {
    return _sHash;
}
//mine the block using sha256
void Block::MineBlock(uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
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
    ss << _nIndex << _tTime << _sData << _receiver << _sender << _nNonce << sPrevHash;

    return sha256(ss.str());
}

//display content of the block
void Block::showAll() {
    cout << "Index: " << _nIndex << endl
         << "Receiver: " << _receiver << endl
         << "Sender: " << _sender << endl
         << "Nonce: " << _nNonce << endl
         << "Data: " << _sData << endl
         << "Hash: " << _sHash << endl
         << "Timestamp: " << _tTime << endl;
}

uint32_t Block::getIndex() {
    return _nIndex;
}