/*
 * Copyright (C) 2003 Carles Company Soler <carles@companysoler.com>
 */

#include "krae.h"
#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>

static const char description[] =
    I18N_NOOP("Query the RAE online dictionary.");

static const char version[] = "0.4";

static KCmdLineOptions options[] =
{
//    { "+[URL]", I18N_NOOP( "Document to open." ), 0 },
    KCmdLineLastOption
};

int main(int argc, char **argv)
{
    KAboutData about("Krae", I18N_NOOP("Krae"), version, description,
                     KAboutData::License_GPL, "(C) 2003 Carles Company Soler", 0, 0, "carles@companysoler.com");
    about.addAuthor( "Carles Company Soler", 0, "carles@companysoler.com" );
    KCmdLineArgs::init(argc, argv, &about);
    KCmdLineArgs::addCmdLineOptions( options );
    KApplication app;
    Krae *mainWin = 0;

    if (app.isRestored())
    {
        RESTORE(Krae);
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

        // TODO: do something with the command line args here

        mainWin = new Krae();
        app.setMainWidget( mainWin );
        mainWin->show();

        args->clear();
    }

    int ret = app.exec();

    delete mainWin;
    return ret;
}
