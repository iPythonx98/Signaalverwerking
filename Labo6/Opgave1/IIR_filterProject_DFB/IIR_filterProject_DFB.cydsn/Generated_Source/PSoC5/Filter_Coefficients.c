#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_ChannelABiquadCoefficients

/* Number of Biquad sections are: 2 */

const uint8 CYCODE Filter_ChannelABiquadCoefficients[Filter_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xBAu, 0x34u, 0x00u, 0x00u, /* Section(0)_A0, 0.00321817398071289 */

 0x75u, 0x69u, 0x00u, 0x00u, /* Section(0)_A1, 0.00643658638000488 */

 0xBAu, 0x34u, 0x00u, 0x00u, /* Section(0)_A2, 0.00321817398071289 */

 0x4Bu, 0xE8u, 0x6Eu, 0x00u, /* Section(0)_B1, -1.73292803764343 */

 0xB0u, 0x6Eu, 0xCCu, 0x00u, /* Section(0)_B2, 0.805744171142578 */

 /* Coefficients of Section 1 */
 0x55u, 0xCBu, 0x05u, 0x00u, /* Section(1)_A0, 0.0905354022979736 */

 0xABu, 0x96u, 0x0Bu, 0x00u, /* Section(1)_A1, 0.181071043014526 */

 0x55u, 0xCBu, 0x05u, 0x00u, /* Section(1)_A2, 0.0905354022979736 */

 0x57u, 0x83u, 0x61u, 0x00u, /* Section(1)_B1, -1.52364134788513 */

 0xB9u, 0x63u, 0xDAu, 0x00u, /* Section(1)_B2, 0.587663412094116 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBBiquadCoefficients Filter_ChannelBBiquadCoefficients

/* Number of Biquad sections are: 2 */

const uint8 CYCODE Filter_ChannelBBiquadCoefficients[Filter_BIQUAD_B_SIZE] = 
{
 /* Coefficients of Section 0 */
 0xBAu, 0x34u, 0x00u, 0x00u, /* Section(0)_A0, 0.00321817398071289 */

 0x75u, 0x69u, 0x00u, 0x00u, /* Section(0)_A1, 0.00643658638000488 */

 0xBAu, 0x34u, 0x00u, 0x00u, /* Section(0)_A2, 0.00321817398071289 */

 0x4Bu, 0xE8u, 0x6Eu, 0x00u, /* Section(0)_B1, -1.73292803764343 */

 0xB0u, 0x6Eu, 0xCCu, 0x00u, /* Section(0)_B2, 0.805744171142578 */

 /* Coefficients of Section 1 */
 0x55u, 0xCBu, 0x05u, 0x00u, /* Section(1)_A0, 0.0905354022979736 */

 0xABu, 0x96u, 0x0Bu, 0x00u, /* Section(1)_A1, 0.181071043014526 */

 0x55u, 0xCBu, 0x05u, 0x00u, /* Section(1)_A2, 0.0905354022979736 */

 0x57u, 0x83u, 0x61u, 0x00u, /* Section(1)_B1, -1.52364134788513 */

 0xB9u, 0x63u, 0xDAu, 0x00u, /* Section(1)_B2, 0.587663412094116 */
};

