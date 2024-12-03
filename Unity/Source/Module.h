/*******************************************************************************
 * @file   Module.h
 * @brief  Module header file
 * @author Enrico Oliveira Rocheti
 ******************************************************************************/

#ifndef __MODULE_H
#define __MODULE_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Include
 ******************************************************************************/
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
 * Public Macros
 ******************************************************************************/
/*!
 * @name  Module macros group
 * @{
 */
#define MODULE_BUFFER_SIZE    (16U)
/** @} */

/*******************************************************************************
 * Public Types
 ******************************************************************************/
/*!
 * @struct  Module
 */
typedef struct ModuleType
{
    uint8_t Buffer[MODULE_BUFFER_SIZE];
    uint8_t IsInitialized;
} Module;

/*******************************************************************************
 * Public Variables
 ******************************************************************************/

/*******************************************************************************
 * Public Functions / API Specification
 ******************************************************************************/
/*!
 * @brief Initializes the module.
 *
 * @param module Pointer to module object.
 * 
 * @return Success (zero) or a specific error code.
 */
int32_t Module_Init(Module *module);

/**
 * @brief Sets a parameter in the module.
 * 
 * @param module Pointer to module object.
 * @param parame The index of the parameter to set.
 * @param value  The value of the parameter.
 * 
 * @return Success (zero) or a specific error code.
 */
int32_t Module_SetParameter(Module *module, uint8_t param, uint8_t value);

/**
 * @brief Get a parameter from the module.
 * 
 * @param module Pointer to module object.
 * @param parame The index of the parameter to read from.
 * @param value  Pointer to read value.
 * 
 * @return Success (zero) or a specific error code.
 */
int32_t Module_GetParameter(Module *module, uint8_t param, uint8_t *value);

/**
 * @brief Shuts down the module and releases resources.
 * 
 * @param module Pointer to module object.
 * 
 * @return Success (zero) or a specific error code.
 */
int32_t Module_Deinit(Module *module);

#ifdef __cplusplus
}
#endif

#endif /* __MODULE_H */