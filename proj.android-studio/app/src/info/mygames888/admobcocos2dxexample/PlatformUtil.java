package info.mygames888.admobcocos2dxexample;

import org.cocos2dx.cpp.AppActivity;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.util.Log;

public class PlatformUtil {
    public static String getAppVersion(){
        try{
            Context context = AppActivity.getContext();
            String packegeName = context.getPackageName();
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(packegeName, PackageManager.GET_META_DATA);
            String versionName = packageInfo.versionName;
            return versionName;
        }catch(Exception e){
            Log.w("PlatformUtil","getUserViewAppVersion get error");
            Log.w("PlatformUtil",e);
            return "";
        }

    }

    public static void setUpAd() {
        AppActivity.getActivity().setUpAd();
    }

    public static void removeAd() {
        AppActivity.getActivity().removeAd();
    }

    public static void showInterstitialAd(){
        Log.d("PlatformUtil", "showInterstitialAd");
        AppActivity.getActivity().showInterstitialAd();
    }

    public static void showRewardBasedVideoAd(){
        //
    }
}