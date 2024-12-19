/**
 * @file    main.c
 * @brief
 */

//==============================================================================
// Includes
//==============================================================================

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define LED0 DT_ALIAS(led0)

const struct gpio_dt_spec g_led0 = GPIO_DT_SPEC_GET(LED0, gpios);

static int init_gpio(void);

static int init_gpio(void)
{
  int ret;

  ret = device_is_ready(g_led0.port);
  if (ret < 0)
  {
    printk("Device led0 nao inicializado!\r\n");
    return -1;
  }

  ret = gpio_pin_configure_dt(&g_led0, GPIO_OUTPUT_ACTIVE);
  if (ret < 0)
  {
    printk("Falha na configuracao do led0!\r\n");
    return -1;
  }

  return 0;
}

int main(void)
{
  init_gpio();
  printk(">> Project: ZPHR-STM32-0003 - v1.0.0<<\r\n");

  while (1)
  {
    // Toogle led
    gpio_pin_toggle_dt(&g_led0);

    k_msleep(300);
  }

  return 0;
}
