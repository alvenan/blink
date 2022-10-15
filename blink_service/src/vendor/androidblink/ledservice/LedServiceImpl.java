package vendor.android_blink.ledservice;

import android.content.Context;

class LedServiceImpl extends ILedService.Stub {
    public static final String LED_PERM = "vendor.android_blink.ledservice.permission.LED";
    private final Context mContext;

    static {
        System.loadLibrary("ledservice_jni");
    }

    public LedServiceImpl(Context context){
        mContext = context;
    }

    public void ledON() {
        mContext.enforceCallingOrSelfPermission(LED_PERM, null);
        nativeLedON();
    }

    public void ledOFF() {
        mContext.enforceCallingOrSelfPermission(LED_PERM, null);
        nativeLedOFF();
    }

    public void unexport() {
        mContext.enforceCallingOrSelfPermission(LED_PERM, null);
        nativeUnexport();
    }

    private static native void nativeLedON();
    private static native void nativeLedOFF();
    private static native void nativeUnexport();
}