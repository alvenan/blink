package vendor.android_blink.ledservice;

import android.app.Application;
import android.os.ServiceManager;
import android.util.Log;

public class LedService extends Application {
    private static final String SERVICE_NAME = "led";
    private LedServiceImpl serviceImpl;

    public void onCreate() {
        super.onCreate();
        Log.i("LedService", "Starting service...");
        serviceImpl = new LedServiceImpl(getApplicationContext());
        ServiceManager.addService(SERVICE_NAME, serviceImpl);
    }

    public void onTerminate() {
        super.onTerminate();
    }
}