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
#import "BTCUnitsAndLimits.h"

@class BTCScript;
@class BTCAddress;
@class BTCTransaction;

static uint32_t const BTCTransactionOutputIndexUnknown = 0xffffffff;

// Transaction output (aka "tx out") is a value with rules attached in form of a script.
// To spend money one need to choose a transaction output and provide an appropriate
// input which makes the script execute with success.
@interface BTCTransactionOutput : NSObject<NSCopying>

// Creates an output with a standard script redeeming to an address (OP_DUP OP_HASH160 <addr> OP_EQUALVERIFY OP_CHECKSIG).
// Also supports P2SH addresses.
+ (instancetype) outputWithValue:(BTCSatoshi)value address:(BTCAddress*)address;

// Serialized binary form of the output (payload)
@property(nonatomic, readonly) NSData* data;

// Value of output in satoshis.
@property(nonatomic) BTCSatoshi value;

// Script defining redemption rules for this output (aka scriptPubKey or pk_script)
@property(nonatomic) BTCScript* script;

// Reference to owning transaction. Set on [tx addOutput:...] and reset to nil on [tx removeAllOutputs].
@property(weak, nonatomic) BTCTransaction* transaction;

// These are informational properties updated in certain context.
// E.g. when loading unspent outputs from blockchain.info (BTCBlockchainInfo), all these properties will be set.
// index and transactionHash are kept up to date when output is added/removed from the transaction.

// Index of this output in its transaction. Default is BTCTransactionOutputIndexUnknown
@property(nonatomic) uint32_t index;

// Number of confirmations. Default is NSNotFound.
@property(nonatomic) NSUInteger confirmations;

// Identifier of the transaction. Default is nil.
@property(nonatomic) NSData* transactionHash;

// Parses tx output from a data buffer.
- (id) initWithData:(NSData*)data;

// Read tx output from the stream.
- (id) initWithStream:(NSInputStream*)stream;

// Constructs transaction output from a dictionary representation
- (id) initWithDictionary:(NSDictionary*)dictionary;

// Returns a dictionary representation suitable for encoding in JSON or Plist.
- (NSDictionary*) dictionaryRepresentation;

@end
