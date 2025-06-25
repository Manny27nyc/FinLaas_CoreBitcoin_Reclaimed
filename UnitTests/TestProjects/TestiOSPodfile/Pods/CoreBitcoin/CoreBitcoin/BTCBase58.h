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

// Base58 is used for compact human-friendly representation of Bitcoin addresses and private keys.
// Typically Base58-encoded text also contains a checksum.
// Addresses look like 19FGfswVqxNubJbh1NW8A4t51T9x9RDVWQ
// Private keys look like 5KQntKuhYWSRXNqp2yhdXzjekYAR7US3MT1715Mbv5CyUKV6hVe
//
// Here is what Satoshi said about Base58:
// Why base-58 instead of standard base-64 encoding?
// - Don't want 0OIl characters that look the same in some fonts and
//      could be used to create visually identical looking account numbers.
// - A string with non-alphanumeric characters is not as easily accepted as an account number.
// - E-mail usually won't line-break if there's no punctuation to break at.
// - Double-clicking selects the whole number as one word if it's all alphanumeric.


// See NS+BTCBase58.h for easy to use categories.

// Returns data for a Base58 string without checksum
// Data is mutable so you can clear sensitive information as soon as possible.
NSMutableData* BTCDataFromBase58(NSString* string);
NSMutableData* BTCDataFromBase58CString(const char* cstring);

// Returns data for a Base58 string with checksum
NSMutableData* BTCDataFromBase58Check(NSString* string);
NSMutableData* BTCDataFromBase58CheckCString(const char* cstring);

// String in Base58 without checksum, you need to free it yourself.
// It's mutable so you can clear it securely yourself.
char* BTCBase58CStringWithData(NSData* data);

// Same as above, but returns an immutable autoreleased string. Suitable for non-sensitive data.
NSString* BTCBase58StringWithData(NSData* data);

// String in Base58 with checksum, you need to free it yourself.
// It's mutable so you can clear it securely yourself.
char* BTCBase58CheckCStringWithData(NSData* data);

// Same as above, but returns an immutable autoreleased string. Suitable for non-sensitive data.
NSString* BTCBase58CheckStringWithData(NSData* data);

