#ifndef SERIAL_H
#define SERIAL_H

// #define TABLE_SIZE_512
# define TABLE_SIZE_256

#ifdef TABLE_SIZE_512

// High byte with 512 samples per period
const uint8_t buf_hi[512] = {
	0x80, 0x81, 0x83, 0x84, 0x86, 0x87, 0x89, 0x8a, 0x8c, 0x8e, 0x8f, 0x91, 0x92, 0x94, 0x95, 0x97, 
	0x98, 0x9a, 0x9c, 0x9d, 0x9f, 0xa0, 0xa2, 0xa3, 0xa5, 0xa6, 0xa8, 0xa9, 0xab, 0xac, 0xae, 0xaf, 
	0xb0, 0xb2, 0xb3, 0xb5, 0xb6, 0xb8, 0xb9, 0xba, 0xbc, 0xbd, 0xbf, 0xc0, 0xc1, 0xc3, 0xc4, 0xc5, 
	0xc7, 0xc8, 0xc9, 0xca, 0xcc, 0xcd, 0xce, 0xcf, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd7, 0xd8, 0xd9, 
	0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 
	0xea, 0xeb, 0xec, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf0, 0xf1, 0xf2, 0xf3, 0xf3, 0xf4, 0xf5, 0xf5, 
	0xf6, 0xf6, 0xf7, 0xf7, 0xf8, 0xf9, 0xf9, 0xfa, 0xfa, 0xfa, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc, 0xfd, 
	0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfd, 
	0xfd, 0xfd, 0xfc, 0xfc, 0xfc, 0xfb, 0xfb, 0xfa, 0xfa, 0xfa, 0xf9, 0xf9, 0xf8, 0xf7, 0xf7, 0xf6, 
	0xf6, 0xf5, 0xf5, 0xf4, 0xf3, 0xf3, 0xf2, 0xf1, 0xf0, 0xf0, 0xef, 0xee, 0xed, 0xec, 0xec, 0xeb, 
	0xea, 0xe9, 0xe8, 0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xe0, 0xdf, 0xde, 0xdd, 0xdc, 0xdb, 
	0xda, 0xd9, 0xd8, 0xd7, 0xd5, 0xd4, 0xd3, 0xd2, 0xd1, 0xcf, 0xce, 0xcd, 0xcc, 0xca, 0xc9, 0xc8, 
	0xc7, 0xc5, 0xc4, 0xc3, 0xc1, 0xc0, 0xbf, 0xbd, 0xbc, 0xba, 0xb9, 0xb8, 0xb6, 0xb5, 0xb3, 0xb2, 
	0xb0, 0xaf, 0xae, 0xac, 0xab, 0xa9, 0xa8, 0xa6, 0xa5, 0xa3, 0xa2, 0xa0, 0x9f, 0x9d, 0x9c, 0x9a, 
	0x98, 0x97, 0x95, 0x94, 0x92, 0x91, 0x8f, 0x8e, 0x8c, 0x8a, 0x89, 0x87, 0x86, 0x84, 0x83, 0x81, 
	0x80, 0x7e, 0x7c, 0x7b, 0x79, 0x78, 0x76, 0x75, 0x73, 0x71, 0x70, 0x6e, 0x6d, 0x6b, 0x6a, 0x68, 
	0x67, 0x65, 0x63, 0x62, 0x60, 0x5f, 0x5d, 0x5c, 0x5a, 0x59, 0x57, 0x56, 0x54, 0x53, 0x51, 0x50, 
	0x4f, 0x4d, 0x4c, 0x4a, 0x49, 0x47, 0x46, 0x45, 0x43, 0x42, 0x40, 0x3f, 0x3e, 0x3c, 0x3b, 0x3a, 
	0x38, 0x37, 0x36, 0x35, 0x33, 0x32, 0x31, 0x30, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a, 0x28, 0x27, 0x26, 
	0x25, 0x24, 0x23, 0x22, 0x21, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 0x16, 
	0x15, 0x14, 0x13, 0x13, 0x12, 0x11, 0x10, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c, 0x0c, 0x0b, 0x0a, 0x0a, 
	0x09, 0x09, 0x08, 0x08, 0x07, 0x06, 0x06, 0x05, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03, 0x03, 0x02, 
	0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 
	0x02, 0x02, 0x03, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09, 
	0x09, 0x0a, 0x0a, 0x0b, 0x0c, 0x0c, 0x0d, 0x0e, 0x0f, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x13, 0x14, 
	0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 
	0x25, 0x26, 0x27, 0x28, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x30, 0x31, 0x32, 0x33, 0x35, 0x36, 0x37, 
	0x38, 0x3a, 0x3b, 0x3c, 0x3e, 0x3f, 0x40, 0x42, 0x43, 0x45, 0x46, 0x47, 0x49, 0x4a, 0x4c, 0x4d, 
	0x4f, 0x50, 0x51, 0x53, 0x54, 0x56, 0x57, 0x59, 0x5a, 0x5c, 0x5d, 0x5f, 0x60, 0x62, 0x63, 0x65, 
	0x67, 0x68, 0x6a, 0x6b, 0x6d, 0x6e, 0x70, 0x71, 0x73, 0x75, 0x76, 0x78, 0x79, 0x7b, 0x7c, 0x7e
};

