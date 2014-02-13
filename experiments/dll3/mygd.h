
//#define BGD_DECLARE(a) a

#define BGD_EXPORT_DATA_PROT __attribute__ ((dllexport))
#define BGD_STDCALL __stdcall
#define BGD_DECLARE(rt) BGD_EXPORT_DATA_PROT rt BGD_STDCALL

BGD_DECLARE(int) gdMajorVersion(void);
