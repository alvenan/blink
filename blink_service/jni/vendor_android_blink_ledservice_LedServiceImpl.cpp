#include "vendor_android_blink_ledservice_LedServiceImpl.h"
#include <vendor/android_blink/led/1.0/ILed.h>

using vendor::android_blink::led::V1_0::ILed;
using namespace android;

static sp<ILed> service = nullptr;

JNIEXPORT void JNICALL
  Java_vendor_android_blink_ledservice_LedServiceImpl_nativeLedON
  (JNIEnv *, jclass) {
      if (service == nullptr)
          service = ILed::getService();
      service->ledON();
}

JNIEXPORT void JNICALL
  Java_vendor_android_blink_ledservice_LedServiceImpl_nativeLedOFF
  (JNIEnv *, jclass) {
      if (service == nullptr)
          service = ILed::getService();
      service->ledOFF();
}

JNIEXPORT void JNICALL
  Java_vendor_android_blink_ledservice_LedServiceImpl_nativeUnexport
  (JNIEnv *, jclass) {
      if (service == nullptr)
          service = ILed::getService();
      service->unexport();
}