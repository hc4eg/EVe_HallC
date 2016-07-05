//*************************************************************************
//  EVe.h  - 4/14/2008
//
//  by miham
//
//  This is the main class of the event display.
//
//
//*************************************************************************

#ifndef ROOT_EVe
#define ROOT_EVe


#include "TCanvas.h"
#include "TGFrame.h"
#include "TGButton.h"
#include "TRootEmbeddedCanvas.h"
#include "TGButtonGroup.h"
#include "TGNumberEntry.h"
#include <RQ_OBJECT.h>
#include "TGClient.h"
#include "TTree.h"
#include "TFile.h"

#include "WirePlane.h"
#include "WirePlane2D.h"
#include "WireChamber.h"
#include "CStransform.h"
#include "Track.h"
#include "ScintPlane.h"
#include "Detector3D.h"
#include "THaRun.h"
#include <TString.h>
#include <TGFileDialog.h>
#include <TStyle.h>

#define MAX_ROADS_NUM 500
#define MAX_HITS_NUM 100

class EVe
{
    RQ_OBJECT("EVe")
public:
    EVe(const TGWindow *p, UInt_t w, UInt_t h);
    ~EVe();
    void CreateXprojection();
    void CreateUVprojection();
    void CreateYprojection();
    void CreateWires();
    void Create3DView();
    void initRun(char *filename);
    void DoDraw(int event);
    void doNext();
    void doNextGood();
    void doPrevious();
    void doPreviousGood();
    void doThis();
    void SelectProj();
    void MyCloseWindow();
    void PrintToFile();

private:
    TGMainFrame *fMainFrame;
    TRootEmbeddedCanvas *fRootEmbeddedCanvas;
    TCanvas *c1;
    TCanvas *c2;
    TCanvas *c3;
    TCanvas *c4;
    TCanvas *c5;
    TGRadioButton *fTextButtonXPlane;
    TGRadioButton *fTextButtonUVPlane;
    TGRadioButton *fTextButtonYPlane;
    TGRadioButton *fTextButton3dView;
    TGRadioButton *fTextButtonProj;

    TGRadioButton *fTextButtonWires;
    TGCheckButton *fTextButtonTrackProj;
    TGCheckButton *fTextButtonTrack;
    TGNumberEntry *fNumberEntry1;

    WireChamber *RDC1;
    WireChamber *RDC2;
    WireChamber *LDC1;
    WireChamber *LDC2;

    ScintPlane *Ls;
    ScintPlane *Rs;

    CStransform *cst;

    int EventNumber;
    int TotalNumberOfEvents;

    WirePlane *x1;
    WirePlane *x1p;
    WirePlane *x2;
    WirePlane *x2p;

    WirePlane *u1;
    WirePlane *v1;
    WirePlane *u2;
    WirePlane *v2;

    WirePlane *y1;
    WirePlane *y1p;
    WirePlane *y2;
    WirePlane *y2p;

    Track *vtr[MAX_ROADS_NUM];
    Track *utr[MAX_ROADS_NUM];
    Track *xtr[MAX_ROADS_NUM];

    TTree *t1;

    /// LDC1 nhits
    Int_t Ndata_B_vdc0_u1_wire;
    Int_t Ndata_B_vdc0_v1_wire;

    /// LDC1 tdc hits
    Double_t B_vdc0_u1_wire[MAX_HITS_NUM];
    Double_t B_vdc0_v1_wire[MAX_HITS_NUM];

    /// LDC1 hit times
    Double_t B_vdc0_u1_time[MAX_HITS_NUM];
    Double_t B_vdc0_v1_time[MAX_HITS_NUM];

    /// LDC2 nhits
    Int_t Ndata_B_vdc0_u2_wire;
    Int_t Ndata_B_vdc0_v2_wire;

    /// LDC2 hit tdc hits
    Double_t B_vdc0_u2_wire[MAX_HITS_NUM];
    Double_t B_vdc0_v2_wire[MAX_HITS_NUM];

    /// LDC2 hit times
    Double_t B_vdc0_u2_time[MAX_HITS_NUM];
    Double_t B_vdc0_v2_time[MAX_HITS_NUM];

    // variables for scintillation planes

    //Int_t Ndata_H_hod_1x_negtdchits;
    //Int_t Ndata_H_hod_1x_postdchits;
    //Double_t H_hod_1x_negtdchits[16];
    //Double_t H_hod_1x_postdchits[16];
    //Double_t* H_hod_1x_negtdchits;
    //Double_t* H_hod_1x_postdchits;

    Detector3D *detector;

    int run_number;
    const char *crun_number;

    const char *graph_title;

    TLatex *title;



};
#endif
