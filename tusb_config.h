#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

// --- Controller Port Configuration ---
// 0 tells TinyUSB to target the Pico's native micro-USB / USB-C port
#define BOARD_DEVICE_RHPORT_NUM     0
#define BOARD_DEVICE_RHPORT_SPEED   OPT_MODE_FULL_SPEED

// Bind Root Hub Port 0 explicitly to Device Mode
#define CFG_TUSB_RHPORT0_MODE       (OPT_MODE_DEVICE | BOARD_DEVICE_RHPORT_SPEED)

// --- Device Stack Configuration ---
#define CFG_TUD_ENABLED             1
#define CFG_TUD_HID                 1

/* HID Report Descriptor Buffer Size */
#define CFG_TUD_HID_EP_BUFSIZE      16

// --- for serial debugging below
// FIXME: this should be enabled for debug builds only

// Enable Device CDC driver
#define CFG_TUD_CDC                 1

// RX and TX internal FIFO buffer sizes (usually 64 for Full-Speed USB, 512 for High-Speed)
#define CFG_TUD_CDC_RX_BUFSIZE      64
#define CFG_TUD_CDC_TX_BUFSIZE      64

// Endpoint transfer buffer size (sets the max packet size for the physical hardware)
#define CFG_TUD_CDC_EP_BUFSIZE      64

#endif
