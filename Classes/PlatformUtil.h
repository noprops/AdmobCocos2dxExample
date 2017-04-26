//
//  PlatformUtil.h
//  AdmobCocos2dxExample
//
//  Created by 山本政徳 on 2017/04/24.
//
//

#ifndef PlatformUtil_h
#define PlatformUtil_h

#include "cocos2d.h"

class PlatformUtil {
public:
    static std::string getAppVersion();
    static void setUpAd();
    static void showInterstitialAd();
    static void showRewardBasedVideoAd();
};

#endif /* PlatformUtil_h */
