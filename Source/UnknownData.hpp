/*
 *  Cannon Fodder
 *  ------------------------
 *
 *  Copyright (C) 2008-2017 Robert Crossfield
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

const int8 byte_3E98F[] = {
  0, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1
};

const int16 mMap_Direction_Calculations[256] = {
	0, 804, 1608, 2410, 3212, 4011, 4808, 5602, 6393, 7179,
	7962, 8739, 9512, 10278, 11039, 11793, 12539, 13279, 14010, 14732,
	15446, 16151, 16846, 17530, 18204, 18867, 19519, 20159, 20787, 21402,
	22005, 22594, 23170, 23731, 24279, 24811, 25329, 25832, 26319, 26790,
	27245, 27683, 28105, 28510, 28898, 29268, 29621, 29956, 30273, 30571,
	30852, 31113, 31356, 31580, 31785, 31971, 32137, 32285, 32412, 32521,
	32609, 32678, 32728, 32757, 32767, 32757, 32728, 32678, 32609, 32521,
	32412, 32285, 32137, 31971, 31785, 31580, 31356, 31113, 30852, 30571,
	30273, 29956, 29621, 29268, 28898, 28510, 28105, 27683, 27245, 26790,
	26319, 25832, 25329, 24812, 24279, 23731, 23170, 22594, 22005, 21403,
	20787, 20159, 19519, 18868, 18204, 17530, 16846, 16151, 15446, 14732,
	14010, 13279, 12539, 11793, 11039, 10278, 9512, 8739, 7962, 7179,
	6393, 5602, 4808, 4011, 3212, 2411, 1608, 804, 0, -804,

	-1608, -2410, -3212, -4011, -4808, -5602, -6393, -7179, -7962, -8739,
	-9512, -10278, -11039, -11793, -12539, -13279, -14010, -14732, -15446, -16151,
	-16846, -17530, -18204, -18868, -19519, -20159, -20787, -21403, -22005, -22594,
	-23170, -23731, -24279, -24812, -25329, -25832, -26319, -26790, -27245, -27683,
	-28105, -28510, -28898, -29268, -29621, -29956, -30273, -30571, -30852, -31113,
	-31356, -31580, -31785, -31971, -32137, -32285, -32412, -32521, -32609, -32678,
	-32728, -32757, -32767, -32757, -32728, -32678, -32609, -32521, -32412, -32285,
	-32137, -31971, -31785, -31580, -31356, -31113, -30852, -30571, -30273, -29956,
	-29621, -29268, -28898, -28510, -28105, -27683, -27245, -26790, -26319, -25832,
	-25329, -24811, -24279, -23731, -23170, -22594, -22005, -21402, -20787, -20159,
	-19519, -18867, -18204, -17530, -16845, -16151, -15446, -14732, -14009, -13278,
	-12539, -11792, -11039, -10278, -9512, -8739, -7961, -7179, -6392, -5602,
	-4808, -4011, -3211, -2410, -1608, -804
};

const int8 mMap_Distance_Calculations[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
	13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 
	23, 24, 25, 26, 27, 28, 29, 30, 31,

	1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 
	13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 
	23, 24, 25, 26, 27, 28, 29, 30, 31,

	2, 2, 3, 4, 4, 5, 
	6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
	16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 
	26, 27, 28, 29, 30, 31, 
	
	3, 3, 4, 4, 5, 6, 7, 8, 9, 9, 10, 11, 12,
	13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 
	24, 25, 26, 27, 28, 29, 30, 31, 
	
	4, 4, 4, 5, 6, 6, 7, 8, 9, 10, 11, 12, 
	13, 14, 15, 16, 16, 17, 18, 19, 20, 21, 
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 
	5, 5, 5, 6, 6, 7, 8, 9, 9, 10, 
	11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
	21, 22, 23, 24, 25, 25, 26, 27, 28, 29, 
	30, 31, 6, 6, 6, 7, 7, 8, 8, 9, 
	10, 11, 12, 13, 13, 14, 15, 16, 17, 18, 
	19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 
	29, 30, 31, 32, 7, 7, 7, 8, 8, 9, 
	9, 10, 11, 11, 12, 13, 14, 15, 16, 17, 
	17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
	27, 28, 29, 30, 31, 32, 8, 8, 8, 9, 
	9, 9, 10, 11, 11, 12, 13, 14, 14, 15, 
	16, 17, 18, 19, 20, 21, 22, 22, 23, 24, 
	25, 26, 27, 28, 29, 30, 31, 32, 9, 9, 
	9, 9, 10, 10, 11, 11, 12, 13, 13, 14, 
	15, 16, 17, 17, 18, 19, 20, 21, 22, 23, 
	24, 25, 26, 27, 28, 28, 29, 30, 31, 32, 
	10, 10, 10, 10, 11, 11, 12, 12, 13, 13, 
	14, 15, 16, 16, 17, 18, 19, 20, 21, 21, 
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 
	32, 33, 11, 11, 11, 11, 12, 12, 13, 13, 
	14, 14, 15, 16, 16, 17, 18, 19, 19, 20, 
	21, 22, 23, 24, 25, 25, 26, 27, 28, 29, 
	30, 31, 32, 33, 12, 12, 12, 12, 13, 13, 
	13, 14, 14, 15, 16, 16, 17, 18, 18, 19, 
	20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 
	29, 30, 30, 31, 32, 33, 13, 13, 13, 13, 
	14, 14, 14, 15, 15, 16, 16, 17, 18, 18, 
	19, 20, 21, 21, 22, 23, 24, 25, 26, 26, 
	27, 28, 29, 30, 31, 32, 33, 34, 14, 14, 
	14, 14, 15, 15, 15, 16, 16, 17, 17, 18, 
	18, 19, 20, 21, 21, 22, 23, 24, 24, 25, 
	26, 27, 28, 29, 30, 30, 31, 32, 33, 34, 
	15, 15, 15, 15, 16, 16, 16, 17, 17, 17, 
	18, 19, 19, 20, 21, 21, 22, 23, 23, 24, 
	25, 26, 27, 27, 28, 29, 30, 31, 32, 33, 
	34, 34, 16, 16, 16, 16, 16, 17, 17, 17, 
	18, 18, 19, 19, 20, 21, 21, 22, 23, 23, 
	24, 25, 26, 26, 27, 28, 29, 30, 31, 31, 
	32, 33, 34, 35, 17, 17, 17, 17, 17, 18, 
	18, 18, 19, 19, 20, 20, 21, 21, 22, 23, 
	23, 24, 25, 25, 26, 27, 28, 29, 29, 30, 
	31, 32, 33, 34, 34, 35, 18, 18, 18, 18, 
	18, 19, 19, 19, 20, 20, 21, 21, 22, 22, 
	23, 23, 24, 25, 25, 26, 27, 28, 28, 29, 
	30, 31, 32, 32, 33, 34, 35, 36, 19, 19, 
	19, 19, 19, 20, 20, 20, 21, 21, 21, 22, 
	22, 23, 24, 24, 25, 25, 26, 27, 28, 28, 
	29, 30, 31, 31, 32, 33, 34, 35, 36, 36, 
	20, 20, 20, 20, 20, 21, 21, 21, 22, 22, 
	22, 23, 23, 24, 24, 25, 26, 26, 27, 28, 
	28, 29, 30, 30, 31, 32, 33, 34, 34, 35, 
	36, 37, 21, 21, 21, 21, 21, 22, 22, 22, 
	22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 
	28, 28, 29, 30, 30, 31, 32, 33, 33, 34, 
	35, 36, 37, 37, 22, 22, 22, 22, 22, 23, 
	23, 23, 23, 24, 24, 25, 25, 26, 26, 27, 
	27, 28, 28, 29, 30, 30, 31, 32, 33, 33, 
	34, 35, 36, 36, 37, 38, 23, 23, 23, 23, 
	23, 24, 24, 24, 24, 25, 25, 25, 26, 26, 
	27, 27, 28, 29, 29, 30, 30, 31, 32, 33, 
	33, 34, 35, 35, 36, 37, 38, 39, 24, 24, 
	24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 
	27, 27, 28, 28, 29, 29, 30, 31, 31, 32, 
	33, 33, 34, 35, 35, 36, 37, 38, 38, 39, 
	25, 25, 25, 25, 25, 25, 26, 26, 26, 27, 
	27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 
	32, 33, 33, 34, 35, 35, 36, 37, 38, 38, 
	39, 40, 26, 26, 26, 26, 26, 26, 27, 27, 
	27, 28, 28, 28, 29, 29, 30, 30, 31, 31, 
	32, 32, 33, 33, 34, 35, 35, 36, 37, 37, 
	38, 39, 40, 40, 27, 27, 27, 27, 27, 27, 
	28, 28, 28, 28, 29, 29, 30, 30, 30, 31, 
	31, 32, 32, 33, 34, 34, 35, 35, 36, 37, 
	37, 38, 39, 40, 40, 41, 28, 28, 28, 28, 
	28, 28, 29, 29, 29, 29, 30, 30, 30, 31, 
	31, 32, 32, 33, 33, 34, 34, 35, 36, 36, 
	37, 38, 38, 39, 40, 40, 41, 42, 29, 29, 
	29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 
	31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 
	36, 37, 38, 38, 39, 40, 40, 41, 42, 42, 
	30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 
	32, 32, 32, 33, 33, 34, 34, 34, 35, 36, 
	36, 37, 37, 38, 38, 39, 40, 40, 41, 42, 
	42, 43, 31, 31, 31, 31, 31, 31, 32, 32, 
	32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 
	36, 36, 37, 37, 38, 39, 39, 40, 40, 41, 
	42, 42, 43, 44, 26
};

const int16 word_3D495[] = {
  0x18, 0x14, 0x0E, 0x0A, 0x08, 
  0x0A, 0x0E, 0x14
};

const int16 word_428DC[] =
{
   0x0180, 0x0040, 0x0004, 0x01A0, 0x0040, 
   0x000F, 0x01C0, 0x0040, 0x0007, 0x01E0, 
   0x0020, 0x0007, 0x0000, 0x0010, 0x000A, 
   0x0080, 0x0010, 0x001E, 0x0100, 0x0010, 
   0x000A, 0x01A0, 0x0008, 0x0019, 0x0170, 
   0x0064, 0x000A, -1, -1, -1
};

const int16 word_428CE[] = {
	0x00, 0x20, 0x40, 0x60 
};

int16 word_32AEC[] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 
  0x05, 0x06, 0x07, 0x20, 0x21, 
  0x22, 0x23, 0x24, 0x25, 0x26, 
  0x27, 0x28, 0x29, 0x22, 0x2B, 
  0x2C, 0x2D, 0x2E, 0x2F, 0x30, 
  0x31, 0x32, 0x33, 0x34, 0x35, 
  0x36, 0x37, 0x18, 0x19, 0x1A, 
  0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 
  0x08, 0x09, 0x0A, 0x0B, 0x0C, 
  0x0D, 0x0E, 0x0F, 0x10, 0x11, 
  0x12, 0x13, 0x14, 0x15, 0x16, 
  0x17, 0x39, 0x3A, 0x3B, 0x3C, 
  0x3D, 0x3E, 0x3F, 0x40, 0xB0, 
  0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 
  0xB6, 0xB7
};

int16 word_32B7C[] = {
  0x42, 0x43, 0x44, 0x45, 0x46,
  0x47, 0x48, 0x49, 0x62, 0x63,
  0x64, 0x65, 0x66, 0x67, 0x68,
  0x69, 0x6A, 0x6B, 0x64, 0x6D,
  0x6E, 0x6F, 0x70, 0x71, 0x72,
  0x73, 0x74, 0x75, 0x76, 0x77,
  0x78, 0x79, 0x5A, 0x5B, 0x5C,
  0x5D, 0x5E, 0x5F, 0x60, 0x61,
  0x4A, 0x4B, 0x4C, 0x4D, 0x4E,
  0x4F, 0x50, 0x51, 0x52, 0x53,
  0x54, 0x55, 0x56, 0x57, 0x58,
  0x59, 0xA8, 0xA9, 0xAA, 0xAB,
  0xAC, 0xAD, 0xAE, 0xAF, 0xB8,
  0xB9, 0xBA, 0xBB, 0xBC, 0xBD,
  0xBE, 0xBF, 
};

int16* mSprite_AnimationPtrs[] = {
	word_32AEC,
	word_32B7C
};

const int16 mDirectionData[] = {
	-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 64, 32, 16, 11, 8, 6, 5, 5, 
	4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 64, 48, 32, 21, 16, 13, 
	11, 9, 8, 7, 6, 6, 5, 5, 5, 4, 
	4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 
	2, 2, 2, 2, 2, 2, 64, 53, 43, 32, 
	24, 19, 16, 14, 12, 11, 10, 9, 8, 7, 
	7, 6, 6, 6, 5, 5, 5, 5, 4, 4, 
	4, 4, 4, 4, 3, 3, 3, 3, 64, 56, 
	48, 40, 32, 26, 21, 18, 16, 14, 13, 12, 
	11, 10, 9, 9, 8, 8, 7, 7, 6, 6, 
	6, 6, 5, 5, 5, 5, 5, 4, 4, 4, 
	64, 58, 51, 45, 38, 32, 27, 23, 20, 18, 
	16, 15, 13, 12, 11, 11, 10, 9, 9, 8, 
	8, 8, 7, 7, 7, 6, 6, 6, 6, 6, 
	5, 5, 64, 59, 53, 48, 43, 37, 32, 27, 
	24, 21, 19, 17, 16, 15, 14, 13, 12, 11, 
	11, 10, 10, 9, 9, 8, 8, 8, 7, 7, 
	7, 7, 6, 6, 64, 59, 55, 50, 46, 41, 
	37, 32, 28, 25, 22, 20, 19, 17, 16, 15, 
	14, 13, 12, 12, 11, 11, 10, 10, 9, 9, 
	9, 8, 8, 8, 7, 7, 64, 60, 56, 52, 
	48, 44, 40, 36, 32, 28, 26, 23, 21, 20, 
	18, 17, 16, 15, 14, 13, 13, 12, 12, 11, 
	11, 10, 10, 9, 9, 9, 9, 8, 64, 60, 
	57, 53, 50, 46, 43, 39, 36, 32, 29, 26, 
	24, 22, 21, 19, 18, 17, 16, 15, 14, 14, 
	13, 13, 12, 12, 11, 11, 10, 10, 10, 9, 
	64, 61, 58, 54, 51, 48, 45, 42, 38, 35, 
	32, 29, 27, 25, 23, 21, 20, 19, 18, 17, 
	16, 15, 15, 14, 13, 13, 12, 12, 11, 11, 
	11, 10, 64, 61, 58, 55, 52, 49, 47, 44, 
	41, 38, 35, 32, 29, 27, 25, 23, 22, 21, 
	20, 19, 18, 17, 16, 15, 15, 14, 14, 13, 
	13, 12, 12, 11, 64, 61, 59, 56, 53, 51, 
	48, 45, 43, 40, 37, 35, 32, 30, 27, 26, 
	24, 23, 21, 20, 19, 18, 17, 17, 16, 15, 
	15, 14, 14, 13, 13, 12, 64, 62, 59, 57, 
	54, 52, 49, 47, 44, 42, 39, 37, 34, 32, 
	30, 28, 26, 24, 23, 22, 21, 20, 19, 18, 
	17, 17, 16, 15, 15, 14, 14, 13, 64, 62, 
	59, 57, 55, 53, 50, 48, 46, 43, 41, 39, 
	37, 34, 32, 30, 28, 26, 25, 24, 22, 21, 
	20, 19, 19, 18, 17, 17, 16, 15, 15, 14, 
	64, 62, 60, 58, 55, 53, 51, 49, 47, 45, 
	43, 41, 38, 36, 34, 32, 30, 28, 27, 25, 
	24, 23, 22, 21, 20, 19, 18, 18, 17, 17, 
	16, 15, 64, 62, 60, 58, 56, 54, 52, 50, 
	48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 
	28, 27, 26, 24, 23, 22, 21, 20, 20, 19, 
	18, 18, 17, 17, 64, 62, 60, 58, 56, 55, 
	53, 51, 49, 47, 45, 43, 41, 40, 38, 36, 
	34, 32, 30, 29, 27, 26, 25, 24, 23, 22, 
	21, 20, 19, 19, 18, 18, 64, 62, 60, 59, 
	57, 55, 53, 52, 50, 48, 46, 44, 43, 41, 
	39, 37, 36, 34, 32, 30, 29, 27, 26, 25, 
	24, 23, 22, 21, 21, 20, 19, 19, 64, 62, 
	61, 59, 57, 56, 54, 52, 51, 49, 47, 45, 
	44, 42, 40, 39, 37, 35, 34, 32, 30, 29, 
	28, 26, 25, 24, 23, 23, 22, 21, 20, 20, 
	64, 62, 61, 59, 58, 56, 54, 53, 51, 50, 
	48, 46, 45, 43, 42, 40, 38, 37, 35, 34, 
	32, 30, 29, 28, 27, 26, 25, 24, 23, 22, 
	21, 21, 64, 62, 61, 59, 58, 56, 55, 53, 
	52, 50, 49, 47, 46, 44, 43, 41, 40, 38, 
	37, 35, 34, 32, 31, 29, 28, 27, 26, 25, 
	24, 23, 22, 22, 64, 63, 61, 60, 58, 57, 
	55, 54, 52, 51, 49, 48, 47, 45, 44, 42, 
	41, 39, 38, 36, 35, 33, 32, 31, 29, 28, 
	27, 26, 25, 24, 23, 23, 64, 63, 61, 60, 
	58, 57, 56, 54, 53, 51, 50, 49, 47, 46, 
	45, 43, 42, 40, 39, 38, 36, 35, 33, 32, 
	31, 29, 28, 27, 26, 25, 25, 24, 64, 63, 
	61, 60, 59, 57, 56, 55, 53, 52, 51, 49, 
	48, 47, 45, 44, 43, 41, 40, 39, 37, 36, 
	35, 33, 32, 31, 30, 28, 27, 26, 26, 25, 
	64, 63, 61, 60, 59, 58, 56, 55, 54, 52, 
	51, 50, 49, 47, 46, 45, 44, 42, 41, 40, 
	38, 37, 36, 35, 33, 32, 31, 30, 29, 28, 
	27, 26, 64, 63, 62, 60, 59, 58, 57, 55, 
	54, 53, 52, 50, 49, 48, 47, 46, 44, 43, 
	42, 41, 39, 38, 37, 36, 34, 33, 32, 31, 
	30, 29, 28, 27, 64, 63, 62, 60, 59, 58, 
	57, 56, 55, 53, 52, 51, 50, 49, 47, 46, 
	45, 44, 43, 41, 40, 39, 38, 37, 36, 34, 
	33, 32, 31, 30, 29, 28, 64, 63, 62, 61, 
	59, 58, 57, 56, 55, 54, 53, 51, 50, 49, 
	48, 47, 46, 45, 43, 42, 41, 40, 39, 38, 
	37, 35, 34, 33, 32, 31, 30, 29, 64, 63, 
	62, 61, 60, 58, 57, 56, 55, 54, 53, 52, 
	51, 50, 49, 47, 46, 45, 44, 43, 42, 41, 
	40, 39, 38, 36, 35, 34, 33, 32, 31, 30, 
	64, 63, 62, 61, 60, 59, 58, 57, 55, 54, 
	53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 
	43, 42, 41, 39, 38, 37, 36, 35, 34, 33, 
	32, 31, 64, 63, 62, 61, 60, 59, 58, 57, 
	56, 55, 54, 53, 52, 51, 50, 49, 47, 46, 
	45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 
	35, 34, 33, 32, 
};

const int16 mTroop_Rotate_Fire_SquadOf1[] = {
	0, 
	-1
};

const int16 mTroop_Rotate_Fire_SquadOf2[] = {
	0, 1, 
	-1
};

const int16 mTroop_Rotate_Fire_SquadOf3[] = {
	0, 1, 0, 2, 
	-1
};

const int16 mTroop_Rotate_Fire_SquadOf4[] = {
	0, 1, 0, 2, 0, 3, 0, 2, 
	-1
};

const int16 mTroop_Rotate_Fire_SquadOf5[] = {
	0, 1, 0, 2, 0, 3, 0, 4, 0, 3,
	0, 2, 
	-1,
};


const int16 mTroop_Rotate_Fire_SquadOf6[] = {
	0, 1, 0, 2, 0, 3, 0, 4, 0, 5,
	0, 4, 0, 3, 0, 2, 
	-1
};

const int16 mTroop_Rotate_Fire_SquadOf7[] = {
	0, 1, 0, 2, 0, 3, 0, 4, 0, 5,
	0, 6, 0, 5, 0, 4, 0, 3, 0, 2,
	-1, 
};

const int16 mTroop_Rotate_Fire_SquadOf8[] = {
	0, 1, 0, 2, 0, 3, 0, 4, 0, 5,
	0, 6, 0, 5, 0, 4, 0, 3, 0, 2,
	-1
};

const int16* mTroop_Rotate_Fire_Order[] = {
	mTroop_Rotate_Fire_SquadOf1,
	mTroop_Rotate_Fire_SquadOf2,
	mTroop_Rotate_Fire_SquadOf3,
	mTroop_Rotate_Fire_SquadOf4,
	mTroop_Rotate_Fire_SquadOf5,
	mTroop_Rotate_Fire_SquadOf6,
	mTroop_Rotate_Fire_SquadOf7,
	mTroop_Rotate_Fire_SquadOf8
};
