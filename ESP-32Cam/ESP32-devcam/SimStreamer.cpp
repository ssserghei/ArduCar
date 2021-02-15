
#include "SimStreamer.h"
#include "JPEGSamples.h"

 SimStreamer::SimStreamer(SOCKET aClient, bool showBig) : CStreamer(aClient, showBig ? 800 : 640, showBig ? 600 : 480)
#ifdef INCLUDE_SIMDATA
{
    m_showBig = showBig;
}

void SimStreamer::streamImage(uint32_t curMsec)
{
    if(m_showBig) {
        BufPtr bytes = capture_jpg;
        uint32_t len = capture_jpg_len;

        streamFrame(bytes, len, curMsec);
    }
    else {
        BufPtr bytes = octo_jpg;
        uint32_t len = octo_jpg_len;

        streamFrame(bytes, len, curMsec);
    }
}

#endif
