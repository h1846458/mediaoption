#pragma once
#include <memory.h> 
#include <stdint.h>
#include <qimage.h>
#pragma pack(push)
#pragma pack(1)
namespace cw {

	struct DecoderData {
		int64_t nTimeStamp;
		QImage img;
		DecoderData()
		{
			memset(this, 0, sizeof(DecoderData));
		}

	};



};

#pragma pack(pop)