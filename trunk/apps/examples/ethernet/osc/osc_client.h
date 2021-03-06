// $Id: osc_client.h 387 2009-03-04 23:15:36Z tk $
/*
 * Header file for OSC client functions
 *
 * ==========================================================================
 *
 *  Copyright (C) 2009 Thorsten Klose (tk@midibox.org)
 *  Licensed for personal non-commercial use only.
 *  All other rights reserved.
 * 
 * ==========================================================================
 */

#ifndef _OSC_CLIENT_H
#define _OSC_CLIENT_H


/////////////////////////////////////////////////////////////////////////////
// Global definitions
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Global Types
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////

extern s32 OSC_CLIENT_Init(u32 mode);
extern s32 OSC_CLIENT_SendButtonState(mios32_osc_timetag_t timetag, u32 button, u8 pressed);
extern s32 OSC_CLIENT_SendPotValue(mios32_osc_timetag_t timetag, u32 pot, float value);


/////////////////////////////////////////////////////////////////////////////
// Export global variables
/////////////////////////////////////////////////////////////////////////////

#endif /* _OSC_CLIENT_H */
