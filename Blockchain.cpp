//
// Created by Jean baptiste Tamas leloup on 2019-02-19.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block", std::string(), std::string()));
    _nDifficulty = 5; //number of zero in nunce
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::GetLastBlock() {
    return _GetLastBlock();
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}