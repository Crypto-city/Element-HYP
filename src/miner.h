#ifndef ELEMENT_MINER_H
#define ELEMENT_MINER_H

class CBlock;
class CWallet;

void ElementMinter(CWallet *pwallet, bool fProofOfStake);
CBlock* CreateNewBlock(CWallet* pwallet, bool fProofOfStake);
void ThreadElementMinter(void* parg);

#endif //ELEMENT_MINER_H
