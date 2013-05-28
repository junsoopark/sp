#ifndef __FACTORY_H__
#define __FACTORY_H__


#ifdef __cplusplus
extern "C" {
#endif

typedef enum _eCLSID {
	eCLSID_FIRST,
	eCLSID_PROTOCOLCORE_HLS,
	eCLSID_PROTOCOLCORE_DASH,
	eCLSID_LAST,
} eCLSID;




bool CreateInstance(eCLSID a_eClsid, void** a_ppInstance);
bool DestroyInstance(void** a_ppInstance);


#ifdef __cplusplus
}
#endif

#endif //__FACTORY_H__
