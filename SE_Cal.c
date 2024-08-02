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

static void check_array_valid(struct obj_2D3D_t *a);
static void check_array_valid(struct obj_2D3D_t *a)
{
    if(a->type == STRUCT_TYPE_2D)
    {
        
    }
    else if(a->type == STRUCT_TYPE_3D)
    {
        
    }
}
