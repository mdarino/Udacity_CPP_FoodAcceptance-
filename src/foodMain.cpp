#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/radiobut.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

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
        wxRadioButton* rb_incoming;
        wxRadioButton* rb_outgoing;
        wxStaticLine* StaticLine1;
        wxStaticLine* StaticLine2;
        wxStaticLine* StaticLine3;
        wxStaticLine* StaticLine4;
        wxStaticText* StaticText10;
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
        wxTextCtrl* T_endDate;
        wxTextCtrl* T_manPorc;
        wxTextCtrl* T_manQuantity;
        wxTextCtrl* T_startDate;

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
        static const long ID_T_MANQUANTITY;
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
        static const long ID_T_STARTDATE;
        static const long ID_T_ENDDATE;
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

    private:
        void OnB_processClick(wxCommandEvent& event);
        void OnCB_saveImgClick(wxCommandEvent& event);
        void OnCB_logClick(wxCommandEvent& event);
        void Onrb_outgoingSelect(wxCommandEvent& event);
        void Onrb_incomingSelect(wxCommandEvent& event);
        void OnB_manEnterClick(wxCommandEvent& event);
        void OnT_manQuantityText(wxCommandEvent& event);
        void OnT_manPorcText(wxCommandEvent& event);
        void OnT_startDateText(wxCommandEvent& event);
        void OnT_endDateText(wxCommandEvent& event);
        void OnB_findClick(wxCommandEvent& event);
        void OnB_csvClick(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
};


const long MyFrame::ID_ST_DAYFOOD = wxNewId();
const long MyFrame::ID_ST_CURRENTDATE = wxNewId();
const long MyFrame::ID_STATICTEXT2 = wxNewId();
const long MyFrame::ID_STATICTEXT3 = wxNewId();
const long MyFrame::ID_STATICLINE1 = wxNewId();
const long MyFrame::ID_RB_INCOMING = wxNewId();
const long MyFrame::ID_RB_OUTGOING = wxNewId();
const long MyFrame::ID_STATICTEXT4 = wxNewId();
const long MyFrame::ID_CB_SAVEIMG = wxNewId();
const long MyFrame::ID_CB_LOG = wxNewId();
const long MyFrame::ID_B_PROCESS = wxNewId();
const long MyFrame::ID_STATICTEXT5 = wxNewId();
const long MyFrame::ID_T_MANQUANTITY = wxNewId();
const long MyFrame::ID_STATICTEXT6 = wxNewId();
const long MyFrame::ID_T_MANPORC = wxNewId();
const long MyFrame::ID_STATICLINE2 = wxNewId();
const long MyFrame::ID_STATICTEXT7 = wxNewId();
const long MyFrame::ID_STATICTEXT8 = wxNewId();
const long MyFrame::ID_STATICTEXT9 = wxNewId();
const long MyFrame::ID_STATICTEXT10 = wxNewId();
const long MyFrame::ID_STATICTEXT11 = wxNewId();
const long MyFrame::ID_ST_DAYINQUANTITY = wxNewId();
const long MyFrame::ID_ST_DAYINPORC = wxNewId();
const long MyFrame::ID_ST_DAYOUTQUANTITY = wxNewId();
const long MyFrame::ID_ST_DAYOUTPORC = wxNewId();
const long MyFrame::ID_STATICLINE3 = wxNewId();
const long MyFrame::ID_STATICTEXT16 = wxNewId();
const long MyFrame::ID_STATICTEXT17 = wxNewId();
const long MyFrame::ID_STATICTEXT18 = wxNewId();
const long MyFrame::ID_T_STARTDATE = wxNewId();
const long MyFrame::ID_T_ENDDATE = wxNewId();
const long MyFrame::ID_B_FIND = wxNewId();
const long MyFrame::ID_STATICTEXT19 = wxNewId();
const long MyFrame::ID_STATICTEXT20 = wxNewId();
const long MyFrame::ID_STATICTEXT21 = wxNewId();
const long MyFrame::ID_STATICTEXT22 = wxNewId();
const long MyFrame::ID_ST_REQINQUANTITY = wxNewId();
const long MyFrame::ID_ST_REQINPORC = wxNewId();
const long MyFrame::ID_ST_REQOUTQUANTITY = wxNewId();
const long MyFrame::ID_ST_REQOUTPORC = wxNewId();
const long MyFrame::ID_B_CSV = wxNewId();
const long MyFrame::ID_B_MANENTER = wxNewId();
const long MyFrame::ID_STATICLINE4 = wxNewId();


wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to Food Acceptance software!");
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    SetClientSize(wxSize(399,660));
    st_dayFood = new wxStaticText(this, ID_ST_DAYFOOD, _("_____________________"), wxPoint(64,16), wxSize(248,17), 0, _T("ID_ST_DAYFOOD"));
    st_currentDate = new wxStaticText(this, ID_ST_CURRENTDATE, _("_____________________"), wxPoint(64,48), wxDefaultSize, 0, _T("ID_ST_CURRENTDATE"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("FOOD NAME:"), wxPoint(10,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT3, _("DATE"), wxPoint(10,48), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(0,152), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    rb_incoming = new wxRadioButton(this, ID_RB_INCOMING, _("INCOMING"), wxPoint(24,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RB_INCOMING"));
    rb_outgoing = new wxRadioButton(this, ID_RB_OUTGOING, _("OUTGOING"), wxPoint(24,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RB_OUTGOING"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT4, _("MANUAL CONTROL"), wxPoint(10,160), wxSize(112,17), 0, _T("ID_STATICTEXT4"));
    wxFont StaticText3Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    CB_saveImg = new wxCheckBox(this, ID_CB_SAVEIMG, _("Save Img"), wxPoint(200,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CB_SAVEIMG"));
    CB_saveImg->SetValue(false);
    CB_log = new wxCheckBox(this, ID_CB_LOG, _("Log"), wxPoint(200,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CB_LOG"));
    CB_log->SetValue(false);
    B_process = new wxButton(this, ID_B_PROCESS, _("PROCESS"), wxPoint(288,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_B_PROCESS"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT5, _("QUANTITY"), wxPoint(16,192), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    T_manQuantity = new wxTextCtrl(this, ID_T_MANQUANTITY, _("0"), wxPoint(104,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_T_MANQUANTITY"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT6, _("%"), wxPoint(200,192), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    T_manPorc = new wxTextCtrl(this, ID_T_MANPORC, _("0"), wxPoint(216,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_T_MANPORC"));
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(0,232), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT7, _("DAY RESULTS"), wxPoint(10,240), wxSize(174,17), 0, _T("ID_STATICTEXT7"));
    wxFont StaticText6Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT8, _("QUANTITY"), wxPoint(112,272), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    StaticText8 = new wxStaticText(this, ID_STATICTEXT9, _("%"), wxPoint(216,272), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    StaticText9 = new wxStaticText(this, ID_STATICTEXT10, _("IN"), wxPoint(16,312), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticText10 = new wxStaticText(this, ID_STATICTEXT11, _("OUT"), wxPoint(16,344), wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    st_dayInQuantity = new wxStaticText(this, ID_ST_DAYINQUANTITY, _("___"), wxPoint(112,312), wxDefaultSize, 0, _T("ID_ST_DAYINQUANTITY"));
    st_dayInPorc = new wxStaticText(this, ID_ST_DAYINPORC, _("___"), wxPoint(216,312), wxDefaultSize, 0, _T("ID_ST_DAYINPORC"));
    st_dayOutQuantity = new wxStaticText(this, ID_ST_DAYOUTQUANTITY, _("___"), wxPoint(112,344), wxDefaultSize, 0, _T("ID_ST_DAYOUTQUANTITY"));
    st_dayOutPorc = new wxStaticText(this, ID_ST_DAYOUTPORC, _("___"), wxPoint(216,344), wxDefaultSize, 0, _T("ID_ST_DAYOUTPORC"));
    StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxPoint(0,384), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    StaticText15 = new wxStaticText(this, ID_STATICTEXT16, _("DB REQUEST"), wxPoint(8,392), wxSize(184,17), 0, _T("ID_STATICTEXT16"));
    wxFont StaticText15Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText15->SetFont(StaticText15Font);
    StaticText16 = new wxStaticText(this, ID_STATICTEXT17, _("START DATE"), wxPoint(24,424), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    StaticText17 = new wxStaticText(this, ID_STATICTEXT18, _("END DATE"), wxPoint(32,464), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    T_startDate = new wxTextCtrl(this, ID_T_STARTDATE, _("mm/dd/yyyy"), wxPoint(112,416), wxSize(104,34), 0, wxDefaultValidator, _T("ID_T_STARTDATE"));
    T_endDate = new wxTextCtrl(this, ID_T_ENDDATE, _("mm/dd/yyyy"), wxPoint(112,456), wxSize(104,34), 0, wxDefaultValidator, _T("ID_T_ENDDATE"));
    B_find = new wxButton(this, ID_B_FIND, _("FIND"), wxPoint(248,456), wxDefaultSize, 0, wxDefaultValidator, _T("ID_B_FIND"));
    StaticText18 = new wxStaticText(this, ID_STATICTEXT19, _("IN"), wxPoint(24,544), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    StaticText19 = new wxStaticText(this, ID_STATICTEXT20, _("OUT"), wxPoint(24,584), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    StaticText20 = new wxStaticText(this, ID_STATICTEXT21, _("QUANTITY"), wxPoint(112,512), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    StaticText21 = new wxStaticText(this, ID_STATICTEXT22, _("%"), wxPoint(216,512), wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    st_reqInQuantity = new wxStaticText(this, ID_ST_REQINQUANTITY, _("__"), wxPoint(112,544), wxDefaultSize, 0, _T("ID_ST_REQINQUANTITY"));
    st_reqInPorc = new wxStaticText(this, ID_ST_REQINPORC, _("__"), wxPoint(216,544), wxDefaultSize, 0, _T("ID_ST_REQINPORC"));
    st_reqOutQuantity = new wxStaticText(this, ID_ST_REQOUTQUANTITY, _("__"), wxPoint(112,584), wxDefaultSize, 0, _T("ID_ST_REQOUTQUANTITY"));
    st_reqOutPorc = new wxStaticText(this, ID_ST_REQOUTPORC, _("__"), wxPoint(216,584), wxDefaultSize, 0, _T("ID_ST_REQOUTPORC"));
    B_csv = new wxButton(this, ID_B_CSV, _("CSV"), wxPoint(24,616), wxDefaultSize, 0, wxDefaultValidator, _T("ID_B_CSV"));
    B_manEnter = new wxButton(this, ID_B_MANENTER, _("ENTER"), wxPoint(312,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_B_MANENTER"));
    StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxPoint(0,656), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));

    Connect(ID_RB_INCOMING,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&MyFrame::Onrb_incomingSelect);
    Connect(ID_RB_OUTGOING,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&MyFrame::Onrb_outgoingSelect);
    Connect(ID_CB_SAVEIMG,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MyFrame::OnCB_saveImgClick);
    Connect(ID_CB_LOG,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MyFrame::OnCB_logClick);
    Connect(ID_B_PROCESS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_processClick);
    Connect(ID_T_MANQUANTITY,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MyFrame::OnT_manQuantityText);
    Connect(ID_T_MANPORC,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MyFrame::OnT_manPorcText);
    Connect(ID_T_STARTDATE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MyFrame::OnT_startDateText);
    Connect(ID_T_ENDDATE,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MyFrame::OnT_endDateText);
    Connect(ID_B_FIND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_findClick);
    Connect(ID_B_CSV,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_csvClick);
    Connect(ID_B_MANENTER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_manEnterClick);

}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("C++ Capstone Project for the Udacity C++ Nanodegree Program","", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnB_processClick(wxCommandEvent& event)
{
}

void MyFrame::OnCB_saveImgClick(wxCommandEvent& event)
{
}

void MyFrame::OnCB_logClick(wxCommandEvent& event)
{
}

void MyFrame::Onrb_outgoingSelect(wxCommandEvent& event)
{
}

void MyFrame::Onrb_incomingSelect(wxCommandEvent& event)
{
}

void MyFrame::OnB_manEnterClick(wxCommandEvent& event)
{
}

void MyFrame::OnT_manQuantityText(wxCommandEvent& event)
{
}

void MyFrame::OnT_manPorcText(wxCommandEvent& event)
{
}

void MyFrame::OnT_startDateText(wxCommandEvent& event)
{
}

void MyFrame::OnT_endDateText(wxCommandEvent& event)
{
}

void MyFrame::OnB_findClick(wxCommandEvent& event)
{
}

void MyFrame::OnB_csvClick(wxCommandEvent& event)
{
}
