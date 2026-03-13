/**
  **********************************************************************************************************************
  * @file    sequencer.h
  * @brief   sequencer interface
  **********************************************************************************************************************
  * @attention
  *
  * Copyright (c) 2019-2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  **********************************************************************************************************************
  */


/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#ifndef SEQUENCER_H
#define SEQUENCER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ----------------------------------------------------------------------------------------------------------*/
#ifdef SEQ_USER_CONFIG
#include "seq_user_conf.h"
#else
#include "cmsis_compiler.h"
#include <string.h>
#endif /* SEQ_USER_CONFIG */

/** @defgroup SEQUENCER Sequencer Utilities
  * @{
  */

/* Exported types ----------------------------------------------------------------------------------------------------*/
/** @defgroup SEQUENCER_EXPORTED_TYPES SEQUENCER Exported Types
  *  @{
  */
/**
  *  @brief  Bit mapping of the task.
  *
  *  This value is used to represent a list of tasks (each corresponds to a task).
  */
typedef uint32_t seq_bm_t;

/**
  *  @brief  List of the sequencer warning codes.
  *
  *  This value is used to indicate warning detected during the sequencer execution.
  */
typedef enum
{
  SEQ_WARNING_INVALIDTASKID,
} seq_warning_t;

/**
  * @brief  Sequencer Task_id definition.
  *
  * Bit mapped task ID definition on 32 bits.
  */
typedef enum
{
  SEQ_TASK_0     = (1U << 0U),
  SEQ_TASK_1     = (1U << 1U),
  SEQ_TASK_2     = (1U << 2U),
  SEQ_TASK_3     = (1U << 3U),
  SEQ_TASK_4     = (1U << 4U),
  SEQ_TASK_5     = (1U << 5U),
  SEQ_TASK_6     = (1U << 6U),
  SEQ_TASK_7     = (1U << 7U),
  SEQ_TASK_8     = (1U << 8U),
  SEQ_TASK_9     = (1U << 9U),
  SEQ_TASK_10    = (1U << 10U),
  SEQ_TASK_11    = (1U << 11U),
  SEQ_TASK_12    = (1U << 12U),
  SEQ_TASK_13    = (1U << 13U),
  SEQ_TASK_14    = (1U << 14U),
  SEQ_TASK_15    = (1U << 15U),
  SEQ_TASK_16    = (1U << 16U),
  SEQ_TASK_17    = (1U << 17U),
  SEQ_TASK_18    = (1U << 18U),
  SEQ_TASK_19    = (1U << 19U),
  SEQ_TASK_20    = (1U << 20U),
  SEQ_TASK_21    = (1U << 21U),
  SEQ_TASK_22    = (1U << 22U),
  SEQ_TASK_23    = (1U << 23U),
  SEQ_TASK_24    = (1U << 24U),
  SEQ_TASK_25    = (1U << 25U),
  SEQ_TASK_26    = (1U << 26U),
  SEQ_TASK_27    = (1U << 27U),
  SEQ_TASK_28    = (1U << 28U),
  SEQ_TASK_29    = (1U << 29U),
  SEQ_TASK_30    = (1U << 30U),
  SEQ_TASK_31    = (1U << 31U)
} seq_task_id_t;

/**
  * @}
 */

/* Exported constants ------------------------------------------------------------------------------------------------*/

/** @defgroup SEQUENCER_EXPORTED_CONSTANTS SEQUENCER Exported Constants
  *  @{
  */

/**
  * @brief Default number of tasks.
  *
  * Default value is 32 (maximum), can be reduced by redefining it in seq_user_conf.h.
  */
#ifndef SEQ_CONF_TASK_NBR
#define SEQ_CONF_TASK_NBR  (32U)
#endif /* SEQ_CONF_TASK_NBR */

/**
  * @brief Default value of priority levels.
  *
  * The default priority value is 2, can be redefined in seq_user_conf.h.
  */
#ifndef SEQ_CONF_PRIO_NBR
#define SEQ_CONF_PRIO_NBR  (2U)
#endif /* SEQ_CONF_PRIO_NBR */


/**
  * @brief Default value for unused parameter
  *
  * The default value for unused parameter is 0.
  */
#define SEQ_RFU (0U)

/**
  * @brief Default value used to start the scheduling.
  *
  * This informs the sequencer that all tasks registered must be considered
  *
  * @note
  * This is a typical use in the application\n
  * while(1)\n
  * {\n
  *    SEQ_Run(SEQ_DEFAULT);\n
  * }\n
  *
  */
#define SEQ_DEFAULT         (~0U)

/**
  * @}
 */

/* External variables ------------------------------------------------------------------------------------------------*/
/* Exported macros ---------------------------------------------------------------------------------------------------*/

/** @defgroup SEQUENCER_EXPORTED_MACROS SEQUENCER Exported Macros
  *  @{
  */


/**
  * @brief  Default macro for initializing the critical section.
  */
#ifndef SEQ_INIT_CRITICAL_SECTION
#define SEQ_INIT_CRITICAL_SECTION( )
#endif /* SEQ_INIT_CRITICAL_SECTION */

/**
  * @brief Default macro for entering the critical section.
  */
#ifndef SEQ_ENTER_CRITICAL_SECTION
#define SEQ_ENTER_CRITICAL_SECTION( )      uint32_t primask_bit = __get_PRIMASK( ); \
  __disable_irq( )
#endif /* SEQ_ENTER_CRITICAL_SECTION */

/**
  * @brief  Default macro for exiting a critical section.
  */
