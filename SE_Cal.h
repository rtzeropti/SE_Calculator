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

#define uc_CIRCLE       (unsigned char)CIRCLE
#define uc_TRIANGLE     (unsigned char)TRIANGLE
#define uc_SQUARE       (unsigned char)SQUARE
#define uc_ERROR2D      (unsigned char)ERROR2D

typedef enum
{
    CC          = 0x11,
    CT          = 0x13,
    CS          = 0x14,
    TT          = 0x33,
    TS          = 0x34,
    SS          = 0x44,
    TC          = 0x31,//This should be converted to CT
    SC          = 0x41,//This should be converted to CS
    ST          = 0x43,//This should be converted to TS
    ER3D        = 0x45
}obj_3D_type;

#define uc_CC           (unsigned char)CC
#define uc_CT           (unsigned char)CT
#define uc_CS           (unsigned char)CS
#define uc_TT           (unsigned char)TT
#define uc_TS           (unsigned char)TS
#define uc_SS           (unsigned char)SS
#define uc_TC           (unsigned char)TC
#define uc_SC           (unsigned char)SC
#define uc_ST           (unsigned char)ST
#define uc_ER3D         (unsigned char)ER3D

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
