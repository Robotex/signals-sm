/**
 * vim: set ts=4 :
 * =============================================================================
 * Signal Extension for SourceMod
 * Copyright (C) 2017 Robotex.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Version: $Id$
 */

#include "extension.h"

#include "ClientListener.h"
#include "SignalHandler.h"

/**
 * @file extension.cpp
 * @brief Implement extension code here.
 */

Signal g_Signal;		/**< Global singleton for extension's main interface */

SMEXT_LINK(&g_Signal);

bool Signal::SDK_OnLoad(char *error, size_t maxlength, bool late)
{ 
    if (!trapTERM())
    {
        snprintf(error, maxlength, "Error setting signal handler!");
        return false;
    }

    playerhelpers->AddClientListener(&g_clientListener);
    
    return true;
}

void Signal::SDK_OnUnload()
{
    playerhelpers->RemoveClientListener(&g_clientListener);
    untrapTERM();
}
