#pragma once

#include <vendor/android_blink/led/1.0/ILed.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace vendor::android_blink::led::implementation {

    using ::android::hardware::hidl_array;
    using ::android::hardware::hidl_memory;
    using ::android::hardware::hidl_string;
    using ::android::hardware::hidl_vec;
    using ::android::hardware::Return;
    using ::android::hardware::Void;
    using ::android::sp;

    struct Led : public V1_0::ILed {
        Return<void> ledON() override;
        Return<void> ledOFF() override;
        Return<void> ledSetup() override;
        Return<void> unexport() override;
    };
    
}
