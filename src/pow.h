// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2019 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GENESIS_POW_H
#define GENESIS_POW_H

#include <arith_uint256.h>
#include <consensus/params.h>

#include <stdint.h>

class CBlockHeader;
class CBlockIndex;
class CChainParams;
class uint256;

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params&);

/** Zawy's LWMA - next generation algorithm */
unsigned int LwmaGetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params&);
unsigned int LwmaCalculateNextWorkRequired(const CBlockIndex* pindexLast, const Consensus::Params& params);


/** Check whether the Equihash solution in a block header is valid */
bool CheckEquihashSolution(const CBlockHeader *pblock, const CChainParams&, const std::string personalizationString);

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params&);

arith_uint256 GetBlockProof(const CBlockIndex& block);

/** Return the time it would take to redo the work difference between from and to, assuming the current hashrate corresponds to the difficulty at tip, in seconds. */
int64_t GetBlockProofEquivalentTime(const CBlockIndex& to, const CBlockIndex& from, const CBlockIndex& tip, const Consensus::Params&);

#endif // GENESIS_POW_H
