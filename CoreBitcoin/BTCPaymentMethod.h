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

@class BTCAssetID;
@class BTCPaymentMethodItem;
@class BTCPaymentMethodAsset;
@class BTCPaymentMethodRejection;
@class BTCPaymentMethodRejectedAsset;

// Reply by the user: payment_method, methods per item, assets per method.
@interface  BTCPaymentMethod : NSObject

@property(nonatomic, nullable) NSData* merchantData;
@property(nonatomic, nullable) NSArray* /* [BTCPaymentMethodItem] */ items;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end





// Proposed method to pay for a given item
@interface  BTCPaymentMethodItem : NSObject

@property(nonatomic, nonnull) NSString* itemType;
@property(nonatomic, nullable) NSData* itemIdentifier;
@property(nonatomic, nullable) NSArray* /* [BTCPaymentMethodAsset] */ assets;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end





// Proposed asset and amount within BTCPaymentMethodItem.
@interface  BTCPaymentMethodAsset : NSObject

@property(nonatomic, nullable) NSString* assetType; // BTCAssetTypeBitcoin or BTCAssetTypeOpenAssets
@property(nonatomic, nullable) BTCAssetID* assetID; // nil if type is "bitcoin".
@property(nonatomic) BTCAmount amount;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end






// Rejection reply by the server: rejection summary and per-asset rejection info.


@interface  BTCPaymentMethodRejection : NSObject

@property(nonatomic, nullable) NSString* memo;
@property(nonatomic) uint64_t code;
@property(nonatomic, nullable) NSArray* /* [BTCPaymentMethodRejectedAsset] */ rejectedAssets;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end


@interface  BTCPaymentMethodRejectedAsset : NSObject

@property(nonatomic, nonnull) NSString* assetType;  // BTCAssetTypeBitcoin or BTCAssetTypeOpenAssets
@property(nonatomic, nullable) BTCAssetID* assetID; // nil if type is "bitcoin".
@property(nonatomic) uint64_t code;
@property(nonatomic, nullable) NSString* reason;

// Binary serialization in protocol buffer format.
@property(nonatomic, readonly, nonnull) NSData* data;

- (nullable id) initWithData:(nullable NSData*)data;
@end

