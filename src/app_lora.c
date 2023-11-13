/*
 * Copyright (c) 2023
 * Regis Rousseau
 * Univ Lyon, INSA Lyon, Inria, CITI, EA3720
 * SPDX-License-Identifier: Apache-2.0
 */

 #include "app_lora.h"


int app_lora_config(const struct device *dev, bool TxRx)
{
	int ret;
	struct lora_modem_config config;

	config.frequency = 868100000;
	config.bandwidth = BW_125_KHZ;
	config.datarate = SF_8;
	config.preamble_len = 8;
	config.coding_rate = CR_4_5;
	config.tx_power = 4;
	config.iq_inverted = false;
	config.public_network = false;
	config.tx = TxRx;

	ret = lora_config(dev, &config);
	if (ret < 0) {
		printk("LoRa device configuration failed. error: %d\n", ret);
		return false;
	}
	return(true);
}
