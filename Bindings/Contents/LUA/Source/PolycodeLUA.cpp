#include "PolycodeLUA.h"
#include "PolycodeLUAWrappers.h"

int luaopen_Polycode(lua_State *L) {
	static const struct luaL_reg polycodeLib [] = {		{"OSFILE", Polycore_OSFILE},
		{"OSFILE_debugDump", Polycore_OSFILE_debugDump},
		{"OSFileEntry", Polycore_OSFileEntry},
		{"OSBasics_open", Polycore_OSBasics_open},
		{"OSBasics_close", Polycore_OSBasics_close},
		{"OSBasics_read", Polycore_OSBasics_read},
		{"OSBasics_write", Polycore_OSBasics_write},
		{"OSBasics_seek", Polycore_OSBasics_seek},
		{"OSBasics_tell", Polycore_OSBasics_tell},
		{"OSBasics_parsePhysFSFolder", Polycore_OSBasics_parsePhysFSFolder},
		{"OSBasics_parseFolder", Polycore_OSBasics_parseFolder},
		{"OSBasics_isFolder", Polycore_OSBasics_isFolder},
		{"OSBasics_createFolder", Polycore_OSBasics_createFolder},
		{"OSBasics_removeItem", Polycore_OSBasics_removeItem},
		{"BezierCurve", Polycore_BezierCurve},
		{"BezierCurve_getControlPoint", Polycore_BezierCurve_getControlPoint},
		{"BezierCurve_getNumControlPoints", Polycore_BezierCurve_getNumControlPoints},
		{"BezierCurve_addControlPoint", Polycore_BezierCurve_addControlPoint},
		{"BezierCurve_addControlPoint3dWithHandles", Polycore_BezierCurve_addControlPoint3dWithHandles},
		{"BezierCurve_addControlPoint3d", Polycore_BezierCurve_addControlPoint3d},
		{"BezierCurve_addControlPoint2dWithHandles", Polycore_BezierCurve_addControlPoint2dWithHandles},
		{"BezierCurve_addControlPoint2d", Polycore_BezierCurve_addControlPoint2d},
		{"BezierCurve_getHeightAt", Polycore_BezierCurve_getHeightAt},
		{"BezierCurve_getPointAt", Polycore_BezierCurve_getPointAt},
		{"BezierCurve_getPointBetween", Polycore_BezierCurve_getPointBetween},
		{"BezierCurve_rebuildBuffers", Polycore_BezierCurve_rebuildBuffers},
		{"Bone", Polycore_Bone},
		{"Bone_enableBoneLabel", Polycore_Bone_enableBoneLabel},
		{"Bone_getName", Polycore_Bone_getName},
		{"Bone_Render", Polycore_Bone_Render},
		{"Bone_setParentBone", Polycore_Bone_setParentBone},
		{"Bone_addChildBone", Polycore_Bone_addChildBone},
		{"Bone_getParentBone", Polycore_Bone_getParentBone},
		{"Bone_getNumChildBones", Polycore_Bone_getNumChildBones},
		{"Bone_getChildBone", Polycore_Bone_getChildBone},
		{"Bone_getBoneMatrix", Polycore_Bone_getBoneMatrix},
		{"Bone_setBoneMatrix", Polycore_Bone_setBoneMatrix},
		{"Bone_getRestMatrix", Polycore_Bone_getRestMatrix},
		{"Bone_getFullRestMatrix", Polycore_Bone_getFullRestMatrix},
		{"Bone_getParentRestMatrix", Polycore_Bone_getParentRestMatrix},
		{"Bone_getFinalMatrix", Polycore_Bone_getFinalMatrix},
		{"Bone_setRestMatrix", Polycore_Bone_setRestMatrix},
		{"Bone_setBaseMatrix", Polycore_Bone_setBaseMatrix},
		{"Bone_getBaseMatrix", Polycore_Bone_getBaseMatrix},
		{"Bone_getFullBaseMatrix", Polycore_Bone_getFullBaseMatrix},
		{"Camera", Polycore_Camera},
		{"Camera_buildFrustrumPlanes", Polycore_Camera_buildFrustrumPlanes},
		{"Camera_isSphereInFrustrum", Polycore_Camera_isSphereInFrustrum},
		{"Camera_canSee", Polycore_Camera_canSee},
		{"Camera_setOrthoMode", Polycore_Camera_setOrthoMode},
		{"Camera_getOrthoMode", Polycore_Camera_getOrthoMode},
		{"Camera_setFOV", Polycore_Camera_setFOV},
		{"Camera_getFOV", Polycore_Camera_getFOV},
		{"Camera_doCameraTransform", Polycore_Camera_doCameraTransform},
		{"Camera_setLightDepthTexture", Polycore_Camera_setLightDepthTexture},
		{"Camera_setParentScene", Polycore_Camera_setParentScene},
		{"Camera_hasFilterShader", Polycore_Camera_hasFilterShader},
		{"Camera_drawFilter", Polycore_Camera_drawFilter},
		{"Camera_setExposureLevel", Polycore_Camera_setExposureLevel},
		{"Camera_getExposureLevel", Polycore_Camera_getExposureLevel},
		{"Camera_createPostFilter", Polycore_Camera_createPostFilter},
		{"Camera_setPostFilter", Polycore_Camera_setPostFilter},
		{"Color", Polycore_Color},
		{"Color_setColorHex", Polycore_Color_setColorHex},
		{"Color_setColorHexRGB", Polycore_Color_setColorHexRGB},
		{"Color_setColorHSV", Polycore_Color_setColorHSV},
		{"Color_setColorRGBA", Polycore_Color_setColorRGBA},
		{"Color_setColorRGB", Polycore_Color_setColorRGB},
		{"Color_setColor", Polycore_Color_setColor},
		{"Color_Random", Polycore_Color_Random},
		{"Color_getBrightness", Polycore_Color_getBrightness},
		{"Color_getUint", Polycore_Color_getUint},
		{"Config", Polycore_Config},
		{"Config_loadConfig", Polycore_Config_loadConfig},
		{"Config_saveConfig", Polycore_Config_saveConfig},
		{"Config_getEntry", Polycore_Config_getEntry},
		{"Config_setStringValue", Polycore_Config_setStringValue},
		{"Config_setNumericValue", Polycore_Config_setNumericValue},
		{"Config_getNumericValue", Polycore_Config_getNumericValue},
		{"Config_getStringValue", Polycore_Config_getStringValue},
		{"CoreInput", Polycore_CoreInput},
		{"CoreInput_mouseWheelUp", Polycore_CoreInput_mouseWheelUp},
		{"CoreInput_mouseWheelDown", Polycore_CoreInput_mouseWheelDown},
		{"CoreInput_getMouseButtonState", Polycore_CoreInput_getMouseButtonState},
		{"CoreInput_setMouseButtonState", Polycore_CoreInput_setMouseButtonState},
		{"CoreInput_setMousePosition", Polycore_CoreInput_setMousePosition},
		{"CoreInput_getMousePosition", Polycore_CoreInput_getMousePosition},
		{"CoreInput_setKeyState", Polycore_CoreInput_setKeyState},
		{"CoreInput_getKeyState", Polycore_CoreInput_getKeyState},
		{"CoreInput_getMouseDelta", Polycore_CoreInput_getMouseDelta},
		{"CoreInput_setDeltaPosition", Polycore_CoreInput_setDeltaPosition},
		{"CoreInput_createEvent", Polycore_CoreInput_createEvent},
		{"CoreServices_getInstance", Polycore_CoreServices_getInstance},
		{"CoreServices_getRenderMutex", Polycore_CoreServices_getRenderMutex},
		{"CoreServices_setRenderer", Polycore_CoreServices_setRenderer},
		{"CoreServices_getRenderer", Polycore_CoreServices_getRenderer},
		{"CoreServices_Update", Polycore_CoreServices_Update},
		{"CoreServices_setCore", Polycore_CoreServices_setCore},
		{"CoreServices_getCore", Polycore_CoreServices_getCore},
		{"CoreServices_handleEvent", Polycore_CoreServices_handleEvent},
		{"CoreServices_installModule", Polycore_CoreServices_installModule},
		{"CoreServices_getMaterialManager", Polycore_CoreServices_getMaterialManager},
		{"CoreServices_getScreenManager", Polycore_CoreServices_getScreenManager},
		{"CoreServices_getSceneManager", Polycore_CoreServices_getSceneManager},
		{"CoreServices_getTimerManager", Polycore_CoreServices_getTimerManager},
		{"CoreServices_getTweenManager", Polycore_CoreServices_getTweenManager},
		{"CoreServices_getResourceManager", Polycore_CoreServices_getResourceManager},
		{"CoreServices_getSoundManager", Polycore_CoreServices_getSoundManager},
		{"CoreServices_getFontManager", Polycore_CoreServices_getFontManager},
		{"CoreServices_getConfig", Polycore_CoreServices_getConfig},
		{"Cubemap", Polycore_Cubemap},
		{"Data", Polycore_Data},
		{"Data_loadFromFile", Polycore_Data_loadFromFile},
		{"Data_getAsString", Polycore_Data_getAsString},
		{"Data_setFromString", Polycore_Data_setFromString},
		{"Data_saveToFile", Polycore_Data_saveToFile},
		{"Data_getData", Polycore_Data_getData},
		{"Entity", Polycore_Entity},
		{"Entity_Render", Polycore_Entity_Render},
		{"Entity_Update", Polycore_Entity_Update},
		{"Entity_transformAndRender", Polycore_Entity_transformAndRender},
		{"Entity_setMatrix", Polycore_Entity_setMatrix},
		{"Entity_rebuildTransformMatrix", Polycore_Entity_rebuildTransformMatrix},
		{"Entity_addEntity", Polycore_Entity_addEntity},
		{"Entity_addChild", Polycore_Entity_addChild},
		{"Entity_removeChild", Polycore_Entity_removeChild},
		{"Entity_updateEntityMatrix", Polycore_Entity_updateEntityMatrix},
		{"Entity_renderChildren", Polycore_Entity_renderChildren},
		{"Entity_getPosition", Polycore_Entity_getPosition},
		{"Entity_setPosition", Polycore_Entity_setPosition},
		{"Entity_setPositionX", Polycore_Entity_setPositionX},
		{"Entity_setPositionY", Polycore_Entity_setPositionY},
		{"Entity_setPositionZ", Polycore_Entity_setPositionZ},
		{"Entity_setScaleX", Polycore_Entity_setScaleX},
		{"Entity_setScaleY", Polycore_Entity_setScaleY},
		{"Entity_setScaleZ", Polycore_Entity_setScaleZ},
		{"Entity_Translate", Polycore_Entity_Translate},
		{"Entity_Scale", Polycore_Entity_Scale},
		{"Entity_setScale", Polycore_Entity_setScale},
		{"Entity_getScale", Polycore_Entity_getScale},
		{"Entity_getCombinedPosition", Polycore_Entity_getCombinedPosition},
		{"Entity_getCombinedPitch", Polycore_Entity_getCombinedPitch},
		{"Entity_getCombinedYaw", Polycore_Entity_getCombinedYaw},
		{"Entity_getCombinedRoll", Polycore_Entity_getCombinedRoll},
		{"Entity_setParentEntity", Polycore_Entity_setParentEntity},
		{"Entity_getParentEntity", Polycore_Entity_getParentEntity},
		{"Entity_rebuildRotation", Polycore_Entity_rebuildRotation},
		{"Entity_dirtyMatrix", Polycore_Entity_dirtyMatrix},
		{"Entity_setPitch", Polycore_Entity_setPitch},
		{"Entity_setYaw", Polycore_Entity_setYaw},
		{"Entity_setRoll", Polycore_Entity_setRoll},
		{"Entity_Roll", Polycore_Entity_Roll},
		{"Entity_Yaw", Polycore_Entity_Yaw},
		{"Entity_Pitch", Polycore_Entity_Pitch},
		{"Entity_getPitch", Polycore_Entity_getPitch},
		{"Entity_getYaw", Polycore_Entity_getYaw},
		{"Entity_getRoll", Polycore_Entity_getRoll},
		{"Entity_setRotationQuat", Polycore_Entity_setRotationQuat},
		{"Entity_getRotationQuat", Polycore_Entity_getRotationQuat},
		{"Entity_getTransformMatrix", Polycore_Entity_getTransformMatrix},
		{"Entity_getConcatenatedMatrix", Polycore_Entity_getConcatenatedMatrix},
		{"Entity_getConcatenatedRollMatrix", Polycore_Entity_getConcatenatedRollMatrix},
		{"Entity_setTransformByMatrix", Polycore_Entity_setTransformByMatrix},
		{"Entity_setTransformByMatrixPure", Polycore_Entity_setTransformByMatrixPure},
		{"Entity_setRenderer", Polycore_Entity_setRenderer},
		{"Entity_getCombinedColor", Polycore_Entity_getCombinedColor},
		{"Entity_setColor", Polycore_Entity_setColor},
		{"Entity_setColorInt", Polycore_Entity_setColorInt},
		{"Entity_recalculateBBox", Polycore_Entity_recalculateBBox},
		{"Entity_getBBoxRadius", Polycore_Entity_getBBoxRadius},
		{"Entity_getCompoundBBoxRadius", Polycore_Entity_getCompoundBBoxRadius},
		{"Entity_setBBoxRadius", Polycore_Entity_setBBoxRadius},
		{"Entity_setBlendingMode", Polycore_Entity_setBlendingMode},
		{"Entity_getChildCenter", Polycore_Entity_getChildCenter},
		{"Entity_setDepthWrite", Polycore_Entity_setDepthWrite},
		{"Entity_doUpdates", Polycore_Entity_doUpdates},
		{"Entity_lookAt", Polycore_Entity_lookAt},
		{"Entity_lookAtEntity", Polycore_Entity_lookAtEntity},
		{"Entity_getLookAtMatrix", Polycore_Entity_getLookAtMatrix},
		{"Entity_buildPositionMatrix", Polycore_Entity_buildPositionMatrix},
		{"Entity_adjustMatrixForChildren", Polycore_Entity_adjustMatrixForChildren},
		{"Entity_setMask", Polycore_Entity_setMask},
		{"Entity_clearMask", Polycore_Entity_clearMask},
		{"Entity_getCompoundScale", Polycore_Entity_getCompoundScale},
		{"Entity_getEntityProp", Polycore_Entity_getEntityProp},
		{"Event", Polycore_Event},
		{"Event_getEventCode", Polycore_Event_getEventCode},
		{"Event_setEventCode", Polycore_Event_setEventCode},
		{"Event_getDispatcher", Polycore_Event_getDispatcher},
		{"Event_setDispatcher", Polycore_Event_setDispatcher},
		{"Event_getEventType", Polycore_Event_getEventType},
		{"EventDispatcher", Polycore_EventDispatcher},
		{"EventDispatcher_removeAllHandlers", Polycore_EventDispatcher_removeAllHandlers},
		{"EventDispatcher_removeAllHandlersForListener", Polycore_EventDispatcher_removeAllHandlersForListener},
		{"EventDispatcher_addEventListener", Polycore_EventDispatcher_addEventListener},
		{"EventDispatcher_removeEventListener", Polycore_EventDispatcher_removeEventListener},
		{"EventDispatcher___dispatchEvent", Polycore_EventDispatcher___dispatchEvent},
		{"EventDispatcher_dispatchEvent", Polycore_EventDispatcher_dispatchEvent},
		{"EventDispatcher_dispatchEventNoDelete", Polycore_EventDispatcher_dispatchEventNoDelete},
		{"EventHandler", Polycore_EventHandler},
		{"EventHandler_secondaryHandler", Polycore_EventHandler_secondaryHandler},
		{"EventHandler_handleEvent", Polycore_EventHandler_handleEvent},
		{"FixedShader", Polycore_FixedShader},
		{"FixedShader_createBinding", Polycore_FixedShader_createBinding},
		{"FixedShaderBinding", Polycore_FixedShaderBinding},
		{"FixedShaderBinding_addTexture", Polycore_FixedShaderBinding_addTexture},
		{"FixedShaderBinding_addCubemap", Polycore_FixedShaderBinding_addCubemap},
		{"FixedShaderBinding_addParam", Polycore_FixedShaderBinding_addParam},
		{"FixedShaderBinding_getDiffuseTexture", Polycore_FixedShaderBinding_getDiffuseTexture},
		{"Font", Polycore_Font},
		{"Font_getFace", Polycore_Font_getFace},
		{"Font_isValid", Polycore_Font_isValid},
		{"FontManager", Polycore_FontManager},
		{"FontManager_registerFont", Polycore_FontManager_registerFont},
		{"FontManager_getFontByName", Polycore_FontManager_getFontByName},
		{"GenericScene", Polycore_GenericScene},
		{"GenericScene_Render", Polycore_GenericScene_Render},
		{"GenericScene_RenderDepthOnly", Polycore_GenericScene_RenderDepthOnly},
		{"GenericScene_addGrid", Polycore_GenericScene_addGrid},
		{"GenericScene_readString", Polycore_GenericScene_readString},
		{"GenericScene_loadScene", Polycore_GenericScene_loadScene},
		{"GenericScene_generateLightmaps", Polycore_GenericScene_generateLightmaps},
		{"GenericScene_addLight", Polycore_GenericScene_addLight},
		{"GenericScene_getNearestLight", Polycore_GenericScene_getNearestLight},
		{"GenericScene_writeEntityMatrix", Polycore_GenericScene_writeEntityMatrix},
		{"GenericScene_writeString", Polycore_GenericScene_writeString},
		{"GenericScene_saveScene", Polycore_GenericScene_saveScene},
		{"GenericScene_getNumStaticGeometry", Polycore_GenericScene_getNumStaticGeometry},
		{"GenericScene_getStaticGeometry", Polycore_GenericScene_getStaticGeometry},
		{"GenericScene_loadCollisionChild", Polycore_GenericScene_loadCollisionChild},
		{"GenericScene_getNumLights", Polycore_GenericScene_getNumLights},
		{"GenericScene_getLight", Polycore_GenericScene_getLight},
		{"GenericScene_getCustomEntityByType", Polycore_GenericScene_getCustomEntityByType},
		{"OpenGLCubemap", Polycore_OpenGLCubemap},
		{"OpenGLCubemap_getTextureID", Polycore_OpenGLCubemap_getTextureID},
		{"Image", Polycore_Image},
		{"Image_loadImage", Polycore_Image_loadImage},
		{"Image_loadPNG", Polycore_Image_loadPNG},
		{"Image_createEmpty", Polycore_Image_createEmpty},
		{"Image_fill", Polycore_Image_fill},
		{"Image_setPixel", Polycore_Image_setPixel},
		{"Image_getPixel", Polycore_Image_getPixel},
		{"Image_setAAPixel", Polycore_Image_setAAPixel},
		{"Image_swap", Polycore_Image_swap},
		{"Image_line", Polycore_Image_line},
		{"Image_moveTo", Polycore_Image_moveTo},
		{"Image_move", Polycore_Image_move},
		{"Image_lineTo", Polycore_Image_lineTo},
		{"Image_drawRect", Polycore_Image_drawRect},
		{"Image_perlinNoise", Polycore_Image_perlinNoise},
		{"Image_fastBlur", Polycore_Image_fastBlur},
		{"Image_fastBlurVert", Polycore_Image_fastBlurVert},
		{"Image_fastBlurHor", Polycore_Image_fastBlurHor},
		{"Image_darken", Polycore_Image_darken},
		{"Image_lighten", Polycore_Image_lighten},
		{"Image_multiply", Polycore_Image_multiply},
		{"Image_getBrushX", Polycore_Image_getBrushX},
		{"Image_getBrushY", Polycore_Image_getBrushY},
		{"Image_isLoaded", Polycore_Image_isLoaded},
		{"Image_getType", Polycore_Image_getType},
		{"Image_writeBMP", Polycore_Image_writeBMP},
		{"Image_getWidth", Polycore_Image_getWidth},
		{"Image_getHeight", Polycore_Image_getHeight},
		{"Image_getPixels", Polycore_Image_getPixels},
		{"InputEvent", Polycore_InputEvent},
		{"InputEvent_keyCode", Polycore_InputEvent_keyCode},
		{"Label", Polycore_Label},
		{"Label_setText", Polycore_Label_setText},
		{"Label_getText", Polycore_Label_getText},
		{"Label_getTextWidth", Polycore_Label_getTextWidth},
		{"Label_getTextHeight", Polycore_Label_getTextHeight},
		{"Label_getFont", Polycore_Label_getFont},
		{"Logger", Polycore_Logger},
		{"Logger_log", Polycore_Logger_log},
		{"Logger_logw", Polycore_Logger_logw},
		{"Material", Polycore_Material},
		{"Material_addShader", Polycore_Material_addShader},
		{"Material_getNumShaders", Polycore_Material_getNumShaders},
		{"Material_addShaderRenderTarget", Polycore_Material_addShaderRenderTarget},
		{"Material_getNumShaderRenderTargets", Polycore_Material_getNumShaderRenderTargets},
		{"Material_getShaderRenderTarget", Polycore_Material_getShaderRenderTarget},
		{"Material_getName", Polycore_Material_getName},
		{"Material_getShader", Polycore_Material_getShader},
		{"Material_getShaderBinding", Polycore_Material_getShaderBinding},
		{"Material_loadMaterial", Polycore_Material_loadMaterial},
		{"MaterialManager", Polycore_MaterialManager},
		{"MaterialManager_Update", Polycore_MaterialManager_Update},
		{"MaterialManager_createFramebufferTexture", Polycore_MaterialManager_createFramebufferTexture},
		{"MaterialManager_createTexture", Polycore_MaterialManager_createTexture},
		{"MaterialManager_createNewTexture", Polycore_MaterialManager_createNewTexture},
		{"MaterialManager_createTextureFromImage", Polycore_MaterialManager_createTextureFromImage},
		{"MaterialManager_createTextureFromFile", Polycore_MaterialManager_createTextureFromFile},
		{"MaterialManager_deleteTexture", Polycore_MaterialManager_deleteTexture},
		{"MaterialManager_reloadTextures", Polycore_MaterialManager_reloadTextures},
		{"MaterialManager_reloadProgramsAndTextures", Polycore_MaterialManager_reloadProgramsAndTextures},
		{"MaterialManager_reloadPrograms", Polycore_MaterialManager_reloadPrograms},
		{"MaterialManager_addShaderModule", Polycore_MaterialManager_addShaderModule},
		{"MaterialManager_getTextureByResourcePath", Polycore_MaterialManager_getTextureByResourcePath},
		{"MaterialManager_cubemapFromXMLNode", Polycore_MaterialManager_cubemapFromXMLNode},
		{"MaterialManager_loadMaterialsFromFile", Polycore_MaterialManager_loadMaterialsFromFile},
		{"MaterialManager_materialFromXMLNode", Polycore_MaterialManager_materialFromXMLNode},
		{"MaterialManager_setShaderFromXMLNode", Polycore_MaterialManager_setShaderFromXMLNode},
		{"MaterialManager_createShaderFromXMLNode", Polycore_MaterialManager_createShaderFromXMLNode},
		{"Matrix4", Polycore_Matrix4},
		{"Matrix4_init", Polycore_Matrix4_init},
		{"Matrix4_identity", Polycore_Matrix4_identity},
		{"Matrix4_rotateVector", Polycore_Matrix4_rotateVector},
		{"Matrix4_getPosition", Polycore_Matrix4_getPosition},
		{"Matrix4_setPosition", Polycore_Matrix4_setPosition},
		{"Matrix4_setScale", Polycore_Matrix4_setScale},
		{"Matrix4_getEulerAngles", Polycore_Matrix4_getEulerAngles},
		{"Matrix4_inverse", Polycore_Matrix4_inverse},
		{"Matrix4_inverseAffine", Polycore_Matrix4_inverseAffine},
		{"Mesh", Polycore_Mesh},
		{"Mesh_addPolygon", Polycore_Mesh_addPolygon},
		{"Mesh_loadMesh", Polycore_Mesh_loadMesh},
		{"Mesh_loadFromFile", Polycore_Mesh_loadFromFile},
		{"Mesh_saveToFile", Polycore_Mesh_saveToFile},
		{"Mesh_getPolygonCount", Polycore_Mesh_getPolygonCount},
		{"Mesh_getPolygon", Polycore_Mesh_getPolygon},
		{"Mesh_createPlane", Polycore_Mesh_createPlane},
		{"Mesh_createBox", Polycore_Mesh_createBox},
		{"Mesh_createSphere", Polycore_Mesh_createSphere},
		{"Mesh_addVertex", Polycore_Mesh_addVertex},
		{"Mesh_getVertex", Polycore_Mesh_getVertex},
		{"Mesh_getNumVertices", Polycore_Mesh_getNumVertices},
		{"Mesh_recenterMesh", Polycore_Mesh_recenterMesh},
		{"Mesh_useVertexNormals", Polycore_Mesh_useVertexNormals},
		{"Mesh_getVertexIndex", Polycore_Mesh_getVertexIndex},
		{"Mesh_setVertexBuffer", Polycore_Mesh_setVertexBuffer},
		{"Mesh_getVertexBuffer", Polycore_Mesh_getVertexBuffer},
		{"Mesh_usesFaceUV", Polycore_Mesh_usesFaceUV},
		{"Mesh_getRadius", Polycore_Mesh_getRadius},
		{"Mesh_calculateNormals", Polycore_Mesh_calculateNormals},
		{"Mesh_getMeshType", Polycore_Mesh_getMeshType},
		{"Mesh_setMeshType", Polycore_Mesh_setMeshType},
		{"Mesh_calculateBBox", Polycore_Mesh_calculateBBox},
		{"Mesh_hasVertexBuffer", Polycore_Mesh_hasVertexBuffer},
		{"VertexBuffer", Polycore_VertexBuffer},
		{"VertexBuffer_getVertexCount", Polycore_VertexBuffer_getVertexCount},
		{"PolycodeModule", Polycore_PolycodeModule},
		{"PolycodeModule_getType", Polycore_PolycodeModule_getType},
		{"ObjectEntry", Polycore_ObjectEntry},
		{"ObjectEntry_addChild", Polycore_ObjectEntry_addChild},
		{"Particle", Polycore_Particle},
		{"Particle_Reset", Polycore_Particle_Reset},
		{"Particle_createSceneParticle", Polycore_Particle_createSceneParticle},
		{"Particle_createScreenParticle", Polycore_Particle_createScreenParticle},
		{"ScreenParticleEmitter", Polycore_ScreenParticleEmitter},
		{"ScreenParticleEmitter_addParticleBody", Polycore_ScreenParticleEmitter_addParticleBody},
		{"ScreenParticleEmitter_getBaseMatrix", Polycore_ScreenParticleEmitter_getBaseMatrix},
		{"ScreenParticleEmitter_Update", Polycore_ScreenParticleEmitter_Update},
		{"SceneParticleEmitter", Polycore_SceneParticleEmitter},
		{"SceneParticleEmitter_addParticleBody", Polycore_SceneParticleEmitter_addParticleBody},
		{"SceneParticleEmitter_getBaseMatrix", Polycore_SceneParticleEmitter_getBaseMatrix},
		{"SceneParticleEmitter_Update", Polycore_SceneParticleEmitter_Update},
		{"Perlin", Polycore_Perlin},
		{"Perlin_Get", Polycore_Perlin_Get},
		{"Polygon", Polycore_Polygon},
		{"Polygon_getVertexCount", Polycore_Polygon_getVertexCount},
		{"Polygon_getVertex", Polycore_Polygon_getVertex},
		{"Polygon_addVertex", Polycore_Polygon_addVertex},
		{"Polygon_removeVertex", Polycore_Polygon_removeVertex},
		{"Polygon_addTexCoord", Polycore_Polygon_addTexCoord},
		{"Polygon_addTexCoord2", Polycore_Polygon_addTexCoord2},
		{"Polygon_getTexCoord", Polycore_Polygon_getTexCoord},
		{"Polygon_getTexCoord2", Polycore_Polygon_getTexCoord2},
		{"Polygon_calculateNormal", Polycore_Polygon_calculateNormal},
		{"Polygon_getFaceNormal", Polycore_Polygon_getFaceNormal},
		{"Polygon_getBounds2D", Polycore_Polygon_getBounds2D},
		{"Polygon_setNormal", Polycore_Polygon_setNormal},
		{"Polygon_flipUVY", Polycore_Polygon_flipUVY},
		{"Polygon_setUseFaceUV", Polycore_Polygon_setUseFaceUV},
		{"Polygon_usesFaceUV", Polycore_Polygon_usesFaceUV},
		{"Quaternion", Polycore_Quaternion},
		{"Quaternion_setFromMatrix", Polycore_Quaternion_setFromMatrix},
		{"Quaternion_Slerp", Polycore_Quaternion_Slerp},
		{"Quaternion_Dot", Polycore_Quaternion_Dot},
		{"Quaternion_Log", Polycore_Quaternion_Log},
		{"Quaternion_Exp", Polycore_Quaternion_Exp},
		{"Quaternion_Norm", Polycore_Quaternion_Norm},
		{"Quaternion_normalise", Polycore_Quaternion_normalise},
		{"Quaternion_lookAt", Polycore_Quaternion_lookAt},
		{"Quaternion_createFromMatrix", Polycore_Quaternion_createFromMatrix},
		{"Quaternion_Squad", Polycore_Quaternion_Squad},
		{"Quaternion_Inverse", Polycore_Quaternion_Inverse},
		{"Quaternion_set", Polycore_Quaternion_set},
		{"Quaternion_inverse", Polycore_Quaternion_inverse},
		{"Quaternion_InvSqrt", Polycore_Quaternion_InvSqrt},
		{"Quaternion_fromAxes", Polycore_Quaternion_fromAxes},
		{"Quaternion_FromAngleAxis", Polycore_Quaternion_FromAngleAxis},
		{"Quaternion_ToAngleAxis", Polycore_Quaternion_ToAngleAxis},
		{"Quaternion_createFromAxisAngle", Polycore_Quaternion_createFromAxisAngle},
		{"Quaternion_createMatrix", Polycore_Quaternion_createMatrix},
		{"QuaternionCurve", Polycore_QuaternionCurve},
		{"QuaternionCurve_interpolate", Polycore_QuaternionCurve_interpolate},
		{"QuaternionCurve_generatePointsFromCurves", Polycore_QuaternionCurve_generatePointsFromCurves},
		{"QuaternionCurve_recalcTangents", Polycore_QuaternionCurve_recalcTangents},
		{"Rectangle", Polycore_Rectangle},
		{"Rectangle_setRect", Polycore_Rectangle_setRect},
		{"Resource", Polycore_Resource},
		{"Resource_getResourceName", Polycore_Resource_getResourceName},
		{"Resource_getResourceType", Polycore_Resource_getResourceType},
		{"Resource_setResourceName", Polycore_Resource_setResourceName},
		{"Resource_setResourcePath", Polycore_Resource_setResourcePath},
		{"Resource_getResourcePath", Polycore_Resource_getResourcePath},
		{"ResourceManager", Polycore_ResourceManager},
		{"ResourceManager_addResource", Polycore_ResourceManager_addResource},
		{"ResourceManager_addDirResource", Polycore_ResourceManager_addDirResource},
		{"ResourceManager_addArchive", Polycore_ResourceManager_addArchive},
		{"ResourceManager_readFile", Polycore_ResourceManager_readFile},
		{"ResourceManager_parseTextures", Polycore_ResourceManager_parseTextures},
		{"ResourceManager_parseMaterials", Polycore_ResourceManager_parseMaterials},
		{"ResourceManager_parseShaders", Polycore_ResourceManager_parseShaders},
		{"ResourceManager_parsePrograms", Polycore_ResourceManager_parsePrograms},
		{"ResourceManager_parseCubemaps", Polycore_ResourceManager_parseCubemaps},
		{"ResourceManager_getResource", Polycore_ResourceManager_getResource},
		{"ResourceManager_addShaderModule", Polycore_ResourceManager_addShaderModule},
		{"SceneEntity", Polycore_SceneEntity},
		{"SceneEntity_testMouseCollision", Polycore_SceneEntity_testMouseCollision},
		{"SceneLabel", Polycore_SceneLabel},
		{"SceneLabel_testMouseCollision", Polycore_SceneLabel_testMouseCollision},
		{"SceneLabel_setText", Polycore_SceneLabel_setText},
		{"SceneLabel_getLabel", Polycore_SceneLabel_getLabel},
		{"SceneLabel_Render", Polycore_SceneLabel_Render},
		{"SceneLight", Polycore_SceneLight},
		{"SceneLight_getIntensity", Polycore_SceneLight_getIntensity},
		{"SceneLight_getDistance", Polycore_SceneLight_getDistance},
		{"SceneLight_getType", Polycore_SceneLight_getType},
		{"SceneLight_renderDepthMap", Polycore_SceneLight_renderDepthMap},
		{"SceneLight_Render", Polycore_SceneLight_Render},
		{"SceneLight_getLightViewMatrix", Polycore_SceneLight_getLightViewMatrix},
		{"SceneLight_getZBufferTexture", Polycore_SceneLight_getZBufferTexture},
		{"SceneLight_setLightColor", Polycore_SceneLight_setLightColor},
		{"SceneLight_enableShadows", Polycore_SceneLight_enableShadows},
		{"SceneLight_setShadowMapFOV", Polycore_SceneLight_setShadowMapFOV},
		{"SceneLight_areShadowsEnabled", Polycore_SceneLight_areShadowsEnabled},
		{"SceneLight_getLightType", Polycore_SceneLight_getLightType},
		{"SceneLine", Polycore_SceneLine},
		{"SceneLine_Render", Polycore_SceneLine_Render},
		{"SceneManager", Polycore_SceneManager},
		{"SceneManager_addScene", Polycore_SceneManager_addScene},
		{"SceneManager_Update", Polycore_SceneManager_Update},
		{"SceneManager_UpdateVirtual", Polycore_SceneManager_UpdateVirtual},
		{"SceneManager_removeScene", Polycore_SceneManager_removeScene},
		{"SceneManager_registerRenderTexture", Polycore_SceneManager_registerRenderTexture},
		{"SceneMesh", Polycore_SceneMesh},
		{"SceneMesh_Render", Polycore_SceneMesh_Render},
		{"SceneMesh_getLocalShaderOptions", Polycore_SceneMesh_getLocalShaderOptions},
		{"SceneMesh_getMesh", Polycore_SceneMesh_getMesh},
		{"SceneMesh_getTexture", Polycore_SceneMesh_getTexture},
		{"SceneMesh_getMaterial", Polycore_SceneMesh_getMaterial},
		{"SceneMesh_loadTexture", Polycore_SceneMesh_loadTexture},
		{"SceneMesh_loadSkeleton", Polycore_SceneMesh_loadSkeleton},
		{"SceneMesh_setTexture", Polycore_SceneMesh_setTexture},
		{"SceneMesh_setMaterial", Polycore_SceneMesh_setMaterial},
		{"SceneMesh_setMesh", Polycore_SceneMesh_setMesh},
		{"SceneMesh_setSkeleton", Polycore_SceneMesh_setSkeleton},
		{"SceneMesh_getSkeleton", Polycore_SceneMesh_getSkeleton},
		{"SceneMesh_renderMeshLocally", Polycore_SceneMesh_renderMeshLocally},
		{"SceneMesh_cacheToVertexBuffer", Polycore_SceneMesh_cacheToVertexBuffer},
		{"ScenePrimitive", Polycore_ScenePrimitive},
		{"SceneRenderTexture", Polycore_SceneRenderTexture},
		{"SceneRenderTexture_drawScreen", Polycore_SceneRenderTexture_drawScreen},
		{"SceneRenderTexture_getTargetTexture", Polycore_SceneRenderTexture_getTargetTexture},
		{"SceneRenderTexture_getTargetScene", Polycore_SceneRenderTexture_getTargetScene},
		{"SceneRenderTexture_getTargetCamera", Polycore_SceneRenderTexture_getTargetCamera},
		{"Screen", Polycore_Screen},
		{"Screen_addChild", Polycore_Screen_addChild},
		{"Screen_removeChild", Polycore_Screen_removeChild},
		{"Screen_setScreenOffset", Polycore_Screen_setScreenOffset},
		{"Screen_getScreenOffset", Polycore_Screen_getScreenOffset},
		{"Screen_Shutdown", Polycore_Screen_Shutdown},
		{"Screen_Update", Polycore_Screen_Update},
		{"Screen_getEntityAt", Polycore_Screen_getEntityAt},
		{"Screen_Render", Polycore_Screen_Render},
		{"Screen_setRenderer", Polycore_Screen_setRenderer},
		{"Screen_setNormalizedCoordinates", Polycore_Screen_setNormalizedCoordinates},
		{"Screen_setScreenShader", Polycore_Screen_setScreenShader},
		{"Screen_handleEvent", Polycore_Screen_handleEvent},
		{"Screen_getHighestZIndex", Polycore_Screen_getHighestZIndex},
		{"Screen_sortChildren", Polycore_Screen_sortChildren},
		{"Screen_cmpZindex", Polycore_Screen_cmpZindex},
		{"Screen_handleInputEvent", Polycore_Screen_handleInputEvent},
		{"Screen_hasFilterShader", Polycore_Screen_hasFilterShader},
		{"Screen_drawFilter", Polycore_Screen_drawFilter},
		{"Screen_usesNormalizedCoordinates", Polycore_Screen_usesNormalizedCoordinates},
		{"Screen_getYCoordinateSize", Polycore_Screen_getYCoordinateSize},
		{"Screen_getRootEntity", Polycore_Screen_getRootEntity},
		{"ScreenCurve", Polycore_ScreenCurve},
		{"ScreenEntity", Polycore_ScreenEntity},
		{"ScreenEntity_setPosition", Polycore_ScreenEntity_setPosition},
		{"ScreenEntity_setScale", Polycore_ScreenEntity_setScale},
		{"ScreenEntity_setRotation", Polycore_ScreenEntity_setRotation},
		{"ScreenEntity_getRotation", Polycore_ScreenEntity_getRotation},
		{"ScreenEntity__onMouseDown", Polycore_ScreenEntity__onMouseDown},
		{"ScreenEntity__onMouseUp", Polycore_ScreenEntity__onMouseUp},
		{"ScreenEntity__onMouseMove", Polycore_ScreenEntity__onMouseMove},
		{"ScreenEntity__onMouseWheelUp", Polycore_ScreenEntity__onMouseWheelUp},
		{"ScreenEntity__onMouseWheelDown", Polycore_ScreenEntity__onMouseWheelDown},
		{"ScreenEntity_onMouseDown", Polycore_ScreenEntity_onMouseDown},
		{"ScreenEntity_onMouseUp", Polycore_ScreenEntity_onMouseUp},
		{"ScreenEntity_onMouseMove", Polycore_ScreenEntity_onMouseMove},
		{"ScreenEntity_onMouseWheelUp", Polycore_ScreenEntity_onMouseWheelUp},
		{"ScreenEntity_onMouseWheelDown", Polycore_ScreenEntity_onMouseWheelDown},
		{"ScreenEntity__onKeyDown", Polycore_ScreenEntity__onKeyDown},
		{"ScreenEntity__onKeyUp", Polycore_ScreenEntity__onKeyUp},
		{"ScreenEntity_onKeyDown", Polycore_ScreenEntity_onKeyDown},
		{"ScreenEntity_onKeyUp", Polycore_ScreenEntity_onKeyUp},
		{"ScreenEntity_hitTest", Polycore_ScreenEntity_hitTest},
		{"ScreenEntity_buildPositionMatrix", Polycore_ScreenEntity_buildPositionMatrix},
		{"ScreenEntity_adjustMatrixForChildren", Polycore_ScreenEntity_adjustMatrixForChildren},
		{"ScreenEntity_getWidth", Polycore_ScreenEntity_getWidth},
		{"ScreenEntity_getHeight", Polycore_ScreenEntity_getHeight},
		{"ScreenEntity_setWidth", Polycore_ScreenEntity_setWidth},
		{"ScreenEntity_setHeight", Polycore_ScreenEntity_setHeight},
		{"ScreenEntity_onGainFocus", Polycore_ScreenEntity_onGainFocus},
		{"ScreenEntity_onLoseFocus", Polycore_ScreenEntity_onLoseFocus},
		{"ScreenEntity_startDrag", Polycore_ScreenEntity_startDrag},
		{"ScreenEntity_stopDrag", Polycore_ScreenEntity_stopDrag},
		{"ScreenEntity_setBlendingMode", Polycore_ScreenEntity_setBlendingMode},
		{"ScreenEntity_setPositionMode", Polycore_ScreenEntity_setPositionMode},
		{"ScreenEntity_setDragLimits", Polycore_ScreenEntity_setDragLimits},
		{"ScreenEntity_clearDragLimits", Polycore_ScreenEntity_clearDragLimits},
		{"ScreenEntity_focusChild", Polycore_ScreenEntity_focusChild},
		{"ScreenEntity_focusNextChild", Polycore_ScreenEntity_focusNextChild},
		{"ScreenEntity_getPosition2D", Polycore_ScreenEntity_getPosition2D},
		{"ScreenEntity_isFocusable", Polycore_ScreenEntity_isFocusable},
		{"ScreenEvent", Polycore_ScreenEvent},
		{"ScreenImage", Polycore_ScreenImage},
		{"ScreenImage_setImageCoordinates", Polycore_ScreenImage_setImageCoordinates},
		{"ScreenImage_getImageWidth", Polycore_ScreenImage_getImageWidth},
		{"ScreenImage_getImageHeight", Polycore_ScreenImage_getImageHeight},
		{"ScreenLabel", Polycore_ScreenLabel},
		{"ScreenLabel_addDropShadow", Polycore_ScreenLabel_addDropShadow},
		{"ScreenLabel_setText", Polycore_ScreenLabel_setText},
		{"ScreenLabel_getText", Polycore_ScreenLabel_getText},
		{"ScreenLabel_getLabel", Polycore_ScreenLabel_getLabel},
		{"ScreenLine", Polycore_ScreenLine},
		{"ScreenLine_Update", Polycore_ScreenLine_Update},
		{"ScreenLine_Render", Polycore_ScreenLine_Render},
		{"ScreenLine_setLineWidth", Polycore_ScreenLine_setLineWidth},
		{"ScreenManager", Polycore_ScreenManager},
		{"ScreenManager_removeScreen", Polycore_ScreenManager_removeScreen},
		{"ScreenManager_addScreen", Polycore_ScreenManager_addScreen},
		{"ScreenManager_Update", Polycore_ScreenManager_Update},
		{"ScreenManager_handleEvent", Polycore_ScreenManager_handleEvent},
		{"ScreenMesh", Polycore_ScreenMesh},
		{"ScreenMesh_Render", Polycore_ScreenMesh_Render},
		{"ScreenMesh_getMesh", Polycore_ScreenMesh_getMesh},
		{"ScreenMesh_getTexture", Polycore_ScreenMesh_getTexture},
		{"ScreenMesh_loadTexture", Polycore_ScreenMesh_loadTexture},
		{"ScreenMesh_setTexture", Polycore_ScreenMesh_setTexture},
		{"ScreenShape", Polycore_ScreenShape},
		{"ScreenShape_Render", Polycore_ScreenShape_Render},
		{"ScreenShape_setStrokeColor", Polycore_ScreenShape_setStrokeColor},
		{"ScreenShape_setStrokeWidth", Polycore_ScreenShape_setStrokeWidth},
		{"ScreenShape_setGradient", Polycore_ScreenShape_setGradient},
		{"ScreenShape_clearGradient", Polycore_ScreenShape_clearGradient},
		{"ScreenShape_setShapeSize", Polycore_ScreenShape_setShapeSize},
		{"ScreenShape_addShapePoint", Polycore_ScreenShape_addShapePoint},
		{"ScreenSprite", Polycore_ScreenSprite},
		{"ScreenSprite_addAnimation", Polycore_ScreenSprite_addAnimation},
		{"ScreenSprite_playAnimation", Polycore_ScreenSprite_playAnimation},
		{"ScreenSprite_Update", Polycore_ScreenSprite_Update},
		{"SkeletonAnimation", Polycore_SkeletonAnimation},
		{"SkeletonAnimation_addBoneTrack", Polycore_SkeletonAnimation_addBoneTrack},
		{"SkeletonAnimation_getName", Polycore_SkeletonAnimation_getName},
		{"SkeletonAnimation_Play", Polycore_SkeletonAnimation_Play},
		{"SkeletonAnimation_Stop", Polycore_SkeletonAnimation_Stop},
		{"SkeletonAnimation_Update", Polycore_SkeletonAnimation_Update},
		{"SkeletonAnimation_setSpeed", Polycore_SkeletonAnimation_setSpeed},
		{"Skeleton", Polycore_Skeleton},
		{"Skeleton_loadSkeleton", Polycore_Skeleton_loadSkeleton},
		{"Skeleton_playAnimation", Polycore_Skeleton_playAnimation},
		{"Skeleton_playAnimationByIndex", Polycore_Skeleton_playAnimationByIndex},
		{"Skeleton_addAnimation", Polycore_Skeleton_addAnimation},
		{"Skeleton_getAnimation", Polycore_Skeleton_getAnimation},
		{"Skeleton_Update", Polycore_Skeleton_Update},
		{"Skeleton_getBoneByName", Polycore_Skeleton_getBoneByName},
		{"Skeleton_bonesVisible", Polycore_Skeleton_bonesVisible},
		{"Skeleton_enableBoneLabels", Polycore_Skeleton_enableBoneLabels},
		{"Skeleton_getNumBones", Polycore_Skeleton_getNumBones},
		{"Skeleton_getBone", Polycore_Skeleton_getBone},
		{"Skeleton_getCurrentAnimation", Polycore_Skeleton_getCurrentAnimation},
		{"BoneTrack", Polycore_BoneTrack},
		{"BoneTrack_Play", Polycore_BoneTrack_Play},
		{"BoneTrack_Stop", Polycore_BoneTrack_Stop},
		{"BoneTrack_Update", Polycore_BoneTrack_Update},
		{"BoneTrack_setSpeed", Polycore_BoneTrack_setSpeed},
		{"Sound", Polycore_Sound},
		{"Sound_Play", Polycore_Sound_Play},
		{"Sound_Stop", Polycore_Sound_Stop},
		{"Sound_loadWAV", Polycore_Sound_loadWAV},
		{"Sound_loadOGG", Polycore_Sound_loadOGG},
		{"Sound_GenSource", Polycore_Sound_GenSource},
		{"Sound_checkALError", Polycore_Sound_checkALError},
		{"Sound_soundError", Polycore_Sound_soundError},
		{"Sound_soundCheck", Polycore_Sound_soundCheck},
		{"SoundManager", Polycore_SoundManager},
		{"SoundManager_initAL", Polycore_SoundManager_initAL},
		{"String", Polycore_String},
		{"String_size", Polycore_String_size},
		{"String_length", Polycore_String_length},
		{"String_getSTLString", Polycore_String_getSTLString},
		{"String_getSTLWString", Polycore_String_getSTLWString},
		{"String_substr", Polycore_String_substr},
		{"String_rfind", Polycore_String_rfind},
		{"String_find", Polycore_String_find},
		{"String_find_last_of", Polycore_String_find_last_of},
		{"String_toLowerCase", Polycore_String_toLowerCase},
		{"String_split", Polycore_String_split},
		{"String_replace", Polycore_String_replace},
		{"String_NumberToString", Polycore_String_NumberToString},
		{"String_c_str", Polycore_String_c_str},
		{"String_wc_str", Polycore_String_wc_str},
		{"String_data", Polycore_String_data},
		{"String_getDataWithEncoding", Polycore_String_getDataWithEncoding},
		{"String_setDataWithEncoding", Polycore_String_setDataWithEncoding},
		{"String_getDataSizeWithEncoding", Polycore_String_getDataSizeWithEncoding},
		{"Timer", Polycore_Timer},
		{"Timer_Pause", Polycore_Timer_Pause},
		{"Timer_isPaused", Polycore_Timer_isPaused},
		{"Timer_getTicks", Polycore_Timer_getTicks},
		{"Timer_Update", Polycore_Timer_Update},
		{"Timer_Reset", Polycore_Timer_Reset},
		{"Timer_hasElapsed", Polycore_Timer_hasElapsed},
		{"Timer_getElapsedf", Polycore_Timer_getElapsedf},
		{"TimerManager", Polycore_TimerManager},
		{"TimerManager_removeTimer", Polycore_TimerManager_removeTimer},
		{"TimerManager_addTimer", Polycore_TimerManager_addTimer},
		{"TimerManager_Update", Polycore_TimerManager_Update},
		{"Tween", Polycore_Tween},
		{"Tween_handleEvent", Polycore_Tween_handleEvent},
		{"Tween_interpolateTween", Polycore_Tween_interpolateTween},
		{"Tween_updateCustomTween", Polycore_Tween_updateCustomTween},
		{"Tween_doOnComplete", Polycore_Tween_doOnComplete},
		{"Tween_Pause", Polycore_Tween_Pause},
		{"Tween_Reset", Polycore_Tween_Reset},
		{"Tween_isComplete", Polycore_Tween_isComplete},
		{"Tween_setSpeed", Polycore_Tween_setSpeed},
		{"BezierPathTween", Polycore_BezierPathTween},
		{"BezierPathTween_updateCustomTween", Polycore_BezierPathTween_updateCustomTween},
		{"QuaternionTween", Polycore_QuaternionTween},
		{"QuaternionTween_updateCustomTween", Polycore_QuaternionTween_updateCustomTween},
		{"TweenManager", Polycore_TweenManager},
		{"TweenManager_addTween", Polycore_TweenManager_addTween},
		{"TweenManager_Update", Polycore_TweenManager_Update},
		{"Vector2", Polycore_Vector2},
		{"Vector3", Polycore_Vector3},
		{"Vector3_set", Polycore_Vector3_set},
		{"Vector3_distance", Polycore_Vector3_distance},
		{"Vector3_length", Polycore_Vector3_length},
		{"Vector3_dot", Polycore_Vector3_dot},
		{"Vector3_crossProduct", Polycore_Vector3_crossProduct},
		{"Vector3_Normalize", Polycore_Vector3_Normalize},
		{"Vertex", Polycore_Vertex},
		{"Vertex_addBoneAssignment", Polycore_Vertex_addBoneAssignment},
		{"Vertex_getNumBoneAssignments", Polycore_Vertex_getNumBoneAssignments},
		{"Vertex_getBoneAssignment", Polycore_Vertex_getBoneAssignment},
		{"Vertex_normalizeWeights", Polycore_Vertex_normalizeWeights},
		{"Vertex_getTexCoord", Polycore_Vertex_getTexCoord},
		{"Vertex_setTexCoord", Polycore_Vertex_setTexCoord},
		{"Vertex_setNormal", Polycore_Vertex_setNormal},
		{NULL, NULL}
	};
	luaL_openlib(L, "Polycore", polycodeLib, 0);
	return 1;
}