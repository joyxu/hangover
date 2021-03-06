/*
 * Copyright 2017 André Hentschel
 * Copyright 2018 Stefan Dösinger for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef QEMU_D3D11_H
#define QEMU_D3D11_H

/* For the private API. D3DERR_INVALIDCALL will not be used at runtime because we provide the IUnknown ptr. */
#define D3D_OK S_OK
#define D3DERR_INVALIDCALL E_FAIL
#define D3DSPD_IUNKNOWN 1
#include "private_data.h"

enum d3d11_calls
{
    CALL_D3D10_BLEND_STATE_ADDREF = 0,
    CALL_D3D10_BLEND_STATE_GETDESC,
    CALL_D3D10_BLEND_STATE_GETDESC1,
    CALL_D3D10_BLEND_STATE_RELEASE,
    CALL_D3D10_BUFFER_ADDREF,
    CALL_D3D10_BUFFER_GETDESC,
    CALL_D3D10_BUFFER_GETEVICTIONPRIORITY,
    CALL_D3D10_BUFFER_GETTYPE,
    CALL_D3D10_BUFFER_MAP,
    CALL_D3D10_BUFFER_RELEASE,
    CALL_D3D10_BUFFER_SETEVICTIONPRIORITY,
    CALL_D3D10_BUFFER_UNMAP,
    CALL_D3D10_DEPTHSTENCIL_STATE_ADDREF,
    CALL_D3D10_DEPTHSTENCIL_STATE_GETDESC,
    CALL_D3D10_DEPTHSTENCIL_STATE_RELEASE,
    CALL_D3D10_DEPTHSTENCIL_VIEW_ADDREF,
    CALL_D3D10_DEPTHSTENCIL_VIEW_GETDESC,
    CALL_D3D10_DEPTHSTENCIL_VIEW_RELEASE,
    CALL_D3D10_DEVICE_CHECKCOUNTER,
    CALL_D3D10_DEVICE_CHECKCOUNTERINFO,
    CALL_D3D10_DEVICE_CHECKFORMATSUPPORT,
    CALL_D3D10_DEVICE_CHECKMULTISAMPLEQUALITYLEVELS,
    CALL_D3D10_DEVICE_CLEARDEPTHSTENCILVIEW,
    CALL_D3D10_DEVICE_CLEARRENDERTARGETVIEW,
    CALL_D3D10_DEVICE_CLEARSTATE,
    CALL_D3D10_DEVICE_COPYRESOURCE,
    CALL_D3D10_DEVICE_COPYSUBRESOURCEREGION,
    CALL_D3D10_DEVICE_CREATECOUNTER,
    CALL_D3D10_DEVICE_DRAW,
    CALL_D3D10_DEVICE_DRAWAUTO,
    CALL_D3D10_DEVICE_DRAWINDEXED,
    CALL_D3D10_DEVICE_DRAWINDEXEDINSTANCED,
    CALL_D3D10_DEVICE_DRAWINSTANCED,
    CALL_D3D10_DEVICE_FLUSH,
    CALL_D3D10_DEVICE_GENERATEMIPS,
    CALL_D3D10_DEVICE_GETCREATIONFLAGS,
    CALL_D3D10_DEVICE_GETDEVICEREMOVEDREASON,
    CALL_D3D10_DEVICE_GETEXCEPTIONMODE,
    CALL_D3D10_DEVICE_GETFEATURELEVEL,
    CALL_D3D10_DEVICE_GETPREDICATION,
    CALL_D3D10_DEVICE_GETTEXTFILTERSIZE,
    CALL_D3D10_DEVICE_GSGETCONSTANTBUFFERS,
    CALL_D3D10_DEVICE_GSGETSAMPLERS,
    CALL_D3D10_DEVICE_GSGETSHADER,
    CALL_D3D10_DEVICE_GSGETSHADERRESOURCES,
    CALL_D3D10_DEVICE_GSSETCONSTANTBUFFERS,
    CALL_D3D10_DEVICE_GSSETSAMPLERS,
    CALL_D3D10_DEVICE_GSSETSHADER,
    CALL_D3D10_DEVICE_GSSETSHADERRESOURCES,
    CALL_D3D10_DEVICE_IAGETINDEXBUFFER,
    CALL_D3D10_DEVICE_IAGETINPUTLAYOUT,
    CALL_D3D10_DEVICE_IAGETPRIMITIVETOPOLOGY,
    CALL_D3D10_DEVICE_IAGETVERTEXBUFFERS,
    CALL_D3D10_DEVICE_IASETINDEXBUFFER,
    CALL_D3D10_DEVICE_IASETINPUTLAYOUT,
    CALL_D3D10_DEVICE_IASETPRIMITIVETOPOLOGY,
    CALL_D3D10_DEVICE_IASETVERTEXBUFFERS,
    CALL_D3D10_DEVICE_OMGETBLENDSTATE,
    CALL_D3D10_DEVICE_OMGETDEPTHSTENCILSTATE,
    CALL_D3D10_DEVICE_OMGETRENDERTARGETS,
    CALL_D3D10_DEVICE_OMSETBLENDSTATE,
    CALL_D3D10_DEVICE_OMSETDEPTHSTENCILSTATE,
    CALL_D3D10_DEVICE_OMSETRENDERTARGETS,
    CALL_D3D10_DEVICE_OPENSHAREDRESOURCE,
    CALL_D3D10_DEVICE_PSGETCONSTANTBUFFERS,
    CALL_D3D10_DEVICE_PSGETSAMPLERS,
    CALL_D3D10_DEVICE_PSGETSHADER,
    CALL_D3D10_DEVICE_PSGETSHADERRESOURCES,
    CALL_D3D10_DEVICE_PSSETCONSTANTBUFFERS,
    CALL_D3D10_DEVICE_PSSETSAMPLERS,
    CALL_D3D10_DEVICE_PSSETSHADER,
    CALL_D3D10_DEVICE_PSSETSHADERRESOURCES,
    CALL_D3D10_DEVICE_RESOLVESUBRESOURCE,
    CALL_D3D10_DEVICE_RSGETSCISSORRECTS,
    CALL_D3D10_DEVICE_RSGETSTATE,
    CALL_D3D10_DEVICE_RSGETVIEWPORTS,
    CALL_D3D10_DEVICE_RSSETSCISSORRECTS,
    CALL_D3D10_DEVICE_RSSETSTATE,
    CALL_D3D10_DEVICE_RSSETVIEWPORTS,
    CALL_D3D10_DEVICE_SETEXCEPTIONMODE,
    CALL_D3D10_DEVICE_SETPREDICATION,
    CALL_D3D10_DEVICE_SETTEXTFILTERSIZE,
    CALL_D3D10_DEVICE_SOGETTARGETS,
    CALL_D3D10_DEVICE_SOSETTARGETS,
    CALL_D3D10_DEVICE_UPDATESUBRESOURCE,
    CALL_D3D10_DEVICE_VSGETCONSTANTBUFFERS,
    CALL_D3D10_DEVICE_VSGETSAMPLERS,
    CALL_D3D10_DEVICE_VSGETSHADER,
    CALL_D3D10_DEVICE_VSGETSHADERRESOURCES,
    CALL_D3D10_DEVICE_VSSETCONSTANTBUFFERS,
    CALL_D3D10_DEVICE_VSSETSAMPLERS,
    CALL_D3D10_DEVICE_VSSETSHADER,
    CALL_D3D10_DEVICE_VSSETSHADERRESOURCES,
    CALL_D3D10_GEOMETRY_SHADER_ADDREF,
    CALL_D3D10_GEOMETRY_SHADER_RELEASE,
    CALL_D3D10_INPUT_LAYOUT_ADDREF,
    CALL_D3D10_INPUT_LAYOUT_GETDEVICE,
    CALL_D3D10_INPUT_LAYOUT_RELEASE,
    CALL_D3D10_MULTITHREAD_ENTER,
    CALL_D3D10_MULTITHREAD_GETMULTITHREADPROTECTED,
    CALL_D3D10_MULTITHREAD_LEAVE,
    CALL_D3D10_MULTITHREAD_SETMULTITHREADPROTECTED,
    CALL_D3D10_PIXEL_SHADER_ADDREF,
    CALL_D3D10_PIXEL_SHADER_RELEASE,
    CALL_D3D10_QUERY_ADDREF,
    CALL_D3D10_QUERY_BEGIN,
    CALL_D3D10_QUERY_END,
    CALL_D3D10_QUERY_GETDATA,
    CALL_D3D10_QUERY_GETDATASIZE,
    CALL_D3D10_QUERY_GETDESC,
    CALL_D3D10_QUERY_RELEASE,
    CALL_D3D10_RASTERIZER_STATE_ADDREF,
    CALL_D3D10_RASTERIZER_STATE_GETDESC,
    CALL_D3D10_RASTERIZER_STATE_RELEASE,
    CALL_D3D10_RENDERTARGET_VIEW_ADDREF,
    CALL_D3D10_RENDERTARGET_VIEW_GETDESC,
    CALL_D3D10_RENDERTARGET_VIEW_RELEASE,
    CALL_D3D10_SAMPLER_STATE_ADDREF,
    CALL_D3D10_SAMPLER_STATE_GETDESC,
    CALL_D3D10_SAMPLER_STATE_RELEASE,
    CALL_D3D10_SHADER_RESOURCE_VIEW_ADDREF,
    CALL_D3D10_SHADER_RESOURCE_VIEW_GETDESC,
    CALL_D3D10_SHADER_RESOURCE_VIEW_GETDESC1,
    CALL_D3D10_SHADER_RESOURCE_VIEW_RELEASE,
    CALL_D3D10_TEXTURE1D_ADDREF,
    CALL_D3D10_TEXTURE1D_GETDESC,
    CALL_D3D10_TEXTURE1D_GETEVICTIONPRIORITY,
    CALL_D3D10_TEXTURE1D_GETTYPE,
    CALL_D3D10_TEXTURE1D_MAP,
    CALL_D3D10_TEXTURE1D_RELEASE,
    CALL_D3D10_TEXTURE1D_SETEVICTIONPRIORITY,
    CALL_D3D10_TEXTURE1D_UNMAP,
    CALL_D3D10_TEXTURE2D_ADDREF,
    CALL_D3D10_TEXTURE2D_GETDESC,
    CALL_D3D10_TEXTURE2D_GETEVICTIONPRIORITY,
    CALL_D3D10_TEXTURE2D_GETTYPE,
    CALL_D3D10_TEXTURE2D_MAP,
    CALL_D3D10_TEXTURE2D_RELEASE,
    CALL_D3D10_TEXTURE2D_SETEVICTIONPRIORITY,
    CALL_D3D10_TEXTURE2D_UNMAP,
    CALL_D3D10_TEXTURE3D_ADDREF,
    CALL_D3D10_TEXTURE3D_GETDESC,
    CALL_D3D10_TEXTURE3D_GETEVICTIONPRIORITY,
    CALL_D3D10_TEXTURE3D_GETTYPE,
    CALL_D3D10_TEXTURE3D_MAP,
    CALL_D3D10_TEXTURE3D_RELEASE,
    CALL_D3D10_TEXTURE3D_SETEVICTIONPRIORITY,
    CALL_D3D10_TEXTURE3D_UNMAP,
    CALL_D3D10_VERTEX_SHADER_ADDREF,
    CALL_D3D10_VERTEX_SHADER_RELEASE,
    CALL_D3D11_BLEND_STATE_ADDREF,
    CALL_D3D11_BLEND_STATE_GETDESC,
    CALL_D3D11_BLEND_STATE_GETDEVICE,
    CALL_D3D11_BLEND_STATE_QUERYINTERFACE,
    CALL_D3D11_BLEND_STATE_RELEASE,
    CALL_D3D11_BUFFER_ADDREF,
    CALL_D3D11_BUFFER_GETDESC,
    CALL_D3D11_BUFFER_GETDEVICE,
    CALL_D3D11_BUFFER_GETEVICTIONPRIORITY,
    CALL_D3D11_BUFFER_GETTYPE,
    CALL_D3D11_BUFFER_QUERYINTERFACE,
    CALL_D3D11_BUFFER_RELEASE,
    CALL_D3D11_BUFFER_SETEVICTIONPRIORITY,
    CALL_D3D11_CLASS_LINKAGE_ADDREF,
    CALL_D3D11_CLASS_LINKAGE_CREATECLASSINSTANCE,
    CALL_D3D11_CLASS_LINKAGE_GETCLASSINSTANCE,
    CALL_D3D11_CLASS_LINKAGE_GETDEVICE,
    CALL_D3D11_CLASS_LINKAGE_QUERYINTERFACE,
    CALL_D3D11_CLASS_LINKAGE_RELEASE,
    CALL_D3D11_COMPUTE_SHADER_ADDREF,
    CALL_D3D11_COMPUTE_SHADER_GETDEVICE,
    CALL_D3D11_COMPUTE_SHADER_QUERYINTERFACE,
    CALL_D3D11_COMPUTE_SHADER_RELEASE,
    CALL_D3D11_DEPTHSTENCIL_STATE_ADDREF,
    CALL_D3D11_DEPTHSTENCIL_STATE_GETDESC,
    CALL_D3D11_DEPTHSTENCIL_STATE_GETDEVICE,
    CALL_D3D11_DEPTHSTENCIL_STATE_QUERYINTERFACE,
    CALL_D3D11_DEPTHSTENCIL_STATE_RELEASE,
    CALL_D3D11_DEPTHSTENCIL_VIEW_ADDREF,
    CALL_D3D11_DEPTHSTENCIL_VIEW_GETDESC,
    CALL_D3D11_DEPTHSTENCIL_VIEW_GETDEVICE,
    CALL_D3D11_DEPTHSTENCIL_VIEW_GETRESOURCE,
    CALL_D3D11_DEPTHSTENCIL_VIEW_QUERYINTERFACE,
    CALL_D3D11_DEPTHSTENCIL_VIEW_RELEASE,
    CALL_D3D11_DEVICE_CHECKCOUNTER,
    CALL_D3D11_DEVICE_CHECKCOUNTERINFO,
    CALL_D3D11_DEVICE_CHECKFEATURESUPPORT,
    CALL_D3D11_DEVICE_CHECKFORMATSUPPORT,
    CALL_D3D11_DEVICE_CHECKMULTISAMPLEQUALITYLEVELS,
    CALL_D3D11_DEVICE_CHECKMULTISAMPLEQUALITYLEVELS1,
    CALL_D3D11_DEVICE_CREATEBLENDSTATE,
    CALL_D3D11_DEVICE_CREATEBLENDSTATE1,
    CALL_D3D11_DEVICE_CREATEBUFFER,
    CALL_D3D11_DEVICE_CREATECLASSLINKAGE,
    CALL_D3D11_DEVICE_CREATECOMPUTESHADER,
    CALL_D3D11_DEVICE_CREATECOUNTER,
    CALL_D3D11_DEVICE_CREATEDEFERREDCONTEXT,
    CALL_D3D11_DEVICE_CREATEDEFERREDCONTEXT1,
    CALL_D3D11_DEVICE_CREATEDEFERREDCONTEXT2,
    CALL_D3D11_DEVICE_CREATEDEPTHSTENCILSTATE,
    CALL_D3D11_DEVICE_CREATEDEPTHSTENCILVIEW,
    CALL_D3D11_DEVICE_CREATEDEVICECONTEXTSTATE,
    CALL_D3D11_DEVICE_CREATEDOMAINSHADER,
    CALL_D3D11_DEVICE_CREATEGEOMETRYSHADER,
    CALL_D3D11_DEVICE_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT,
    CALL_D3D11_DEVICE_CREATEHULLSHADER,
    CALL_D3D11_DEVICE_CREATEINPUTLAYOUT,
    CALL_D3D11_DEVICE_CREATEPIXELSHADER,
    CALL_D3D11_DEVICE_CREATEPREDICATE,
    CALL_D3D11_DEVICE_CREATEQUERY,
    CALL_D3D11_DEVICE_CREATERASTERIZERSTATE,
    CALL_D3D11_DEVICE_CREATERASTERIZERSTATE1,
    CALL_D3D11_DEVICE_CREATERENDERTARGETVIEW,
    CALL_D3D11_DEVICE_CREATESAMPLERSTATE,
    CALL_D3D11_DEVICE_CREATESHADERRESOURCEVIEW,
    CALL_D3D11_DEVICE_CREATETEXTURE1D,
    CALL_D3D11_DEVICE_CREATETEXTURE2D,
    CALL_D3D11_DEVICE_CREATETEXTURE3D,
    CALL_D3D11_DEVICE_CREATEUNORDEREDACCESSVIEW,
    CALL_D3D11_DEVICE_CREATEVERTEXSHADER,
    CALL_D3D11_DEVICE_GETCREATIONFLAGS,
    CALL_D3D11_DEVICE_GETDEVICEREMOVEDREASON,
    CALL_D3D11_DEVICE_GETEXCEPTIONMODE,
    CALL_D3D11_DEVICE_GETFEATURELEVEL,
    CALL_D3D11_DEVICE_GETIMMEDIATECONTEXT,
    CALL_D3D11_DEVICE_GETIMMEDIATECONTEXT1,
    CALL_D3D11_DEVICE_GETIMMEDIATECONTEXT2,
    CALL_D3D11_DEVICE_GETRESOURCETILING,
    CALL_D3D11_DEVICE_OPENSHAREDRESOURCE,
    CALL_D3D11_DEVICE_OPENSHAREDRESOURCE1,
    CALL_D3D11_DEVICE_OPENSHAREDRESOURCEBYNAME,
    CALL_D3D11_DEVICE_SETEXCEPTIONMODE,
    CALL_D3D11_DOMAIN_SHADER_ADDREF,
    CALL_D3D11_DOMAIN_SHADER_GETDEVICE,
    CALL_D3D11_DOMAIN_SHADER_QUERYINTERFACE,
    CALL_D3D11_DOMAIN_SHADER_RELEASE,
    CALL_D3D11_GEOMETRY_SHADER_ADDREF,
    CALL_D3D11_GEOMETRY_SHADER_GETDEVICE,
    CALL_D3D11_GEOMETRY_SHADER_QUERYINTERFACE,
    CALL_D3D11_GEOMETRY_SHADER_RELEASE,
    CALL_D3D11_HULL_SHADER_ADDREF,
    CALL_D3D11_HULL_SHADER_GETDEVICE,
    CALL_D3D11_HULL_SHADER_QUERYINTERFACE,
    CALL_D3D11_HULL_SHADER_RELEASE,
    CALL_D3D11_IMMEDIATE_CONTEXT_ADDREF,
    CALL_D3D11_IMMEDIATE_CONTEXT_BEGIN,
    CALL_D3D11_IMMEDIATE_CONTEXT_CLEARDEPTHSTENCILVIEW,
    CALL_D3D11_IMMEDIATE_CONTEXT_CLEARRENDERTARGETVIEW,
    CALL_D3D11_IMMEDIATE_CONTEXT_CLEARSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_CLEARUNORDEREDACCESSVIEWFLOAT,
    CALL_D3D11_IMMEDIATE_CONTEXT_CLEARUNORDEREDACCESSVIEWUINT,
    CALL_D3D11_IMMEDIATE_CONTEXT_CLEARVIEW,
    CALL_D3D11_IMMEDIATE_CONTEXT_COPYRESOURCE,
    CALL_D3D11_IMMEDIATE_CONTEXT_COPYSTRUCTURECOUNT,
    CALL_D3D11_IMMEDIATE_CONTEXT_COPYSUBRESOURCEREGION,
    CALL_D3D11_IMMEDIATE_CONTEXT_COPYSUBRESOURCEREGION1,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSGETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSGETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSGETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSGETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSGETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSGETUNORDEREDACCESSVIEWS,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSSETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSSETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSSETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSSETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSSETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_CSSETUNORDEREDACCESSVIEWS,
    CALL_D3D11_IMMEDIATE_CONTEXT_DISCARDRESOURCE,
    CALL_D3D11_IMMEDIATE_CONTEXT_DISCARDVIEW,
    CALL_D3D11_IMMEDIATE_CONTEXT_DISCARDVIEW1,
    CALL_D3D11_IMMEDIATE_CONTEXT_DISPATCH,
    CALL_D3D11_IMMEDIATE_CONTEXT_DISPATCHINDIRECT,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAW,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAWAUTO,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAWINDEXED,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAWINDEXEDINSTANCED,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAWINDEXEDINSTANCEDINDIRECT,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAWINSTANCED,
    CALL_D3D11_IMMEDIATE_CONTEXT_DRAWINSTANCEDINDIRECT,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSGETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSGETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSGETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSGETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSGETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSSETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSSETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSSETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSSETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_DSSETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_END,
    CALL_D3D11_IMMEDIATE_CONTEXT_EXECUTECOMMANDLIST,
    CALL_D3D11_IMMEDIATE_CONTEXT_FINISHCOMMANDLIST,
    CALL_D3D11_IMMEDIATE_CONTEXT_FLUSH,
    CALL_D3D11_IMMEDIATE_CONTEXT_GENERATEMIPS,
    CALL_D3D11_IMMEDIATE_CONTEXT_GETCONTEXTFLAGS,
    CALL_D3D11_IMMEDIATE_CONTEXT_GETDATA,
    CALL_D3D11_IMMEDIATE_CONTEXT_GETDEVICE,
    CALL_D3D11_IMMEDIATE_CONTEXT_GETPREDICATION,
    CALL_D3D11_IMMEDIATE_CONTEXT_GETRESOURCEMINLOD,
    CALL_D3D11_IMMEDIATE_CONTEXT_GETTYPE,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSGETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSGETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSGETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSGETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSGETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSSETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSSETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSSETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSSETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_GSSETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSGETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSGETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSGETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSGETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSGETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSSETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSSETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSSETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSSETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_HSSETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_IAGETINDEXBUFFER,
    CALL_D3D11_IMMEDIATE_CONTEXT_IAGETINPUTLAYOUT,
    CALL_D3D11_IMMEDIATE_CONTEXT_IAGETPRIMITIVETOPOLOGY,
    CALL_D3D11_IMMEDIATE_CONTEXT_IAGETVERTEXBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_IASETINDEXBUFFER,
    CALL_D3D11_IMMEDIATE_CONTEXT_IASETINPUTLAYOUT,
    CALL_D3D11_IMMEDIATE_CONTEXT_IASETPRIMITIVETOPOLOGY,
    CALL_D3D11_IMMEDIATE_CONTEXT_IASETVERTEXBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_MAP,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMGETBLENDSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMGETDEPTHSTENCILSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMGETRENDERTARGETS,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMGETRENDERTARGETSANDUNORDEREDACCESSVIEWS,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMSETBLENDSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMSETDEPTHSTENCILSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMSETRENDERTARGETS,
    CALL_D3D11_IMMEDIATE_CONTEXT_OMSETRENDERTARGETSANDUNORDEREDACCESSVIEWS,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSGETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSGETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSGETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSGETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSGETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSSETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSSETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSSETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSSETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_PSSETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_QUERYINTERFACE,
    CALL_D3D11_IMMEDIATE_CONTEXT_RELEASE,
    CALL_D3D11_IMMEDIATE_CONTEXT_RESOLVESUBRESOURCE,
    CALL_D3D11_IMMEDIATE_CONTEXT_RSGETSCISSORRECTS,
    CALL_D3D11_IMMEDIATE_CONTEXT_RSGETSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_RSGETVIEWPORTS,
    CALL_D3D11_IMMEDIATE_CONTEXT_RSSETSCISSORRECTS,
    CALL_D3D11_IMMEDIATE_CONTEXT_RSSETSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_RSSETVIEWPORTS,
    CALL_D3D11_IMMEDIATE_CONTEXT_SETPREDICATION,
    CALL_D3D11_IMMEDIATE_CONTEXT_SETRESOURCEMINLOD,
    CALL_D3D11_IMMEDIATE_CONTEXT_SOGETTARGETS,
    CALL_D3D11_IMMEDIATE_CONTEXT_SOSETTARGETS,
    CALL_D3D11_IMMEDIATE_CONTEXT_SWAPDEVICECONTEXTSTATE,
    CALL_D3D11_IMMEDIATE_CONTEXT_UNMAP,
    CALL_D3D11_IMMEDIATE_CONTEXT_UPDATESUBRESOURCE,
    CALL_D3D11_IMMEDIATE_CONTEXT_UPDATESUBRESOURCE1,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSGETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSGETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSGETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSGETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSGETSHADERRESOURCES,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSSETCONSTANTBUFFERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSSETCONSTANTBUFFERS1,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSSETSAMPLERS,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSSETSHADER,
    CALL_D3D11_IMMEDIATE_CONTEXT_VSSETSHADERRESOURCES,
    CALL_D3D11_INPUT_LAYOUT_ADDREF,
    CALL_D3D11_INPUT_LAYOUT_GETDEVICE,
    CALL_D3D11_INPUT_LAYOUT_QUERYINTERFACE,
    CALL_D3D11_INPUT_LAYOUT_RELEASE,
    CALL_D3D11_PIXEL_SHADER_ADDREF,
    CALL_D3D11_PIXEL_SHADER_GETDEVICE,
    CALL_D3D11_PIXEL_SHADER_QUERYINTERFACE,
    CALL_D3D11_PIXEL_SHADER_RELEASE,
    CALL_D3D11_QUERY_ADDREF,
    CALL_D3D11_QUERY_GETDATASIZE,
    CALL_D3D11_QUERY_GETDESC,
    CALL_D3D11_QUERY_GETDEVICE,
    CALL_D3D11_QUERY_QUERYINTERFACE,
    CALL_D3D11_QUERY_RELEASE,
    CALL_D3D11_RASTERIZER_STATE_ADDREF,
    CALL_D3D11_RASTERIZER_STATE_GETDESC,
    CALL_D3D11_RASTERIZER_STATE_GETDEVICE,
    CALL_D3D11_RASTERIZER_STATE_QUERYINTERFACE,
    CALL_D3D11_RASTERIZER_STATE_RELEASE,
    CALL_D3D11_RENDERTARGET_VIEW_ADDREF,
    CALL_D3D11_RENDERTARGET_VIEW_GETDESC,
    CALL_D3D11_RENDERTARGET_VIEW_GETDEVICE,
    CALL_D3D11_RENDERTARGET_VIEW_GETRESOURCE,
    CALL_D3D11_RENDERTARGET_VIEW_QUERYINTERFACE,
    CALL_D3D11_RENDERTARGET_VIEW_RELEASE,
    CALL_D3D11_SAMPLER_STATE_ADDREF,
    CALL_D3D11_SAMPLER_STATE_GETDESC,
    CALL_D3D11_SAMPLER_STATE_GETDEVICE,
    CALL_D3D11_SAMPLER_STATE_QUERYINTERFACE,
    CALL_D3D11_SAMPLER_STATE_RELEASE,
    CALL_D3D11_SHADER_RESOURCE_VIEW_ADDREF,
    CALL_D3D11_SHADER_RESOURCE_VIEW_GETDESC,
    CALL_D3D11_SHADER_RESOURCE_VIEW_GETDEVICE,
    CALL_D3D11_SHADER_RESOURCE_VIEW_GETRESOURCE,
    CALL_D3D11_SHADER_RESOURCE_VIEW_QUERYINTERFACE,
    CALL_D3D11_SHADER_RESOURCE_VIEW_RELEASE,
    CALL_D3D11_TEXTURE1D_ADDREF,
    CALL_D3D11_TEXTURE1D_GETDESC,
    CALL_D3D11_TEXTURE1D_GETDEVICE,
    CALL_D3D11_TEXTURE1D_GETEVICTIONPRIORITY,
    CALL_D3D11_TEXTURE1D_GETTYPE,
    CALL_D3D11_TEXTURE1D_QUERYINTERFACE,
    CALL_D3D11_TEXTURE1D_RELEASE,
    CALL_D3D11_TEXTURE1D_SETEVICTIONPRIORITY,
    CALL_D3D11_TEXTURE2D_ADDREF,
    CALL_D3D11_TEXTURE2D_GETDESC,
    CALL_D3D11_TEXTURE2D_GETDEVICE,
    CALL_D3D11_TEXTURE2D_GETEVICTIONPRIORITY,
    CALL_D3D11_TEXTURE2D_GETTYPE,
    CALL_D3D11_TEXTURE2D_QUERYINTERFACE,
    CALL_D3D11_TEXTURE2D_RELEASE,
    CALL_D3D11_TEXTURE2D_SETEVICTIONPRIORITY,
    CALL_D3D11_TEXTURE3D_ADDREF,
    CALL_D3D11_TEXTURE3D_GETDESC,
    CALL_D3D11_TEXTURE3D_GETDEVICE,
    CALL_D3D11_TEXTURE3D_GETEVICTIONPRIORITY,
    CALL_D3D11_TEXTURE3D_GETTYPE,
    CALL_D3D11_TEXTURE3D_QUERYINTERFACE,
    CALL_D3D11_TEXTURE3D_RELEASE,
    CALL_D3D11_TEXTURE3D_SETEVICTIONPRIORITY,
    CALL_D3D11_UNORDERED_ACCESS_VIEW_ADDREF,
    CALL_D3D11_UNORDERED_ACCESS_VIEW_GETDESC,
    CALL_D3D11_UNORDERED_ACCESS_VIEW_GETDEVICE,
    CALL_D3D11_UNORDERED_ACCESS_VIEW_GETRESOURCE,
    CALL_D3D11_UNORDERED_ACCESS_VIEW_QUERYINTERFACE,
    CALL_D3D11_UNORDERED_ACCESS_VIEW_RELEASE,
    CALL_D3D11_VERTEX_SHADER_ADDREF,
    CALL_D3D11_VERTEX_SHADER_GETDEVICE,
    CALL_D3D11_VERTEX_SHADER_QUERYINTERFACE,
    CALL_D3D11_VERTEX_SHADER_RELEASE,
    CALL_D3D_DEVICE_INNER_ADDREF,
    CALL_D3D_DEVICE_INNER_QUERYINTERFACE,
    CALL_D3D_DEVICE_INNER_RELEASE,
    CALL_INIT_DLL,
    CALL_LAYER_CREATE,
    CALL_LAYER_GET_SIZE,
    CALL_WRAP_IMPLICIT_SURFACE,
};

