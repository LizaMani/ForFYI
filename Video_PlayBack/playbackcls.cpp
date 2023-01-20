#include "playbackcls.h"
#pragma comment(lib,"Strmiids.lib")
#pragma comment(lib,"comdlg32.lib")
#pragma comment(lib,"user32.lib")
PlayBackCls::PlayBackCls(QObject *parent) : QObject(parent)
{

}
void PlayBackCls::fileSelectionDialog()
{
  GetOpenFileNameA(fileName);
  LoadLibraryA(fileName->lpstrFile);
}
void PlayBackCls::onPlay()
{



HRESULT hr = CoCreateInstance(CLSID_FilterGraph, NULL,
    CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraph);
hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);
pGraph->RenderFile((LPCWSTR)fileName->lpstrFile,NULL);
hr = pControl->Run();
long evCode = 0;
pEvent->WaitForCompletion(INFINITE, &evCode);

    /*HRESULT hr=MFCreateSourceResolver(&pSourceResolver);
    pSourceResolver->CreateObjectfromURL();*/
}
void PlayBackCls::onPause()
{
    pControl->Pause();
}
void PlayBackCls::onSliderMoved()
{


}
PlayBackCls::~PlayBackCls()
{
    pControl->Release();
    pEvent->Release();
    pGraph->Release();
    CoUninitialize();
}
