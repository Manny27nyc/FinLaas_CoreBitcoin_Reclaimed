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

// TODO: support handling URL from UIApplicationDelegate.

/*!
 * Class to compose and handle various Bitcoin URLs according to BIP21.
 * See: https://github.com/bitcoin/bips/blob/master/bip-0021.mediawiki
 */
@class BTCAddress;
@class BTCAssetID;
@interface BTCBitcoinURL : NSObject

/*!
 * Encoded address.
 */
@property(nonatomic, nullable) BTCAddress* address;

/*!
 * Amount in satoshis. Default is 0.
 */
@property(nonatomic) BTCAmount amount;

/*!
 * Asset ID for Open Assets URL.
 */
@property(nonatomic, nullable) BTCAssetID* assetID;

/*!
 * Label. Default is nil.
 */
@property(nonatomic, nullable) NSString* label;

/*!
 * Message. Default is nil.
 */
@property(nonatomic, nullable) NSString* message;

/*!
 * Query parameters. Default is nil.
 */
@property(nonatomic, nonnull) NSDictionary* queryParameters;

/*!
 * Payment request URL (r=...). Default is nil.
 */
@property(nonatomic, nullable) NSURL* paymentRequestURL;

/*!
 * Complete URL built from the individual properties.
 */
@property(nonatomic, readonly, nonnull) NSURL* URL;

/*!
 * Returns YES if it has a valid address or paymentRequestURL.
 */
@property(nonatomic, readonly) BOOL isValid;

/*!
 * Returns YES if it is a pure bitcoin URL. That does not specify asset_id and not uses openassets: scheme.
 */
@property(nonatomic, readonly) BOOL isValidBitcoinURL;

/*!
 * Returns YES if it is an Open Assets URL.
 */
@property(nonatomic, readonly) BOOL isValidOpenAssetsURL;

/*!
 * Makes a URL in form "bitcoin:<address>?amount=1.2345&label=<label>.
 * @param address Address to be rendered in base58 format.
 * @param amount  Amount in satoshis. Note that URI scheme dictates to render this amount as a decimal number in BTC.
 * @param label   Optional label.
 */
+ (nonnull NSURL*) URLWithAddress:(nonnull BTCAddress*)address amount:(BTCAmount)amount label:(nullable NSString*)label;

/*!
 * Instantiates if URL is a valid bitcoin: URL.
 * To be valid it should either contain a valid address, or payment request URL (r=), or both.
 */
- (nullable id) initWithURL:(nullable NSURL*)url;

/*!
 * Instantiates an empty Bitcoin URL.
 * Fill in address, amount, label and other fields and use `URL` property to get a composed URL.
 */
- (nonnull id) init;

/*!
 * Object subscripting to access query parameters more conveniently
 * @param key The key in the queryParameters
 */
- (nullable id)objectForKeyedSubscript:(nonnull id <NSCopying>)key;

/*!
 * Object subscripting to set query parameter key value pairs more conveniently
 * @param obj The value to be set for key in queryParameters
 * @param key The key for value in the queryParameters
 */
- (void)setObject:(nullable id)obj forKeyedSubscript:(nonnull id <NSCopying>)key;

@end
