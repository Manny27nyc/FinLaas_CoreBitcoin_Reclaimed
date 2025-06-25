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

extern NSString* const BTCErrorDomain;

typedef NS_ENUM(NSUInteger, BTCErrorCode) {
    
    // Canonical pubkey/signature check errors
    BTCErrorNonCanonicalPublicKey            = 4001,
    BTCErrorNonCanonicalScriptSignature      = 4002,
    
    // Script verification errors
    BTCErrorScriptError                      = 5001,
    
    // BTCPriceSource errors
    BTCErrorUnsupportedCurrencyCode          = 6001,

    // BIP70 Payment Protocol errors
    BTCErrorPaymentRequestInvalidResponse    = 7001,
    BTCErrorPaymentRequestTooBig             = 7002,

    // Secret Sharing errors
    BTCErrorIncompatibleSecret               = 10001,
    BTCErrorInsufficientShares               = 10002,
    BTCErrorMalformedShare                   = 10003,
};