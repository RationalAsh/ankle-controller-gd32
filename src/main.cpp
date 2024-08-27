/*
  LiangShan Pi has four LED: E3/D7/G3/A5
*/

#include "gd32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"
#include "gd32f4xx_it.h"
#include "systick.h"
#include "system_gd32f4xx.h"

static can_receive_message_struct receive_message;
static FlagStatus can0_receive_flag;
static FlagStatus can1_receive_flag;
static FlagStatus can0_error_flag;
static FlagStatus can1_error_flag;

/*!
    \brief      this function handles CAN0 RX0 exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN0_RX0_IRQHandler(void)
{
    /* check the receive message */
    can_message_receive(CAN0, CAN_FIFO0, &receive_message);
    
    if((0x7ab == receive_message.rx_sfid)&&(CAN_FF_STANDARD == receive_message.rx_ff)&&(8 == receive_message.rx_dlen)){
        can0_receive_flag = SET; 
    }else{
        can0_error_flag = SET; 
    }
}
/*!
    \brief      this function handles CAN1 RX0 exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN1_RX0_IRQHandler(void)
{
    /* check the receive message */
    can_message_receive(CAN1, CAN_FIFO0, &receive_message);
    
    if((0x7ab == receive_message.rx_sfid)&&(CAN_FF_STANDARD == receive_message.rx_ff)&&(8 == receive_message.rx_dlen)){
        can1_receive_flag = SET; 
    }else{
        can1_error_flag = SET; 
    }
}

void setup_peripherals();

/* Task to blink an led. */
void vTaskBlinkLED( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */

    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    while(1) {
        gpio_bit_set(GPIOC, GPIO_PIN_1);
        gpio_bit_reset(GPIOC, GPIO_PIN_2);
        vTaskDelay(50);
        gpio_bit_reset(GPIOC, GPIO_PIN_1);
        gpio_bit_set(GPIOC, GPIO_PIN_2);
        vTaskDelay(100);
    }
}

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
    SystemInit();

    /* configure systick */
    systick_config();

    // Set up the peripherals
    setup_peripherals();

    // Turn on both LEDs
    gpio_bit_set(GPIOC, GPIO_PIN_1);
    gpio_bit_set(GPIOC, GPIO_PIN_2);

    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;

    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    vTaskBlinkLED,       /* Function that implements the task. */
                    "BLINK_LED",          /* Text name for the task. */
                    64,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    3,/* Priority at which the task is created. */
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
     * not enough heap memory to create either the idle or timer tasks. 
     * 
     * If we do reach here, then the LED will blink with long 1s delays, to indicate
     * that the scheduler has failed to start.
     */
    for( ;; ) {
        // Turn on both LEDs
        gpio_bit_set(GPIOC, GPIO_PIN_1);
        gpio_bit_set(GPIOC, GPIO_PIN_2);

        // Delay 100ms
        delay_1ms(1000);

        // Turn off both LEDs
        gpio_bit_reset(GPIOC, GPIO_PIN_1);
        gpio_bit_reset(GPIOC, GPIO_PIN_2);
        
        // Delay 100ms
        delay_1ms(1000);
    }
}


// Function to set up gpio periopherals
static inline void setup_gpio() {
    // Enable the GPIOA peripheral
    rcu_periph_clock_enable(RCU_GPIOA);
    // Enable the GPIOB peripheral
    rcu_periph_clock_enable(RCU_GPIOB);
    // Enable the GPIOC peripheral
    rcu_periph_clock_enable(RCU_GPIOC);

    /******** Configure LED GPIOs ********/
    // Configure the GPIOC pin 1 and 2 as output for LEDs
    gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_1);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
    gpio_bit_reset(GPIOC, GPIO_PIN_1);

    gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_2);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);
    gpio_bit_reset(GPIOC, GPIO_PIN_2);

    /******** Configure CAN GPIOs ********/
    // Set up gpio output options
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_12);
    // Set up gpio mode
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_11);
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_12);
    // Confiugure GPIOA pin 11 and 12 and CAN RX and TX
    gpio_af_set(GPIOA, GPIO_AF_9, GPIO_PIN_11);
    gpio_af_set(GPIOA, GPIO_AF_9, GPIO_PIN_12);
    
    
    // Set up gpio output options
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_12);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
    // Set up gpio mode
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_12);
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO_PIN_13);
    // Configure GPIOB pins 12 and 13 as CAN RX and TX
    gpio_af_set(GPIOB, GPIO_AF_9, GPIO_PIN_12);
    gpio_af_set(GPIOB, GPIO_AF_9, GPIO_PIN_13);
}

// Function to setup the CAN peripheral
static inline void setup_can() {
    // Enable the CAN0 peripheral and the CAN1 peripheral
    rcu_periph_clock_enable(RCU_CAN0);
    rcu_periph_clock_enable(RCU_CAN1);

    // Initialize can bus registers
    can_deinit(CAN0);
    can_deinit(CAN1);

    // Configure the CAN0 and CAN1 peripherals
    can_parameter_struct can_parameter;
    can_struct_para_init(CAN_INIT_STRUCT, &can_parameter);

    /* initialize CAN parameters */
    can_parameter.time_triggered = DISABLE;
    can_parameter.auto_bus_off_recovery = ENABLE;
    can_parameter.auto_wake_up = DISABLE;
    can_parameter.auto_retrans = ENABLE;
    can_parameter.rec_fifo_overwrite = DISABLE;
    can_parameter.trans_fifo_order = DISABLE;
    can_parameter.working_mode = CAN_NORMAL_MODE;
    can_parameter.resync_jump_width = CAN_BT_SJW_1TQ;
    can_parameter.time_segment_1 = CAN_BT_BS1_7TQ;
    can_parameter.time_segment_2 = CAN_BT_BS2_2TQ;
    
    // Baud rate is 1Mbps
    can_parameter.prescaler = 5;

    can_init(CAN0, &can_parameter);
    can_init(CAN1, &can_parameter);
}

static inline void nvic_config() {
    nvic_irq_enable(CAN0_RX0_IRQn, 0, 0);
    nvic_irq_enable(CAN1_RX0_IRQn, 0, 0);
}

// Function to set up all the peripherals on the board
void setup_peripherals() {
    // Set up the GPIO peripherals
    setup_gpio();

    // Set up the CAN peripheral
    setup_can();

    // Set up the NVIC
    nvic_config();
}