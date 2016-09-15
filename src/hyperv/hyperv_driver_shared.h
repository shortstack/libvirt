/*
 * hyperv_shared.h
 *
 * Copyright (C) 2011 Matthias Bolte <matthias.bolte@googlemail.com>
 * Copyright (C) 2009 Michael Sievers <msievers83@googlemail.com>
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
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __HYPERV_DRIVER_SHARED_H__
# define __HYPERV_DRIVER_SHARED_H__

#include <config.h>

#include "internal.h"
#include "datatypes.h"
#include "virdomainobjlist.h"
#include "virauth.h"
#include "viralloc.h"
#include "virlog.h"
#include "viruuid.h"
#include "hyperv_driver.h"
#include "hyperv_network_driver.h"
#include "hyperv_private.h"
#include "hyperv_util.h"
#include "hyperv_wmi.h"
#include "openwsman.h"
#include "virstring.h"
#include "virtypedparam.h"

#define VIR_FROM_THIS VIR_FROM_HYPERV

int
hypervParseDomainDefFindParentRasd(
            Msvm_ResourceAllocationSettingData *rasdEntry,
            Msvm_ResourceAllocationSettingData *rasdEntryListStart,
            Msvm_ResourceAllocationSettingData **rasdEntryParent);
            
int
hypervParseDomainDefSetDiskTarget(
            virDomainDiskDefPtr disk,
            Msvm_ResourceAllocationSettingData *rasdEntry,
            Msvm_ResourceAllocationSettingData *rasdEntryListStart,
            int *scsiDriveIndex);
            
int
hypervParseDomainDefStorageExtent(
            virDomainPtr domain, virDomainDefPtr def,
            Msvm_ResourceAllocationSettingData *rasdEntry,
            Msvm_ResourceAllocationSettingData *rasdEntryListStart,            
            int *scsiDriveIndex);
            
int
hypervParseDomainDefDisk(
        virDomainPtr domain, virDomainDefPtr def,
        Msvm_ResourceAllocationSettingData *rasdEntry,
        Msvm_ResourceAllocationSettingData *rasdEntryListStart,
        int *scsiDriveIndex);

#endif /* __HYPERV_DRIVER_SHARED_H__ */
