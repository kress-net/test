
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CP210xDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CP210xDLL_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef CP210xDLL_EXPORTS
#define CP210xDLL_API __declspec(dllexport)
#else
#define CP210xDLL_API __declspec(dllimport)
#endif

// GetProductString() function flags
#define		CP210x_RETURN_SERIAL_NUMBER			0x00
#define		CP210x_RETURN_DESCRIPTION			0x01
#define		CP210x_RETURN_FULL_PATH				0x02

#ifndef _CP210x_STANDARD_DEF_
#define _CP210x_STANDARD_DEF_

// GetDeviceVersion() return codes
#define		CP210x_CP2101_VERSION				0x01
#define		CP210x_CP2102_VERSION				0x02
#define		CP210x_CP2103_VERSION				0x03
#define		CP210x_CP2104_VERSION				0x04
#define		CP210x_CP2105_VERSION				0x05
											
// Return codes									
#define		CP210x_SUCCESS						0x00
#define		CP210x_DEVICE_NOT_FOUND				0xFF
#define		CP210x_INVALID_HANDLE				0x01
#define		CP210x_INVALID_PARAMETER			0x02
#define		CP210x_DEVICE_IO_FAILED				0x03
#define		CP210x_FUNCTION_NOT_SUPPORTED		0x04
#define		CP210x_GLOBAL_DATA_ERROR			0x05
#define		CP210x_FILE_ERROR					0x06
#define		CP210x_COMMAND_FAILED				0x08
#define		CP210x_INVALID_ACCESS_TYPE			0x09

// Type definitions
typedef		int		CP210x_STATUS;

#endif //_CP210x_STANDARD_DEF
						
						
// Buffer size limits
//
// CP2101/2/3/4
#define		CP210x_MAX_DEVICE_STRLEN			256
#define		CP210x_MAX_PRODUCT_STRLEN			126
#define		CP210x_MAX_SERIAL_STRLEN			63
#define		CP210x_MAX_MAXPOWER					250
//
// CP2105
#define		CP2105_MAX_PRODUCT_STRLEN			47
#define		CP2105_MAX_INTERFACE_STRLEN			32
#define		CP2105_MAX_SERIAL_STRLEN			16

// Type definitions
typedef		char	CP210x_DEVICE_STRING[CP210x_MAX_DEVICE_STRLEN];
typedef		char	CP210x_PRODUCT_STRING[CP210x_MAX_PRODUCT_STRLEN];
typedef		char	CP210x_SERIAL_STRING[CP210x_MAX_SERIAL_STRLEN];
typedef		char	CP210x_INTERFACE_STRING[CP2105_MAX_INTERFACE_STRLEN];


// Baud Rate Aliasing definitions
//
#define		NUM_BAUD_CONFIGS	32
//
// Baud Config Structure
typedef		struct
{
	WORD	BaudGen;
	WORD	Timer0Reload;
	BYTE	Prescaler;
	DWORD	BaudRate;
} BAUD_CONFIG;
//
// Size of the Baud Config Structure
#define		BAUD_CONFIG_SIZE	10
//
// Array of all Baud Rate Configurations
typedef		BAUD_CONFIG		BAUD_CONFIG_DATA[NUM_BAUD_CONFIGS];
//


// Flush Buffer definitions
//
// CP2104
#define FC_OPEN_TX		0x01	// When these bits are set, the device will flush that buffer
#define FC_OPEN_RX		0x02
#define FC_CLOSE_TX		0x04
#define FC_CLOSE_RX		0x08
//
// CP2105 - Standard Port
#define FC_OPEN_TX_SCI  FC_OPEN_TX
#define FC_OPEN_RX_SCI  FC_OPEN_RX
#define FC_CLOSE_TX_SCI FC_CLOSE_TX
#define FC_CLOSE_RX_SCI FC_CLOSE_RX
//
// CP2105 - Enhanced Port
#define FC_OPEN_TX_ECI  0x10
#define FC_OPEN_RX_ECI  0x20
#define FC_CLOSE_TX_ECI 0x40
#define FC_CLOSE_RX_ECI 0x80


