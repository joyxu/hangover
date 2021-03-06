/*
 * Copyright 2017 André Hentschel
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

/* NOTE: The guest side uses mingw's headers. The host side uses Wine's headers. */

#include <windows.h>
#include <stdio.h>

#include "windows-user-services.h"
#include "dll_list.h"
#include "qemu_gdi32.h"

#ifdef QEMU_DLL_GUEST

/* Pointers to USER implementation of SelectPalette/RealizePalette */
/* FIXME: Wine says "they will be patched by USER on startup". Do I need
 * this, or are these just Wine internals that are missing the __wine
 * name prefix? */

extern void DbgBreakPoint(void);
HPALETTE WINAPI GDISelectPalette( HDC hdc, HPALETTE hpal, WORD wBkg)
{
    DbgBreakPoint();
    return NULL;
}

UINT WINAPI GDIRealizePalette( HDC hdc )
{
    DbgBreakPoint();
    return 0;
}

HPALETTE (WINAPI *pfnSelectPalette)(HDC hdc, HPALETTE hpal, WORD bkgnd ) = GDISelectPalette;
UINT (WINAPI *pfnRealizePalette)(HDC hdc) = GDIRealizePalette;

#else

#include <wine/debug.h>
WINE_DEFAULT_DEBUG_CHANNEL(qemu_gdi32);

#endif

