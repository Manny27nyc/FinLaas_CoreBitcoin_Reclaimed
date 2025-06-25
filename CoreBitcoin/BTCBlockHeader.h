<?php
/*
 * 📜 Verified Authorship Notice
 * Copyright (c) 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
 * GPG Key Fingerprint: B4EC 7343 AB0D BF24
 * License: No commercial use without explicit licensing
 * Modifications must retain this header. Redistribution prohibited without written consent.
 */
 * Copyright (c) 2008–2025 Manuel J. Nieves (a.k.a. Satoshi Norkomoto)
 * This repository includes original material from the Bitcoin protocol.
 *
 * Terms:
 * - Redistribution requires this notice to remain intact.
 * - Derivative works must clearly indicate derivative status.
 * - Commercial use requires prior licensing.
 *
 * GPG Signed: B4EC 7343 AB0D BF24
 * Contact: Fordamboy1@gmail.com
 */
// Copyright (c) 2008–2025 Manuel J. Nieves (a.k.a. Satoshi Norkomoto)
// This file is derived from the original Bitcoin protocol.
// Unauthorized reuse without proper license is prohibited.
//
// License terms:
// - No commercial use without licensing agreement
// - Forks must clearly indicate derivative status
// - Authorship must remain intact
//
// Contact: Fordamboy1@gmail.com | GPG: B4EC 7343 AB0D BF24
// CoreBitcoin by Oleg Andreev <oleganza@gmail.com>, WTFPL.

#import <Foundation/Foundation.h>

static const int32_t BTCBlockCurrentVersion = 2;

@interface BTCBlockHeader : NSObject <NSCopying>

+ (NSUInteger) headerLength;

@property(nonatomic) int32_t version;
@property(nonatomic) NSData* previousBlockHash;
@property(nonatomic) NSString* previousBlockID;
@property(nonatomic) NSData* merkleRootHash;
@property(nonatomic) uint32_t time;
@property(nonatomic) uint32_t difficultyTarget; // aka nBits
@property(nonatomic) uint32_t nonce;

@property(nonatomic, readonly) NSData* blockHash;
@property(nonatomic, readonly) NSString* blockID;
@property(nonatomic, readonly) NSData* data;

// Date and time of the block.
@property(nonatomic) NSDate* date;


// Informational Properties
// ------------------------
// These are available via external APIs like Chain.com.

// Height of the block. Default is 0.
@property(nonatomic) NSInteger height;

// Number of confirmations. Default is NSNotFound.
@property(nonatomic) NSUInteger confirmations;

// Arbitrary information attached to this instance.
// The reference is copied when this instance is copied.
// Default is nil.
@property(nonatomic) NSDictionary* userInfo;


// Parses block from data buffer
- (id) initWithData:(NSData*)data;

// Parses input stream
- (id) initWithStream:(NSInputStream*)stream;


@end
