//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRMerkleBlock *previous, uint32_t transitionTime);
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
		"213.126.73.99", NULL
};

static const char *BRTestNetDNSSeeds[] = {
        NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    
    {      0, uint256("2a8e100939494904af825b488596ddd536b3a96226ad02e0f7ab7ae472b27a8e"), 1390598806, 0x1e0fffff },
    {5000,uint256("0beb5667d997b1b54af8b9fe7a54a7f6890713a20394d567fd4471aa5fbafdef"),1395271386,0x1b26df79},
    {  10000, uint256("dbe68da579f18c58c7945d560488d02b93a2f6246f1ad54195b95601271fa952"), 1397381675, 0x1c0162bd },
    {  15000, uint256("527ad7df2de9756f1abec5e64c5a79cc720db8dbc9f66b17089934704cb4592e"), 1398914165, 0x1c035879 },
    {  20000, uint256("5f36b392d08f5c5613b14e80201999678955a39b02211573e06b5bf3000aa80f"), 1400417608, 0x1c0378d7 },
    {  25000, uint256("9a66d76b1af7f47940af88c96a8946d90ccbbe30783f9a9f829f841974dfbb43"), 1401980006, 0x1c070cbd },
    { 30000, uint256("cc5130f9fc9325a2031f539047dda13302f7ff5f3c1700d87ca1943590ce0ab8"), 1403465200, 0x1c0596d2 },
    { 35000, uint256("dc8969c16f274fc76cd45e9c1de1e7259893d448b86d62bb40ab784db296cb0b"), 1404931180, 0x1c03db9a },
    { 40000, uint256("7ec384c556f369f4e222c51446ebca2f80c559ae2d0830b863d0e3a23be6dba2"), 1406425500, 0x1c039832 },
    { 45000, uint256("110d779b4c7cc23ba7d35031fc7aa673dd56799e9d4b2966839f921b29c934a2"), 1407927929, 0x1c03341d },
    { 50000, uint256("ff2594d604f31f7a53c0fac2f2ae1c659f24f2c27a7700e4623a86677f600f2e"), 1409448522, 0x1c0525a7 },
    { 55000, uint256("ef195eaa9b25d0003284c49f03d8a285a109d8a25b52d129e531d134e9f5cf1c"), 1410957355, 0x1c03bbe0 },
    { 60000, uint256("800570d8f95796e4642b10dac1f1a6bdd8ddeb8a7334c265110e8105466d1c67"), 1412459068, 0x1c04221c },
    { 65000, uint256("62111ca110698ff55e48e80ee61f80453a429a648702f4d9ebce2c053b67e43b"), 1413943868, 0x1c02ba43 },
    { 70000, uint256("c6455afc0ede26dc33cd816ebb0fa09c464ac0f78941ba6ac3653c13593ca76f"), 1415429641, 0x1c0243d9 },
    { 75000, uint256("a8ed37ab1ea171558831a439956621c44e05f00cdce02f62b69297a929dc5a4c"), 1416927243, 0x1c01bc1d },
    { 80000, uint256("6f32ca479e462c3993fcdf1ef63ed31db24ebeaac38441c9f2526232889ddda2"), 1418447143, 0x1c022aa8 },
    { 85000, uint256("ef40eeaccf79799fa7870e9e9bcfa625739f4806ac697f0a6364c7598795182e"), 1419945097, 0x1c0206da },
    { 90000, uint256("60e3c599d1bf594378b2de4040612ef9c59b2ff6ca64093b2010381307c306f2"), 1421462153, 0x1c027dba },
    { 95000, uint256("8a0ddfe5e1684711d0707b3dea8b94df5b46251b089e24b100559d0f0152a38f"), 1422984133, 0x1c02c56c },
    { 100000, uint256("588d3c1f5ca16ee2036676dac041da617f2c9d7405b1ab6a2df076ddfc8de89b"), 1424511512, 0x1c03109b },
    { 105000, uint256("695ee209bb54f6e7407aa92e2d60a66d351be0793a519e95221b7262f56ec5c6"), 1425994704, 0x1b775828 },
    { 110000, uint256("1d863d6f4b789fdc13725664ea20021c57252c74ad1d26da949eb275dd6627e2"), 1427609571, 0x1c01d590 },
    { 115000, uint256("47285039b0b0b9a908721e8756097a751bd79bf6f51b8d2f0fb5071785514813"), 1429081532, 0x1c010a73 },
    { 120000, uint256("cccd20eab8d3a2207e1041a391cd036efb31fac310954ab7c696adef1324d4f9"), 1430548470, 0x1c008b48 },
    { 125000, uint256("40f63a567ffe586699f8c1b24f42e109b494a52f6f304d7d23ff0d277af685a7"), 1432059302, 0x1c009bd9 },
    { 130000, uint256("64670174930564e09e1414a597039c246ec6266492bb857a36d64d4679a7e21a"), 1433603515, 0x1c01387a },
    { 135000, uint256("bd8ebb8b2278e4d224b5a947867d9341adf7df19aa56d57e733914a028f371c2"), 1435136686, 0x1c01b3b6 },
    { 140000, uint256("4cd632b57985c330ee9e15f5fdda2efa09d8622bf49b2d53dd3ab28e03997709"), 1436694589, 0x1c032c29 },
    { 145000, uint256("cccd20eab8d3a2207e1041a391cd036efb31fac310954ab7c696adef1324d4f9"), 1438204879, 0x1c008b48 },
    { 150000, uint256("d38f2b80525b7ec2df0e71983e3793d33ab465e130006091b2d2327c9cf483a2"), 1439715185, 0x1c036c67 }


};

