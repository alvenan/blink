#include<iostream>
#include<fstream>
#include<chrono>
#include<thread>
#include<signal.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Definições de estados
#define ON "1"
#define OFF "0"

// Protótipo da função para desativar gpio
void unexport(int signum);

// Nome do gpio em que o LED está conectado
static const string led = "12";

// Caminhos para pasta e arquivos do driver
static const string gpio_driver_path = "/sys/class/gpio";
static const string export_path = gpio_driver_path + "/export";
static const string unexport_path = gpio_driver_path + "/unexport";
static const string direction_path = gpio_driver_path + "/gpio" + led + "/direction";
static const string value_path = gpio_driver_path + "/gpio" + led + "/value";

// Variáveis dos arquivos a serem abertos
ofstream export_file, unexport_file, direction_file, value_file;

int main() {
    // Ao finalizar o programa a função unexport é chamada
    signal(SIGINT, unexport);

    // Abre arquivo export e ativa o pino do led para uso
    export_file.open(export_path);
    if(!export_file.is_open()){
        cout << "Error on file " << export_path << endl;
    }
    else {
        export_file << led << endl;
        export_file.close();
    }

    // Abre o arquivo direction e seta a diração do pino para saída
    direction_file.open(direction_path);
    if(!direction_file.is_open()){
        cout << "Error on file " << direction_path << endl;
    }
    else {
        direction_file << "out" << endl;
        direction_file.close();
    }

    // Abre o arquivo value e cria o loop infinito do blink
    value_file.open(value_path);
    if(!value_file.is_open()){
        cout << "Error on file " << value_path << endl;
    }
    else {
        while(true){
            value_file << ON << endl;
            sleep_for(seconds(1));
            value_file << OFF << endl;
            sleep_for(seconds(1));
        }
    }

    return 0;
}

// Implementação da função para desativar gpio
void unexport(int signum) {
    value_file.close();
    unexport_file.open(unexport_path);
    if(!unexport_file.is_open())
        cout << "Error on file " << unexport_path << endl;
    else {
        unexport_file << led << endl;
        unexport_file.close();
    }
    exit(signum);
}