#ifndef SEQ_EXIT_CRITICAL_SECTION
#define SEQ_EXIT_CRITICAL_SECTION( )       __set_PRIMASK( primask_bit )
#endif /* SEQ_EXIT_CRITICAL_SECTION */

/**
  * @brief Default macro for calling memset to fill memory.
  */
#ifndef SEQ_MEMSET8
#define SEQ_MEMSET8(dest, value, size)     memset((dest),(value),(size));
#endif /* SEQ_MEMSET8 */

/**
  * @brief Default macro for entering the critical section before calling the IDLE function.
  *
  * @note  In a basic configuration must be identical to the macro
  *        SEQ_ENTER_CRITICAL_SECTION. The redefinition of this macro will allow
  *        to perform specific operation

  */
#ifndef SEQ_ENTER_CRITICAL_SECTION_IDLE
#define SEQ_ENTER_CRITICAL_SECTION_IDLE( )    SEQ_ENTER_CRITICAL_SECTION( )
#endif /* SEQ_ENTER_CRITICAL_SECTION_IDLE */

/**
  * @brief Default macro for exiting a critical section when exiting the IDLE function.
  *
  * @note  The behavior of the macro must be symmetrical with the macro
  *        SEQ_ENTER_CRITICAL_SECTION_IDLE
  */
#ifndef SEQ_EXIT_CRITICAL_SECTION_IDLE
#define SEQ_EXIT_CRITICAL_SECTION_IDLE( )     SEQ_EXIT_CRITICAL_SECTION( )
#endif /* SEQ_EXIT_CRITICAL_SECTION_IDLE */


/**
  * @brief  This macro can be used to define a task with one parameter.
  *
  * @note   This is an example of using this macro
  *
  *         task prototype definition
  *         void FUNCTION_NAME(void *Instance)
  *         {
  *             uint8_t _instance = *(uint8_t*) Instance;
  *         }
  *
  *         task declaration in the application for two instances
  *         const uint8_t instance1 = 1;
  *         const uint8_t instance2 = 2;
  *         SEQ_TASK_PARAM_DEF(FUNCTION_NAME, instance1)
  *         SEQ_TASK_PARAM_DEF(FUNCTION_NAME, instance2)
  *
  *         task initialization
  *         SEQ_RegTask(SEQ_TASK_1,  0, SEQ_TASK_FUNCTION(FUNCTION_NAME,instance1));
  *         SEQ_RegTask(SEQ_TASK_10, 0, SEQ_TASK_FUNCTION(FUNCTION_NAME,instance2));
  *
  *         Then no change on the management of the task within the application, the instance being managed within the
  *         overloaded function
  *
  */
#define SEQ_TASK_PARAM_DEF(_FUNC_,_INSTANCE_)        \
  static void SEQ_FUNC_##_FUNC_##_INSTANCE_(void);        \
  static void SEQ_FUNC_##_FUNC_##_INSTANCE_(void)         \
  {                                                       \
    static void *SEQ_PARAM_##_FUNC_ = (void*)&_INSTANCE_; \
    _FUNC_(SEQ_PARAM_##_FUNC_);                           \
  }

/**
  * @brief  This macro is used to retrieve the function name of the task
  *
  * Retrieve the function name of the task from two parameters: function and instance.
  */
#define SEQ_TASK_FUNCTION(_FUNC_,_INSTANCE_)  SEQ_FUNC_##_FUNC_##_INSTANCE_

/**
  * @}
 */

/* Exported functions ----------------------------------------------------------------------------------------------- */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS SEQUENCER Exported Functions
  *  @{
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G1 Initialization And DeInitialization Functions
  * @{
  */

void SEQ_Init(void);
void SEQ_DeInit(void);

/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G2 Idle Task Functions
  * @{
  */


void SEQ_Idle(void);
void SEQ_PreIdle(void);
void SEQ_PostIdle(void);
/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G3 Scheduler Functions
  * @{
 */

void SEQ_Run(seq_bm_t mask_bm);

/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G4 Task Creation Functions
  * @{
  */

void SEQ_RegTask(seq_task_id_t task_id_bm, uint32_t flags, void (*task)(void));
uint32_t SEQ_IsRegisteredTask(seq_task_id_t task_id_bm);

/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G5 Task Enable Functions
  * @{
 */

void SEQ_SetTask(seq_task_id_t task_id_bm, uint32_t task_prio);
uint32_t SEQ_IsSchedulableTask(seq_task_id_t task_id_bm);
/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G6 Task Pause/Resume Functions
  * @{
  */

void SEQ_PauseTask(seq_task_id_t task_id_bm);
uint32_t SEQ_IsPauseTask(seq_task_id_t task_id_bm);
void SEQ_ResumeTask(seq_task_id_t task_id_bm);

/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G7 Task Event Functions
  * @{
  */

void SEQ_SetEvt(seq_bm_t evt_id_bm);
void SEQ_ClrEvt(seq_bm_t evt_id_bm);
void SEQ_WaitEvt(seq_bm_t evt_id_bm);
seq_bm_t SEQ_IsEvtPend(void);
void SEQ_EvtIdle(seq_bm_t task_id_bm, seq_bm_t evt_waited_bm);

/**
  * @}
  */

/** @defgroup SEQUENCER_EXPORTED_FUNCTIONS_G8 Pre-Post Task Functions
  * @{
  */

void SEQ_PreTask(uint32_t task_id);
void SEQ_PostTask(uint32_t task_id);
void SEQ_CatchWarning(seq_warning_t warning_id);
/**
  * @}
  */

/**
  * @}
 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* SEQUENCER_H */
