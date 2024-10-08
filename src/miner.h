#ifndef ELEMENT_MINER_H
#define ELEMENT_MINER_H

class CBlock;
class CWallet;

void BitcoinMiner(CWallet *pwallet, bool fProofOfStake);
CBlock* CreateNewBlock(CWallet* pwallet, bool fProofOfStake);
void ThreadBitcoinMiner(void* parg);

#endif //ELEMENT_MINER_H
