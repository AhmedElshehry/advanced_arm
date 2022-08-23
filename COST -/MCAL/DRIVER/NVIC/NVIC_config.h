/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  NVIC                                                    */
/*  version    :  V01                                                 */
/*  DATA       : 16/8/2022                                            */
/**************************************************************************/

#ifndef   NVIC_CONFIG_H 
#define   NVIC_CONFIG_H
/*number of GROUP PRIORITY  AND SUB PRIORITY for bit         //number  probability of group and sub group can access
 optain that: x the bit number of group , y  the bit number of sub group
                 GROUP_x_SUB_y                               the number of group and sub group piority 
                 GROUP_3_SUB_0                                number group     number sub piority
              1- GROUP_3_SUB_0                               1-  GROUP = 8     , SUB = 1
              2- GROUP_2_SUB_1                               2-  GROUP = 4     , SUB = 2
              3- GROUP_1_SUB_2                               3-  GROUP = 2     , SUB = 4
              4- GROUP_1_SUB_3                               4-  GROUP = 1     , SUB = 8
                                                                                               */

#define    NUMBER_OF_GROUP_SUB      GROUP_2_SUB_2





#endif 
