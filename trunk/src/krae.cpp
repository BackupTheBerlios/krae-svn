/*
 * Copyright (C) 2003 Carles Company Soler <carles@companysoler.com>
 */

#include "krae.h"

Krae::Krae()
        : KMainWindow( 0, "Krae" )
{
    // set the shell's ui resource file
    //    setXMLFile("kraeui.rc");
    KStdAction::quit    ( kapp, SLOT(quit()), actionCollection() );
    KStdAction::zoomIn    ( this, SLOT(slotZoomIn()), actionCollection() );
    KStdAction::zoomOut   ( this, SLOT(slotZoomOut()), actionCollection() );
    /*KAction cercar=*/
    new KAction ( i18n("&Find"), ALT+Key_F,this, SLOT(change_location()), actionCollection(), "query" );
    createGUI("kraeui.h");
    QVBox *vbox=new QVBox(this);
    paraula=new QLineEdit(vbox);
    QPushButton *boto=new QPushButton(i18n("F&ind"),vbox);
    connect(boto , SIGNAL( clicked() ),this, SLOT( change_location() ) );
    connect(paraula , SIGNAL( returnPressed() ),this, SLOT( change_location() ) );
    browser=new KHTMLPart(vbox);
    connect( browser->browserExtension(),
             SIGNAL( openURLRequest( const KURL &, const KParts::URLArgs & ) ),
             this, SLOT( openURLRequest(const KURL &, const KParts::URLArgs & ) ) );
    setCentralWidget( vbox );
}

Krae::~Krae()
{}

void Krae::change_location()
{
    KURL url = "http://buscon.rae.es/draeI/SrvltGUIBusUsual?TIPO_HTML=2&LEMA="+paraula->text();
    browser->openURL(url);
}

void Krae::openURLRequest(const KURL &url, const KParts::URLArgs & )
{
    KRegExp ex("=[a-z]+&");
    KRegExp ex2("[a-z]+");
    QString prova=url.query();
    ex.match(prova);
    ex2.match(ex.group(0));
    paraula->setText(ex2.group(0));
    browser->openURL(url);
}

/*!
    \fn Krae::slotZoomOut()
 */
void Krae::slotZoomOut()
{
    browser->setZoomFactor(browser->zoomFactor()/2);
}

/*!
    \fn Krae::slotZoomIn()
 */
void Krae::slotZoomIn()
{
    browser->setZoomFactor(browser->zoomFactor()*2);
}




#include "krae.moc"