#define MAX_CONSTANT_BUFFERS        15
#define MAX_STREAMS                 16

#ifdef QEMU_DLL_GUEST

typedef ID3D11Device ID3D11Device2;
typedef ID3D11DeviceContext ID3D11DeviceContext1;
typedef ID3D11BlendState ID3D11BlendState1;
typedef ID3D11RasterizerState ID3D11RasterizerState1;
typedef ID3D11DeviceContext1 ID3D11DeviceContext2;
typedef void ID3DDeviceContextState;
typedef void D3D11_BLEND_DESC1, D3D11_RASTERIZER_DESC1;
typedef void D3D11_PACKED_MIP_DESC, D3D11_TILE_SHAPE, D3D11_SUBRESOURCE_TILING;

#endif

struct qemu_d3d11_device_context
{
    /* Guest fields */
    ID3D11DeviceContext1 ID3D11DeviceContext1_iface;
    struct wined3d_private_store private_store;

    /* Host fields */
    ID3D11DeviceContext1 *host;
};

struct qemu_d3d11_device
{
    /* Guest fields */
    IUnknown IUnknown_inner;
    ID3D11Device2 ID3D11Device2_iface;
    ID3D10Device1 ID3D10Device1_iface;
    ID3D10Multithread ID3D10Multithread_iface;
    IQemuD3D11Device IQemuD3D11Device_iface;
    IUnknown *outer_unk;

