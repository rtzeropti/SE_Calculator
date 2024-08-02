#include "SE_Cal.h"

static struct obj_2D3D_t inner = 
{
    .type = STRUCT_TYPE_2D,
    .array_1 = (unsigned char)CIRCLE,
    .array_2 = (unsigned char)TRIANGLE,
    .array_3 = (unsigned char)SQUARE,
    .flag = 0,
    .reserved = 0,
    .temp_array_1 = (unsigned char)CIRCLE,
    .temp_array_2 = (unsigned char)TRIANGLE,
    .temp_array_3 = (unsigned char)SQUARE,
};
static struct obj_2D3D_t outer = 
{
    .type = STRUCT_TYPE_3D,
    .array_1 = (unsigned char)CC,
    .array_2 = (unsigned char)TT,
    .array_3 = (unsigned char)SS,
    .flag = 0,
    .reserved = 0,
    .temp_array_1 = (unsigned char)CT,
    .temp_array_2 = (unsigned char)CS,
    .temp_array_3 = (unsigned char)TS,
};

static unsigned char check_array_valid(struct obj_2D3D_t *a);
static unsigned char check_array_valid(struct obj_2D3D_t *a)
{
    unsigned char check_id = 0x00U;
    unsigned char temp = 0;
    unsigned char cur_array = a->array_1;
    if(a->type == STRUCT_TYPE_2D)
    {
Check_2D_1_laber:
        temp = 0;
        if(cur_array == CIRCLE)
        {
            flag &= 0;
            check_id |= CHECK_1;
            if(check_id == (CHECK_1 | CHECK_2 | CHECK_3)
            {
                return SUCCESS;
            }
            temp = check_id;
        }
        else
        {
            flag |= CHECK_1;
            if(flag == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return FAIL;
            }
            temp = flag;
        }
        if(temp & CHECK_2)
        {
            goto Check_2D_3_laber;
        }
        else
        {
            goto Check_2D_2_laber;
        }
Check_2D_2_laber:
        temp = 0;
        if(cur_array == CIRCLE)
        {
            flag &= 0;
            check_id |= CHECK_2;
            if(check_id == (CHECK_1 | CHECK_2 | CHECK_3)
            {
                return SUCCESS;
            }
            temp = check_id;
        }
        else
        {
            flag |= CHECK_2;
            if(flag == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return FAIL;
            }
            temp = flag;
        }
        if(temp & CHECK_1)
        {
            goto Check_2D_3_laber;
        }
        else
        {
            goto Check_2D_1_laber;
        }
Check_2D_3_laber:
        temp = 0;
        if(cur_array == CIRCLE)
        {
            flag &= 0;
            check_id |= CHECK_3;
            temp = check_id;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3)
            {
                return SUCCESS;
            }
        }
        else
        {
            flag |= CHECK_3;
            temp = flag;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return FAIL;
            }
        }
        if(temp & CHECK_2)
        {
            goto Check_2D_1_laber;
        }
        else
        {
            goto Check_2D_2_laber;
        }
    }
    else if(a->type == STRUCT_TYPE_3D)
    {
        
    }
}
