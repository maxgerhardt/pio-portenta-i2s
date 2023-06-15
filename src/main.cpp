#include <Arduino.h>
#include <i2s_init.h>

uint16_t samplebuf[4096]; // for both left + right
const int nsamples = sizeof(samplebuf) / sizeof(samplebuf[0]);
#ifndef PI
#define PI 3.14159265358979323846
#endif
#define TAU (2.0 * PI)
/**
 * I2S1 GPIO Configuration
    PB5     ------> I2S1_SDO   [serial data]
    PG10     ------> I2S1_WS   [word-select, left=0, right=1]
    PG11     ------> I2S1_CK   [serial clock]
    PC4     ------> I2S1_MCK   [master clock output if codex needs it]
*/

void setup()
{
    MX_GPIO_Init();
    MX_I2S1_Init();
    // fill signal buffer with sine wave
    int i = 0;
    while(i < nsamples) {
        double t = ((double)i/2.0)/((double)nsamples);
        samplebuf[i] = 32767*sin(100.0 * TAU * t); // left channel
        samplebuf[i+1] = samplebuf[i]; // right channel (same)
        i += 2;
    }
}

void loop()
{
    // transmit full buffer over and over again
    HAL_I2S_Transmit(&hi2s1, samplebuf, nsamples, HAL_MAX_DELAY);
}