    /* Host fields */
    ID3D11Device2 *host_d3d11;
    ID3D10Device1 *host_d3d10;
    ID3D10Multithread *host_mt;
    struct qemu_d3d11_device_context immediate_context;
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_texture
{
    /* Guest fields */
    union
    {
        ID3D11Texture1D ID3D11Texture1D_iface;
        ID3D11Texture2D ID3D11Texture2D_iface;
        ID3D11Texture3D ID3D11Texture3D_iface;
    };
    union
    {
        ID3D10Texture1D ID3D10Texture1D_iface;
        ID3D10Texture2D ID3D10Texture2D_iface;
        ID3D10Texture3D ID3D10Texture3D_iface;
    };

    IUnknown *dxgi_surface;
    struct wined3d_private_store private_store;

    /* Host fields */
    union
    {
        ID3D11Texture1D *host11_1d;
        ID3D11Texture2D *host11_2d;
        ID3D11Texture3D *host11_3d;
    };
    union
    {
        ID3D10Texture1D *host10_1d;
        ID3D10Texture2D *host10_2d;
        ID3D10Texture3D *host10_3d;
    };
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_buffer
{
    /* Guest fields */
    ID3D11Buffer ID3D11Buffer_iface;
    ID3D10Buffer ID3D10Buffer_iface;
    struct wined3d_private_store private_store;

    /* Host fields */
    ID3D11Buffer *host11;
    ID3D10Buffer *host10;
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_view
{
    /* Guest fields */
    union
    {
        ID3D11DepthStencilView ID3D11DepthStencilView_iface;
        ID3D11RenderTargetView ID3D11RenderTargetView_iface;
        ID3D11ShaderResourceView ID3D11ShaderResourceView_iface;
        ID3D11UnorderedAccessView ID3D11UnorderedAccessView_iface;
    };
    union
    {
        ID3D10DepthStencilView ID3D10DepthStencilView_iface;
        ID3D10RenderTargetView ID3D10RenderTargetView_iface;
        ID3D10ShaderResourceView1 ID3D10ShaderResourceView1_iface;
    };

    struct wined3d_private_store private_store;

    /* Host fields */
    union
    {
        ID3D11DepthStencilView *host_ds11;
        ID3D11RenderTargetView *host_rt11;
        ID3D11ShaderResourceView *host_sr11;
        ID3D11UnorderedAccessView *host_uav;
    };
    union
    {
        ID3D10DepthStencilView *host_ds10;
        ID3D10RenderTargetView *host_rt10;
        ID3D10ShaderResourceView1 *host_sr10;
    };
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_shader
{
    /* Guest fields */
    union
    {
        ID3D11VertexShader ID3D11VertexShader_iface;
        ID3D11HullShader ID3D11HullShader_iface;
        ID3D11DomainShader ID3D11DomainShader_iface;
        ID3D11GeometryShader ID3D11GeometryShader_iface;
        ID3D11PixelShader ID3D11PixelShader_iface;
        ID3D11ComputeShader ID3D11ComputeShader_iface;
    };
    union
    {
        ID3D10VertexShader ID3D10VertexShader_iface;
        ID3D10PixelShader ID3D10PixelShader_iface;
        ID3D10GeometryShader ID3D10GeometryShader_iface;
    };

    struct wined3d_private_store private_store;

    /* Host fields */
    union
    {
        ID3D11VertexShader *host_vs11;
        ID3D11HullShader *host_hs11;
        ID3D11DomainShader *host_ds11;
        ID3D11GeometryShader *host_gs11;
        ID3D11PixelShader *host_ps11;
        ID3D11ComputeShader *host_cs11;
    };
    union
    {
        ID3D10VertexShader *host_vs10;
        ID3D10PixelShader *host_ps10;
        ID3D10GeometryShader *host_gs10;
    };
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_class_linkage
{
    /* Guest fields */
    ID3D11ClassLinkage ID3D11ClassLinkage_iface;
    struct wined3d_private_store private_store;

    /* Host fields */
    ID3D11ClassLinkage *host;
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_state
{
    /* Guest fields */
    union
    {
        ID3D11BlendState ID3D11BlendState_iface;
        ID3D11DepthStencilState ID3D11DepthStencilState_iface;
        ID3D11RasterizerState ID3D11RasterizerState_iface;
        ID3D11SamplerState ID3D11SamplerState_iface;
    };
    union
    {
        ID3D10BlendState1 ID3D10BlendState1_iface;
        ID3D10DepthStencilState ID3D10DepthStencilState_iface;
        ID3D10RasterizerState ID3D10RasterizerState_iface;
        ID3D10SamplerState ID3D10SamplerState_iface;
    };

    struct wined3d_private_store private_store;

    /* Host fields */
    union
    {
        ID3D11BlendState *host_bs11;
        ID3D11DepthStencilState *host_ds11;
        ID3D11RasterizerState *host_rs11;
        ID3D11SamplerState *host_ss11;
    };
    union
    {
        ID3D10BlendState1 *host_bs10;
        ID3D10DepthStencilState *host_ds10;
        ID3D10RasterizerState *host_rs10;
        ID3D10SamplerState *host_ss10;
    };
    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_query
{
    /* Guest fields */
    ID3D11Query ID3D11Query_iface;
    ID3D10Query ID3D10Query_iface;

    struct wined3d_private_store private_store;

    /* Host fields */
    ID3D11Query *host11;
    ID3D10Query *host10;

    IUnknown priv_data_iface;
    ULONG refcount;
};

struct qemu_d3d11_input_layout
{
    /* Guest fields */
    ID3D11InputLayout ID3D11InputLayout_iface;
    ID3D10InputLayout ID3D10InputLayout_iface;
    struct wined3d_private_store private_store;

    /* Host fields */
    ID3D11InputLayout *host11;
    ID3D10InputLayout *host10;

    IUnknown priv_data_iface;
    ULONG refcount;
};

#ifdef QEMU_DLL_GUEST

enum D3D11_USAGE d3d11_usage_from_d3d10_usage(enum D3D10_USAGE usage);
UINT d3d11_bind_flags_from_d3d10_bind_flags(UINT bind_flags);
UINT d3d11_cpu_access_flags_from_d3d10_cpu_access_flags(UINT cpu_access_flags);
UINT d3d11_resource_misc_flags_from_d3d10_resource_misc_flags(UINT resource_misc_flags);

static inline struct qemu_d3d11_device *impl_from_ID3D11Device2(ID3D11Device2 *iface)
{
    return CONTAINING_RECORD(iface, struct qemu_d3d11_device, ID3D11Device2_iface);
}

static inline struct qemu_d3d11_device *impl_from_ID3D10Device(ID3D10Device1 *iface)
{
    return CONTAINING_RECORD(iface, struct qemu_d3d11_device, ID3D10Device1_iface);
}

struct qemu_d3d11_buffer *unsafe_impl_from_ID3D11Buffer(ID3D11Buffer *iface);
struct qemu_d3d11_buffer *unsafe_impl_from_ID3D10Buffer(ID3D10Buffer *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D11DepthStencilView(ID3D11DepthStencilView *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D10DepthStencilView(ID3D10DepthStencilView *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D11RenderTargetView(ID3D11RenderTargetView *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D10RenderTargetView(ID3D10RenderTargetView *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D11ShaderResourceView(ID3D11ShaderResourceView *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D10ShaderResourceView(ID3D10ShaderResourceView *iface);
struct qemu_d3d11_view *unsafe_impl_from_ID3D11UnorderedAccessView(ID3D11UnorderedAccessView *iface);
struct qemu_d3d11_texture *unsafe_impl_from_ID3D11Texture1D(ID3D11Texture1D *iface);
struct qemu_d3d11_texture *unsafe_impl_from_ID3D10Texture1D(ID3D10Texture1D *iface);
struct qemu_d3d11_texture *unsafe_impl_from_ID3D11Texture2D(ID3D11Texture2D *iface);
struct qemu_d3d11_texture *unsafe_impl_from_ID3D10Texture2D(ID3D10Texture2D *iface);
struct qemu_d3d11_texture *unsafe_impl_from_ID3D10Texture3D(ID3D10Texture3D *iface);
struct qemu_d3d11_texture *unsafe_impl_from_ID3D11Texture3D(ID3D11Texture3D *iface);
struct qemu_d3d11_query *unsafe_impl_from_ID3D11Query(ID3D11Query *iface);
struct qemu_d3d11_query *unsafe_impl_from_ID3D10Query(ID3D10Query *iface);
struct qemu_d3d11_query *unsafe_impl_from_ID3D11Asynchronous(ID3D11Asynchronous *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D11VertexShader(ID3D11VertexShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D10VertexShader(ID3D10VertexShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D11HullShader(ID3D11HullShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D11DomainShader(ID3D11DomainShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D11GeometryShader(ID3D11GeometryShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D10GeometryShader(ID3D10GeometryShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D11PixelShader(ID3D11PixelShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D10PixelShader(ID3D10PixelShader *iface);
struct qemu_d3d11_shader *unsafe_impl_from_ID3D11ComputeShader(ID3D11ComputeShader *iface);
struct qemu_d3d11_input_layout *unsafe_impl_from_ID3D11InputLayout(ID3D11InputLayout *iface);
struct qemu_d3d11_input_layout *unsafe_impl_from_ID3D10InputLayout(ID3D10InputLayout *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D11BlendState(ID3D11BlendState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D10BlendState(ID3D10BlendState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D11DepthStencilState(ID3D11DepthStencilState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D10DepthStencilState(ID3D10DepthStencilState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D11RasterizerState(ID3D11RasterizerState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D10RasterizerState(ID3D10RasterizerState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D11SamplerState(ID3D11SamplerState *iface);
struct qemu_d3d11_state *unsafe_impl_from_ID3D10SamplerState(ID3D10SamplerState *iface);

extern HRESULT (* WINAPI p_DXGID3D10CreateDevice)(HMODULE d3d10core, IDXGIFactory *factory, IDXGIAdapter *adapter,
        unsigned int flags, const D3D_FEATURE_LEVEL *feature_levels, unsigned int level_count, void **device);

void qemu_d3d11_device_guest_init(struct qemu_d3d11_device *device, void *outer_unknown);
void qemu_d3d11_context_guest_init(struct qemu_d3d11_device_context *context);
void qemu_d3d11_texture_guest_init(struct qemu_d3d11_texture *texture, struct qemu_d3d11_device *device,
        unsigned int dim, uint64_t dxgi_surface);
void qemu_d3d11_buffer_guest_init(struct qemu_d3d11_buffer *buffer);
void qemu_d3d11_depth_stencil_view_guest_init(struct qemu_d3d11_view *view);
void qemu_d3d11_shader_resource_view_guest_init(struct qemu_d3d11_view *view);
void qemu_d3d11_render_target_view_guest_init(struct qemu_d3d11_view *view);
void qemu_d3d11_unordered_access_view_guest_init(struct qemu_d3d11_view *view);
void qemu_d3d11_pixel_shader_guest_init(struct qemu_d3d11_shader *shader);
void qemu_d3d11_vertex_shader_guest_init(struct qemu_d3d11_shader *shader);
void qemu_d3d11_geometry_shader_guest_init(struct qemu_d3d11_shader *shader);
void qemu_d3d11_hull_shader_guest_init(struct qemu_d3d11_shader *shader);
void qemu_d3d11_domain_shader_guest_init(struct qemu_d3d11_shader *shader);
void qemu_d3d11_compute_shader_guest_init(struct qemu_d3d11_shader *shader);
void qemu_d3d11_sampler_state_guest_init(struct qemu_d3d11_state *state);
void qemu_d3d11_blend_state_guest_init(struct qemu_d3d11_state *state);
void qemu_d3d11_depthstencil_state_guest_init(struct qemu_d3d11_state *state);
void qemu_d3d11_rasterizer_state_guest_init(struct qemu_d3d11_state *state);
void qemu_d3d11_query_guest_init(struct qemu_d3d11_query *view);
void qemu_d3d11_input_layout_guest_init(struct qemu_d3d11_input_layout *layout);

HRESULT d3d_get_private_data(struct wined3d_private_store *store,
        REFGUID guid, UINT *data_size, void *data);
HRESULT d3d_set_private_data(struct wined3d_private_store *store,
        REFGUID guid, UINT data_size, const void *data);
HRESULT d3d_set_private_data_interface(struct wined3d_private_store *store,
        REFGUID guid, const IUnknown *object);

void __fastcall d3d11_device_context_guest_destroy(struct qemu_d3d11_device_context *);
void __fastcall d3d11_texture_guest_destroy(struct qemu_d3d11_texture *);
void __fastcall d3d11_buffer_guest_destroy(struct qemu_d3d11_buffer *);
void __fastcall d3d11_view_guest_destroy(struct qemu_d3d11_view *);
void __fastcall d3d11_shader_guest_destroy(struct qemu_d3d11_shader *);
void __fastcall d3d11_class_linkage_guest_destroy(struct qemu_d3d11_class_linkage *);
void __fastcall d3d11_state_guest_destroy(struct qemu_d3d11_state *);
void __fastcall d3d11_query_guest_destroy(struct qemu_d3d11_query *);
void __fastcall d3d11_input_layout_guest_destroy(struct qemu_d3d11_input_layout *);

#else

extern const struct qemu_ops *qemu_ops;

void qemu_d3d10_blend_state_AddRef(struct qemu_syscall *call);
void qemu_d3d10_blend_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_blend_state_GetDesc1(struct qemu_syscall *call);
void qemu_d3d10_blend_state_Release(struct qemu_syscall *call);
void qemu_d3d10_buffer_AddRef(struct qemu_syscall *call);
void qemu_d3d10_buffer_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_buffer_GetDevice(struct qemu_syscall *call);
void qemu_d3d10_buffer_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_buffer_GetType(struct qemu_syscall *call);
void qemu_d3d10_buffer_Map(struct qemu_syscall *call);
void qemu_d3d10_buffer_Release(struct qemu_syscall *call);
void qemu_d3d10_buffer_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_buffer_Unmap(struct qemu_syscall *call);
void qemu_d3d10_depthstencil_state_AddRef(struct qemu_syscall *call);
void qemu_d3d10_depthstencil_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_depthstencil_state_Release(struct qemu_syscall *call);
void qemu_d3d10_depthstencil_view_AddRef(struct qemu_syscall *call);
void qemu_d3d10_depthstencil_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_depthstencil_view_Release(struct qemu_syscall *call);
void qemu_d3d10_device_CheckCounter(struct qemu_syscall *call);
void qemu_d3d10_device_CheckCounterInfo(struct qemu_syscall *call);
void qemu_d3d10_device_CheckFormatSupport(struct qemu_syscall *call);
void qemu_d3d10_device_CheckMultisampleQualityLevels(struct qemu_syscall *call);
void qemu_d3d10_device_ClearDepthStencilView(struct qemu_syscall *call);
void qemu_d3d10_device_ClearRenderTargetView(struct qemu_syscall *call);
void qemu_d3d10_device_ClearState(struct qemu_syscall *call);
void qemu_d3d10_device_CopyResource(struct qemu_syscall *call);
void qemu_d3d10_device_CopySubresourceRegion(struct qemu_syscall *call);
void qemu_d3d10_device_CreateCounter(struct qemu_syscall *call);
void qemu_d3d10_device_CreateShaderResourceView1(struct qemu_syscall *call);
void qemu_d3d10_device_Draw(struct qemu_syscall *call);
void qemu_d3d10_device_DrawAuto(struct qemu_syscall *call);
void qemu_d3d10_device_DrawIndexed(struct qemu_syscall *call);
void qemu_d3d10_device_DrawIndexedInstanced(struct qemu_syscall *call);
void qemu_d3d10_device_DrawInstanced(struct qemu_syscall *call);
void qemu_d3d10_device_Flush(struct qemu_syscall *call);
void qemu_d3d10_device_GSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_GSGetSamplers(struct qemu_syscall *call);
void qemu_d3d10_device_GSGetShader(struct qemu_syscall *call);
void qemu_d3d10_device_GSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d10_device_GSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_GSSetSamplers(struct qemu_syscall *call);
void qemu_d3d10_device_GSSetShader(struct qemu_syscall *call);
void qemu_d3d10_device_GSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d10_device_GenerateMips(struct qemu_syscall *call);
void qemu_d3d10_device_GetCreationFlags(struct qemu_syscall *call);
void qemu_d3d10_device_GetDeviceRemovedReason(struct qemu_syscall *call);
void qemu_d3d10_device_GetExceptionMode(struct qemu_syscall *call);
void qemu_d3d10_device_GetFeatureLevel(struct qemu_syscall *call);
void qemu_d3d10_device_GetPredication(struct qemu_syscall *call);
void qemu_d3d10_device_GetTextFilterSize(struct qemu_syscall *call);
void qemu_d3d10_device_IAGetIndexBuffer(struct qemu_syscall *call);
void qemu_d3d10_device_IAGetInputLayout(struct qemu_syscall *call);
void qemu_d3d10_device_IAGetPrimitiveTopology(struct qemu_syscall *call);
void qemu_d3d10_device_IAGetVertexBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_IASetIndexBuffer(struct qemu_syscall *call);
void qemu_d3d10_device_IASetInputLayout(struct qemu_syscall *call);
void qemu_d3d10_device_IASetPrimitiveTopology(struct qemu_syscall *call);
void qemu_d3d10_device_IASetVertexBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_OMGetBlendState(struct qemu_syscall *call);
void qemu_d3d10_device_OMGetDepthStencilState(struct qemu_syscall *call);
void qemu_d3d10_device_OMGetRenderTargets(struct qemu_syscall *call);
void qemu_d3d10_device_OMSetBlendState(struct qemu_syscall *call);
void qemu_d3d10_device_OMSetDepthStencilState(struct qemu_syscall *call);
void qemu_d3d10_device_OMSetRenderTargets(struct qemu_syscall *call);
void qemu_d3d10_device_OpenSharedResource(struct qemu_syscall *call);
void qemu_d3d10_device_PSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_PSGetSamplers(struct qemu_syscall *call);
void qemu_d3d10_device_PSGetShader(struct qemu_syscall *call);
void qemu_d3d10_device_PSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d10_device_PSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_PSSetSamplers(struct qemu_syscall *call);
void qemu_d3d10_device_PSSetShader(struct qemu_syscall *call);
void qemu_d3d10_device_PSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d10_device_RSGetScissorRects(struct qemu_syscall *call);
void qemu_d3d10_device_RSGetState(struct qemu_syscall *call);
void qemu_d3d10_device_RSGetViewports(struct qemu_syscall *call);
void qemu_d3d10_device_RSSetScissorRects(struct qemu_syscall *call);
void qemu_d3d10_device_RSSetState(struct qemu_syscall *call);
void qemu_d3d10_device_RSSetViewports(struct qemu_syscall *call);
void qemu_d3d10_device_ResolveSubresource(struct qemu_syscall *call);
void qemu_d3d10_device_SOGetTargets(struct qemu_syscall *call);
void qemu_d3d10_device_SOSetTargets(struct qemu_syscall *call);
void qemu_d3d10_device_SetExceptionMode(struct qemu_syscall *call);
void qemu_d3d10_device_SetPredication(struct qemu_syscall *call);
void qemu_d3d10_device_SetTextFilterSize(struct qemu_syscall *call);
void qemu_d3d10_device_UpdateSubresource(struct qemu_syscall *call);
void qemu_d3d10_device_VSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_VSGetSamplers(struct qemu_syscall *call);
void qemu_d3d10_device_VSGetShader(struct qemu_syscall *call);
void qemu_d3d10_device_VSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d10_device_VSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d10_device_VSSetSamplers(struct qemu_syscall *call);
void qemu_d3d10_device_VSSetShader(struct qemu_syscall *call);
void qemu_d3d10_device_VSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d10_geometry_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d10_geometry_shader_Release(struct qemu_syscall *call);
void qemu_d3d10_input_layout_AddRef(struct qemu_syscall *call);
void qemu_d3d10_input_layout_GetDevice(struct qemu_syscall *call);
void qemu_d3d10_input_layout_Release(struct qemu_syscall *call);
void qemu_d3d10_multithread_Enter(struct qemu_syscall *call);
void qemu_d3d10_multithread_GetMultithreadProtected(struct qemu_syscall *call);
void qemu_d3d10_multithread_Leave(struct qemu_syscall *call);
void qemu_d3d10_multithread_SetMultithreadProtected(struct qemu_syscall *call);
void qemu_d3d10_pixel_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d10_pixel_shader_Release(struct qemu_syscall *call);
void qemu_d3d10_query_AddRef(struct qemu_syscall *call);
void qemu_d3d10_query_Begin(struct qemu_syscall *call);
void qemu_d3d10_query_End(struct qemu_syscall *call);
void qemu_d3d10_query_GetData(struct qemu_syscall *call);
void qemu_d3d10_query_GetDataSize(struct qemu_syscall *call);
void qemu_d3d10_query_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_query_Release(struct qemu_syscall *call);
void qemu_d3d10_rasterizer_state_AddRef(struct qemu_syscall *call);
void qemu_d3d10_rasterizer_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_rasterizer_state_Release(struct qemu_syscall *call);
void qemu_d3d10_rendertarget_view_AddRef(struct qemu_syscall *call);
void qemu_d3d10_rendertarget_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_rendertarget_view_Release(struct qemu_syscall *call);
void qemu_d3d10_sampler_state_AddRef(struct qemu_syscall *call);
void qemu_d3d10_sampler_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_sampler_state_Release(struct qemu_syscall *call);
void qemu_d3d10_shader_resource_view_AddRef(struct qemu_syscall *call);
void qemu_d3d10_shader_resource_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_shader_resource_view_GetDesc1(struct qemu_syscall *call);
void qemu_d3d10_shader_resource_view_Release(struct qemu_syscall *call);
void qemu_d3d10_texture1d_AddRef(struct qemu_syscall *call);
void qemu_d3d10_texture1d_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_texture1d_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_texture1d_GetType(struct qemu_syscall *call);
void qemu_d3d10_texture1d_Map(struct qemu_syscall *call);
void qemu_d3d10_texture1d_Release(struct qemu_syscall *call);
void qemu_d3d10_texture1d_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_texture1d_Unmap(struct qemu_syscall *call);
void qemu_d3d10_texture2d_AddRef(struct qemu_syscall *call);
void qemu_d3d10_texture2d_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_texture2d_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_texture2d_GetType(struct qemu_syscall *call);
void qemu_d3d10_texture2d_Map(struct qemu_syscall *call);
void qemu_d3d10_texture2d_Release(struct qemu_syscall *call);
void qemu_d3d10_texture2d_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_texture2d_Unmap(struct qemu_syscall *call);
void qemu_d3d10_texture3d_AddRef(struct qemu_syscall *call);
void qemu_d3d10_texture3d_GetDesc(struct qemu_syscall *call);
void qemu_d3d10_texture3d_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_texture3d_GetType(struct qemu_syscall *call);
void qemu_d3d10_texture3d_Map(struct qemu_syscall *call);
void qemu_d3d10_texture3d_Release(struct qemu_syscall *call);
void qemu_d3d10_texture3d_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d10_texture3d_Unmap(struct qemu_syscall *call);
void qemu_d3d10_vertex_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d10_vertex_shader_Release(struct qemu_syscall *call);
void qemu_d3d11_blend_state_AddRef(struct qemu_syscall *call);
void qemu_d3d11_blend_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_blend_state_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_blend_state_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_blend_state_Release(struct qemu_syscall *call);
void qemu_d3d11_buffer_AddRef(struct qemu_syscall *call);
void qemu_d3d11_buffer_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_buffer_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_buffer_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_buffer_GetType(struct qemu_syscall *call);
void qemu_d3d11_buffer_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_buffer_Release(struct qemu_syscall *call);
void qemu_d3d11_buffer_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_class_linkage_AddRef(struct qemu_syscall *call);
void qemu_d3d11_class_linkage_CreateClassInstance(struct qemu_syscall *call);
void qemu_d3d11_class_linkage_GetClassInstance(struct qemu_syscall *call);
void qemu_d3d11_class_linkage_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_class_linkage_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_class_linkage_Release(struct qemu_syscall *call);
void qemu_d3d11_compute_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d11_compute_shader_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_compute_shader_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_compute_shader_Release(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_state_AddRef(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_state_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_state_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_state_Release(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_view_AddRef(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_view_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_view_GetResource(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_view_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_depthstencil_view_Release(struct qemu_syscall *call);
void qemu_d3d11_device_CheckCounter(struct qemu_syscall *call);
void qemu_d3d11_device_CheckCounterInfo(struct qemu_syscall *call);
void qemu_d3d11_device_CheckFeatureSupport(struct qemu_syscall *call);
void qemu_d3d11_device_CheckFormatSupport(struct qemu_syscall *call);
void qemu_d3d11_device_CheckMultisampleQualityLevels(struct qemu_syscall *call);
void qemu_d3d11_device_CheckMultisampleQualityLevels1(struct qemu_syscall *call);
void qemu_d3d11_device_CreateBlendState(struct qemu_syscall *call);
void qemu_d3d11_device_CreateBlendState1(struct qemu_syscall *call);
void qemu_d3d11_device_CreateBuffer(struct qemu_syscall *call);
void qemu_d3d11_device_CreateClassLinkage(struct qemu_syscall *call);
void qemu_d3d11_device_CreateComputeShader(struct qemu_syscall *call);
void qemu_d3d11_device_CreateCounter(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDeferredContext(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDeferredContext1(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDeferredContext2(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDepthStencilState(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDepthStencilView(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDeviceContextState(struct qemu_syscall *call);
void qemu_d3d11_device_CreateDomainShader(struct qemu_syscall *call);
void qemu_d3d11_device_CreateGeometryShader(struct qemu_syscall *call);
void qemu_d3d11_device_CreateGeometryShaderWithStreamOutput(struct qemu_syscall *call);
void qemu_d3d11_device_CreateHullShader(struct qemu_syscall *call);
void qemu_d3d11_device_CreateInputLayout(struct qemu_syscall *call);
void qemu_d3d11_device_CreatePixelShader(struct qemu_syscall *call);
void qemu_d3d11_device_CreatePredicate(struct qemu_syscall *call);
void qemu_d3d11_device_CreateQuery(struct qemu_syscall *call);
void qemu_d3d11_device_CreateRasterizerState(struct qemu_syscall *call);
void qemu_d3d11_device_CreateRasterizerState1(struct qemu_syscall *call);
void qemu_d3d11_device_CreateRenderTargetView(struct qemu_syscall *call);
void qemu_d3d11_device_CreateSamplerState(struct qemu_syscall *call);
void qemu_d3d11_device_CreateShaderResourceView(struct qemu_syscall *call);
void qemu_d3d11_device_CreateTexture1D(struct qemu_syscall *call);
void qemu_d3d11_device_CreateTexture2D(struct qemu_syscall *call);
void qemu_d3d11_device_CreateTexture3D(struct qemu_syscall *call);
void qemu_d3d11_device_CreateUnorderedAccessView(struct qemu_syscall *call);
void qemu_d3d11_device_CreateVertexShader(struct qemu_syscall *call);
void qemu_d3d11_device_GetCreationFlags(struct qemu_syscall *call);
void qemu_d3d11_device_GetDeviceRemovedReason(struct qemu_syscall *call);
void qemu_d3d11_device_GetExceptionMode(struct qemu_syscall *call);
void qemu_d3d11_device_GetFeatureLevel(struct qemu_syscall *call);
void qemu_d3d11_device_GetImmediateContext(struct qemu_syscall *call);
void qemu_d3d11_device_GetImmediateContext1(struct qemu_syscall *call);
void qemu_d3d11_device_GetImmediateContext2(struct qemu_syscall *call);
void qemu_d3d11_device_GetResourceTiling(struct qemu_syscall *call);
void qemu_d3d11_device_OpenSharedResource(struct qemu_syscall *call);
void qemu_d3d11_device_OpenSharedResource1(struct qemu_syscall *call);
void qemu_d3d11_device_OpenSharedResourceByName(struct qemu_syscall *call);
void qemu_d3d11_device_SetExceptionMode(struct qemu_syscall *call);
void qemu_d3d11_domain_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d11_domain_shader_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_domain_shader_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_domain_shader_Release(struct qemu_syscall *call);
void qemu_d3d11_geometry_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d11_geometry_shader_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_geometry_shader_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_geometry_shader_Release(struct qemu_syscall *call);
void qemu_d3d11_hull_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d11_hull_shader_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_hull_shader_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_hull_shader_Release(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_AddRef(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Begin(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSGetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSGetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSGetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSGetUnorderedAccessViews(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSSetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSSetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSSetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CSSetUnorderedAccessViews(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ClearDepthStencilView(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ClearRenderTargetView(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ClearState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ClearUnorderedAccessViewFloat(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ClearUnorderedAccessViewUint(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ClearView(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CopyResource(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CopyStructureCount(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CopySubresourceRegion(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_CopySubresourceRegion1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSGetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSGetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSGetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSSetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSSetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSSetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DiscardResource(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DiscardView(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DiscardView1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Dispatch(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DispatchIndirect(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Draw(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DrawAuto(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DrawIndexed(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DrawIndexedInstanced(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DrawIndexedInstancedIndirect(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DrawInstanced(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_DrawInstancedIndirect(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_End(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ExecuteCommandList(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_FinishCommandList(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Flush(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSGetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSGetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSGetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSSetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSSetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSSetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GenerateMips(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GetContextFlags(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GetData(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GetPredication(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GetResourceMinLOD(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_GetType(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSGetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSGetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSGetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSSetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSSetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSSetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_HSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IAGetIndexBuffer(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IAGetInputLayout(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IAGetPrimitiveTopology(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IAGetVertexBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IASetIndexBuffer(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IASetInputLayout(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IASetPrimitiveTopology(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_IASetVertexBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Map(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMGetBlendState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMGetDepthStencilState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMGetRenderTargets(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMGetRenderTargetsAndUnorderedAccessViews(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMSetBlendState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMSetDepthStencilState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMSetRenderTargets(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_OMSetRenderTargetsAndUnorderedAccessViews(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSGetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSGetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSGetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSSetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSSetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSSetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_PSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_RSGetScissorRects(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_RSGetState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_RSGetViewports(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_RSSetScissorRects(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_RSSetState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_RSSetViewports(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Release(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_ResolveSubresource(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_SOGetTargets(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_SOSetTargets(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_SetPredication(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_SetResourceMinLOD(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_SwapDeviceContextState(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_Unmap(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_UpdateSubresource(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_UpdateSubresource1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSGetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSGetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSGetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSGetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSGetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSSetConstantBuffers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSSetConstantBuffers1(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSSetSamplers(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSSetShader(struct qemu_syscall *call);
void qemu_d3d11_immediate_context_VSSetShaderResources(struct qemu_syscall *call);
void qemu_d3d11_input_layout_AddRef(struct qemu_syscall *call);
void qemu_d3d11_input_layout_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_input_layout_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_input_layout_Release(struct qemu_syscall *call);
void qemu_d3d11_pixel_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d11_pixel_shader_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_pixel_shader_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_pixel_shader_Release(struct qemu_syscall *call);
void qemu_d3d11_query_AddRef(struct qemu_syscall *call);
void qemu_d3d11_query_GetDataSize(struct qemu_syscall *call);
void qemu_d3d11_query_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_query_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_query_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_query_Release(struct qemu_syscall *call);
void qemu_d3d11_rasterizer_state_AddRef(struct qemu_syscall *call);
void qemu_d3d11_rasterizer_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_rasterizer_state_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_rasterizer_state_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_rasterizer_state_Release(struct qemu_syscall *call);
void qemu_d3d11_rendertarget_view_AddRef(struct qemu_syscall *call);
void qemu_d3d11_rendertarget_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_rendertarget_view_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_rendertarget_view_GetResource(struct qemu_syscall *call);
void qemu_d3d11_rendertarget_view_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_rendertarget_view_Release(struct qemu_syscall *call);
void qemu_d3d11_sampler_state_AddRef(struct qemu_syscall *call);
void qemu_d3d11_sampler_state_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_sampler_state_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_sampler_state_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_sampler_state_Release(struct qemu_syscall *call);
void qemu_d3d11_shader_resource_view_AddRef(struct qemu_syscall *call);
void qemu_d3d11_shader_resource_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_shader_resource_view_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_shader_resource_view_GetResource(struct qemu_syscall *call);
void qemu_d3d11_shader_resource_view_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_shader_resource_view_Release(struct qemu_syscall *call);
void qemu_d3d11_texture1d_AddRef(struct qemu_syscall *call);
void qemu_d3d11_texture1d_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_texture1d_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_texture1d_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_texture1d_GetType(struct qemu_syscall *call);
void qemu_d3d11_texture1d_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_texture1d_Release(struct qemu_syscall *call);
void qemu_d3d11_texture1d_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_texture2d_AddRef(struct qemu_syscall *call);
void qemu_d3d11_texture2d_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_texture2d_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_texture2d_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_texture2d_GetType(struct qemu_syscall *call);
void qemu_d3d11_texture2d_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_texture2d_Release(struct qemu_syscall *call);
void qemu_d3d11_texture2d_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_texture3d_AddRef(struct qemu_syscall *call);
void qemu_d3d11_texture3d_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_texture3d_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_texture3d_GetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_texture3d_GetType(struct qemu_syscall *call);
void qemu_d3d11_texture3d_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_texture3d_Release(struct qemu_syscall *call);
void qemu_d3d11_texture3d_SetEvictionPriority(struct qemu_syscall *call);
void qemu_d3d11_unordered_access_view_AddRef(struct qemu_syscall *call);
void qemu_d3d11_unordered_access_view_GetDesc(struct qemu_syscall *call);
void qemu_d3d11_unordered_access_view_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_unordered_access_view_GetResource(struct qemu_syscall *call);
void qemu_d3d11_unordered_access_view_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_unordered_access_view_Release(struct qemu_syscall *call);
void qemu_d3d11_vertex_shader_AddRef(struct qemu_syscall *call);
void qemu_d3d11_vertex_shader_GetDevice(struct qemu_syscall *call);
void qemu_d3d11_vertex_shader_QueryInterface(struct qemu_syscall *call);
void qemu_d3d11_vertex_shader_Release(struct qemu_syscall *call);
void qemu_d3d_device_inner_AddRef(struct qemu_syscall *call);
void qemu_d3d_device_inner_QueryInterface(struct qemu_syscall *call);
void qemu_d3d_device_inner_Release(struct qemu_syscall *call);
void qemu_wrap_implicit_surface(struct qemu_syscall *call);

HRESULT qemu_d3d11_texture_create(ID3D11Resource *host, struct qemu_d3d11_device *device,
        uint64_t *dxgi_surface, unsigned int dim, struct qemu_d3d11_texture **texture);
HRESULT qemu_d3d11_buffer_create(ID3D11Buffer *host, struct qemu_d3d11_buffer **buffer);
HRESULT qemu_d3d11_view_create(ID3D11View *host, const IID *d3d10iface, struct qemu_d3d11_view **view);
HRESULT qemu_d3d11_shader_create(ID3D11DeviceChild *host, const IID *d3d10iface, struct qemu_d3d11_shader **shader);
HRESULT qemu_d3d11_state_create(ID3D11DeviceChild *host, const IID *d3d10iface, struct qemu_d3d11_state **state);
HRESULT qemu_d3d11_query_create(ID3D11Query *host, struct qemu_d3d11_query **query);
HRESULT qemu_d3d11_input_layout_create(ID3D11InputLayout *host, struct qemu_d3d11_input_layout **layout);

DEFINE_GUID(IID_d3d11_priv_data, 0x2b676c65, 0x7123, 0x4138, 0xb6, 0xdb, 0x96, 0xfe, 0xa9, 0xae, 0x00, 0x43);

struct qemu_d3d11_device *device_from_host(ID3D11Device2 *host);
struct qemu_d3d11_state *state_from_host(ID3D11DeviceChild *host);
struct qemu_d3d11_view *view_from_host(ID3D11DeviceChild *host);
struct qemu_d3d11_query *query_from_host(ID3D11Query *host);
struct qemu_d3d11_shader *shader_from_host(ID3D11DeviceChild *host);
struct qemu_d3d11_buffer *buffer_from_host(ID3D11Buffer *host);
struct qemu_d3d11_buffer *buffer_from_host10(ID3D10Buffer *host);
struct qemu_d3d11_input_layout *input_layout_from_host(ID3D11InputLayout *host);
struct qemu_d3d11_texture *texture_from_host(ID3D11DeviceChild *host);

extern uint64_t d3d11_device_context_guest_destroy;
extern uint64_t d3d11_texture_guest_destroy;
extern uint64_t d3d11_buffer_guest_destroy;
extern uint64_t d3d11_view_guest_destroy;
extern uint64_t d3d11_shader_guest_destroy;
extern uint64_t d3d11_class_linkage_guest_destroy;
extern uint64_t d3d11_state_guest_destroy;
extern uint64_t d3d11_query_guest_destroy;
extern uint64_t d3d11_input_layout_guest_destroy;

#endif

#endif
