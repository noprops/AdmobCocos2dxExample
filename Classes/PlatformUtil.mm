//
//  PlatformUtil.m
//  AdmobCocos2dxExample
//
//  Created by 山本政徳 on 2017/04/24.
//
//

#include "PlatformUtil.h"
#include "AppController.h"
#import "Firebase.h"

using namespace std;
USING_NS_CC;

std::string PlatformUtil::getAppVersion()
{
    NSBundle *bundle = [NSBundle mainBundle];
    NSDictionary *dic = [bundle infoDictionary];
    NSString * bundleShortVersion = (NSString *)[dic objectForKey:@"CFBundleVersion"];
    
    std::string ret = [bundleShortVersion UTF8String];
    return ret;
}

void PlatformUtil::setUpAd()
{
    auto appController = (AppController *)[[UIApplication sharedApplication] delegate];
    [appController setUpAd];
}

void PlatformUtil::showInterstitialAd()
{
    auto appController = (AppController *)[[UIApplication sharedApplication] delegate];
    [appController showInterstitialAd];
}

void PlatformUtil::showRewardBasedVideoAd()
{
    auto appController = (AppController *)[[UIApplication sharedApplication] delegate];
    [appController showRewardBasedVideoAd];
}
