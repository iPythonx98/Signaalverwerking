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
 0x8Eu, 0xA4u, 0x00u, 0x00u, /* Section(0)_A0, 0.0100436210632324 */

 0xE4u, 0xB6u, 0xFEu, 0x00u, /* Section(0)_A1, -0.0200872421264648 */

 0x8Eu, 0xA4u, 0x00u, 0x00u, /* Section(0)_A2, 0.0100436210632324 */

 0x0Fu, 0x31u, 0x7Fu, 0x00u, /* Section(0)_B1, -1.98736929893494 */

 0x78u, 0x2Eu, 0xC0u, 0x00u, /* Section(0)_B2, 0.997163772583008 */

 /* Coefficients of Section 1 */
 0x34u, 0x06u, 0x00u, 0x00u, /* Section(1)_A0, 0.000378608703613281 */

 0x69u, 0x0Cu, 0x00u, 0x00u, /* Section(1)_A1, 0.000757455825805664 */

 0x34u, 0x06u, 0x00u, 0x00u, /* Section(1)_A2, 0.000378608703613281 */

 0xAAu, 0x29u, 0x7Fu, 0x00u, /* Section(1)_B1, -1.9869179725647 */

 0x6Bu, 0x34u, 0xC0u, 0x00u, /* Section(1)_B2, 0.996800661087036 */
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
 0xACu, 0x00u, 0x00u, 0x00u, /* Section(0)_A0, 4.10079956054688E-05 */

 0x58u, 0x01u, 0x00u, 0x00u, /* Section(0)_A1, 8.20159912109375E-05 */

 0xACu, 0x00u, 0x00u, 0x00u, /* Section(0)_A2, 4.10079956054688E-05 */

 0x0Eu, 0x11u, 0x7Du, 0x00u, /* Section(0)_B1, -1.95416593551636 */

 0x7Eu, 0x10u, 0xC0u, 0x00u, /* Section(0)_B2, 0.998993396759033 */

 /* Coefficients of Section 1 */
 0x1Cu, 0x23u, 0x05u, 0x00u, /* Section(1)_A0, 0.0802679061889648 */

 0xC8u, 0xB9u, 0xF5u, 0x00u, /* Section(1)_A1, -0.16053581237793 */

 0x1Cu, 0x23u, 0x05u, 0x00u, /* Section(1)_A2, 0.0802679061889648 */

 0xF0u, 0x28u, 0x7Du, 0x00u, /* Section(1)_B1, -1.95562362670898 */

 0x81u, 0x10u, 0xC0u, 0x00u, /* Section(1)_B2, 0.998992681503296 */
};

