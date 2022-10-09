#include "PinNames.h"
#include "ThisThread.h"
#include "Thread.h"
#include "cmsis_os2.h"
#include "mbed.h"
#include "nsapi_types.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

void CtrlLed1();

// main() runs in its own thread in the OS
int main()
{
    Thread* led1_thread = new Thread(osPriorityNormal, 2048, nullptr, "led1_thread");
    Thread* led2_thread = new Thread(osPriorityNormal, 2048, nullptr, "led2_thread");
    led1_thread->start(CtrlLed1);
    led2_thread->start(CtrlLed2);

}

void CtrlLed1()
{
    while(1)
    {
        led1 = !led;
        printf("on-off");
        wait_us(5e5);
        led = !led;
        wait_us(5e5);
    }
}