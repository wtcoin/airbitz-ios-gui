//
//  User.h
//  AirBitz
//
//  Created by Carson Whitsett on 3/27/14.
//  Copyright (c) 2014 AirBitz. All rights reserved.
//
//  master user object that other modules can access in order to get userName and password

#import <Foundation/Foundation.h>
#import "CommonTypes.h"

@interface User : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *password;

// User Settings
@property (nonatomic) int minutesAutoLogout;
@property (nonatomic) int defaultCurrencyNum;
@property (nonatomic) int64_t denomination;
@property (nonatomic, copy) NSString* denominationLabel;
@property (nonatomic) int denominationType;
@property (nonatomic, copy) NSString* firstName;
@property (nonatomic, copy) NSString* lastName;
@property (nonatomic, copy) NSString* nickName;
@property (nonatomic, copy) NSString* fullName;
@property (nonatomic) bool bNameOnPayments;
@property (nonatomic, copy) NSString* denominationLabelShort;
@property (nonatomic) bool bDailySpendLimit;
@property (nonatomic) int64_t dailySpendLimitSatoshis;
@property (nonatomic) bool bSpendRequirePin;
@property (nonatomic) int64_t spendRequirePinSatoshis;
@property (nonatomic) bool bDisablePINLogin;
@property (nonatomic) NSUInteger sendInvalidEntryCount;
@property (nonatomic) NSUInteger sendState;
@property (nonatomic) NSRunLoop *runLoop;
@property (nonatomic) NSTimer *sendInvalidEntryTimer;
@property (nonatomic) NSUInteger PINLoginInvalidEntryCount;
@property (nonatomic) bool reviewNotified;
@property (nonatomic) NSDate *twoWeeksAfterFirstLoginTime;
@property (nonatomic) int loginCount;

+ (void)initAll;
+ (void)freeAll;
+ (User *)Singleton;
+ (bool)isLoggedIn;
+ (bool)offerUserReview;
+ (void)login:(NSString *)user password:(NSString *)pword;

- (id)init;
- (void)clear;
- (void)loadSettings;
- (void)saveLocalSettings;
- (SendViewState)sendInvalidEntry;
- (void)startInvalidEntryWait;
- (void)endInvalidEntryWait;
- (NSTimeInterval)getRemainingInvalidEntryWait;
- (bool)haveExceededPINLoginInvalidEntries;
- (void)resetPINLoginInvalidEntryCount;
@end
