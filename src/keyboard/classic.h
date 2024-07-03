#ifndef CLASSIC_KEYBOARD_H
#define CLASSIC_KEYBOARD_H

#define PS2_PORT 0x64
#define PS2_COMMAND_ENABLE_FIRST_PORT 0xAE
#define CLASSIC_KEYBOARD_KEY_RELEASED 0x80
#define ISR_KEYBOARD_INTERRUPT 0x21
/**
 * IO port
 */
#define KEYBOARD_INPUT_PORT 0x60

struct keyboard* classic_init();
void classic_keyboard_handle_interrupt();

#endif