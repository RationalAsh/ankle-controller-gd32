/*
  LiangShan Pi has four LED: E3/D7/G3/A5
*/

#include "gd32f4xx.h"
#include "systick.h"
#include "FreeRTOS.h"
#include "task.h"
#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"


/* Task to blink an led. */
void vTaskBlinkLED( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */

    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    while(1) {
        gpio_bit_set(GPIOC, GPIO_PIN_1);
        vTaskDelay(100);
        gpio_bit_reset(GPIOC, GPIO_PIN_1);
    }
}

/* Function that creates a task. */
// void vOtherFunction( void )
// {
//     BaseType_t xReturned;
//     TaskHandle_t xHandle = NULL;

//     /* Create the task, storing the handle. */
//     xReturned = xTaskCreate(
//                     vTaskCode,       /* Function that implements the task. */
//                     "NAME",          /* Text name for the task. */
//                     64,      /* Stack size in words, not bytes. */
//                     ( void * ) 1,    /* Parameter passed into the task. */
//                     tskIDLE_PRIORITY,/* Priority at which the task is created. */
//                     &xHandle );      /* Used to pass out the created task's handle. */

//     if( xReturned == pdPASS )
//     {
//         /* The task was created. Use the task's handle to delete the task. */
//         vTaskDelete( xHandle );
//     }
// }

// Define vApplicationMallocFailedHook() to catch memory allocation errors
void vApplicationMallocFailedHook( void )
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.  It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created.  It is also called by various parts of the
    demo application.  If heap_1.c, heap_2.c or heap_4.c are used, then the
    size of the heap available to pvPortMalloc() is defined by
    configTOTAL_HEAP_SIZE in FreeRTOSConfig.h, and the xPortGetFreeHeapSize()
    API function can be used to query the size of free heap space that remains
    (although it does not provide information on how the remaining heap space
    might be fragmented). */
    taskDISABLE_INTERRUPTS();
    for( ;; );
}


int main(void)
{
    /* configure systick */
    systick_config();

    /* enable the LEDs GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOC);

    /* configure LED GPIO port */
    gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_1);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
    gpio_bit_reset(GPIOC, GPIO_PIN_1);

    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;

    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    vTaskBlinkLED,       /* Function that implements the task. */
                    "BLINK_LED",          /* Text name for the task. */
                    64,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */

    if( xReturned == pdPASS )
    {
        /* The task was created. Use the task's handle to delete the task. */
        // vTaskDelete( xHandle );
    }

    /* Start the scheduler so the tasks start executing. */
    vTaskStartScheduler();

    /*
     * If all is well main() will not reach here because the scheduler will now
     * be running the created tasks. If main() does reach here then there was
     * not enough heap memory to create either the idle or timer tasks
     * (described later in this book). Chapter 3 provides more information on
     * heap memory management.
     */
    for( ;; );
}