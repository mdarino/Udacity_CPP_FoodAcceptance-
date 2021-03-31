/** 
 *  @file   foodMain.h
 *  @brief  Food acceptance Main header file
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#ifndef FOODMAIN_H
#define FOODMAIN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/radiobut.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/event.h>
#include <vector>
#include <future>
#include <thread>

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

class MyFrame : public wxFrame
{
    public:
        MyFrame();
        wxButton* B_csv;
        wxButton* B_find;
        wxButton* B_manEnter;
        wxButton* B_process;
        wxCheckBox* CB_log;
        wxCheckBox* CB_saveImg;
        wxRadioButton* RB_incoming;
        wxRadioButton* RB_outgoing;
        wxStaticBitmap* StaticBitmapIn;
        wxStaticBitmap* StaticBitmapOut;
        wxStaticLine* StaticLine1;
        wxStaticLine* StaticLine2;
        wxStaticLine* StaticLine3;
        wxStaticLine* StaticLine4;
        wxStaticLine* StaticLine5;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText15;
        wxStaticText* StaticText16;
        wxStaticText* StaticText17;
        wxStaticText* StaticText18;
        wxStaticText* StaticText19;
        wxStaticText* StaticText1;
        wxStaticText* StaticText20;
        wxStaticText* StaticText21;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStaticText* st_currentDate;
        wxStaticText* st_dayFood;
        wxStaticText* st_dayInPorc;
        wxStaticText* st_dayInQuantity;
        wxStaticText* st_dayOutPorc;
        wxStaticText* st_dayOutQuantity;
        wxStaticText* st_reqInPorc;
        wxStaticText* st_reqInQuantity;
        wxStaticText* st_reqOutPorc;
        wxStaticText* st_reqOutQuantity;
        wxTextCtrl* T_manPorc;
        wxTimer Timer1;
        wxDatePickerCtrl* DatePickerCtrlEnd;
        wxDatePickerCtrl* DatePickerCtrlMan;
        wxDatePickerCtrl* DatePickerCtrlSta;

        std::thread tIncoming,tOutgoing;
        std::promise<void> exitSignalIn;
        std::promise<void> exitSignalOut;
        std::future<void> futureObjIn;
        std::future<void> futureObjOut;


    protected:
        static const long ID_ST_DAYFOOD;
        static const long ID_ST_CURRENTDATE;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICLINE1;
        static const long ID_RB_INCOMING;
        static const long ID_RB_OUTGOING;
        static const long ID_STATICTEXT4;
        static const long ID_CB_SAVEIMG;
        static const long ID_CB_LOG;
        static const long ID_B_PROCESS;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_T_MANPORC;
        static const long ID_STATICLINE2;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_ST_DAYINQUANTITY;
        static const long ID_ST_DAYINPORC;
        static const long ID_ST_DAYOUTQUANTITY;
        static const long ID_ST_DAYOUTPORC;
        static const long ID_STATICLINE3;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT18;
        static const long ID_B_FIND;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT21;
        static const long ID_STATICTEXT22;
        static const long ID_ST_REQINQUANTITY;
        static const long ID_ST_REQINPORC;
        static const long ID_ST_REQOUTQUANTITY;
        static const long ID_ST_REQOUTPORC;
        static const long ID_B_CSV;
        static const long ID_B_MANENTER;
        static const long ID_STATICLINE4;
        static const long ID_STATICBITMAPIN;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT12;
        static const long ID_STATICBITMAPOUT;
        static const long ID_STATICLINE5;
        static const long ID_TIMER1;
        static const long ID_DATEPICKERCTRL1;
        static const long ID_DATEPICKERCTRL2;
        static const long ID_DATEPICKERCTRL3;
    private:

        void OnClose(wxCloseEvent& event);
        void OnB_processClick(wxCommandEvent& event);
        void OnCB_saveImgClick(wxCommandEvent& event);
        void OnCB_logClick(wxCommandEvent& event);
        void OnB_manEnterClick(wxCommandEvent& event);
        void OnB_findClick(wxCommandEvent& event);
        void OnB_csvClick(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);

};

#endif