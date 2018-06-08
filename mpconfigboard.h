#define MICROPY_HW_BOARD_NAME       "BRAINPAD"
#define MICROPY_HW_MCU_NAME         "STM32F401RE"
#define MICROPY_PY_SYS_PLATFORM     "pyboard"

#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_HAS_SDCARD       (0)
#define MICROPY_HW_HAS_MMA7660      (0)
#define MICROPY_HW_HAS_LIS3DSH      (0)
#define MICROPY_HW_HAS_LCD          (0)
#define MICROPY_HW_ENABLE_RNG       (0)
#define MICROPY_HW_ENABLE_RTC       (0)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_DAC       (0)
#define MICROPY_HW_ENABLE_CAN       (0)

// HSE is 8 MHz - F401 does 84 MHz max
#define MICROPY_HW_CLK_PLLM (8)
#define MICROPY_HW_CLK_PLLN (336)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV4)
#define MICROPY_HW_CLK_PLLQ (7)

// The BRAINPAD doesn't have an RTC crystal.
#define MICROPY_HW_RTC_USE_LSE      (0)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (0)

// UART config
#define MICROPY_HW_UART1_TX	(pin_A9)
#define MICROPY_HW_UART1_RX	(pin_A10)

#define MICROPY_HW_UART2_TX     (pin_A2)
#define MICROPY_HW_UART2_RX     (pin_A3)
#define MICROPY_HW_UART2_RTS  	(pin_A1) // doesn't seem to be accessible on BrainPad
#define MICROPY_HW_UART2_CTS  	(pin_A0)

// I2C busses
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)

#define MICROPY_HW_I2C3_SCL (pin_A8)
#define MICROPY_HW_I2C3_SDA (pin_B4)

// SPI busses

// We don't use NSS, but need to define it.
#define MICROPY_HW_SPI1_NSS  (pin_C3)

#define MICROPY_HW_SPI1_SCK  (pin_B3)
#define MICROPY_HW_SPI1_MISO (pin_B4)
#define MICROPY_HW_SPI1_MOSI (pin_B5)

// The BrainPad has an RGB LED, so we map LED 1 to Red, 2 to Greem and 3 to Blue
#define MICROPY_HW_LED1             (pin_C9)
#define MICROPY_HW_LED1_PWM         { TIM3, 3, TIM_CHANNEL_4, GPIO_AF2_TIM3 }
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

#define MICROPY_HW_LED2             (pin_C8)
#define MICROPY_HW_LED2_PWM         { TIM3, 3, TIM_CHANNEL_3, GPIO_AF2_TIM3 }

#define MICROPY_HW_LED3             (pin_C6)
#define MICROPY_HW_LED3_PWM         { TIM3, 3, TIM_CHANNEL_1, GPIO_AF2_TIM3 }

// There are 4 switches, but the current code only supports one
// So I picked LDR0
#define MICROPY_HW_USRSW_PIN        (pin_A15)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// USB config
#define MICROPY_HW_USB_FS              (1)
//#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
//#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)