// Low nybble with 512 samples per period
const uint8_t buf_lo[512] = {
	0x00, 0x90, 0x20, 0xb0, 0x40, 0xd0, 0x60, 0xf0, 0x80, 0x10, 0xa0, 0x30, 0xc0, 0x50, 0xe0, 0x60, 
	0xf0, 0x80, 0x00, 0x90, 0x10, 0x90, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x10, 0x90, 0x10, 0x80, 
	0xf0, 0x60, 0xd0, 0x40, 0xb0, 0x20, 0x80, 0xf0, 0x50, 0xb0, 0x10, 0x70, 0xc0, 0x20, 0x70, 0xc0, 
	0x10, 0x60, 0xb0, 0xf0, 0x30, 0x80, 0xb0, 0xf0, 0x30, 0x60, 0x90, 0xc0, 0xf0, 0x10, 0x40, 0x60, 
	0x80, 0x90, 0xb0, 0xc0, 0xd0, 0xe0, 0xe0, 0xf0, 0xf0, 0xe0, 0xe0, 0xd0, 0xc0, 0xb0, 0xa0, 0x80, 
	0x60, 0x40, 0x20, 0xf0, 0xc0, 0x90, 0x50, 0x20, 0xe0, 0x90, 0x50, 0x00, 0xb0, 0x50, 0x00, 0xa0, 
	0x40, 0xd0, 0x60, 0xf0, 0x80, 0x00, 0x80, 0x00, 0x70, 0xe0, 0x50, 0xc0, 0x20, 0x80, 0xe0, 0x30, 
	0x80, 0xd0, 0x10, 0x50, 0x90, 0xd0, 0x00, 0x30, 0x60, 0x80, 0xa0, 0xc0, 0xd0, 0xe0, 0xf0, 0xf0, 
	0x00, 0xf0, 0xf0, 0xe0, 0xd0, 0xc0, 0xa0, 0x80, 0x60, 0x30, 0x00, 0xd0, 0x90, 0x50, 0x10, 0xd0, 
	0x80, 0x30, 0xe0, 0x80, 0x20, 0xc0, 0x50, 0xe0, 0x70, 0x00, 0x80, 0x00, 0x80, 0xf0, 0x60, 0xd0, 
	0x40, 0xa0, 0x00, 0x50, 0xb0, 0x00, 0x50, 0x90, 0xe0, 0x20, 0x50, 0x90, 0xc0, 0xf0, 0x20, 0x40, 
	0x60, 0x80, 0xa0, 0xb0, 0xc0, 0xd0, 0xe0, 0xe0, 0xf0, 0xf0, 0xe0, 0xe0, 0xd0, 0xc0, 0xb0, 0x90, 
	0x80, 0x60, 0x40, 0x10, 0xf0, 0xc0, 0x90, 0x60, 0x30, 0xf0, 0xb0, 0x80, 0x30, 0xf0, 0xb0, 0x60, 
	0x10, 0xc0, 0x70, 0x20, 0xc0, 0x70, 0x10, 0xb0, 0x50, 0xf0, 0x80, 0x20, 0xb0, 0x40, 0xd0, 0x60, 
	0xf0, 0x80, 0x10, 0x90, 0x10, 0xa0, 0x20, 0xa0, 0x20, 0xa0, 0x20, 0x90, 0x10, 0x90, 0x00, 0x80, 
	0xf0, 0x60, 0xe0, 0x50, 0xc0, 0x30, 0xa0, 0x10, 0x80, 0xf0, 0x60, 0xd0, 0x40, 0xb0, 0x20, 0x90, 
	0x00, 0x60, 0xd0, 0x40, 0xb0, 0x20, 0x90, 0x00, 0x70, 0xe0, 0x50, 0xc0, 0x30, 0xa0, 0x10, 0x90, 
	0x00, 0x70, 0xf0, 0x60, 0xe0, 0x60, 0xd0, 0x50, 0xd0, 0x50, 0xd0, 0x50, 0xe0, 0x60, 0xe0, 0x70, 
	0x00, 0x90, 0x20, 0xb0, 0x40, 0xd0, 0x70, 0x00, 0xa0, 0x40, 0xe0, 0x80, 0x30, 0xd0, 0x80, 0x30, 
	0xe0, 0x90, 0x40, 0x00, 0xc0, 0x70, 0x40, 0x00, 0xc0, 0x90, 0x60, 0x30, 0x00, 0xe0, 0xb0, 0x90, 
	0x70, 0x60, 0x40, 0x30, 0x20, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x20, 0x30, 0x40, 0x50, 0x70, 
	0x90, 0xb0, 0xd0, 0x00, 0x30, 0x60, 0xa0, 0xd0, 0x10, 0x60, 0xa0, 0xf0, 0x40, 0xa0, 0xf0, 0x50, 
	0xb0, 0x20, 0x90, 0x00, 0x70, 0xf0, 0x70, 0xf0, 0x80, 0x10, 0xa0, 0x30, 0xd0, 0x70, 0x10, 0xc0, 
	0x70, 0x20, 0xe0, 0xa0, 0x60, 0x20, 0xf0, 0xc0, 0x90, 0x70, 0x50, 0x30, 0x20, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x10, 0x20, 0x30, 0x50, 0x70, 0x90, 0xc0, 0xf0, 0x20, 0x60, 0xa0, 0xe0, 0x20, 
	0x70, 0xc0, 0x10, 0x70, 0xd0, 0x30, 0xa0, 0x10, 0x80, 0xf0, 0x70, 0xf0, 0x70, 0x00, 0x90, 0x20, 
	0xb0, 0x50, 0xf0, 0xa0, 0x40, 0xf0, 0xa0, 0x60, 0x10, 0xd0, 0xa0, 0x60, 0x30, 0x00, 0xd0, 0xb0, 
	0x90, 0x70, 0x50, 0x40, 0x30, 0x20, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x20, 0x30, 0x40, 0x60, 
	0x70, 0x90, 0xb0, 0xe0, 0x00, 0x30, 0x60, 0x90, 0xc0, 0x00, 0x40, 0x70, 0xc0, 0x00, 0x40, 0x90, 
	0xe0, 0x30, 0x80, 0xd0, 0x30, 0x80, 0xe0, 0x40, 0xa0, 0x00, 0x70, 0xd0, 0x40, 0xb0, 0x20, 0x90, 
	0x00, 0x70, 0xe0, 0x60, 0xe0, 0x50, 0xd0, 0x50, 0xd0, 0x50, 0xd0, 0x60, 0xe0, 0x60, 0xf0, 0x70, 
	0x00, 0x90, 0x10, 0xa0, 0x30, 0xc0, 0x50, 0xe0, 0x70, 0x00, 0x90, 0x20, 0xb0, 0x40, 0xd0, 0x60
};
#endif

