#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "portaudio.h"

int main() 
{
    PaError err = paNoError;

    PaDeviceIndex defaultOutputDevice;
    PaDeviceIndex defaultInputDevice;

    err = Pa_Initialize();
    if( err != paNoError )
    {
        printf( "ERROR: Pa_Initialize returned 0x%x\n", err );
        goto error;
    }

    printf( "PortAudio version: 0x%08X\n", Pa_GetVersion());
    // printf( "Version text: '%s'\n", Pa_GetVersionInfo()->versionText );

    const int count = 20;
    for (int i = 0; i < count; ++i)
    {
        defaultInputDevice = Pa_GetDefaultInputDevice();
        defaultOutputDevice = Pa_GetDefaultOutputDevice();
        printf("Input: %i, Output: %i\n", defaultInputDevice, defaultOutputDevice);

        err = Pa_RefreshDevices();
        if( err != paNoError )
        {
            printf( "ERROR: Pa_RefreshDevices returned 0x%x\n", err );
            goto error;
        }

        sleep(2);
    }

    Pa_Terminate();

    printf("----------------------------------------------\n");
    return 0;
error:
    return 1;
}