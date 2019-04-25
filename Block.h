//
// Created by Jean baptiste Tamas leloup on 2019-02-19.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <time.h>
#include "sha256.h"

using namespace std;

class Block {
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &sDataIn);

    string GetHash();

    void MineBlock(uint32_t nDifficulty);

    time_t get_tTime() const;

	uint32_t getIndex();

	void showAll();

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    string _CalculateHash() const;
};


#endif //BLOCKCHAIN_BLOCK_H
