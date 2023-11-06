/*
 * Copyright (c) 2023
 * Regis Rousseau
 * Univ Lyon, INSA Lyon, Inria, CITI, EA3720
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/lora.h>
#include <zephyr/drivers/gpio.h>

#include "app_lora.h"

#define MAX_DATA_LEN 10

char data_tx[MAX_DATA_LEN] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};

int main(void)
{
	const struct device *lora_dev;
	int8_t ret;
	int8_t itr = 0;

	printk("LoRa Transmitter Example\nBoard: %s\n", CONFIG_BOARD);
	
	// setup LoRa radio device:
	lora_dev = DEVICE_DT_GET(DT_ALIAS(lora0));
	if (!device_is_ready(lora_dev)) {
		printk("%s: device not ready\n", lora_dev->name);
		return 0;
	}

	if (app_lora_config(lora_dev, TRANSMIT)) {
		printk("LoRa device configured\n");
	} else {
			return 0;
		}

	for (itr = 0; itr < 200; itr++) {

		printk("iteration: %d\n", itr);
		ret = lora_send(lora_dev, data_tx, MAX_DATA_LEN);
		
		if (ret < 0) {
			printk("LoRa send failed\n");
			return 0;
		} else {
			printk("XMIT %d bytes: ", MAX_DATA_LEN);
			for (uint16_t i = 0; i < MAX_DATA_LEN; i++)
				printk("0x%02x ",data_tx[i]);
			printk("\n");
		}

		k_sleep(K_MSEC(50));
	}
	return 0;
}