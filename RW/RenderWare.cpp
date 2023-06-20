#include "mod/amlmod.h"
#include "mod/logger.h"
#include "main.h"
#include "RenderWare.h"

#define ASSIGN_TO(__first, __second)	*(void**)(&__first) = (void*)aml->GetSym(pGameHandle, #__second);



RsGlobalType* RsGlobal;

/* rwcore.h */
RwCamera*   (*RwCameraBeginUpdate)(RwCamera* camera);
RwCamera*   (*RwCameraEndUpdate)(RwCamera* camera);
RwCamera*   (*RwCameraShowRaster)(RwCamera * camera, void *pDev, RwUInt32 flags);

RwRaster* 	(*RwRasterCreate)(RwInt32 width, RwInt32 height, RwInt32 depth, RwInt32 flags);
RwBool 		(*RwRasterDestroy)(RwRaster * raster);
RwRaster* 	(*RwRasterGetOffset)(RwRaster *raster, RwInt16 *xOffset, RwInt16 *yOffset);
RwInt32 	(*RwRasterGetNumLevels)(RwRaster * raster);
RwRaster* 	(*RwRasterSubRaster)(RwRaster * subRaster, RwRaster * raster, RwRect * rect);
RwRaster* 	(*RwRasterRenderFast)(RwRaster * raster, RwInt32 x, RwInt32 y);
RwRaster* 	(*RwRasterRender)(RwRaster * raster, RwInt32 x, RwInt32 y);
RwRaster* 	(*RwRasterRenderScaled)(RwRaster * raster, RwRect * rect);
RwRaster* 	(*RwRasterPushContext)(RwRaster * raster);
RwRaster* 	(*RwRasterPopContext)(void);
RwRaster* 	(*RwRasterGetCurrentContext)(void);
RwBool 		(*RwRasterClear)(RwInt32 pixelValue);
RwBool 		(*RwRasterClearRect)(RwRect * rpRect, RwInt32 pixelValue);
RwRaster* 	(*RwRasterShowRaster)(RwRaster * raster, void *dev, RwUInt32 flags);
RwUInt8* 	(*RwRasterLock)(RwRaster * raster, RwUInt8 level, RwInt32 lockMode);
RwRaster* 	(*RwRasterUnlock)(RwRaster * raster);
RwUInt8* 	(*RwRasterLockPalette)(RwRaster * raster, RwInt32 lockMode);
RwRaster* 	(*RwRasterUnlockPalette)(RwRaster * raster);
RwImage* 	(*RwImageCreate)(RwInt32 width, RwInt32 height, RwInt32 depth);
RwBool 		(*RwImageDestroy)(RwImage * image);
RwImage* 	(*RwImageAllocatePixels)(RwImage * image);
RwImage* 	(*RwImageFreePixels)(RwImage * image);
RwImage* 	(*RwImageCopy)(RwImage * destImage, const RwImage * sourceImage);
RwImage* 	(*RwImageResize)(RwImage * image, RwInt32 width, RwInt32 height);
RwImage* 	(*RwImageApplyMask)(RwImage * image, const RwImage * mask);
RwImage* 	(*RwImageMakeMask)(RwImage * image);
RwImage* 	(*RwImageReadMaskedImage)(const RwChar * imageName, const RwChar * maskname);
RwImage* 	(*RwImageRead)(const RwChar * imageName);
RwImage* 	(*RwImageWrite)(RwImage * image, const RwChar * imageName);
RwImage* 	(*RwImageSetFromRaster)(RwImage *image, RwRaster *raster);
RwRaster* 	(*RwRasterSetFromImage)(RwRaster *raster, RwImage *image);
RwRaster* 	(*RwRasterRead)(const RwChar *filename);
RwRaster* 	(*RwRasterReadMaskedRaster)(const RwChar *filename, const RwChar *maskname);
RwImage* 	(*RwImageFindRasterFormat)(RwImage *ipImage, RwInt32 nRasterType, RwInt32 *npWidth, RwInt32 *npHeight, RwInt32 *npDepth,RwInt32 *npFormat);

/* rwlpcore.h */
RwReal 		(*RwIm2DGetNearScreenZ)(void);
RwReal 		(*RwIm2DGetFarScreenZ)(void);
RwBool 		(*RwRenderStateGet)(RwRenderState state, void *value);
RwBool 		(*RwRenderStateSet)(RwRenderState state, void *value);
RwBool 		(*RwIm2DRenderLine)(RwIm2DVertex *vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2);
RwBool 		(*RwIm2DRenderTriangle)(RwIm2DVertex *vertices, RwInt32 numVertices, RwInt32 vert1, RwInt32 vert2, RwInt32 vert3 );
RwBool 		(*RwIm2DRenderPrimitive)(RwPrimitiveType primType, RwIm2DVertex *vertices, RwInt32 numVertices);
RwBool 		(*RwIm2DRenderIndexedPrimitive)(RwPrimitiveType primType, RwIm2DVertex *vertices, RwInt32 numVertices, RwImVertexIndex *indices, RwInt32 numIndices);

/* rtpng.h */
RwImage*	(*RtPNGImageWrite)(RwImage* image, const RwChar* imageName);
RwImage* 	(*RtPNGImageRead)(const RwChar* imageName);

