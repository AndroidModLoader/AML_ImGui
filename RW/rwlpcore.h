#pragma once

#define RwIm2DVertexSetRecipCameraZ(vert, recipz)   ((vert)->rhw = recipz)
#define RwIm2DVertexSetScreenX(vert, scrnx)         ((vert)->x = (scrnx))
#define RwIm2DVertexSetScreenY(vert, scrny)         ((vert)->y = (scrny))
#define RwIm2DVertexSetScreenZ(vert, scrnz)         ((vert)->z = (scrnz))
#define RwIm2DVertexSetU(vert, texU, recipz)        ((vert)->u = (texU))
#define RwIm2DVertexSetV(vert, texV, recipz)        ((vert)->v = (texV))

typedef long RwFixed;
typedef int  RwInt32;
typedef unsigned int RwUInt32;
typedef short RwInt16;
typedef unsigned short RwUInt16;
typedef unsigned char RwUInt8;
typedef signed char RwInt8;
typedef char RwChar;
typedef float RwReal;
typedef RwInt32 RwBool;



typedef struct RwV2d RwV2d;
struct RwV2d
{
    RwReal x;
    RwReal y;
};
typedef struct RwV3d RwV3d;
struct RwV3d
{
    union
    {
        struct
        {
            RwReal x;
            RwReal y;
        };
        RwV2d vec2D;
    };
    RwReal z;
};

typedef struct RwRect RwRect;
struct RwRect
{
    RwInt32 x;
    RwInt32 y;
    RwInt32 w;
    RwInt32 h;
};

enum RwRenderState
{
    rwRENDERSTATENARENDERSTATE = 0,
    rwRENDERSTATETEXTURERASTER = 1,
    rwRENDERSTATETEXTUREADDRESS = 2,
    rwRENDERSTATETEXTUREADDRESSU = 3,
    rwRENDERSTATETEXTUREADDRESSV = 4,
    rwRENDERSTATETEXTUREPERSPECTIVE = 5,
    rwRENDERSTATEZTESTENABLE = 6,
    rwRENDERSTATESHADEMODE = 7,
    rwRENDERSTATEZWRITEENABLE = 8,
    rwRENDERSTATETEXTUREFILTER = 9,
    rwRENDERSTATESRCBLEND = 10,
    rwRENDERSTATEDESTBLEND = 11,
    rwRENDERSTATEVERTEXALPHAENABLE = 12,
    rwRENDERSTATEBORDERCOLOR = 13,
    rwRENDERSTATEFOGENABLE = 14,
    rwRENDERSTATEFOGCOLOR = 15,
    rwRENDERSTATEFOGTYPE = 16,
    rwRENDERSTATEFOGDENSITY = 17,
    rwRENDERSTATECULLMODE = 20,
    rwRENDERSTATESTENCILENABLE,
    rwRENDERSTATESTENCILFAIL,
    rwRENDERSTATESTENCILZFAIL,
    rwRENDERSTATESTENCILPASS,
    rwRENDERSTATESTENCILFUNCTION,
    rwRENDERSTATESTENCILFUNCTIONREF,
    rwRENDERSTATESTENCILFUNCTIONMASK,
    rwRENDERSTATESTENCILFUNCTIONWRITEMASK,
    rwRENDERSTATEALPHATESTFUNCTION,
    rwRENDERSTATEALPHATESTFUNCTIONREF
};
typedef enum RwRenderState RwRenderState;

enum RwPrimitiveType
{
    rwPRIMTYPENAPRIMTYPE = 0,
    rwPRIMTYPELINELIST = 1,
    rwPRIMTYPEPOLYLINE = 2,
    rwPRIMTYPETRILIST = 3,
    rwPRIMTYPETRISTRIP = 4,
    rwPRIMTYPETRIFAN = 5 ,
    rwPRIMTYPEPOINTLIST = 6,
};
typedef enum RwPrimitiveType RwPrimitiveType;


struct RwD3D9Vertex
{
    RwReal      x;            
    RwReal      y;            
    RwReal      z;            
    RwReal      rhw;          

    RwUInt32    emissiveColor;

    RwReal      u;            
    RwReal      v;            
};
typedef RwD3D9Vertex    RwIm2DVertex;
typedef RwUInt32        RxVertexIndex;
typedef RxVertexIndex   RwImVertexIndex;

extern RwReal (*RwIm2DGetNearScreenZ)(void);
extern RwReal (*RwIm2DGetFarScreenZ)(void);
extern RwBool (*RwRenderStateGet)(RwRenderState state, void *value);
extern RwBool (*RwRenderStateSet)(RwRenderState state, void *value);
extern RwBool (*RwIm2DRenderLine)(RwIm2DVertex *vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2);
extern RwBool (*RwIm2DRenderTriangle)(RwIm2DVertex *vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2, RwInt32 vert3 );
extern RwBool (*RwIm2DRenderPrimitive)(RwPrimitiveType primType, RwIm2DVertex *vertices, RwInt32 numVertices);
extern RwBool (*RwIm2DRenderIndexedPrimitive)(RwPrimitiveType primType, RwIm2DVertex *vertices, RwInt32 numVertices, RwImVertexIndex *indices, RwInt32 numIndices);

typedef struct RwRGBAReal RwRGBAReal;
struct RwRGBAReal
{
    RwReal red;
    RwReal green;
    RwReal blue;
    RwReal alpha;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    RwUInt8 red;
    RwUInt8 green;
    RwUInt8 blue;
    RwUInt8 alpha;
};