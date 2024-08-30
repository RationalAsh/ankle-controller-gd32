/*
  LiangShan Pi has four LED: E3/D7/G3/A5
*/

#include "gd32f4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "gd32f4xx_rcu.h"
#include "gd32f4xx_gpio.h"
#include "gd32f4xx_timer.h"
#include "gd32f4xx_it.h"
#include "systick.h"
#include "system_gd32f4xx.h"
#include <stdio.h>
#include "arm_math.h"
#include "backsupport_gyems_v4_f446.h"

static can_receive_message_struct receive_message;
static FlagStatus can0_receive_flag;
static FlagStatus can1_receive_flag;
static FlagStatus can0_error_flag;
static FlagStatus can1_error_flag;
static backsupportModelClass simulink_model;
static backsupportModelClass::ExtU model_inputs;
static backsupportModelClass::ExtY model_outputs;
static float32_t s = 0;

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
    } else {
        can1_error_flag = SET; 
    }
}

/* Function Declarations */
void setup_peripherals();
void set_motor_current(unsigned int id, uint16_t current);

/* Task to blink an led. */
void vTaskControlLoop( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
       pvParameters value in the call to xTaskCreate() below. */

    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    // Task call counter
    static uint32_t ulCallCount = 0;

    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 2;

    xLastWakeTime = xTaskGetTickCount();

    while(1) {
        // Turn on LED to measure the time taken to execute the task
        gpio_bit_set(GPIOC, GPIO_PIN_1);

        // Setup the model inputs
        model_inputs.TimeSignal = xTaskGetTickCount() * 0.001f;

        // Spring Encoder Data
        model_inputs.SpringEncoder1 = 0.0f;

        // IMU Data
        model_inputs.IMU1[0] = 0.0f;
        model_inputs.IMU1[1] = 0.0f;
        model_inputs.IMU1[2] = 0.0f;
        model_inputs.IMU1[3] = 0.0f;
        model_inputs.IMU1[4] = 0.0f;
        model_inputs.IMU1[5] = 0.0f;

        // Control Gains
        model_inputs.Kp = 1.50;
        model_inputs.Kd = 0.02;
        model_inputs.Ki = 0.00001;
        model_inputs.Kff = (1.0/9.0);
        model_inputs.k_theta = 0.182;

        // The control input mode.
        model_inputs.Mode = 6;
        
        if (ulCallCount == 0) {
            model_inputs.EnableAssist = 0;
        }


        if (ulCallCount > 1000) {
            model_inputs.EnableAssist = 1;
        }
        
        // Set the model inputs
        simulink_model.setExternalInputs(&model_inputs);
        simulink_model.step();
        // Read model outputs
        model_outputs = simulink_model.getExternalOutputs();    
        
        
        // Set the motor command
        // set_motor_command(model_outputs.Motor1Command);

        if (model_outputs.LEDStates[0] == 1) {
            gpio_bit_reset(GPIOC, GPIO_PIN_2);
        } else {
            gpio_bit_set(GPIOC, GPIO_PIN_2);
        }

        // Increment the counter
        ulCallCount++;

        // Wait for the next cycle.
        gpio_bit_reset(GPIOC, GPIO_PIN_1); // Turn off the LED
        vTaskDelayUntil( &xLastWakeTime, xFrequency );
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

    // Setup the simulink model
    simulink_model.initialize();

    printf("Peripherals setup complete\n");

    // Turn on both LEDs
    gpio_bit_set(GPIOC, GPIO_PIN_1);
    gpio_bit_set(GPIOC, GPIO_PIN_2);

    BaseType_t xReturned;
    TaskHandle_t xHandle = NULL;

    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    vTaskControlLoop,       /* Function that implements the task. */
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


    /* Configure the GPIO pin for the encoders */
    // First TIM3 for PA6 and PA7
    // Set up gpio output options
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
    // Set up gpio mode
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO_PIN_6);
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO_PIN_7);
    // Configure GPIOA pins 6 and 7 as encoder A and B channels
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_6);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_7);

    // Next TIM4 for PB6 and PB7
    // Set up gpio output options
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
    gpio_output_options_set(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
    // Set up gpio mode
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO_PIN_6);
    gpio_mode_set(GPIOB, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO_PIN_7);
    // Configure GPIOB pins 6 and 7 as encoder A and B channels
    gpio_af_set(GPIOB, GPIO_AF_2, GPIO_PIN_6);
    gpio_af_set(GPIOB, GPIO_AF_2, GPIO_PIN_7);

    /* Configure the GPIO pins PC10 and PC11 for USART2 */
    // Set up gpio output options
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_11);
    // Set up gpio mode
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_10);
    gpio_mode_set(GPIOC, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_11);
    // Configure GPIOC pins 10 and 11 as USART2 TX and RX
    gpio_af_set(GPIOC, GPIO_AF_7, GPIO_PIN_10);
    gpio_af_set(GPIOC, GPIO_AF_7, GPIO_PIN_11);
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
    can_parameter.time_triggered = DISABLE;             // Time triggered communication mode disable
    can_parameter.auto_bus_off_recovery = ENABLE;       // Automatic bus-off recovery enable
    can_parameter.auto_wake_up = DISABLE;               // Automatic wake-up mode disable
    can_parameter.auto_retrans = ENABLE;                // Automatic retransmission mode enable
    can_parameter.rec_fifo_overwrite = DISABLE;         // Receive FIFO overwrite mode disable
    can_parameter.trans_fifo_order = DISABLE;           // Transmit FIFO order
    can_parameter.working_mode = CAN_NORMAL_MODE;       // CAN normal mode
    can_parameter.resync_jump_width = CAN_BT_SJW_1TQ;   // Resynchronization jump width is 1 time quantum
    can_parameter.time_segment_1 = CAN_BT_BS1_7TQ;      // Time segment 1 is 7 time quantum
    can_parameter.time_segment_2 = CAN_BT_BS2_2TQ;      // Time segment 2 is 2 time quantum
    
    // Baud rate is 1Mbps
    can_parameter.prescaler = 5;                        // Baud rate prescaler is 5

    can_init(CAN0, &can_parameter);
    can_init(CAN1, &can_parameter);

    // Enable the CAN Bus reception FIFO0 not empty interrupt
    can_interrupt_enable(CAN0, CAN_INT_RFNE0);
    can_interrupt_enable(CAN1, CAN_INT_RFNE0);
}

