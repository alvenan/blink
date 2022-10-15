#include "Led.h"
#include<fstream>
#include<log/log.h>

// Definção de TAG para logs
#define TAG "LedHAL"

// Definições de estados
#define ON "1"
#define OFF "0"

namespace vendor::blink::led::implementation {

    using namespace std;

    // Nome do gpio em que o LED está conectado
    static const string led_pin = "12";

    // Caminhos para pasta e arquivos do driver
    static const string gpio_driver_path = "/sys/class/gpio";
    static const string export_path = gpio_driver_path + "/export";
    static const string unexport_path = gpio_driver_path + "/unexport";
    static const string direction_path = gpio_driver_path + "/gpio" + led_pin + "/direction";
    static const string value_path = gpio_driver_path + "/gpio" + led_pin + "/value";

    // Variáveis dos arquivos a serem abertos
    ofstream export_file, unexport_file, direction_file, value_file;

    Return<void> Led::ledON() {
        // Verifica se a pasta de configuração do gpio já existe
        if(access((gpio_driver_path + "/gpio" + led_pin).c_str(), 0))
            ledSetup();

        // Abre o arquivo value e escreve 1 para nível alto
        value_file.open(value_path);
        if(!value_file.is_open())
            ALOG(LOG_ERROR, TAG, "Error on file %s", value_path.c_str());
        else {
            value_file << ON << endl;
            value_file.close();
        }

        return Void();
    }

    Return<void> Led::ledOFF() {
        // Verifica se a pasta de configuração do gpio já existe
        if(access((gpio_driver_path + "/gpio" + led_pin).c_str(), 0))
            ledSetup();

        // Abre o arquivo value e escreve 0 para nível baixo
        value_file.open(value_path);
        if(!value_file.is_open())
            ALOG(LOG_ERROR, TAG, "Error on file %s", value_path.c_str());
        else {
            value_file << OFF << endl;
            value_file.close();
        }
        return Void();
    }

    Return<void> Led::ledSetup() {
        // Abre arquivo export e ativa o pino do led para uso
        export_file.open(export_path);
        if(!export_file.is_open())
            ALOG(LOG_ERROR, TAG, "Error on file %s", export_path.c_str());
        else {
            export_file << led_pin << endl;
            export_file.close();
        }

        // Abre o arquivo direction e seta a direção do pino para saída
        direction_file.open(direction_path);
        if(!direction_file.is_open())
            ALOG(LOG_ERROR, TAG, "Error on file %s", direction_path.c_str());
        else {
            direction_file << "out" << endl;
            direction_file.close();
        }
        return Void();
    }

    // Função para desativar gpio
    Return<void> Led::unexport() {
        unexport_file.open(unexport_path);
        if(!unexport_file.is_open())
            ALOG(LOG_ERROR, TAG, "Error on file %s", unexport_path.c_str());
        else {
            unexport_file << led_pin << endl;
            unexport_file.close();
        }
        return Void();
    }
}
