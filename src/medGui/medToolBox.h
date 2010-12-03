/* medToolBox.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Oct  9 19:41:48 2009 (+0200)
 * Version: $Id$
 * Last-Updated: Wed Nov 10 15:47:49 2010 (+0100)
 *           By: Julien Wintz
 *     Update #: 68
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#ifndef MEDTOOLBOX_H
#define MEDTOOLBOX_H

#include "medGuiExport.h"

#include <QtGui>

class medToolBoxPrivate;

class MEDGUI_EXPORT medToolBox : public QWidget
{
    Q_OBJECT

public:
             medToolBox(QWidget *parent = 0);
    virtual ~medToolBox(void);

    void setWidget(QWidget *widget);

    void setTitle(const QString& title);
    
signals:
    void addToolBox   (medToolBox *toolbox);
    void removeToolBox(medToolBox *toolbox);

private:
    medToolBoxPrivate *d;
};

#endif