#ifdef TABLE_SIZE_256
// High byte with 256 samples per period
const uint8_t buf_hi[256] = {
	0x80, 0x83, 0x86, 0x89, 0x8c, 0x8f, 0x92, 0x95, 0x98, 0x9c, 0x9f, 0xa2, 0xa5, 0xa8, 0xab, 0xae, 
	0xb0, 0xb3, 0xb6, 0xb9, 0xbc, 0xbf, 0xc1, 0xc4, 0xc7, 0xc9, 0xcc, 0xce, 0xd1, 0xd3, 0xd5, 0xd8, 
	0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xed, 0xef, 0xf0, 0xf2, 0xf3, 0xf5, 
	0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfc, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfd, 0xfc, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 
	0xf6, 0xf5, 0xf3, 0xf2, 0xf0, 0xef, 0xed, 0xec, 0xea, 0xe8, 0xe6, 0xe4, 0xe2, 0xe0, 0xde, 0xdc, 
	0xda, 0xd8, 0xd5, 0xd3, 0xd1, 0xce, 0xcc, 0xc9, 0xc7, 0xc4, 0xc1, 0xbf, 0xbc, 0xb9, 0xb6, 0xb3, 
	0xb0, 0xae, 0xab, 0xa8, 0xa5, 0xa2, 0x9f, 0x9c, 0x98, 0x95, 0x92, 0x8f, 0x8c, 0x89, 0x86, 0x83, 
	0x80, 0x7c, 0x79, 0x76, 0x73, 0x70, 0x6d, 0x6a, 0x67, 0x63, 0x60, 0x5d, 0x5a, 0x57, 0x54, 0x51, 
	0x4f, 0x4c, 0x49, 0x46, 0x43, 0x40, 0x3e, 0x3b, 0x38, 0x36, 0x33, 0x31, 0x2e, 0x2c, 0x2a, 0x27, 
	0x25, 0x23, 0x21, 0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x12, 0x10, 0x0f, 0x0d, 0x0c, 0x0a, 
	0x09, 0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x03, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 
	0x09, 0x0a, 0x0c, 0x0d, 0x0f, 0x10, 0x12, 0x13, 0x15, 0x17, 0x19, 0x1b, 0x1d, 0x1f, 0x21, 0x23, 
	0x25, 0x27, 0x2a, 0x2c, 0x2e, 0x31, 0x33, 0x36, 0x38, 0x3b, 0x3e, 0x40, 0x43, 0x46, 0x49, 0x4c, 
	0x4f, 0x51, 0x54, 0x57, 0x5a, 0x5d, 0x60, 0x63, 0x67, 0x6a, 0x6d, 0x70, 0x73, 0x76, 0x79, 0x7c
};

