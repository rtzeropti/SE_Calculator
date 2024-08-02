#ifndef SE_CAL_H
#define SE_CAL_H

#define STRUCT_TYPE_2D 0
#define STRUCT_TYPE_3D 1

#define CHECK_1 0x01
#define CHECK_2 0x02
#define CHECK_3 0x04
#define CHECK_4 0x08
#define CHECK_5 0x10
#define CHECK_6 0x20
#define CHECK_7 0x40
#define CHECK_8 0x80

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
    unsigned char array_1;
    unsigned char array_2;
    unsigned char array_3;
    unsigned char flag;
    unsigned char temp_array_1;
    unsigned char temp_array_2;
    unsigned char temp_array_3;
    unsigned char reserved:7;
    unsigned char type:1;
}obj_2D3D_t;

#endif
