#include "pico/stdlib.h"
#include "tusb.h"

#define JIGGLE_INTERVAL_MS 60000 // 60 seconds

void mouse_jiggle_task(void) {
    static uint32_t start_ms = 0;
    static bool direction = false;

    // check if the USB host is ready and configured
    if (!tud_hid_ready()) return;

    uint32_t current_time_ms = to_ms_since_boot(get_absolute_time());

    // move mouse run when interval expires
    if (current_time_ms - start_ms < JIGGLE_INTERVAL_MS) return;
    start_ms = current_time_ms;

    if (direction) {
        // right 1 pixel
        tud_hid_mouse_report(1, 0, 1, 0, 0, 0);
    } else {
        // left 1 pixel
        tud_hid_mouse_report(1, 0, -1, 0, 0, 0);
    }

    // toggle direction for the next run
    direction = !direction;
}

int main(void) {
    stdio_init_all(); 
    tusb_init();

    while (1) {
        tud_task(); // TinyUSB device task
        mouse_jiggle_task();
    }
}

// Required TinyUSB callbacks
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen) {
    (void) instance; (void) report_id; (void) report_type; (void) buffer; (void) reqlen;
    return 0;
}

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) {
    (void) instance; (void) report_id; (void) report_type; (void) buffer; (void) bufsize;
}
