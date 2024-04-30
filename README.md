# Code for 6sens Omnitilt Project : test of LoRa radio (transmitter)

## Overview
This simple application allows us to demonstrate and validate the LoRa subsystem of Zephyr RTOS. This code allows testing of LoRa radio, only transmission for this code.
This is useful for validating your LoRa radio is working correctly before trying to connect to LoRaWAN networks. The version of Zephyr RTOS used is the version v3.4.0.

When started, the application transmit a packet sizes that could be used in a real-world application, a sensor propagating a measurement. To check the transmission of a packet, a code in matlab using a PlutoSDR board was added with an example of plots.

**First Board used** : Cicecrone board by Move-X

**Second Board used** : Original MAMWLExx board, powered by battery/solar panel. (see 6sens_omnitilt repository, hardware part, for more information)

## Building and Running
Before building the sample, please check the frequency/channel configuration prior to use and ensure you are transmitting on a permitted band for your country.

The following commands clean build folder, build and flash the sample:

**Command to use**

west build -t pristine

west build -p -b stm32wl_dw1000_iot_board applications/stm32wle5_rtos_lora

west flash --runner stm32cubeprogrammer