static inline void nvic_config() {
    nvic_irq_enable(CAN0_RX0_IRQn, 0, 0);
    nvic_irq_enable(CAN1_RX0_IRQn, 0, 0);
}

// Function to set up the timer peripheral to 
// count incremental encoder pulses (A and B channels)
static inline void incremental_encoder1_setup() {
    // Enable clock to timer 3
    rcu_periph_clock_enable(RCU_TIMER3);

    // Enable count
    timer_enable(TIMER3);
    // Set timer mode
    timer_quadrature_decoder_mode_config(TIMER3, TIMER_ENCODER_MODE2, TIMER_IC_POLARITY_RISING, TIMER_IC_POLARITY_RISING);
    // Set prescaler
    timer_prescaler_config(TIMER3, 0x0000, TIMER_PSC_RELOAD_NOW);
    // Set the autoreload value
    timer_auto_reload_shadow_enable(TIMER3);
    timer_autoreload_value_config(TIMER3, 0xFFFF);
    // Set the initial value to 0
    timer_counter_value_config(TIMER3, 0x0000);
}

static inline void incremental_encoder2_setup() {
    // Enable clock to timer 4
    rcu_periph_clock_enable(RCU_TIMER4);

    timer_deinit(TIMER4);

    // Enable count
    timer_enable(TIMER4);
    // Set timer mode
    timer_quadrature_decoder_mode_config(TIMER4, TIMER_ENCODER_MODE2, TIMER_IC_POLARITY_RISING, TIMER_IC_POLARITY_RISING);
    // Set prescaler
    timer_prescaler_config(TIMER4, 0x0000, TIMER_PSC_RELOAD_NOW);
    // Set the autoreload value
    timer_auto_reload_shadow_enable(TIMER4);
    timer_autoreload_value_config(TIMER4, 0xFFFF);
    // Set the initial value to 0
    timer_counter_value_config(TIMER4, 0x0000);
}

static inline void setup_usart() {
    // Enable the USART2 peripheral
    rcu_periph_clock_enable(RCU_USART2);

    // Set the baud rate to 500000
    usart_baudrate_set(USART2, 500000U);

    // Receive and transmit enable
    usart_deinit(USART2);
    usart_receive_config(USART2, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART2, USART_TRANSMIT_ENABLE);
    usart_enable(USART2);
}

// Function to set up all the peripherals on the board
void setup_peripherals() {
    // Set up the GPIO peripherals
    setup_gpio();

    // Set up the CAN peripheral
    setup_can();

    // Set up the incremental encoders
    incremental_encoder1_setup();
    incremental_encoder2_setup();

    // Set up the USART peripheral
    setup_usart();

    // Set up the NVIC
    nvic_config();
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART2, (uint8_t)ch);
    while(RESET == usart_flag_get(USART2, USART_FLAG_TBE));
    return ch;
}

void set_motor_current(unsigned int id, int16_t cmd) {
    // Create a new message for transmission
    can_trasnmit_message_struct transmit_message;
    int16_t cmd2send = 0;
    uint16_t cmd2sendu = 0;

    // Safety check the command
    if (cmd > 2000) {
        cmd2send = 2000;
    } else if (cmd < -2000) {
        cmd2send = -2000;
    } else {
        cmd2send = cmd; 
    }

    // Convert the command to an unsigned integer
    memcpy(&cmd2sendu, &cmd2send, 2);

    // Set the message ID
    transmit_message.tx_sfid = 0x140 + id;
    transmit_message.tx_efid = 0x00;

    // Set the message type
    transmit_message.tx_ff = CAN_FF_STANDARD; // Standard frame format
    transmit_message.tx_ft = CAN_FT_DATA;     // Data frame

    // Set the message length
    transmit_message.tx_dlen = 8;

    // Set the message data 
    // Current is in bytes 4 and 5 of the data
    transmit_message.tx_data[0] = 0xA1; // Command byte
    transmit_message.tx_data[1] = 0x00; 
    transmit_message.tx_data[2] = 0x00;
    transmit_message.tx_data[3] = 0x00;
    transmit_message.tx_data[4] = (cmd2sendu & 0xFF);
    transmit_message.tx_data[5] = ((cmd2sendu >> 8) & 0xFF);
    transmit_message.tx_data[6] = 0x00;
    transmit_message.tx_data[7] = 0x00;

    // Transmit the message
    uint8_t tx_mb = can_message_transmit(CAN0, &transmit_message);
}