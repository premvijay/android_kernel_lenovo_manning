/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

#include "mtk_kbase_spm.h"
static const u32 dvfs_gpu_binary[] = {
	0xe8288000, 0x11016800, 0x00000008, 0x000aae60, 0x00094ed0, 0x0007ef40,
	0x0006c084, 0x000591c8, 0x000499bc, 0x0003a1b0, 0x00025b84, 0x00000469,
	0x00000436, 0x000003e9, 0x000003cf, 0x0000038f, 0x00000382, 0x0000035c,
	0x00000328, 0xe8280000, 0x11016608, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x1890001f, 0x1000c244, 0x18c0001f, 0x1101660c, 0xe0c00002,
	0x1880001f, 0x00000000, 0xc0802a20, 0x17c07c1f, 0x18c0001f, 0x11016608,
	0xe0c00002, 0x18c0001f, 0x11016610, 0x1890001f, 0x11016608, 0xe0c00002,
	0x18c0001f, 0x11016614, 0x1890001f, 0x1101660c, 0xe0c00002, 0xe8208000,
	0x11016618, 0x00000465, 0xe8208000, 0x1101661c, 0x000aae60, 0xe8208000,
	0x11016620, 0x00000352, 0xe8208000, 0x11016624, 0x0003a1b0, 0xf0000000,
	0x17c07c1f, 0x1900001f, 0x11016610, 0xe1000002, 0x1900001f, 0x11016614,
	0xe1000003, 0xc0802540, 0x17c07c1f, 0x1900001f, 0x11016610, 0xe1000002,
	0x1890001f, 0x11016614, 0xc0801960, 0x17c07c1f, 0x1900001f, 0x11016614,
	0xe1000002, 0xf0000000, 0x17c07c1f, 0x10802c1f, 0x88c00002, 0x07000000,
	0x10cc0c1f, 0x88800002, 0x001fffff, 0x69200003, 0x00000001, 0xd8200d44,
	0x17c07c1f, 0x1080881f, 0xd0000e40, 0x17c07c1f, 0x69200003, 0x00000002,
	0xd8200e24, 0x17c07c1f, 0x1081081f, 0xd0000e40, 0x17c07c1f, 0x1081881f,
	0x12c0081f, 0xf0000000, 0x17c07c1f, 0x1890001f, 0x11016610, 0x39300002,
	0x11016620, 0xd8001004, 0x17c07c1f, 0x1940001f, 0x11016610, 0x18d0001f,
	0x11016620, 0xe1400003, 0x59300002, 0x11016618, 0xd8001124, 0x17c07c1f,
	0x1940001f, 0x11016610, 0x18d0001f, 0x11016618, 0xe1400003, 0x1990001f,
	0x11016614, 0xc1800ba0, 0x17c07c1f, 0x1950001f, 0x11016624, 0xc1400ba0,
	0x17c07c1f, 0x30e01406, 0xd8001323, 0x17c07c1f, 0x1940001f, 0x11016614,
	0x18d0001f, 0x11016624, 0xe1400003, 0x1950001f, 0x1101661c, 0xc1400ba0,
	0x17c07c1f, 0x50e01406, 0xd80014a3, 0x17c07c1f, 0x1940001f, 0x11016614,
	0x18d0001f, 0x1101661c, 0xe1400003, 0x1890001f, 0x11016610, 0x08900002,
	0x11016614, 0x08b00002, 0x11016608, 0x68f00002, 0x1101660c, 0xd8001923,
	0x17c07c1f, 0x1890001f, 0x11016610, 0x28f00002, 0x11016608, 0xc8802a23,
	0x17c07c1f, 0x1890001f, 0x11016614, 0xc08022c0, 0x17c07c1f, 0x1890001f,
	0x11016610, 0x48f00002, 0x11016608, 0xc8802a23, 0x17c07c1f, 0x1900001f,
	0x11016608, 0x1950001f, 0x11016610, 0xe1000005, 0x1900001f, 0x1101660c,
	0x1950001f, 0x11016614, 0xe1000005, 0xf0000000, 0x17c07c1f, 0x10802c1f,
	0x18c0001f, 0x00000f00, 0x88d00003, 0x10206050, 0x78e00003, 0x00000100,
	0xd8001b03, 0x17c07c1f, 0x28e00002, 0x0007a120, 0xd8002083, 0x17c07c1f,
	0x28e00002, 0x000c4c70, 0xd8002083, 0x17c07c1f, 0x28e00002, 0x0003d090,
	0xd8001e43, 0x17c07c1f, 0x1000081f, 0x1840001f, 0x00000064, 0xa9c00007,
	0x00000001, 0x89c00007, 0xfffffff9, 0x1018b41f, 0x1840001f, 0x0000001a,
	0x0800000d, 0x00000005, 0x1840001f, 0x0000000a, 0xaac0000d, 0x83000000,
	0xd0002280, 0x17c07c1f, 0x1000081f, 0x1840001f, 0x00000064, 0xa9c00007,
	0x00000001, 0x89c00007, 0xfffffff9, 0x1018341f, 0x1840001f, 0x0000001a,
	0x0800000d, 0x00000005, 0x1840001f, 0x0000000a, 0xaac0000d, 0x82000000,
	0xd0002280, 0x17c07c1f, 0x1000081f, 0x1840001f, 0x00000064, 0xa9c00007,
	0x00000001, 0x89c00007, 0xfffffff9, 0x1017b41f, 0x1840001f, 0x0000001a,
	0x0800000d, 0x00000005, 0x1840001f, 0x0000000a, 0xaac0000d, 0x81000000,
	0xf0000000, 0x17c07c1f, 0x10802c1f, 0xe8208000, 0x10000058, 0x03000000,
	0xe8208000, 0x10000004, 0x00000080, 0x18c0001f, 0x1000c244, 0xe0c00002,
	0x1b80001f, 0x2000030c, 0xe8208000, 0x10000054, 0x01000000, 0xe8208000,
	0x10000004, 0x00000080, 0xf0000000, 0x17c07c1f, 0x10c02c1f, 0x10918c1f,
	0x00928c02, 0x00930c02, 0x00938c02, 0x00940c02, 0x00948c02, 0x08200002,
	0x00091a6b, 0x1840001f, 0x0000321a, 0xa9c00007, 0x00000001, 0x89c00007,
	0xfffffff9, 0x1080341f, 0x29200002, 0x0000003f, 0xd8202804, 0x17c07c1f,
	0x1880001f, 0x0000003f, 0xaac00002, 0x00000080, 0xf0000000, 0x17c07c1f,
	0xd00029c0, 0x17c07c1f, 0xd00029c0, 0x17c07c1f, 0xd00029c0, 0x17c07c1f,
	0xd00029c0, 0x17c07c1f, 0xd00029c0, 0x17c07c1f, 0xe8208000, 0x11010050,
	0x00000001, 0x10802c1f, 0xe8208000, 0x11016410, 0x00000001, 0x18d0001f,
	0x11016410, 0x69200003, 0x00000001, 0xd8202a44, 0x17c07c1f, 0xe8208000,
	0x11010010, 0x0000003a, 0xe8208000, 0x11010004, 0x000000c0, 0xe8208000,
	0x1101000c, 0x00000007, 0xe8208000, 0x11010038, 0x00000001, 0xe8208000,
	0x11010008, 0x00000000, 0xe8208000, 0x11010014, 0x00000001, 0xe8208000,
	0x11010018, 0x00000002, 0xe8208000, 0x11010000, 0x00000000, 0xe8208000,
	0x11010024, 0x00000001, 0xe8208000, 0x11016604, 0x00000001, 0x1940001f,
	0x0000ffff, 0x09600005, 0x00000001, 0x69200005, 0x00000000, 0xd8002884,
	0x17c07c1f, 0x1910001f, 0x1101000c, 0xd8202f64, 0x17c07c1f, 0x89000004,
	0x00000006, 0xd80028c4, 0x17c07c1f, 0xe8208000, 0x11016604, 0x00000002,
	0x1910001f, 0x11010030, 0x1102101f, 0x89000004, 0x0000000f, 0x79200004,
	0x00000001, 0xd8002904, 0x17c07c1f, 0x1950001f, 0x11010000, 0x78e00002,
	0x00000000, 0xd80033c3, 0x17c07c1f, 0x12c0141f, 0xd0004560, 0x17c07c1f,
	0x60e01402, 0xd8004563, 0x17c07c1f, 0x21a01402, 0xd82038c6, 0x17c07c1f,
	0x08e00002, 0x00000087, 0x10c08c1f, 0x39200003, 0x00000007, 0xd80035a4,
	0x17c07c1f, 0x18c0001f, 0x00000007, 0x59200003, 0x0000000f, 0xd8003664,
	0x17c07c1f, 0x18c0001f, 0x0000000f, 0x1900001f, 0x10001fc8, 0xe1000003,
	0x1800001f, 0x00000101, 0x10400c1f, 0x89c00007, 0xfffffffe, 0x10c0341f,
	0x11180c1f, 0x00c01003, 0x1900001f, 0x10001fc0, 0xe1000003, 0x1900001f,
	0x10001fc4, 0xe1000003, 0x1b80001f, 0x20000208, 0xe8208000, 0x11010010,
	0x0000002a, 0xe8208000, 0x11010004, 0x000000c0, 0xe8208000, 0x1101000c,
	0x00000007, 0xe8208000, 0x11010038, 0x00000001, 0xe8208000, 0x11010008,
	0x00000000, 0xe8208000, 0x11010014, 0x00000002, 0xe8208000, 0x11010018,
	0x00000001, 0xe8208000, 0x11010000, 0x00000000, 0x18c0001f, 0x11010000,
	0xe0c00002, 0xe8208000, 0x11010024, 0x00000001, 0xe8208000, 0x11016604,
	0x00000003, 0x1940001f, 0x0000ffff, 0x09600005, 0x00000001, 0x69200005,
	0x00000000, 0xd8002944, 0x17c07c1f, 0x1910001f, 0x1101000c, 0xd8203d24,
	0x17c07c1f, 0x89000004, 0x00000006, 0xd8002984, 0x17c07c1f, 0xe8208000,
	0x11016604, 0x00000004, 0xd82040a6, 0x17c07c1f, 0x1b80001f, 0x20001c70,
	0x18c0001f, 0x11016634, 0x19300003, 0x17c07c1f, 0x09000004, 0x00000001,
	0xe0c00004, 0xd8004526, 0x17c07c1f, 0x08e00002, 0x00000087, 0x10c08c1f,
	0x39200003, 0x00000007, 0xd8004204, 0x17c07c1f, 0x18c0001f, 0x00000007,
	0x59200003, 0x0000000f, 0xd80042c4, 0x17c07c1f, 0x18c0001f, 0x0000000f,
	0x1900001f, 0x10001fc8, 0xe1000003, 0x1800001f, 0x00000101, 0x10400c1f,
	0x89c00007, 0xfffffffe, 0x10c0341f, 0x11180c1f, 0x00c01003, 0x1900001f,
	0x10001fc0, 0xe1000003, 0x1900001f, 0x10001fc4, 0xe1000003, 0x1b80001f,
	0x20000208, 0xd0002b60, 0x17c07c1f, 0xe8208000, 0x11016410, 0x00000001,
	0xe8208000, 0x11016604, 0x0000000f, 0xf0000000, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f,
	0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0x17c07c1f, 0xc0800000, 0x17c07c1f,
	0xe8208000, 0x11016310, 0x00000000, 0xe8208000, 0x11016314, 0x00000000,
	0xe8208000, 0x1101632c, 0x00000001, 0xe8208000, 0x11016320, 0x00000000,
	0xe8208000, 0x11016324, 0x00000000, 0xe8208000, 0x110163ec, 0x00000000,
	0xe8208000, 0x110163cc, 0x00000000, 0xe8208000, 0x110163d0, 0x00000000,
	0xe8208000, 0x110163e8, 0x00000000, 0x1880001f, 0x11016354, 0x18c0001f,
	0x00000000, 0x49200003, 0x00000010, 0xd8208584, 0x17c07c1f, 0xe0a00000,
	0x08800002, 0x00000004, 0x08c00003, 0x00000001, 0xd0008420, 0x17c07c1f,
	0x1890001f, 0x11016648, 0x1940001f, 0x11016640, 0xe1400002, 0x98f00002,
	0x11016644, 0x89000002, 0x00000001, 0xd820ea24, 0x17c07c1f, 0x81000c04,
	0xd8208dc4, 0x17c07c1f, 0x1890001f, 0x11016618, 0x48e00002, 0x000000aa,
	0xd80088a3, 0x17c07c1f, 0xc0802540, 0x17c07c1f, 0x18c0001f, 0x11016618,
	0xe0c00002, 0x1890001f, 0x11016620, 0x48e00002, 0x000000aa, 0xd8008a03,
	0x17c07c1f, 0xc0802540, 0x17c07c1f, 0x18c0001f, 0x11016620, 0xe0c00002,
	0x1880001f, 0x80000000, 0x88d00002, 0x1101661c, 0xd8008ba3, 0x17c07c1f,
	0x1890001f, 0x1101661c, 0xc0801960, 0x17c07c1f, 0x18c0001f, 0x1101661c,
	0xe0c00002, 0x1880001f, 0x80000000, 0x88d00002, 0x11016624, 0xd8008d43,
	0x17c07c1f, 0x1890001f, 0x11016624, 0xc0801960, 0x17c07c1f, 0x18c0001f,
	0x11016624, 0xe0c00002, 0x1890001f, 0x11016640, 0x98f00002, 0x11016644,
	0x89000002, 0x00000002, 0x81000c04, 0xd8208e64, 0x17c07c1f, 0x89000002,
	0x00000002, 0xd820e144, 0x17c07c1f, 0x1910001f, 0x11016304, 0x78e00004,
	0x00000000, 0xd8009003, 0x17c07c1f, 0x1900001f, 0x110163ac, 0xe1200000,
	0x18d0001f, 0x11016308, 0x29200003, 0x00000000, 0xd8209244, 0x17c07c1f,
	0x18d0001f, 0x11016324, 0x69200003, 0x00000000, 0xd8209244, 0x17c07c1f,
	0x18c0001f, 0x11016308, 0xe0e00000, 0x18c0001f, 0x11016324, 0xe0e00001,
	0x1910001f, 0x110163dc, 0x28e00004, 0x00000000, 0xd8209423, 0x17c07c1f,
	0x18c0001f, 0x110163dc, 0xe0e00000, 0xc100f220, 0x17c07c1f, 0xc100f780,
	0x17c07c1f, 0xc0800920, 0x17c07c1f, 0x1880001f, 0x0000000f, 0x88d00002,
	0x11016310, 0x78a00003, 0x00000000, 0xd8009582, 0x17c07c1f, 0x1900001f,
	0x11016318, 0xe1200000, 0xc100ec20, 0x17c07c1f, 0x18c0001f, 0x110163a8,
	0xe0c00004, 0x1850001f, 0x110163c8, 0x08500001, 0x11016630, 0x68a00001,
	0x00000000, 0xd8009822, 0x17c07c1f, 0x1880001f, 0x00000000, 0x18c0001f,
	0x00000000, 0x1940001f, 0x00000000, 0xd0009b40, 0x17c07c1f, 0xe8208000,
	0x11016444, 0x00000001, 0x18d0001f, 0x11016444, 0x68a00003, 0x00000001,
	0xd8209822, 0x17c07c1f, 0xe8208000, 0x13020004, 0x00000003, 0xe8208000,
	0x13020008, 0x00000001, 0xe8208000, 0x1302000c, 0x00000001, 0x1890001f,
	0x13020230, 0x18d0001f, 0x13020234, 0xe8208000, 0x11016444, 0x00000001,
	0x1900001f, 0x11016398, 0xe1000002, 0x1900001f, 0x1101639c, 0xe1000003,
	0x1a00001f, 0x110163e4, 0x1a50001f, 0x11016398, 0x1a80001f, 0x11016324,
	0x1890001f, 0x11016324, 0x68e00002, 0x00000001, 0xd820a3c3, 0x17c07c1f,
	0x1880001f, 0x11016328, 0xe0a00000, 0x1890001f, 0x110163b0, 0x48e00002,
	0x000001f4, 0xd820a3c3, 0x17c07c1f, 0x1890001f, 0x11016398, 0x28e00002,
	0x000001f4, 0xd820a3c3, 0x17c07c1f, 0x1880001f, 0x11016324, 0xe0a00002,
	0xe2200000, 0x18d0001f, 0x11016334, 0x08d00003, 0x11016338, 0x08d00003,
	0x1101633c, 0x08d00003, 0x11016340, 0x1900001f, 0x110163e8, 0xe1000003,
	0x49200003, 0x000005dc, 0xd820a2c4, 0x17c07c1f, 0x18c0001f, 0x11016328,
	0xe0e00000, 0x18c0001f, 0x110163e0, 0xe0e00000, 0xd000a3c0, 0x17c07c1f,
	0x18c0001f, 0x11016328, 0xe0e00004, 0x1900001f, 0x0003d08f, 0x18c0001f,
	0x110163e0, 0xe0c00004, 0x1a00001f, 0x110163e4, 0x1a50001f, 0x11016398,
	0x1a80001f, 0x11016324, 0x1890001f, 0x11016324, 0x68e00002, 0x00000002,
	0xd820acc3, 0x17c07c1f, 0x1940001f, 0x00061a80, 0x20e01409, 0xd820aca3,
	0x17c07c1f, 0x1890001f, 0x110163e4, 0x08800002, 0x00000001, 0xe2000002,
	0x18d0001f, 0x11016328, 0x31200c02, 0xd820acc4, 0x17c07c1f, 0x1880001f,
	0x110163e8, 0xe0a00000, 0x1880001f, 0x11016324, 0xe0a00000, 0x1880001f,
	0x1101662c, 0xe0a00000, 0x1890001f, 0x110163e0, 0x18c0001f, 0x110163ac,
	0xe0c00002, 0x18c0001f, 0x0007ef40, 0x1880001f, 0x110163dc, 0xe0800003,
	0x11120c1f, 0x1880001f, 0x11016334, 0xe0800004, 0x1880001f, 0x11016338,
	0xe0800004, 0x1880001f, 0x1101633c, 0xe0800004, 0x1880001f, 0x11016340,
	0xe0800004, 0x1910001f, 0x110163dc, 0x1880001f, 0x00000001, 0x1990001f,
	0x11016314, 0x1940001f, 0x11016354, 0x50e01802, 0xd820acc3, 0x17c07c1f,
	0xe1400004, 0x08800002, 0x00000001, 0x09400005, 0x00000004, 0xd000ab60,
	0x17c07c1f, 0xe2200000, 0x1880001f, 0x110163b0, 0xe0800009, 0x1890001f,
	0x11016398, 0x1900001f, 0x11016354, 0x1950001f, 0x11016314, 0x01911404,
	0xe1800002, 0x18d0001f, 0x1101639c, 0x29200003, 0x00000014, 0xd820b144,
	0x17c07c1f, 0x1950001f, 0x110163cc, 0x01400c05, 0x1980001f, 0x110163cc,
	0xe1800005, 0x18d0001f, 0x1101639c, 0x69200003, 0x000186a0, 0xd800b144,
	0x17c07c1f, 0x1950001f, 0x11016318, 0x09800005, 0x00000001, 0x1940001f,
	0x11016318, 0xe1400006, 0x1890001f, 0x11016310, 0x08800002, 0x00000001,
	0x18c0001f, 0x11016310, 0xe0c00002, 0x1890001f, 0x11016314, 0x1900001f,
	0x1101631c, 0x68e00002, 0x0000000f, 0xd820b3e3, 0x17c07c1f, 0xe1200001,
	0x1940001f, 0x11016314, 0xe1600000, 0xd000b4e0, 0x17c07c1f, 0xe1200000,
	0x1950001f, 0x11016314, 0x09400005, 0x00000001, 0x1980001f, 0x11016314,
	0xe1800005, 0x1890001f, 0x1101632c, 0x28e00002, 0x00000000, 0xd820e0e3,
	0x17c07c1f, 0x1890001f, 0x1101631c, 0x68e00002, 0x00000001, 0xd820e0e3,
	0x17c07c1f, 0x1880001f, 0x00000000, 0x1900001f, 0x00000000, 0x1940001f,
	0x11016354, 0x48e00002, 0x00000010, 0xd820b8c3, 0x17c07c1f, 0x19b00005,
	0x17c07c1f, 0x01001804, 0x08800002, 0x00000001, 0x09400005, 0x00000004,
	0xd000b720, 0x17c07c1f, 0x1880001f, 0x11016330, 0xe0800004, 0x1890001f,
	0x11016320, 0x48e00002, 0x00000003, 0xd820c203, 0x17c07c1f, 0x1880001f,
	0x11016334, 0x1910001f, 0x11016320, 0x00911002, 0x1950001f, 0x11016330,
	0xe0800005, 0x1890001f, 0x110163a8, 0x1052081f, 0x1890001f, 0x11016330,
	0x10d3081f, 0x00d28803, 0x00d10803, 0x10000c1f, 0x18c0001f, 0x11016348,
	0xa9c00007, 0x00000001, 0x89c00007, 0xfffffff9, 0x17c07c1f, 0x17c07c1f,
	0xe0c0000d, 0x19300003, 0x17c07c1f, 0x39600004, 0x00000064, 0xd820bec5,
	0x17c07c1f, 0x1890001f, 0x110163a8, 0x08800002, 0x00030d40, 0x18c0001f,
	0x110163c0, 0xe0c00002, 0x1880001f, 0x00000046, 0x18c0001f, 0x00000055,
	0x1910001f, 0x11016348, 0x1940001f, 0x110163c0, 0x1990001f, 0x110163a8,
	0x20600c04, 0xd820c101, 0x17c07c1f, 0x09800006, 0x000186a0, 0xe1400006,
	0xd000dce0, 0x17c07c1f, 0x40600804, 0xd820c1c1, 0x17c07c1f, 0x09a00006,
	0x000186a0, 0xe1400006, 0xd000dce0, 0x17c07c1f, 0x1880001f, 0x11016334,
	0x08800002, 0x0000000c, 0x18d0001f, 0x11016330, 0xe0800003, 0x1890001f,
	0x110163a8, 0x1052081f, 0x1890001f, 0x11016330, 0x10d3081f, 0x00d28803,
	0x00d10803, 0x10000c1f, 0x18c0001f, 0x11016348, 0xa9c00007, 0x00000001,
	0x89c00007, 0xfffffff9, 0x17c07c1f, 0x17c07c1f, 0xe0c0000d, 0x1890001f,
	0x110163a8, 0x1052081f, 0x1890001f, 0x110163cc, 0x10d3081f, 0x00d28803,
	0x00d10803, 0x10000c1f, 0x18c0001f, 0x110163d0, 0xa9c00007, 0x00000001,
	0x89c00007, 0xfffffff9, 0x17c07c1f, 0x17c07c1f, 0xe0c0000d, 0x1880001f,
	0x110163cc, 0xe0a00000, 0x1940001f, 0x1101634c, 0x1850001f, 0x11016334,
	0x1890001f, 0x11016338, 0x01a00801, 0x48e00006, 0x00000000, 0xd820c943,
	0x17c07c1f, 0x01a00402, 0xe1400006, 0x1850001f, 0x11016338, 0x1890001f,
	0x1101633c, 0x01a00801, 0x48e00006, 0x00000000, 0xd820caa3, 0x17c07c1f,
	0x01a00402, 0x18f00005, 0x17c07c1f, 0x00c01803, 0xe1400003, 0x1850001f,
	0x1101633c, 0x1890001f, 0x11016340, 0x01a00801, 0x48e00006, 0x00000000,
	0xd820cc63, 0x17c07c1f, 0x01a00402, 0x18f00005, 0x17c07c1f, 0x00c01803,
	0xe1400003, 0x18c0001f, 0x11016334, 0x18b00003, 0x17c07c1f, 0x08c00003,
	0x00000004, 0x19300003, 0x17c07c1f, 0x00801002, 0x08c00003, 0x00000004,
	0x19300003, 0x17c07c1f, 0x00801002, 0x08c00003, 0x00000004, 0x19300003,
	0x17c07c1f, 0x00801002, 0x1940001f, 0x110163b8, 0xe1400002, 0x10d1881f,
	0x00d10803, 0x00d08803, 0x00d00803, 0x10000c1f, 0x1840001f, 0x00000190,
	0xa9c00007, 0x00000001, 0x89c00007, 0xfffffff9, 0x17c07c1f, 0x17c07c1f,
	0x18c0001f, 0x110163b4, 0xe0c0000d, 0x1890001f, 0x110163b8, 0x1910001f,
	0x110163b4, 0x18d0001f, 0x1101634c, 0x1a00001f, 0x11016394, 0x1a40001f,
	0x11016334, 0x21601003, 0xd820d3c5, 0x17c07c1f, 0x1181081f, 0xe2200001,
	0xd000d460, 0x17c07c1f, 0x0a400009, 0x0000000c, 0x19b00009, 0x17c07c1f,
	0xe2200002, 0x1182181f, 0x18c0001f, 0x110163bc, 0xe0c00006, 0x1900001f,
	0x110163c0, 0xe1000006, 0x1890001f, 0x11016318, 0x38e00002, 0x00000010,
	0xd820d763, 0x17c07c1f, 0x1910001f, 0x110163bc, 0xc100f1c0, 0x17c07c1f,
	0x1900001f, 0x110163c0, 0x08c00003, 0x00004e20, 0xe1000003, 0xd000da00,
	0x17c07c1f, 0x1890001f, 0x11016348, 0x18d0001f, 0x110163d0, 0x00a00c02,
	0x18c0001f, 0x110163d4, 0xe0c00002, 0x38e00002, 0x00000046, 0xd820da03,
	0x17c07c1f, 0x1910001f, 0x110163bc, 0xc100f1c0, 0x17c07c1f, 0x1900001f,
	0x110163c0, 0x08c00003, 0x00004e20, 0xe1000003, 0x1880001f, 0x11016334,
	0x18c0001f, 0x11016334, 0x08c00003, 0x00000004, 0x19300003, 0x17c07c1f,
	0xe0800004, 0x08800002, 0x00000004, 0x08c00003, 0x00000004, 0x19300003,
	0x17c07c1f, 0xe0800004, 0x08800002, 0x00000004, 0x08c00003, 0x00000004,
	0x19300003, 0x17c07c1f, 0xe0800004, 0x1890001f, 0x11016320, 0x08800002,
	0x00000001, 0x18c0001f, 0x11016320, 0xe0c00002, 0x1910001f, 0x110163c0,
	0x1890001f, 0x110163ac, 0x40e00804, 0xd820df43, 0x17c07c1f, 0x18c0001f,
	0x110163c0, 0xe0c00002, 0x1910001f, 0x110163c0, 0x1950001f, 0x110163ec,
	0x28e00005, 0x00000000, 0xd820e023, 0x17c07c1f, 0x01001404, 0xc100f1c0,
	0x17c07c1f, 0xc100f720, 0x17c07c1f, 0xc0800920, 0x17c07c1f, 0x1890001f,
	0x11016600, 0x08800002, 0x00000001, 0x18c0001f, 0x11016600, 0xe0c00002,
	0x1890001f, 0x1101662c, 0x28e00002, 0x00000000, 0xd820e323, 0x17c07c1f,
	0x18c0001f, 0x1101662c, 0x08a00002, 0x00000001, 0xe0c00002, 0x1890001f,
	0x11016630, 0x68e00002, 0x00000000, 0xd800e4c3, 0x17c07c1f, 0x18c0001f,
	0x11016630, 0x08a00002, 0x00000001, 0xe0c00002, 0xd0008520, 0x17c07c1f,
	0xe8208000, 0x11016634, 0x00000000, 0x1890001f, 0x110163c8, 0x68e00002,
	0x00000000, 0xc8800ea3, 0x17c07c1f, 0x1850001f, 0x110163c4, 0x69200001,
	0x00000000, 0xd800e744, 0x17c07c1f, 0xe8208000, 0x110163c8, 0x00000000,
	0xd000e7a0, 0x17c07c1f, 0xe8208000, 0x110163c8, 0x00000001, 0x1880001f,
	0x11016644, 0x18d0001f, 0x11016640, 0xe0800003, 0x1890001f, 0x11016634,
	0xd800e942, 0x17c07c1f, 0x1b80001f, 0x20006590, 0xd000e980, 0x17c07c1f,
	0x1b80001f, 0x20004510, 0xd0008520, 0x17c07c1f, 0x1940001f, 0x11016640,
	0x1980001f, 0x11016644, 0x1910001f, 0x11016648, 0xe1400004, 0x1880001f,
	0x00000001, 0x80c01002, 0xd8008523, 0x17c07c1f, 0xe1800004, 0xd000ea40,
	0x17c07c1f, 0xf0000000, 0x18d0001f, 0x1000c244, 0x88800003, 0x001fffff,
	0x1152081f, 0x01518805, 0x01508805, 0x108c0c1f, 0x88800002, 0x00000003,
	0x68e00002, 0x00000001, 0xd820ede3, 0x17c07c1f, 0x1187941f, 0xd000eec0,
	0x17c07c1f, 0x68e00002, 0x00000002, 0xd820eea3, 0x1188141f, 0xd000eec0,
	0x17c07c1f, 0x1188941f, 0x1094981f, 0x00941802, 0x00939802, 0x00931802,
	0x00929802, 0x00919802, 0x12c0081f, 0xf0000000, 0x17c07c1f, 0x1800001f,
	0x11016844, 0xe0000002, 0x0880000b, 0x00000001, 0x1091081f, 0x08800002,
	0x11016800, 0x18300002, 0x17c07c1f, 0x1890001f, 0x11016844, 0x12c0001f,
	0xf0000000, 0x17c07c1f, 0x10c02c1f, 0x1900001f, 0x00000000, 0x1940001f,
	0x11016800, 0x09400005, 0x00000004, 0x09000004, 0x00000001, 0x38b00004,
	0x11016800, 0xd800f462, 0x17c07c1f, 0x00911005, 0x18b00002, 0x17c07c1f,
	0x20a00803, 0xd800f462, 0x17c07c1f, 0xd000f2a0, 0x17c07c1f, 0x1890001f,
	0x1101662c, 0x28e00002, 0x00000000, 0xd820f5a3, 0x17c07c1f, 0x1910001f,
	0x11016628, 0x09000004, 0x00000001, 0x1940001f, 0x11016800, 0x00d11005,
	0x18f00003, 0x17c07c1f, 0x09100004, 0x11016800, 0x00911005, 0x18b00002,
	0x17c07c1f, 0xf0000000, 0x17c07c1f, 0x09200004, 0x00000009, 0x89000004,
	0x00000007, 0x1950001f, 0x110163d8, 0x1151941f, 0xa1401005, 0x1900001f,
	0x110163d8, 0xe1000005, 0xf0000000, 0x17c07c1f, 0xf0000000, 0x17c07c1f
};


struct pcm_desc dvfs_gpu_pcm = {
	.version	= "SPM_PCMASM_JADE_20150421",
	.base		= dvfs_gpu_binary,
	.size		= 1992,
	.sess		= 2,
	.replace	= 0,
};

