#ifndef __BITRATECONFIGURATION_H__
#define __BITRATECONFIGURATION_H__

class BitrateConfiguration
{
public:
	typedef enum _EMediaType{
		EMEDIA_TYPE_VIDEO,
		EMEDIA_TYPE_AUDIO
	} EMediaType;

	typedef struct _BitrateInfo{
		EMediaType eMediaType;
		int Height;
		int Width;
		int Bitrate;
	} BitrateInfo;

	typedef struct _BitrateConfig{
		list<StreamInfo*> m_pAvailableStreamInfos;
		StreamInfo* CurrentStreamInfo;
		int InitialBitrate;
		int FixdedBitrate;
	} BitrateConfig;
	
private:
	BitrateConfig m_oVideoConfig;
	BitrateConfig m_oAutioconfig;
		
public:
	AddBitrateInfo(EMediaType a_eMediaType, int a_nBitrate);
	AddBitrateInfo(EMediaType a_eMediaType, int a_nHeight, int a_nWidth, int a_nBitrate);
	
	IsFixedBitrate(EMediaType a_eMediaType);

	SetBitrateRange(EMediaType a_eMediaType, int a_nMin, int a_nMax);
	SetInitialBitrate(EMediaType a_eMediaType, int a_nBitrate);
	
	GetCurrentBitrateInfo(EMediaType a_eMediaType);
	GetInitialBitrate(EMediaType a_eMediaType);
};

#endif //__BITRATECONFIGURATION_H__
