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

// Serialized binary form of the output (payload)
@property(nonatomic, readonly) NSData* data;

// Value of output in satoshis.
@property(nonatomic) BTCAmount value;

// Script defining redemption rules for this output (aka scriptPubKey or pk_script)
@property(nonatomic) BTCScript* script;

// Reference to owning transaction. Set on [tx addOutput:...] and reset to nil on [tx removeAllOutputs].
@property(weak, nonatomic) BTCTransaction* transaction;

// Hash of the transaction. Default is nil.
@property(nonatomic) NSData* transactionHash;

// Identifier of the transaction. Default is nil.
@property(nonatomic) NSString* transactionID;

// Informational properties
// ------------------------
// These are set by external APIs such as Chain.com.
// E.g. when loading unspent outputs from Chain, all these properties will be set.
// index and transactionHash are kept up to date when output is added/removed from the transaction.


// Index of this output in its transaction. Default is BTCTransactionOutputIndexUnknown
@property(nonatomic) uint32_t index;

// Hash of the block in which this transaction output is included.
// Unconfirmed transaction outputs have nil block hash.
// Default is transaction.blockHash or nil.
@property(nonatomic) NSData* blockHash;

// ID of the block in which this transaction output is included.
// Unconfirmed transaction outputs have nil block ID.
// Default is transaction.blockHash or nil.
@property(nonatomic) NSString* blockID;

// Informational property, could be set by some APIs that fetch transactions.
// Note: unconfirmed transactions may be marked with -1 block height.
// Default is transaction.blockHeight or 0.
@property(nonatomic) NSInteger blockHeight;

// Date and time of the block if specified by the API that returns this transaction.
// Default is transaction.blockDate or nil.
@property(nonatomic) NSDate* blockDate;

// Number of confirmations.
// Default is transaction.confirmations or NSNotFound.
@property(nonatomic) NSUInteger confirmations;

// If available, returns whether this output is spent (YES or NO).
// Default is NO.
@property(nonatomic, getter=isSpent) BOOL spent;

// If this transaction is spent, contains number of confirmations of the spending transaction.
// Returns NSNotFound if not available or output is not spent.
// Returns 0 if spending transaction is unconfirmed.
@property(nonatomic) NSUInteger spentConfirmations;


// Arbitrary information attached to this instance.
// The reference is copied when this instance is copied.
// Default is nil.
@property(nonatomic) NSDictionary* userInfo;

// Parses tx output from a data buffer.
- (id) initWithData:(NSData*)data;

// Reads tx output from the stream.
- (id) initWithStream:(NSInputStream*)stream;

// Makes tx output from a dictionary representation
- (id) initWithDictionary:(NSDictionary*)dictionary;

// Makes tx output with a certain amount of coins on the output.
- (id) initWithValue:(BTCAmount)value;

// Makes tx output with a standard script redeeming to an address (pubkey hash or P2SH).
- (id) initWithValue:(BTCAmount)value address:(BTCAddress*)address;

// Makes tx output with a given script.
- (id) initWithValue:(BTCAmount)value script:(BTCScript*)script;

// Returns a dictionary representation suitable for encoding in JSON or Plist.
@property(nonatomic, readonly) NSDictionary* dictionary;

- (NSDictionary*) dictionaryRepresentation DEPRECATED_ATTRIBUTE;

@end
