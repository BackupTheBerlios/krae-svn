/*
 * Copyright (C) 2003 Carles Company Soler <carles@companysoler.com>
 */

#ifndef _Krae_H_
#define _Krae_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kapp.h>
#include <qwidget.h>
#include <kmainwindow.h>
#include <kmenubar.h>
#include <klocale.h>
#include <kpopupmenu.h>
#include <qvbox.h>
#include <qstring.h>
#include <qlineedit.h>
#include <kurl.h>
#include <qpushbutton.h>
#include <khelpmenu.h>
#include <kregexp.h>
#include <kparts/browserextension.h>
#include <khtml_part.h>
#include <kxmlguifactory.h>
#include <kaction.h>
#include <kstdaction.h>
#include <qkeysequence.h>

/**
 * @short Application Main Window
 * @author Carles Company Soler <carles@companysoler.com>
 * @version 0.4
 */
class Krae : public KMainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    Krae();

    /**
     * Default Destructor
     */
    virtual ~Krae();

private:
    QLineEdit *paraula;
    KHTMLPart *browser;
public slots: // Public slots
    /** No descriptions */
    void change_location();
    void openURLRequest(const KURL &url, const KParts::URLArgs & );
    void slotZoomOut();
    void slotZoomIn();
};

#endif // _Krae_H_
