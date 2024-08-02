#ifndef SE_CAL_H
#define SE_CAL_H

typedef enum
{
    CIRCLE      = 0x01, //Varry from 0 to 1
    TRIANGLE    = 0x03,
    SQUARE      = 0x04,
    ERROR2D     = 0x05
}obj_2D_type;

typedef enum
{
    CC          = 0x02,
    CT          = 0x04,
    CS          = 0x05,
    TT          = 0x06,
    TS          = 0x07,
    SS          = 0x08,
    ER          = 0x09
}obj_3D_type;

tydedef struct
{
    unsigned char array[3];
    unsigned char flag;
    unsigned char temp_array[3];
    unsigned char reserved:7;
    unsigned char type:1;
}obj_2D3D_t;

#endif