static const BRCheckPoint BRTestNetCheckpoints[] = {
        //   {     0, "852c475c605e1f20bbe60219c811abaeef08bf0d4ff87eef59200fd7a7567fa7", 1413145109, 0x1b336ce6 },
        // Sitt 2016-02-18 Use Checkpoint from the First day of digiwallet fork (from breadWallet)
    {       0, uint256("000000000933ea01ad0ee984209779baaec3ced90fa3f408719526f8d77f4943"), 1296688602, 0x1d00ffff },
    {  100800, uint256("0000000000a33112f86f3f7b0aa590cb4949b84c2d9c673e9e303257b3be9000"), 1376543922, 0x1c00d907 },
    {  201600, uint256("0000000000376bb71314321c45de3015fe958543afcbada242a3b1b072498e38"), 1393813869, 0x1b602ac0 },
    {  302400, uint256("0000000000001c93ebe0a7c33426e8edb9755505537ef9303a023f80be29d32d"), 1413766239, 0x1a33605e },
    {  403200, uint256("0000000000ef8b05da54711e2106907737741ac0278d59f358303c71d500f3c4"), 1431821666, 0x1c02346c },
    {  504000, uint256("0000000000005d105473c916cd9d16334f017368afea6bcee71629e0fcf2f4f5"), 1436951946, 0x1b00ab86 },
    {  604800, uint256("00000000000008653c7e5c00c703c5a9d53b318837bb1b3586a3d060ce6fff2e"), 1447484641, 0x1a092a20 },
    {  705600, uint256("00000000004ee3bc2e2dd06c31f2d7a9c3e471ec0251924f59f222e5e9c37e12"), 1455728685, 0x1c0ffff0 },
    {  806400,uint256("0000000000000faf114ff29df6dbac969c6b4a3b407cd790d3a12742b50c2398"), 1462006183, 0x1a34e280 },
    {  907200, uint256("0000000000166938e6f172a21fe69fe335e33565539e74bf74eeb00d2022c226"), 1469705562, 0x1c00ffff },
    { 1008000, uint256("000000000000390aca616746a9456a0d64c1bd73661fd60a51b5bf1c92bae5a0"), 1476926743, 0x1a52ccc0 },
    { 1108800, uint256("00000000000288d9a219419d0607fb67cc324d4b6d2945ca81eaa5e739fab81e"), 1490751239, 0x1b09ecf0 }

    
};

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRMerkleBlock *previous, uint32_t transitionTime)
{
    int r = 1;
    
    assert(block != NULL);
    
    if (! previous || !UInt256Eq(block->prevBlock, previous->blockHash) || block->height != previous->height + 1)
        r = 0;
    
    return r;
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    12340,       // standardPort
    0x6cdca4fd, // magicNumber
    0,          // services
    BRMerkleBlockVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints)/sizeof(*BRMainNetCheckpoints)
};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    18333,      // standardPort
    0x6ddca4fd, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints)/sizeof(*BRTestNetCheckpoints)
};

#endif // BRChainParams_h
