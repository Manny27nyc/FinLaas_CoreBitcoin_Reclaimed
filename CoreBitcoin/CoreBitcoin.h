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

#import <CoreBitcoin/BTC256.h>
#import <CoreBitcoin/BTCAddress.h>
#import <CoreBitcoin/BTCAddressSubclass.h>
#import <CoreBitcoin/BTCAssetAddress.h>
#import <CoreBitcoin/BTCAssetID.h>
#import <CoreBitcoin/BTCAssetType.h>
#import <CoreBitcoin/BTCBase58.h>
#import <CoreBitcoin/BTCBigNumber.h>
#import <CoreBitcoin/BTCBitcoinURL.h>
#import <CoreBitcoin/BTCBlindSignature.h>
#import <CoreBitcoin/BTCBlock.h>
#import <CoreBitcoin/BTCBlockchainInfo.h>
#import <CoreBitcoin/BTCBlockHeader.h>
#import <CoreBitcoin/BTCChainCom.h>
#import <CoreBitcoin/BTCCurrencyConverter.h>
#import <CoreBitcoin/BTCCurvePoint.h>
#import <CoreBitcoin/BTCData.h>
#import <CoreBitcoin/BTCEncryptedBackup.h>
#import <CoreBitcoin/BTCEncryptedMessage.h>
#import <CoreBitcoin/BTCErrors.h>
#import <CoreBitcoin/BTCFancyEncryptedMessage.h>
#import <CoreBitcoin/BTCHashID.h>
#import <CoreBitcoin/BTCKey.h>
#import <CoreBitcoin/BTCKeychain.h>
#import <CoreBitcoin/BTCMerkleTree.h>
#import <CoreBitcoin/BTCMnemonic.h>
#import <CoreBitcoin/BTCNetwork.h>
#import <CoreBitcoin/BTCNumberFormatter.h>
#import <CoreBitcoin/BTCOpcode.h>
#import <CoreBitcoin/BTCOutpoint.h>
#import <CoreBitcoin/BTCPaymentMethod.h>
#import <CoreBitcoin/BTCPaymentMethodDetails.h>
#import <CoreBitcoin/BTCPaymentMethodRequest.h>
#import <CoreBitcoin/BTCPaymentProtocol.h>
#import <CoreBitcoin/BTCPaymentRequest.h>
#import <CoreBitcoin/BTCPriceSource.h>
#import <CoreBitcoin/BTCProcessor.h>
#import <CoreBitcoin/BTCProtocolBuffers.h>
#import <CoreBitcoin/BTCProtocolSerialization.h>
#import <CoreBitcoin/BTCQRCode.h>
#import <CoreBitcoin/BTCScript.h>
#import <CoreBitcoin/BTCScriptMachine.h>
#import <CoreBitcoin/BTCSecretSharing.h>
#import <CoreBitcoin/BTCSignatureHashType.h>
#import <CoreBitcoin/BTCTransaction.h>
#import <CoreBitcoin/BTCTransactionBuilder.h>
#import <CoreBitcoin/BTCTransactionInput.h>
#import <CoreBitcoin/BTCTransactionOutput.h>
#import <CoreBitcoin/BTCUnitsAndLimits.h>
#import <CoreBitcoin/SwiftBridgingHeader.h>
