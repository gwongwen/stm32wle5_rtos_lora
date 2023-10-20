# Code for 6sens Omnitilt Project : test LoRaWAN sample application

## Overview
This simple application allows us to demonstrate and validate the LoRa subsystem Zephyr. This code allow testing of LoRa radios, only transmission for this code\.
This is useful for validating your LoRa radio is working correctly before trying to connect to LoRaWAN networks..

**First Board used** : Cicecrone board by Move-X

**Second Board used** : Original MAMWLExx board, powered by battery/solar panel. (see 6sens_omnitilt repository/hardware part, for more information)

## Building and Running
Before building the sample, make sure to select the correct region in the prj.conf file.

The following commands clean build folder, build and flash the sample:

**Command to use**

west build -t pristine

west build -p -b stm32wl_dw1000_iot_board applications/stm32wle5_rtos_lora

west flash --runner stm32cubeprogrammer