void InitRenderWareFunctions()
{
	logger->Info("Initializing RenderWare...");

	/* skeleton.h */
	RsGlobal = (RsGlobalType*)aml->GetSym(pGameHandle, "RsGlobal");

	/* rwCore.h */
	ASSIGN_TO(RwCameraBeginUpdate, 				_Z19RwCameraBeginUpdateP8RwCamera);
	ASSIGN_TO(RwCameraEndUpdate, 				_Z17RwCameraEndUpdateP8RwCamera);
	ASSIGN_TO(RwCameraShowRaster, 				_Z18RwCameraShowRasterP8RwCameraPvj);

	ASSIGN_TO(RwRasterCreate, 					_Z14RwRasterCreateiiii);
	ASSIGN_TO(RwRasterDestroy, 					_Z15RwRasterDestroyP8RwRaster);
	ASSIGN_TO(RwRasterGetOffset, 				_Z17RwRasterGetOffsetP8RwRasterPsS1_);
	ASSIGN_TO(RwRasterGetNumLevels, 			_Z20RwRasterGetNumLevelsP8RwRaster);
	ASSIGN_TO(RwRasterSubRaster, 				_Z17RwRasterSubRasterP8RwRasterS0_P6RwRect);
	ASSIGN_TO(RwRasterRenderFast, 				_Z18RwRasterRenderFastP8RwRasterii);
	ASSIGN_TO(RwRasterRender, 					_Z14RwRasterRenderP8RwRasterii);
	ASSIGN_TO(RwRasterRenderScaled, 			_Z20RwRasterRenderScaledP8RwRasterP6RwRect);
	ASSIGN_TO(RwRasterPushContext, 				_Z19RwRasterPushContextP8RwRaster);
	ASSIGN_TO(RwRasterPopContext, 				_Z18RwRasterPopContextv);
	ASSIGN_TO(RwRasterGetCurrentContext, 		_Z25RwRasterGetCurrentContextv);
	ASSIGN_TO(RwRasterClear, 					_Z13RwRasterCleari);
	ASSIGN_TO(RwRasterClearRect, 				_Z17RwRasterClearRectP6RwRecti);
	ASSIGN_TO(RwRasterShowRaster, 				_Z18RwRasterShowRasterP8RwRasterPvj);
	ASSIGN_TO(RwRasterLock, 					_Z14_rwRasterClosePvii);
	ASSIGN_TO(RwRasterUnlock, 					_Z14RwRasterUnlockP8RwRaster);
	ASSIGN_TO(RwRasterLockPalette, 				_Z19RwRasterLockPaletteP8RwRasteri);
	ASSIGN_TO(RwRasterUnlockPalette, 			_Z21RwRasterUnlockPaletteP8RwRaster);
	ASSIGN_TO(RwImageCreate, 					_Z13RwImageCreateiii);
	ASSIGN_TO(RwImageDestroy, 					_Z14RwImageDestroyP7RwImage);
	ASSIGN_TO(RwImageAllocatePixels, 			_Z21RwImageAllocatePixelsP7RwImage);
	ASSIGN_TO(RwImageFreePixels, 				_Z17RwImageFreePixelsP7RwImage);
	ASSIGN_TO(RwImageCopy, 						_Z11RwImageCopyP7RwImagePKS_);
	ASSIGN_TO(RwImageResize, 					_Z13RwImageResizeP7RwImageii);
	ASSIGN_TO(RwImageApplyMask, 				_Z16RwImageApplyMaskP7RwImagePKS_);
	ASSIGN_TO(RwImageMakeMask, 					_Z15RwImageMakeMaskP7RwImage);
	ASSIGN_TO(RwImageReadMaskedImage, 			_Z22RwImageReadMaskedImagePKcS0_);
	ASSIGN_TO(RwImageRead, 						_Z11RwImageReadPKc);
	ASSIGN_TO(RwImageWrite, 					_Z12RwImageWriteP7RwImagePKc);
	ASSIGN_TO(RwImageSetFromRaster, 			_Z20RwImageSetFromRasterP7RwImageP8RwRaster);
	ASSIGN_TO(RwRasterSetFromImage, 			_Z20RwRasterSetFromImageP8RwRasterP7RwImage);
	ASSIGN_TO(RwRasterRead, 					_Z12RwRasterReadPKc);
	ASSIGN_TO(RwRasterReadMaskedRaster, 		_Z24RwRasterReadMaskedRasterPKcS0_);
	ASSIGN_TO(RwImageFindRasterFormat, 			_Z23RwImageFindRasterFormatP7RwImageiPiS1_S1_S1_);

	/* rwlpcore.h */
	ASSIGN_TO(RwIm2DGetNearScreenZ, 			_Z20RwIm2DGetNearScreenZv);
	ASSIGN_TO(RwIm2DGetFarScreenZ, 				_Z19RwIm2DGetFarScreenZv);
	ASSIGN_TO(RwRenderStateGet, 				_Z16RwRenderStateGet13RwRenderStatePv);
	ASSIGN_TO(RwRenderStateSet, 				_Z16RwRenderStateSet13RwRenderStatePv);
	ASSIGN_TO(RwIm2DRenderLine, 				_Z16RwIm2DRenderLineP14RwOpenGLVertexiii);
	ASSIGN_TO(RwIm2DRenderTriangle, 			_Z20RwIm2DRenderTriangleP14RwOpenGLVertexiiii);
	ASSIGN_TO(RwIm2DRenderPrimitive, 			_Z21RwIm2DRenderPrimitive15RwPrimitiveTypeP14RwOpenGLVertexi);
	ASSIGN_TO(RwIm2DRenderIndexedPrimitive,		_Z28RwIm2DRenderIndexedPrimitive15RwPrimitiveTypeP14RwOpenGLVertexiPti);

	/* rtpng.h */
	ASSIGN_TO(RtPNGImageWrite, 					_Z15RtPNGImageWriteP7RwImagePKc);
	ASSIGN_TO(RtPNGImageRead, 					_Z14RtPNGImageReadPKc);
}