//Port Config definitions
//
// CP2103/4 Port Config Structure
typedef		struct
{
	WORD Mode;			// Push-Pull = 1, Open-Drain = 0
	WORD Reset_Latch;	// Logic High = 1, Logic Low = =0
	WORD Suspend_Latch;	// Logic High = 1, Logic Low = =0
	unsigned char EnhancedFxn;
} PORT_CONFIG;
//
// Define bit locations for Mode/Latch for Reset and Suspend structures
#define PORT_RI_ON				0x0001
#define PORT_DCD_ON				0x0002
#define PORT_DTR_ON				0x0004
#define PORT_DSR_ON				0x0008
#define PORT_TXD_ON				0x0010
#define PORT_RXD_ON				0x0020
#define PORT_RTS_ON				0x0040
#define PORT_CTS_ON				0x0080
//
#define PORT_GPIO_0_ON			0x0100
#define PORT_GPIO_1_ON			0x0200
#define PORT_GPIO_2_ON			0x0400
#define PORT_GPIO_3_ON			0x0800
//
#define PORT_SUSPEND_ON			0x4000	//  Can't configure latch value
#define PORT_SUSPEND_BAR_ON		0x8000	//  Can't configure latch value
//
// Define bit locations for EnhancedFxn
#define EF_GPIO_0_TXLED				0x01	//  Under device control
#define EF_GPIO_1_RXLED				0x02	//  Under device control
#define EF_GPIO_2_RS485				0x04	//  Under device control
#define EF_RS485_INVERT				0x08	//  RS485 Invert bit
#define EF_WEAKPULLUP				0x10	//  Weak Pull-up on
#define EF_RESERVED_1				0x20	//	Reserved, leave bit 5 cleared
#define EF_SERIAL_DYNAMIC_SUSPEND	0x40	//  For 8 UART/Modem signals
#define EF_GPIO_DYNAMIC_SUSPEND		0x80	//  For 4 GPIO signals
//
//
//
// CP2105 Dual Port Config Structure
typedef		struct
{
	WORD Mode;			// Push-Pull = 1, Open-Drain = 0
	WORD Reset_Latch;	// Logic High = 1, Logic Low = =0
	WORD Suspend_Latch;	// Logic High = 1, Logic Low = =0
	unsigned char EnhancedFxn_ECI;
	unsigned char EnhancedFxn_SCI;
	unsigned char EnhancedFxn_Device;
} DUAL_PORT_CONFIG;
//
// CP2105 Define bit locations for Mode/Latch for Reset and Suspend structures
#define PORT_RI_SCI_ON			0x0001
#define PORT_DCD_SCI_ON			0x0002
#define PORT_DTR_SCI_ON			0x0004
#define PORT_DSR_SCI_ON			0x0008
#define PORT_TXD_SCI_ON			0x0010
#define PORT_RXD_SCI_ON			0x0020
#define PORT_RTS_SCI_ON			0x0040
#define PORT_CTS_SCI_ON			0x0080
#define PORT_GPIO_0_SCI_ON		0x0002
#define PORT_GPIO_1_SCI_ON		0x0004
#define PORT_GPIO_2_SCI_ON		0x0008
#define PORT_SUSPEND_SCI_ON		0x0001	//  Can't configure latch value
//
#define PORT_RI_ECI_ON			0x0100
#define PORT_DCD_ECI_ON			0x0200
#define PORT_DTR_ECI_ON			0x0400
#define PORT_DSR_ECI_ON			0x0800
#define PORT_TXD_ECI_ON			0x1000
#define PORT_RXD_ECI_ON			0x2000
#define PORT_RTS_ECI_ON			0x4000
#define PORT_CTS_ECI_ON			0x8000
#define PORT_GPIO_0_ECI_ON		0x0400
#define PORT_GPIO_1_ECI_ON		0x0800
#define PORT_SUSPEND_ECI_ON		0x0100	//  Can't configure latch value
//
// CP2105 Define bit locations for EnhancedFxn_ECI
#define EF_GPIO_0_TXLED_ECI			0x01	//  Under device control
#define EF_GPIO_1_RXLED_ECI			0x02	//  Under device control
#define EF_GPIO_1_RS485_ECI			0x04	//  Under device control
#define EF_RS485_INVERT				0x08	//  Under device control
#define EF_INVERT_SUSPEND_ECI		0x10	//  RS485 Invert bit
#define EF_DYNAMIC_SUSPEND_ECI		0x40	//  For GPIO signals
//
// CP2105 Define bit locations for EnhancedFxn_SCI
#define EF_GPIO_0_TXLED_SCI			0x01	//  Under device control
#define EF_GPIO_1_RXLED_SCI			0x02	//  Under device control
#define EF_INVERT_SUSPEND_SCI		0x10	//  RS485 Invert bit
#define EF_DYNAMIC_SUSPEND_SCI		0x40	//  For GPIO signals
//
// CP2105 Define bit locations for EnhancedFxn_Device
#define EF_WEAKPULLUP				0x10	//  Weak Pull-up on
//



