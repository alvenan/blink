#!/bin/sh
 
# Nome do gpio em que o LED está conectado
LED=12
 
# Função para desativar o gpio                  
function unexport {                             
    echo $LED > $GPIO_DRIVER_PATH/unexport       
} 
 
# Ao finalizar o programa a função unexport é chamada
trap unexport EXIT
 
# Estados
ON="1"
OFF="0"
 
# Pasta do driver de gpio
GPIO_DRIVER_PATH=/sys/class/gpio
 
# Ativa o pino LED para uso
echo $LED > $GPIO_DRIVER_PATH/export
 
# Seta a direção do pino para saída
echo "out" > $GPIO_DRIVER_PATH/gpio$LED/direction
 
# Loop infinito do blink
while :; do
    echo $ON > $GPIO_DRIVER_PATH/gpio$LED/value
    sleep 1
    echo $OFF > $GPIO_DRIVER_PATH/gpio$LED/value
    sleep 1
done
