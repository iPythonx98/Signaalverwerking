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
 0x76u, 0xF1u, 0x0Fu, 0x00u, /* Section(0)_A0, 0.249112606048584 */

 0xE8u, 0x1Du, 0xE0u, 0x00u, /* Section(0)_A1, -0.498174667358398 */

 0x76u, 0xF1u, 0x0Fu, 0x00u, /* Section(0)_A2, 0.249112606048584 */

 0x62u, 0x88u, 0x7Fu, 0x00u, /* Section(0)_B1, -1.99269914627075 */

 0x4Du, 0x74u, 0xC0u, 0x00u, /* Section(0)_B2, 0.992901563644409 */

 /* Coefficients of Section 1 */
 0xD9u, 0xC5u, 0x3Fu, 0x00u, /* Section(1)_A0, 3.98580265045166 */

 0x20u, 0x92u, 0x80u, 0x00u, /* Section(1)_A1, -7.96432495117188 */

 0xD9u, 0xC5u, 0x3Fu, 0x00u, /* Section(1)_A2, 3.98580265045166 */

 0xE0u, 0x6Du, 0x7Fu, 0x00u, /* Section(1)_B1, -1.99108123779297 */

 0x4Du, 0x74u, 0xC0u, 0x00u, /* Section(1)_B2, 0.992901563644409 */
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
 0x76u, 0xF1u, 0x0Fu, 0x00u, /* Section(0)_A0, 0.249112606048584 */

 0xE8u, 0x1Du, 0xE0u, 0x00u, /* Section(0)_A1, -0.498174667358398 */

 0x76u, 0xF1u, 0x0Fu, 0x00u, /* Section(0)_A2, 0.249112606048584 */

 0x62u, 0x88u, 0x7Fu, 0x00u, /* Section(0)_B1, -1.99269914627075 */

 0x4Du, 0x74u, 0xC0u, 0x00u, /* Section(0)_B2, 0.992901563644409 */

 /* Coefficients of Section 1 */
 0xD9u, 0xC5u, 0x3Fu, 0x00u, /* Section(1)_A0, 3.98580265045166 */

 0x20u, 0x92u, 0x80u, 0x00u, /* Section(1)_A1, -7.96432495117188 */

 0xD9u, 0xC5u, 0x3Fu, 0x00u, /* Section(1)_A2, 3.98580265045166 */

 0xE0u, 0x6Du, 0x7Fu, 0x00u, /* Section(1)_B1, -1.99108123779297 */

 0x4Du, 0x74u, 0xC0u, 0x00u, /* Section(1)_B2, 0.992901563644409 */
};