#ifdef __cplusplus
extern "C" {
#endif

CP210xDLL_API
CP210x_STATUS WINAPI CP210x_GetNumDevices(
	LPDWORD	lpdwNumDevices
	);

CP210xDLL_API
CP210x_STATUS WINAPI CP210x_GetProductString(
	DWORD	dwDeviceNum,
	LPVOID	lpvDeviceString,
	DWORD	dwFlags
	);

CP210xDLL_API
CP210x_STATUS WINAPI CP210x_Open(
	DWORD	dwDevice,
	HANDLE*	cyHandle
	); 

CP210xDLL_API
CP210x_STATUS WINAPI CP210x_Close(
	HANDLE	cyHandle
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_GetPartNumber(
	HANDLE cyHandle,
	LPBYTE	lpbPartNum
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetVid(
	HANDLE	cyHandle,
	WORD	wVid
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetPid(
	HANDLE	cyHandle,
	WORD	wPid
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetProductString(
	HANDLE	cyHandle,
	LPVOID	lpvProduct,
	BYTE	bLength,
	BOOL	bConvertToUnicode = TRUE
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetInterfaceString(
	HANDLE cyHandle,
	BYTE bInterfaceNumber,
	LPVOID lpvInterface,
	BYTE bLength,
	BOOL bConvertToUnicode
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetSerialNumber(
	HANDLE	cyHandle,
	LPVOID	lpvSerialNumber,
	BYTE	bLength,
	BOOL	bConvertToUnicode = TRUE
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetSelfPower(
	HANDLE cyHandle, 
	BOOL bSelfPower
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetMaxPower(
	HANDLE cyHandle,
	BYTE bMaxPower
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetFlushBufferConfig(
	HANDLE cyHandle,
	BYTE bFlushBufferConfig
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetDeviceMode(
	HANDLE cyHandle,
	BYTE bDeviceModeECI,
	BYTE bDeviceModeSCI
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_SetDeviceVersion(
	HANDLE cyHandle,
	WORD wVersion
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_SetBaudRateConfig(
	HANDLE	cyHandle,
	BAUD_CONFIG* baudConfigData
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_SetPortConfig(	
	HANDLE cyHandle,
	PORT_CONFIG*	PortConfig
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_SetDualPortConfig(	
	HANDLE cyHandle,
	DUAL_PORT_CONFIG*	DualPortConfig
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_SetLockValue(
	HANDLE cyHandle
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetDeviceVid(
	HANDLE	cyHandle,
	LPWORD	lpwVid
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetDevicePid(
	HANDLE	cyHandle,
	LPWORD	lpwPid
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetDeviceProductString(	
	HANDLE	cyHandle,
	LPVOID	lpProduct,
	LPBYTE	lpbLength,
	BOOL	bConvertToASCII = TRUE
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetDeviceInterfaceString(
	HANDLE cyHandle,
	BYTE bInterfaceNumber,
	LPVOID lpInterface,
	LPBYTE lpbLength,
	BOOL bConvertToASCII
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetDeviceSerialNumber(	
	HANDLE	cyHandle,
	LPVOID	lpSerialNumber,
	LPBYTE	lpbLength,
	BOOL	bConvertToASCII = TRUE
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetSelfPower(
	HANDLE	cyHandle,
	LPBOOL	lpbSelfPower
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetMaxPower(
	HANDLE	cyHandle,
	LPBYTE	lpbPower
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_GetFlushBufferConfig(
	HANDLE cyHandle,
	LPBYTE lpbFlushBufferConfig
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI 
CP210x_GetDeviceMode(
	HANDLE cyHandle,
	LPBYTE lpbDeviceModeECI,
	LPBYTE lpbDeviceModeSCI
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_GetDeviceVersion(
	HANDLE	cyHandle,
	LPWORD	lpwVersion
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_GetBaudRateConfig(
	HANDLE	cyHandle,
	BAUD_CONFIG* baudConfigData
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_GetPortConfig(	
	HANDLE cyHandle,
	PORT_CONFIG*	PortConfig
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_GetDualPortConfig(	
	HANDLE cyHandle,
	DUAL_PORT_CONFIG*	DualPortConfig
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_GetLockValue(	
	HANDLE cyHandle,
	LPBYTE	lpbLockValue
	);

CP210xDLL_API
CP210x_STATUS	
WINAPI
CP210x_Reset(
	HANDLE	cyHandle
	);

CP210xDLL_API
CP210x_STATUS 
WINAPI 
CP210x_CreateHexFile(	
	HANDLE cyHandle,
	LPCSTR lpvFileName
	);


#ifdef __cplusplus
}
#endif
