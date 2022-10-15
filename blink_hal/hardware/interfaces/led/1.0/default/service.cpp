#include <hidl/LegacySupport.h>
#include "Led.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using vendor::blink::led::implementation::Led;

#define TAG "LedHalService"

int main() {
    configureRpcThreadpool(16, true);

    android::sp<Led> led = new Led();
    if (led->registerAsService() != ::android::OK) {
        ALOG(LOG_ERROR, TAG, "Erro ao registrar o serviço");
        return 1;
    }

    ALOG(LOG_INFO, TAG, "Serviço inicializado com sucesso!");

    joinRpcThreadpool();

    return 0;
}