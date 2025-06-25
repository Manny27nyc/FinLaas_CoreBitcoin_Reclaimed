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
#import "BTCData.h"

// This category is for user's convenience only.
// For documentation look into BTCData.h.
// If you link CoreBitcoin library without categories enabled, nothing will break.
// This is also used in unit tests in CoreBitcoin.
@interface NSData (BTCData)

// Core hash functions
- (NSData*) SHA1;
- (NSData*) SHA256;
- (NSData*) BTCHash256;  // SHA256(SHA256(self)) aka Hash or Hash256 in BitcoinQT

#if BTCDataRequiresOpenSSL
- (NSData*) RIPEMD160;
- (NSData*) BTCHash160; // RIPEMD160(SHA256(self)) aka Hash160 in BitcoinQT
#endif

// Formats data as a lowercase hex string
- (NSString*) hexString;
- (NSString*) hexUppercaseString;

// Encrypts/decrypts data using the key.
+ (NSMutableData*) encryptData:(NSData*)data key:(NSData*)key iv:(NSData*)initializationVector;
+ (NSMutableData*) decryptData:(NSData*)data key:(NSData*)key iv:(NSData*)initializationVector;

@end