// Low nybble with 256 samples per period
const uint8_t buf_lo[256] = {
	0x00, 0x20, 0x40, 0x60, 0x80, 0xa0, 0xc0, 0xe0, 0xf0, 0x00, 0x10, 0x20, 0x20, 0x20, 0x10, 0x10, 
	0xf0, 0xd0, 0xb0, 0x80, 0x50, 0x10, 0xc0, 0x70, 0x10, 0xb0, 0x30, 0xb0, 0x30, 0x90, 0xf0, 0x40, 
	0x80, 0xb0, 0xd0, 0xe0, 0xf0, 0xe0, 0xc0, 0xa0, 0x60, 0x20, 0xc0, 0x50, 0xe0, 0x50, 0xb0, 0x00, 
	0x40, 0x60, 0x80, 0x80, 0x70, 0x50, 0x20, 0xe0, 0x80, 0x10, 0x90, 0x00, 0x60, 0xa0, 0xd0, 0xf0, 
	0x00, 0xf0, 0xd0, 0xa0, 0x60, 0x00, 0x90, 0x10, 0x80, 0xe0, 0x20, 0x50, 0x70, 0x80, 0x80, 0x60, 
	0x40, 0x00, 0xb0, 0x50, 0xe0, 0x50, 0xc0, 0x20, 0x60, 0xa0, 0xc0, 0xe0, 0xf0, 0xe0, 0xd0, 0xb0, 
	0x80, 0x40, 0xf0, 0x90, 0x30, 0xb0, 0x30, 0xb0, 0x10, 0x70, 0xc0, 0x10, 0x50, 0x80, 0xb0, 0xd0, 
	0xf0, 0x10, 0x10, 0x20, 0x20, 0x20, 0x10, 0x00, 0xf0, 0xe0, 0xc0, 0xa0, 0x80, 0x60, 0x40, 0x20, 
	0x00, 0xd0, 0xb0, 0x90, 0x70, 0x50, 0x30, 0x10, 0x00, 0xf0, 0xe0, 0xd0, 0xd0, 0xd0, 0xe0, 0xe0, 
	0x00, 0x20, 0x40, 0x70, 0xa0, 0xe0, 0x30, 0x80, 0xe0, 0x40, 0xc0, 0x40, 0xc0, 0x60, 0x00, 0xb0, 
	0x70, 0x40, 0x20, 0x10, 0x00, 0x10, 0x30, 0x50, 0x90, 0xd0, 0x30, 0xa0, 0x10, 0xa0, 0x40, 0xf0, 
	0xb0, 0x90, 0x70, 0x70, 0x80, 0xa0, 0xd0, 0x10, 0x70, 0xe0, 0x60, 0xf0, 0x90, 0x50, 0x20, 0x00, 
	0x00, 0x00, 0x20, 0x50, 0x90, 0xf0, 0x60, 0xe0, 0x70, 0x10, 0xd0, 0xa0, 0x80, 0x70, 0x70, 0x90, 
	0xb0, 0xf0, 0x40, 0xa0, 0x10, 0xa0, 0x30, 0xd0, 0x90, 0x50, 0x30, 0x10, 0x00, 0x10, 0x20, 0x40, 
	0x70, 0xb0, 0x00, 0x60, 0xc0, 0x40, 0xc0, 0x40, 0xe0, 0x80, 0x30, 0xe0, 0xa0, 0x70, 0x40, 0x20, 
	0x00, 0xe0, 0xe0, 0xd0, 0xd0, 0xd0, 0xe0, 0xf0, 0x00, 0x10, 0x30, 0x50, 0x70, 0x90, 0xb0, 0xd0
};
#endif

#endif