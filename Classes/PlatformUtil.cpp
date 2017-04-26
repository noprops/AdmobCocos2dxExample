//
//  PlatformUtil.cpp
//  AdmobCocos2dxExample
//
//  Created by 山本政徳 on 2017/04/24.
//
//

#include "PlatformUtil.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include "platform/android/jni/JniHelper.h"

using namespace std;
USING_NS_CC;

const static char className[] = "info/mygames888/admobcocos2dxexample/PlatformUtil";

std::string PlatformUtil::getAppVersion()
{
    JniMethodInfo t;
    std::string ret = "";
    
    if (JniHelper::getStaticMethodInfo(t, className, "getAppVersion", "()Ljava/lang/String;"))
    {
        jstring  jBundleString = (jstring) t.env->CallStaticObjectMethod(t.classID, t.methodID);
        const char* cpBuf = t.env->GetStringUTFChars(jBundleString,NULL);
        ret = std::string(cpBuf);
        
        t.env->ReleaseStringUTFChars(jBundleString,cpBuf);
        t.env->DeleteLocalRef(jBundleString);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

void PlatformUtil::setUpAd()
{
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, className, "setUpAd", "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
    }
}

void PlatformUtil::showInterstitialAd()
{
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, className, "showInterstitialAd", "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
    }
}

void PlatformUtil::showRewardBasedVideoAd()
{
    JniMethodInfo t;
    
    if (JniHelper::getStaticMethodInfo(t, className, "showRewardBasedVideoAd", "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
    }
}

#endif