struct qemu_CreatePalette
{
    struct qemu_syscall super;
    uint64_t palette;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HPALETTE WINAPI CreatePalette(const LOGPALETTE* palette)
{
    struct qemu_CreatePalette call;
    call.super.id = QEMU_SYSCALL_ID(CALL_CREATEPALETTE);
    call.palette = (ULONG_PTR)palette;

    qemu_syscall(&call.super);

    return (HPALETTE)(ULONG_PTR)call.super.iret;
}

#else

void qemu_CreatePalette(struct qemu_syscall *call)
{
    struct qemu_CreatePalette *c = (struct qemu_CreatePalette *)call;
    WINE_TRACE("\n");
    c->super.iret = (ULONG_PTR)CreatePalette(QEMU_G2H(c->palette));
}

#endif

struct qemu_CreateHalftonePalette
{
    struct qemu_syscall super;
    uint64_t hdc;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc)
{
    struct qemu_CreateHalftonePalette call;
    call.super.id = QEMU_SYSCALL_ID(CALL_CREATEHALFTONEPALETTE);
    call.hdc = (ULONG_PTR)hdc;

    qemu_syscall(&call.super);

    return (HPALETTE)(ULONG_PTR)call.super.iret;
}

#else

void qemu_CreateHalftonePalette(struct qemu_syscall *call)
{
    struct qemu_CreateHalftonePalette *c = (struct qemu_CreateHalftonePalette *)call;
    WINE_TRACE("\n");
    c->super.iret = (ULONG_PTR)CreateHalftonePalette(QEMU_G2H(c->hdc));
}

#endif

struct qemu_GetPaletteEntries
{
    struct qemu_syscall super;
    uint64_t hpalette;
    uint64_t start;
    uint64_t count;
    uint64_t entries;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI GetPaletteEntries(HPALETTE hpalette, UINT start, UINT count, LPPALETTEENTRY entries)
{
    struct qemu_GetPaletteEntries call;
    call.super.id = QEMU_SYSCALL_ID(CALL_GETPALETTEENTRIES);
    call.hpalette = (ULONG_PTR)hpalette;
    call.start = (ULONG_PTR)start;
    call.count = (ULONG_PTR)count;
    call.entries = (ULONG_PTR)entries;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_GetPaletteEntries(struct qemu_syscall *call)
{
    struct qemu_GetPaletteEntries *c = (struct qemu_GetPaletteEntries *)call;
    WINE_TRACE("\n");
    c->super.iret = GetPaletteEntries(QEMU_G2H(c->hpalette), c->start, c->count, QEMU_G2H(c->entries));
}

#endif

struct qemu_SetPaletteEntries
{
    struct qemu_syscall super;
    uint64_t hpalette;
    uint64_t start;
    uint64_t count;
    uint64_t entries;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI SetPaletteEntries(HPALETTE hpalette, UINT start, UINT count, const PALETTEENTRY *entries)
{
    struct qemu_SetPaletteEntries call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SETPALETTEENTRIES);
    call.hpalette = (ULONG_PTR)hpalette;
    call.start = (ULONG_PTR)start;
    call.count = (ULONG_PTR)count;
    call.entries = (ULONG_PTR)entries;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_SetPaletteEntries(struct qemu_syscall *call)
{
    struct qemu_SetPaletteEntries *c = (struct qemu_SetPaletteEntries *)call;
    WINE_TRACE("\n");
    c->super.iret = SetPaletteEntries(QEMU_G2H(c->hpalette), c->start, c->count, QEMU_G2H(c->entries));
}

#endif

struct qemu_ResizePalette
{
    struct qemu_syscall super;
    uint64_t hPal;
    uint64_t cEntries;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI ResizePalette(HPALETTE hPal, UINT cEntries)
{
    struct qemu_ResizePalette call;
    call.super.id = QEMU_SYSCALL_ID(CALL_RESIZEPALETTE);
    call.hPal = (ULONG_PTR)hPal;
    call.cEntries = (ULONG_PTR)cEntries;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_ResizePalette(struct qemu_syscall *call)
{
    struct qemu_ResizePalette *c = (struct qemu_ResizePalette *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = ResizePalette(QEMU_G2H(c->hPal), c->cEntries);
}

#endif

struct qemu_AnimatePalette
{
    struct qemu_syscall super;
    uint64_t hPal;
    uint64_t StartIndex;
    uint64_t NumEntries;
    uint64_t PaletteColors;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI AnimatePalette(HPALETTE hPal, UINT StartIndex, UINT NumEntries, const PALETTEENTRY* PaletteColors)
{
    struct qemu_AnimatePalette call;
    call.super.id = QEMU_SYSCALL_ID(CALL_ANIMATEPALETTE);
    call.hPal = (ULONG_PTR)hPal;
    call.StartIndex = (ULONG_PTR)StartIndex;
    call.NumEntries = (ULONG_PTR)NumEntries;
    call.PaletteColors = (ULONG_PTR)PaletteColors;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_AnimatePalette(struct qemu_syscall *call)
{
    struct qemu_AnimatePalette *c = (struct qemu_AnimatePalette *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = AnimatePalette(QEMU_G2H(c->hPal), c->StartIndex, c->NumEntries, QEMU_G2H(c->PaletteColors));
}

#endif

struct qemu_SetSystemPaletteUse
{
    struct qemu_syscall super;
    uint64_t hdc;
    uint64_t use;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI SetSystemPaletteUse(HDC hdc, UINT use)
{
    struct qemu_SetSystemPaletteUse call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SETSYSTEMPALETTEUSE);
    call.hdc = (ULONG_PTR)hdc;
    call.use = (ULONG_PTR)use;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_SetSystemPaletteUse(struct qemu_syscall *call)
{
    struct qemu_SetSystemPaletteUse *c = (struct qemu_SetSystemPaletteUse *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = SetSystemPaletteUse(QEMU_G2H(c->hdc), c->use);
}

#endif

struct qemu_GetSystemPaletteUse
{
    struct qemu_syscall super;
    uint64_t hdc;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI GetSystemPaletteUse(HDC hdc)
{
    struct qemu_GetSystemPaletteUse call;
    call.super.id = QEMU_SYSCALL_ID(CALL_GETSYSTEMPALETTEUSE);
    call.hdc = (ULONG_PTR)hdc;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_GetSystemPaletteUse(struct qemu_syscall *call)
{
    struct qemu_GetSystemPaletteUse *c = (struct qemu_GetSystemPaletteUse *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = GetSystemPaletteUse(QEMU_G2H(c->hdc));
}

#endif

struct qemu_GetSystemPaletteEntries
{
    struct qemu_syscall super;
    uint64_t hdc;
    uint64_t start;
    uint64_t count;
    uint64_t entries;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc, UINT start, UINT count, LPPALETTEENTRY entries)
{
    struct qemu_GetSystemPaletteEntries call;
    call.super.id = QEMU_SYSCALL_ID(CALL_GETSYSTEMPALETTEENTRIES);
    call.hdc = (ULONG_PTR)hdc;
    call.start = (ULONG_PTR)start;
    call.count = (ULONG_PTR)count;
    call.entries = (ULONG_PTR)entries;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_GetSystemPaletteEntries(struct qemu_syscall *call)
{
    struct qemu_GetSystemPaletteEntries *c = (struct qemu_GetSystemPaletteEntries *)call;
    WINE_TRACE("\n");
    c->super.iret = GetSystemPaletteEntries(QEMU_G2H(c->hdc), c->start, c->count, QEMU_G2H(c->entries));
}

#endif

struct qemu_GetNearestPaletteIndex
{
    struct qemu_syscall super;
    uint64_t hpalette;
    uint64_t color;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI GetNearestPaletteIndex(HPALETTE hpalette, COLORREF color)
{
    struct qemu_GetNearestPaletteIndex call;
    call.super.id = QEMU_SYSCALL_ID(CALL_GETNEARESTPALETTEINDEX);
    call.hpalette = (ULONG_PTR)hpalette;
    call.color = (ULONG_PTR)color;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_GetNearestPaletteIndex(struct qemu_syscall *call)
{
    struct qemu_GetNearestPaletteIndex *c = (struct qemu_GetNearestPaletteIndex *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = GetNearestPaletteIndex(QEMU_G2H(c->hpalette), c->color);
}

#endif

struct qemu_GetNearestColor
{
    struct qemu_syscall super;
    uint64_t hdc;
    uint64_t color;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI COLORREF WINAPI GetNearestColor(HDC hdc, COLORREF color)
{
    struct qemu_GetNearestColor call;
    call.super.id = QEMU_SYSCALL_ID(CALL_GETNEARESTCOLOR);
    call.hdc = (ULONG_PTR)hdc;
    call.color = (ULONG_PTR)color;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_GetNearestColor(struct qemu_syscall *call)
{
    struct qemu_GetNearestColor *c = (struct qemu_GetNearestColor *)call;
    WINE_TRACE("\n");
    c->super.iret = GetNearestColor(QEMU_G2H(c->hdc), c->color);
}

#endif

struct qemu_SelectPalette
{
    struct qemu_syscall super;
    uint64_t hDC;
    uint64_t hPal;
    uint64_t bForceBackground;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI HPALETTE WINAPI SelectPalette(HDC hDC, HPALETTE hPal, BOOL bForceBackground)
{
    struct qemu_SelectPalette call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SELECTPALETTE);
    call.hDC = (ULONG_PTR)hDC;
    call.hPal = (ULONG_PTR)hPal;
    call.bForceBackground = (ULONG_PTR)bForceBackground;

    qemu_syscall(&call.super);

    return (HPALETTE)(ULONG_PTR)call.super.iret;
}

#else

void qemu_SelectPalette(struct qemu_syscall *call)
{
    struct qemu_SelectPalette *c = (struct qemu_SelectPalette *)call;
    WINE_TRACE("\n");
    c->super.iret = (ULONG_PTR)SelectPalette(QEMU_G2H(c->hDC), QEMU_G2H(c->hPal), c->bForceBackground);
}

#endif

struct qemu_RealizePalette
{
    struct qemu_syscall super;
    uint64_t hDC;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI UINT WINAPI RealizePalette(HDC hDC)
{
    struct qemu_RealizePalette call;
    call.super.id = QEMU_SYSCALL_ID(CALL_REALIZEPALETTE);
    call.hDC = (ULONG_PTR)hDC;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_RealizePalette(struct qemu_syscall *call)
{
    struct qemu_RealizePalette *c = (struct qemu_RealizePalette *)call;
    WINE_TRACE("\n");
    c->super.iret = RealizePalette(QEMU_G2H(c->hDC));
}

#endif

struct qemu_UpdateColors
{
    struct qemu_syscall super;
    uint64_t hDC;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI UpdateColors(HDC hDC)
{
    struct qemu_UpdateColors call;
    call.super.id = QEMU_SYSCALL_ID(CALL_UPDATECOLORS);
    call.hDC = (ULONG_PTR)hDC;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

void qemu_UpdateColors(struct qemu_syscall *call)
{
    struct qemu_UpdateColors *c = (struct qemu_UpdateColors *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = UpdateColors(QEMU_G2H(c->hDC));
}

#endif

struct qemu_SetMagicColors
{
    struct qemu_syscall super;
    uint64_t hdc;
    uint64_t u1;
    uint64_t u2;
};

#ifdef QEMU_DLL_GUEST

WINBASEAPI BOOL WINAPI SetMagicColors(HDC hdc, ULONG u1, ULONG u2)
{
    struct qemu_SetMagicColors call;
    call.super.id = QEMU_SYSCALL_ID(CALL_SETMAGICCOLORS);
    call.hdc = (ULONG_PTR)hdc;
    call.u1 = (ULONG_PTR)u1;
    call.u2 = (ULONG_PTR)u2;

    qemu_syscall(&call.super);

    return call.super.iret;
}

#else

/* TODO: Add SetMagicColors to Wine headers? */
extern BOOL WINAPI SetMagicColors(HDC hdc, ULONG u1, ULONG u2);
void qemu_SetMagicColors(struct qemu_syscall *call)
{
    struct qemu_SetMagicColors *c = (struct qemu_SetMagicColors *)call;
    WINE_FIXME("Unverified!\n");
    c->super.iret = SetMagicColors(QEMU_G2H(c->hdc), c->u1, c->u2);
}

#endif

