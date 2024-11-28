/*******************************************************************************
 * @file   Example.c
 * @brief  Doxygen source example file
 * @author Enrico Oliveira Rocheti
 ******************************************************************************/

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "Example.h"

/*******************************************************************************
 * Private Macros
 ******************************************************************************/
/*!
 * @name  Private macros group
 * @brief Private macros used as an example
 * 
 * @{
 */
#define PRIVATE_MACRO_ONE    0x01	/**< Macro one value */
#define PRIVATE_MACRO_TWO    0x02   /**< Macro two value */
/** @} */

/*******************************************************************************
 * Private Types
 ******************************************************************************/

/*******************************************************************************
 * Private Variables
 ******************************************************************************/
/*!
 * @brief Local variable example
 */
static uint8_t mParam;

/*******************************************************************************
 * Private Functions
 ******************************************************************************/
/*!
 * @brief Private Function Example
 *
 * @param param Example parameter 
 * 
 * @return Success (zero) or a specific error code 
 * @private
 */
static uint32_t privateFunctionExample(uint8_t param) 
{
    return 0;
}

/*******************************************************************************
 * Public Functions / API Specification
 ******************************************************************************/
/*!
 * @note See full documentation in module's header file
 */
uint32_t Example_PublicFunction(uint8_t *sourceBuffer, uint8_t *destBuffer, uint16_t length) 
{
    return 0;
}
