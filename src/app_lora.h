/*
 * Copyright (c) 2023
 * Regis Rousseau
 * Univ Lyon, INSA Lyon, Inria, CITI, EA3720
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef APP_LORA__H
#define APP_LORA__H

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/lora.h>
#include <zephyr/drivers/gpio.h>

#define TRANSMIT    1

int app_lora_config(const struct device *dev, bool TxRx);

#endif /* APP_LORA__H */