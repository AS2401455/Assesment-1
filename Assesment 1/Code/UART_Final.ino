#include <avr/io.h>
#include <util/delay.h>
#include "Uart.h"

void init(void);

int main(void) {
    init();
    Uart_Init();

    while (1) {
        // Button check
        if (!(PINB & (1 << 3))) { // Button pressed (active low)
            PORTB |= (1 << 5);  // Turn LED on
            Uart_SendString("Button Pressed\r\n", 16);
            while (!(PINB & (1 << 3))); // Wait for release
            PORTB &= ~(1 << 5); // Turn LED off
            Uart_SendString("Button Released\r\n", 17);
        }

        // Serial command check (minimal)
        if (Uart_IsDataAvailable()) {
            char c = Uart_ReadData();
            if (c == 'L') {
                if (Uart_ReadData() == 'e' && Uart_ReadData() == 'd') {
                    if (Uart_ReadData() == 'O' && Uart_ReadData() == 'n')
                        PORTB |= (1 << 5);  // Turn LED on
                    else if (Uart_ReadData() == 'O' && Uart_ReadData() == 'f' && Uart_ReadData() == 'f')
                        PORTB &= ~(1 << 5); // Turn LED off
                }
            }
        }
    }
}

void init(void) {
    DDRB |= (1 << 5);  // PB5 as output (LED)
    DDRB &= ~(1 << 3); // PB3 as input (Button)
    PORTB |= (1 << 3); // Enable pull-up resistor on PB3
}


