#ifndef ITKFILTERSSUBTRACTPROCESS_H
#define ITKFILTERSSUBTRACTPROCESS_H

#include <dtkCore/dtkAbstractProcess.h>
#include <dtkCore/dtkAbstractData.h>

#include "itkFiltersPluginExport.h"

class dtkAbstractData;
class itkFiltersSubtractProcessPrivate;

class ITKFILTERSPLUGIN_EXPORT itkFiltersSubtractProcess : public dtkAbstractProcess
{
    Q_OBJECT
public:
    itkFiltersSubtractProcess(void);
    virtual ~itkFiltersSubtractProcess(void);
    
    virtual QString description(void) const;
    
    static bool registered(void);
    
    void emitProgress(int progress);
    
public slots:
    void setInput(dtkAbstractData *data);
    void setParameter(double data, int channel);
    int update(void);
    
    dtkAbstractData *output(void);
    
private:
    itkFiltersSubtractProcessPrivate *d;
};


dtkAbstractProcess * createitkFiltersSubtractProcess(void);

#endif // ITKFILTERSSUBTRACTPROCESS_H
