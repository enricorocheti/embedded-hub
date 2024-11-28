/*******************************************************************************
 * @file   Example.h
 * @brief  Doxygen header example file
 * @author Enrico Oliveira Rocheti
 ******************************************************************************/

#ifndef __EXAMPLE_H
#define __EXAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Include
 ******************************************************************************/

/*******************************************************************************
 * Public Macros
 ******************************************************************************/
/*!
 * @name  Public macros group
 * @brief Public macros used as an example
 * 
 * @{
 */
#define PUBLIC_MACRO_ONE    0x01	/**< Macro one value */
#define PUBLIC_MACRO_TWO    0x02    /**< Macro two value */
/** @} */

/*******************************************************************************
 * Public Types
 ******************************************************************************/
/*!
 * @struct  PublicStruct
 * @brief   Public structure used as an example
 */
typedef struct 
{
    uint32_t Counter;   /*!< Counter variable */
    bool FlagPressed;   /*!< Indicates if flag has been pressed */
} PublicStruct;

/*!
 * @enum   PublicEnum
 * @brief  Public enumeration used as an example
 */
typedef enum 
{
    StateOff = 0U,  /*!< Indicates state OFF        */
    StateOn  = 1U,  /*!< Indicates state ON         */
    StateLength,    /*!< Maximum size of this enum  */
} PublicEnum;

/*******************************************************************************
 * Public Variables
 ******************************************************************************/

/*******************************************************************************
 * Public Functions / API Specification
 ******************************************************************************/
/*!
 * @brief Public Function Example
 *
 * @param sourceBuffer  Example parameter 
 * @param destBuffer    Example parameter 
 * @param length        Example parameter 
 * 
 * @return Success (zero) or a specific error code
 */
Result Example_PublicFunction(uint8_t *sourceBuffer, uint8_t *destBuffer, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* __EXAMPLE_H */