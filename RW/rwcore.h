#pragma once

struct RwCamera {};
typedef struct RwRaster RwRaster;
struct RwRaster
{
    RwRaster           *parent; /* Top level raster if a sub raster */
    RwUInt8            *cpPixels; /* Pixel pointer when locked */
    RwUInt8            *palette; /* Raster palette */
    RwInt32             width, height, depth; /* Dimensions of raster */
    RwInt32             stride; /* Lines bytes of raster */
    RwInt16             nOffsetX, nOffsetY; /* Sub raster offset */
    RwUInt8             cType;  /* Type of raster */
    RwUInt8             cFlags; /* Raster flags */
    RwUInt8             privateFlags; /* Raster private flags */
    RwUInt8             cFormat; /* Raster format */

    RwUInt8            *originalPixels;
    RwInt32             originalWidth;
    RwInt32             originalHeight;
    RwInt32             originalStride;
};
typedef struct RwImage RwImage;
struct RwImage
{
        RwInt32             flags;
        RwInt32             width;
        RwInt32             height;
        RwInt32             depth;
        RwInt32             stride;
        RwUInt8            *cpPixels;
        RwRGBA             *palette;
};

extern RwRaster* (*RwRasterCreate)(RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags);
extern RwBool (*RwRasterDestroy)(RwRaster* raster);
extern RwRaster* (*RwRasterRender)(RwRaster* raster, RwInt32 x, RwInt32 y);
extern RwRaster* (*RwRasterUnlock)(RwRaster* raster);
extern RwRaster* (*RwRasterGetCurrentContext)(void);
extern RwRaster* (*RwRasterGetOffset)(RwRaster *raster, RwInt16 *xOffset, RwInt16 *yOffset);
extern RwInt32 (*RwRasterGetNumLevels)(RwRaster* raster);
extern RwImage* (*RwImageAllocatePixels)(RwImage * image);
extern RwRaster* (*RwRasterRenderScaled)(RwRaster* raster, RwRect* rect);
extern RwRaster* (*RwRasterSubRaster)(RwRaster* subRaster, RwRaster* raster, RwRect * rect);
extern RwRaster* (*RwRasterRenderFast)(RwRaster* raster, RwInt32 x,RwInt32 y);
extern RwBool (*RwRasterClear)(RwInt32 pixelValue);
extern RwBool (*RwRasterClearRect)(RwRect* rpRect, RwInt32 pixelValue);
extern RwImage* (*RwImageCreate)(RwInt32 width, RwInt32 height, RwInt32 depth);
extern RwBool (*RwImageDestroy)(RwImage * image);
extern RwRaster* (*RwRasterShowRaster)(RwRaster* raster, void *dev, RwUInt32 flags);
extern RwUInt8* (*RwRasterLockPalette)(RwRaster* raster, RwInt32 lockMode);
extern RwRaster* (*RwRasterUnlockPalette)(RwRaster* raster);
extern RwRaster* (*RwRasterPushContext)(RwRaster* raster);
extern RwRaster* (*RwRasterPopContext)(void);
extern RwUInt8* (*RwRasterLock)(RwRaster* raster, RwUInt8 level, RwInt32 lockMode);
extern RwRaster* (*RwRasterSetFromImage)(RwRaster *raster, RwImage *image);
extern RwImage* (*RwImageFindRasterFormat)(RwImage *ipImage,RwInt32 nRasterType, RwInt32 *npWidth,RwInt32 *npHeight, RwInt32 *npDepth,RwInt32 *npFormat);
extern RwImage* (*RwImageSetFromRaster)(RwImage *image, RwRaster *raster);