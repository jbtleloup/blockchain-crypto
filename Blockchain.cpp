//
// Created by Jean baptiste Tamas leloup on 2019-02-19.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 3;
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    //cout << "time" << _GetLastBlock().get_tTime() << endl;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::GetLastBlock()
{
	return _GetLastBlock();
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}