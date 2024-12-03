/*******************************************************************************
 * @file   Module.c
 * @brief  Module source file
 * @author Enrico Oliveira Rocheti
 ******************************************************************************/

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "Module.h"

/*******************************************************************************
 * Private Macros
 ******************************************************************************/

/*******************************************************************************
 * Private Types
 ******************************************************************************/

/*******************************************************************************
 * Private Variables
 ******************************************************************************/

/*******************************************************************************
 * Private Functions
 ******************************************************************************/

/*******************************************************************************
 * Public Functions / API Specification
 ******************************************************************************/
/*!
 * @note See full documentation in module's header file
 */

int32_t Module_Init(Module *module)
{
    if(module == NULL)
    {
        return -1;
    }

    module->IsInitialized = 1;

    return 0;
}

/*!
 * @note See full documentation in module's header file
 */
int32_t Module_SetParameter(Module *module, uint8_t param, uint8_t value)
{
    if(module == NULL || module->IsInitialized == 0 || param >= MODULE_BUFFER_SIZE)
    {
        return -1;
    }

    module->Buffer[param] = value;

    return 0;
}

/*!
 * @note See full documentation in module's header file
 */
int32_t Module_GetParameter(Module *module, uint8_t param, uint8_t *value)
{
    if(module == NULL || module->IsInitialized == 0 || param >= MODULE_BUFFER_SIZE)
    {
        return -1;
    }

    *value = module->Buffer[param];

    return 0;
}

/*!
 * @note See full documentation in module's header file
 */
int32_t Module_Deinit(Module *module)
{
    if(module == NULL)
    {
        return -1;
    }

    module->IsInitialized = 0;

    return 0;
}
