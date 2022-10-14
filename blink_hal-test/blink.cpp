#include<vendor/android_blink/led/1.0/ILed.h>
#include<iostream>
#include<chrono>
#include<thread>
#include<signal.h>

using vendor::android_blink::led::V1_0::ILed;

using namespace std;
using namespace android;
using namespace std::this_thread;
using namespace std::chrono;

// Protótipo da função para desativar gpio
void unexport(int signum);

sp<ILed> ledhalService;

int main() {
    ledhalService = ILed::getService();
    
    // Ao finalizar o programa a função unexport é chamada
    signal(SIGINT, unexport);

    // Verifica se o serviço está funcionando
    if (!ledhalService) {
        cout << "Erro ao acessar o serviço da HAL ILed" << endl;
        return 1;
    }

    // Cria o loop infinito do blink
    while(true) {
        ledhalService->ledON();
        sleep_for(seconds(1));
        ledhalService->ledOFF();
        sleep_for(seconds(1));
    }

    return 0;
}

// Implementação da função para desativar gpio
void unexport(int signum) {
    ledhalService->unexport();
    exit(signum);
}