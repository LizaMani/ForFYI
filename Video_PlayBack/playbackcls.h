#ifndef PLAYBACKCLS_H
#define PLAYBACKCLS_H

#include <QObject>
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mferror.h>
#include <evr.h>
#include <shobjidl.h>
#include <shlwapi.h>
#include <assert.h>
#include <strsafe.h>
#include <dshow.h>
#include <commdlg.h>
//interface IMFSourceResolver;
class PlayBackCls : public QObject
{
    Q_OBJECT
public:
    explicit PlayBackCls(QObject *parent = nullptr);
    void fileSelectionDialog();
    void onPlay();
    void onPause();
    void onSliderMoved();
    LPOPENFILENAMEA fileName;

IGraphBuilder *pGraph;
IMediaControl *pControl;
IMediaEvent   *pEvent;

signals:
public:
 ~PlayBackCls();
};

#endif // PLAYBACKCLS_H
