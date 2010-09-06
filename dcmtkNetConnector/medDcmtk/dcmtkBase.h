    /**
    * This software was developed using DCMTK from OFFIS e.V.
    *
    * Kuratorium OFFIS e.V.
    * Healthcare Information and Communication Systems
    * Escherweg 2
    * D-26121 Oldenburg, Germany
    */

#ifndef DCMTKBASE_H
#define DCMTKBASE_H

#include "dcmtk/config/osconfig.h"    /* make sure OS specific configuration is included first */
#include "dcmtk/ofstd/ofcond.h"
#include "dcmtk/dcmnet/assoc.h"
#include "dcmtk/dcmnet/dimse.h"


/* DICOM standard transfer syntaxes */
static const char* transferSyntaxes[] = {
      UID_LittleEndianImplicitTransferSyntax, /* default xfer syntax first */
      UID_LittleEndianExplicitTransferSyntax,
      UID_BigEndianExplicitTransferSyntax,
      UID_JPEGProcess1TransferSyntax,
      UID_JPEGProcess2_4TransferSyntax,
      UID_JPEGProcess3_5TransferSyntax,
      UID_JPEGProcess6_8TransferSyntax,
      UID_JPEGProcess7_9TransferSyntax,
      UID_JPEGProcess10_12TransferSyntax,
      UID_JPEGProcess11_13TransferSyntax,
      UID_JPEGProcess14TransferSyntax,
      UID_JPEGProcess15TransferSyntax,
      UID_JPEGProcess16_18TransferSyntax,
      UID_JPEGProcess17_19TransferSyntax,
      UID_JPEGProcess20_22TransferSyntax,
      UID_JPEGProcess21_23TransferSyntax,
      UID_JPEGProcess24_26TransferSyntax,
      UID_JPEGProcess25_27TransferSyntax,
      UID_JPEGProcess28TransferSyntax,
      UID_JPEGProcess29TransferSyntax,
      UID_JPEGProcess14SV1TransferSyntax,
      UID_RLELosslessTransferSyntax,
      UID_JPEGLSLosslessTransferSyntax,
      UID_JPEGLSLossyTransferSyntax,
      UID_DeflatedExplicitVRLittleEndianTransferSyntax,
      UID_JPEG2000LosslessOnlyTransferSyntax,
      UID_JPEG2000TransferSyntax,
      UID_MPEG2MainProfileAtMainLevelTransferSyntax,
      UID_JPEG2000Part2MulticomponentImageCompressionLosslessOnlyTransferSyntax,
      UID_JPEG2000Part2MulticomponentImageCompressionTransferSyntax
};


    /**
    * @class dcmtkBase
    * @author Michael Knopke
    * @brief base class for all SCU/SCP base implementations.
    * Adds common network connection stuff.
    */

class dcmtkBase
{
public:

    /**
    * Default Constructor
    */
    dcmtkBase();

    /**
    * Default Destructor
    */
    ~dcmtkBase();


protected:
    


};

#endif DCMTKBASE_H