package vendor.blink.ledmanager;

import java.lang.reflect.*;
import android.os.RemoteException;
import android.os.IBinder;
import vendor.blink.ledservice.*;

public class LedManager {

    private static final String SERVICE_NAME = "led";
    private static LedManager instance;
    private static ILedService service;

    private LedManager() {
        Method method = null;
        service = null;
        try {
            method = Class.forName("android.os.ServiceManager").getMethod("getService", String.class);
            IBinder binder = (IBinder) method.invoke(null, SERVICE_NAME);
            if (binder != null) {
                service = ILedService.Stub.asInterface(binder);
            }
        } catch (NoSuchMethodException | ClassNotFoundException | IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
        }
    }

    public static LedManager getInstance() {
        if(instance == null) {
            instance = new LedManager();
        }
        return instance;
    }

    public void ledON() throws RemoteException {
        service.ledON();
    }

    public void ledOFF() throws RemoteException {
        service.ledOFF();
    }

    public void unexport() throws RemoteException {
        service.unexport();
    }
}