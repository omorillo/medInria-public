    /**
    * This software was developed using DCMTK from OFFIS e.V.
    *
    * Kuratorium OFFIS e.V.
    * Healthcare Information and Communication Systems
    * Escherweg 2
    * D-26121 Oldenburg, Germany
    */


#ifndef DCMTKSTORESCU_H
#define DCMTKSTORESCU_H

#include "dcmtk/config/osconfig.h" /* make sure OS specific configuration is included first */

#define INCLUDE_CSTDLIB
#define INCLUDE_CSTDIO
#define INCLUDE_CSTRING
#define INCLUDE_CCTYPE
#include "dcmtk/ofstd/ofstdinc.h"

#include "dcmtk/ofstd/ofstd.h"
#include "dcmtk/ofstd/ofconapp.h"
#include "dcmtk/ofstd/ofstring.h"
#include "dcmtk/ofstd/ofstream.h"
#include "dcmtk/dcmnet/dicom.h"      /* for DICOM_APPLICATION_REQUESTOR */
#include "dcmtk/dcmnet/dimse.h"
#include "dcmtk/dcmnet/diutil.h"
#include "dcmtk/dcmnet/dcasccfg.h"   /* for class DcmAssociationConfiguration */
#include "dcmtk/dcmnet/dcasccff.h"   /* for class DcmAssociationConfigurationFile */
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcmetinf.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/dcmdata/dcdict.h"
#include "dcmtk/dcmdata/dcdeftag.h"
#include "dcmtk/dcmdata/cmdlnarg.h"
#include "dcmtk/dcmdata/dcuid.h"     /* for dcmtk version name */
#include "dcmtk/dcmdata/dcostrmz.h"  /* for dcmZlibCompressionLevel */

#include "dcmtkBaseScu.h"



    /**
     * @class dcmtkStoreScu
     * @author Michael Knopke
     * @brief class to send C-STORE to the remote node.
     * Used to send DICOM data to another modality.
     */

class dcmtkStoreScu : public  dcmtkBaseScu
{
public:

    dcmtkStoreScu();


    /**
    * Directory to look for DICOM files. Default ist: current directory
    * @param dir path to dicom source files
    * see setScanPattern(const char* pattern) for file exclusion
    */
    bool setScanDirectory(const char* dir);

    /*
    * Add a scan pattern. Default is all files and types: *.*
    */
    bool setScanPattern(const char* pattern){};

    /**
    * Performs the C-STORE request on the peer.
    * @param peerTitle The AE of the peer
    * @param peerIP The IP of the peer that performs the C-FIND.
    * @param peerPort The port number of the peer.
    * @param ourTitel The AE of the caller
    * @param ourIP The IP of the caller.
    * @param ourPort The port number of the caller.
    * @return 0 for success, otherwise errorcode
    */
    int  sendStoreRequest(const char* peerTitle, const char* peerIP, int peerPort, 
                          const char* ourTitle, const char* ourIP, int ourPort);

    /**
    * Overloaded for convenience. Performs the C-STORE request on the peer.
    * Uses the internal connection parameters. 
    * @see setConnectionParams(const char*, const char*, unsigned short,const char*, const char*, unsigned short)
    * @return 0 for success or errorcode
    */
    int sendStoreRequest();

protected:

    /**
    * This function will read all the information from the given file,
    * figure out a corresponding presentation context which will be used
    * to transmit the information over the network to the SCP, and it
    * will finally initiate the transmission of all data to the SCP.
    * @param assoc - [in] The association (network connection to another DICOM application).
    * @param fname - [in] Name of the file which shall be processed.
    */
    OFCondition dcmtkStoreScu::storeSCU(T_ASC_Association *assoc, const char *fname);

    /**
    * This function will process the given file as often as is specified by opt_repeatCount.
    * "Process" in this case means "read file, send C-STORE-RQ, receive C-STORE-RSP".
    * @param assoc - [in] The association (network connection to another DICOM application).
    * @param fname - [in] Name of the file which shall be processed.
    */
    OFCondition cstore(T_ASC_Association *assoc, const OFString &fname);

    OFBool findSOPClassAndInstanceInFile(const char *fname, char *sopClass, char *sopInstance);

    OFBool isaListMember(OFList<OFString> &lst, OFString &s);

    OFCondition dcmtkStoreScu::addPresentationContext(T_ASC_Parameters *params, int presentationContextId,
                                                  const OFString &abstractSyntax, const OFString &transferSyntax,
                                                  T_ASC_SC_ROLE proposedRole = ASC_SC_ROLE_DEFAULT);

    OFCondition dcmtkStoreScu::addPresentationContext(T_ASC_Parameters *params, int presentationContextId,
                                                  const OFString &abstractSyntax, const OFList<OFString> &transferSyntaxList,
                                                  T_ASC_SC_ROLE proposedRole = ASC_SC_ROLE_DEFAULT);

    OFCondition addStoragePresentationContexts(T_ASC_Parameters *params, OFList<OFString> &sopClasses);

    OFCondition configureUserIdentityRequest(T_ASC_Parameters *params);

    OFCondition checkUserIdentityResponse(T_ASC_Parameters *params);

    static void progressCallback(void * /*callbackData*/, T_DIMSE_StoreProgress *progress,
                          T_DIMSE_C_StoreRQ * req);

    OFBool updateStringAttributeValue(DcmItem *dataset, const DcmTagKey &key, OFString &value);

    void replaceSOPInstanceInformation(DcmDataset *dataset);


protected:


    // helper
    
    int secondsSince1970();

    OFString intToString(int i);

    OFString makeUID(OFString basePrefix, int counter);


    // variables
    OFList<OFString>                    inputFiles;
    OFString                            opt_directory;
    OFBool                              opt_showPresentationContexts;
    OFBool                              opt_abortAssociation;
    E_FileReadMode                      opt_readMode;

    OFBool                              opt_scanDir;
    OFBool                              opt_recurse;
    const char*                         opt_scanPattern;

    OFBool                              opt_haltOnUnsuccessfulStore;
    OFBool                              unsuccessfulStoreEncountered;
    int                                 lastStatusCode;

    OFBool                              opt_proposeOnlyRequiredPresentationContexts;
    OFBool                              opt_combineProposedTransferSyntaxes;

    T_ASC_UserIdentityNegotiationMode   opt_identMode;
    OFString                            opt_user;
    OFString                            opt_password;
    OFString                            opt_identFile;
    OFBool                              opt_identResponse;

    
    OFCmdUnsignedInt opt_inventPatientCount;
    OFCmdUnsignedInt opt_inventStudyCount;
    OFCmdUnsignedInt opt_inventSeriesCount;
    OFBool opt_inventSOPInstanceInformation;
    OFBool opt_correctUIDPadding;
    OFString patientNamePrefix;         // PatientName is PN (maximum 16 chars)
    OFString patientIDPrefix;           // PatientID is LO (maximum 64 chars)
    OFString studyIDPrefix;             // StudyID is SH (maximum 16 chars)
    OFString accessionNumberPrefix;     // AccessionNumber is SH (maximum 16 chars)
    
    OFBool opt_secureConnection; 
    const char *opt_configFile;
    const char *opt_profileName;


};

#endif DCMTKSTORESCU_H
