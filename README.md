# Android blink in Raspberry
This project has the objective to develop a blink app passing through all AOSP layers 

# Hardware
1x Raspiberry Pi 4B 4/8GB

1x led

1x 330 ohm resistor

jumpers

# Circuit
<img
  src="https://github.com/alvenan/blink/blob/main/raspblink.png"
  alt="Alt text"
  title="Blink Circuit"
  style="display: inline-block; margin: 0 auto; width: 300px">

The Gpio used in this project is gpio12

# Code Architecture
blink_shell -> gpio driver -> led

blink_native -> gpio driver -> led

blink_hal-test -> blink_hal -> gpio driver -> led

blink_app -> blink_manager -> blink_service -> blink_hal -> gpio driver -> led

# Setup
In your AOSP device makefile you have to add the following lines:

```Makefile
PRODUCT_PACKAGES += \
    blink_native \
    vendor.blink.led@1.0-service \
    blink_hal-test \
    LedService \
    vendor.blink.ledmanager
```
# Running 
## Bash test
For the shell script file you have to push it via adb to the system and then run
```Shell
localhost blink_shell$ adb push blink_shell.sh /sdcard
rpi /sdcard# sh blink_shell.sh
```

## Native test
For native test, in the android shell run blink_native
```Shell
rpi /# blink_native
```

## HAL test
```Shell
rpi /# blink_hal-test
```

## Java Service Test
```
rpi /# service call led 1 
rpi /# service call led 2 
```

## Android App Installation
Open the blink_app project in the Android Studio and install it in the Raspberry
Press the button to blink the led

<img
  src="https://github.com/alvenan/blink/blob/main/raspblink.gif"
  alt="Alt text"
  title="App gif"
  style="display: inline-block; margin: 0 auto; width: 1000px">



