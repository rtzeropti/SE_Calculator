#include "SE_Cal.h"

static obj_2D3D_t inner = 
{
    .type = STRUCT_TYPE_2D,
    .array_1 = uc_CIRCLE,
    .array_2 = uc_TRIANGLE,
    .array_3 = uc_SQUARE,
    .flag = 0,
    .reserved = 0,
    .temp_array_1 = uc_CIRCLE,
    .temp_array_2 = uc_TRIANGLE,
    .temp_array_3 = uc_SQUARE,
};
static obj_2D3D_t outer = 
{
    .type = STRUCT_TYPE_3D,
    .array_1 = uc_CC,
    .array_2 = uc_TT,
    .array_3 = uc_SS,
    .flag = 0,
    .reserved = 0,
    .temp_array_1 = uc_CT,
    .temp_array_2 = uc_CS,
    .temp_array_3 = uc_TS,
};

static unsigned char check_array_valid(obj_2D3D_t *a);
static void change_normal_valid(unsigned char *a);

static unsigned char check_array_valid(obj_2D3D_t *a)
{
    unsigned char check_id = 0x00U;
    unsigned char temp = 0;
    unsigned char *cur_array = &(a->array_1);
    if(a->type == STRUCT_TYPE_2D)
    {
#if defined COMPLEX_CHECK_2D
Check_2D_same:
        if(a->array_1 == a->array_2 || a->array_1 == a->array_3)
        {
            return (FAIL | (0x1));
        }
        else if(a->array_2 == a->array_3)
        {
            return (FAIL | (0x2));
        }
Check_2D_1_laber:
        temp = 0;
        if(*cur_array == uc_CIRCLE)
        {
            a->flag &= 0;
            check_id |= CHECK_1;
            temp = check_id;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return SUCCESS;
            }
            else if(temp & CHECK_2)
            {
                cur_array = &(a->array_3);
            }
            else
            {
                cur_array = &(a->array_2);
            }
        }
        else
        {
            a->flag |= CHECK_1;
            temp = a->flag;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return FAIL;
            }
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
        if(*cur_array == uc_TRIANGLE)
        {
            a->flag &= 0;
            check_id |= CHECK_2;
            temp = check_id;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return SUCCESS;
            }
            else if(temp & CHECK_1)
            {
                cur_array = &(a->array_3);
            }
            else
            {
                cur_array = &(a->array_1);
            }
        }
        else
        {
            a->flag |= CHECK_2;
            temp = a->flag;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return FAIL;
            }
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
        if(*cur_array == uc_SQUARE)
        {
            a->flag &= 0;
            check_id |= CHECK_3;
            temp = check_id;
            if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
            {
                return SUCCESS;
            }
            else if(temp & CHECK_2)
            {
                cur_array = &(a->array_1);
            }
            else
            {
                cur_array = &(a->array_2);
            }
        }
        else
        {
            a->flag |= CHECK_3;
            temp = a->flag;
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
#elif defined EACH_COMPARE
        unsigned char i = 0;
        for(i = 0 ; i < 3 ; i++)
        {
            if(*cur_array == uc_CIRCLE)
            {
                if(temp & CHECK_1)
                {
                    goto Return_fail_laber;
                }
                else
                {
                    temp |= CHECK_1;
                }
            }
            else if(*cur_array == uc_TRIANGLE)
            {
                if(temp & CHECK_2)
                {
                    goto Return_fail_laber;
                }
                else
                {
                    temp |= CHECK_2;
                }
            }
            else if(*cur_array == uc_SQUARE)
            {
                if(temp & CHECK_3)
                {
                    goto Return_fail_laber;
                }
                else
                {
                    temp |= CHECK_3;
                }
            }
            else
            {
                goto Return_fail_laber;
            }
        }
        if(temp == (CHECK_1 | CHECK_2 | CHECK_3))
        {
            return SUCCESS;
        }
Return_fail_laber:
        return (FAIL | (cur_array - &(a->array_1) + 1));
#else
        a->temp_array_1 = a->array_1;
        a->temp_array_2 = a->array_2;
        a->temp_array_3 = a->array_3;
        sort_3_low_to_high2(a->temp_array_1,a->temp_array_2,a->temp_array_3);
        if( a->temp_array_1!=uc_CIRCLE || a->temp_array_2!=uc_TRIANGLE ||  a->temp_array_3!=uc_SQUARE )
        {
            return FAIL;
        }
        else
        {
            return SUCCESS;
        }
#endif
    }
    else if(a->type == STRUCT_TYPE_3D)
    {
        change_normal_valid(&(a->array_1));
        change_normal_valid(&(a->array_2));
        change_normal_valid(&(a->array_3));
        change_normal_valid(&(cur_array));
#if defined COMPLEX_CHECK_3D
Check_3D_1_laber:
        temp = 0;
        if()
#else
        a->temp_array_1 = a->array_1;
        a->temp_array_2 = a->array_2;
        a->temp_array_3 = a->array_3;
        sort_3_low_to_high2(a->temp_array_1,a->temp_array_2,a->temp_array_3);
Sum_check:
        temp = a->temp_array_1 + a->temp_array_2 + a->temp_array_3;
        switch(temp)
        {
            case 0x88:
                if(a->temp_array_1 == CC && a->temp_array_2 == TT && a->temp_array_3 == SS)
                {
                    temp = SUCCESS;
                }
                else
                {
                    temp = FAIL;
                }
                break;
            case 0x79:
                if(a->temp_array_1 == CC && a->temp_array_2 == TS && a->temp_array_3 == TS)
                {
                    temp = SUCCESS;
                }
                else
                {
                    temp = FAIL;
                }
                break;
            case 0x6A:
                if(a->temp_array_1 == CT && a->temp_array_2 == CT && a->temp_array_3 == SS)
                {
                    temp = SUCCESS;
                }
                else
                {
                    temp = FAIL;
                }
                break;
            case 0x5B:
                if( (a->temp_array_1 == CS && a->temp_array_2 == CS && a->temp_array_3 == TT) || \
                    (a->temp_array_1 == CT && a->temp_array_2 == CS && a->temp_array_3 == TS) )
                {
                    temp = SUCCESS;
                }
                else
                {
                    temp = FAIL;
                }
                break;
            default:
                temp = FAIL;
                break;
        }
        return temp;
#endif
    }
}

static void change_normal_valid(unsigned char *a)
{
    if(*a == uc_TC)
    {
        *a = uc_CT;
    }
    if(*a == uc_SC)
    {
        *a = uc_CS;
    }
    if(*a == uc_ST)
    {
        *a = uc_TS;
    }
}

void swap_a_b(unsigned char *a,unsigned char *b)
{
    (*a) ^= (*b);
    (*b) ^= (*a);
    (*a) ^= (*b);
}

unsigned char obj_2D3D_init(obj_2D3D_t *a, unsigned char a1, unsigned char a2, unsigned char a3, unsigned char type)
{
    a->array_1 = a1;
    a->array_1 = a2;
    a->array_1 = a3;
    a->type = type;
    return check_array_valid(a);
}
