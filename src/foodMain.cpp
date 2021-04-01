/** 
 *  @file   foodMain.cpp
 *  @brief  Food acceptance Main source code
 *  @author Marcos Darino
 *  @date   2020-MAR-01
 ***********************************************/

#include "selfTest.h"
#include "debugFood.h"
#include "foodMain.h"
#include "plate.h"
#include "camera.h"
#include "db.h"


// size of chatbot window
constexpr int width = 1050;
constexpr int height = 780;

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
const long MyFrame::ID_STATICTEXT13 = wxNewId();
const long MyFrame::ID_STATICTEXT12 = wxNewId();
const long MyFrame::ID_STATICBITMAPOUT = wxNewId();
const long MyFrame::ID_STATICBITMAPIN = wxNewId();
const long MyFrame::ID_STATICLINE5 = wxNewId();
const long MyFrame::ID_TIMER1 = wxNewId();
const long MyFrame::ID_DATEPICKERCTRL1 = wxNewId();
const long MyFrame::ID_DATEPICKERCTRL2 = wxNewId();
const long MyFrame::ID_DATEPICKERCTRL3 = wxNewId();

Camera myInCamera("LogCamIn.txt", "../log/", true, 0, false);  /* Incoming camara */
Camera myOutCamera("LogCamOut.txt", "../log/", true, 1, false);  /* Outgoing camara */
std::shared_ptr<ResultDB> myResult = std::make_shared<ResultDB>("LogDB.txt", "../log/", true);;

std::thread tResults;
std::promise<void> tResultExit;
std::future<void> tResultFuture;
bool myProcessFlag = false;

wxIMPLEMENT_APP(MyApp);  /* MAIN */
bool MyApp::OnInit()
{
    // make sure to call this first
    wxInitAllImageHandlers();
    
    /* SELFTEST OF THE SYSTEM */
    if (false == selfTest())
    {
        std::cout << "SELFTEST FAIL!!" << std::endl;
        return false; /*Don't lunch the GUI */
    }
    
    myResult->PlateName("Meat with salad");
    myResult->ExpPercentage(71);

    std::srand((unsigned) time(0));
    myInCamera.dPrintObj();
    myOutCamera.dPrintObj();
    myResult->dPrintObj();

    tResultFuture = tResultExit.get_future();
    tResults = std::thread(&ResultDB::processRecords, myResult, std::move(tResultFuture)); /*STD REF to avoid std::tuple …’ no overloaded function …”.*/
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Food Acceptance", wxDefaultPosition, wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
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

    st_dayFood = new wxStaticText(this, ID_ST_DAYFOOD, _(myResult->PlateName()), wxPoint(64,16), wxSize(248,17), 0, _T("ID_ST_DAYFOOD"));
    st_currentDate = new wxStaticText(this, ID_ST_CURRENTDATE, _("_____________________"), wxPoint(64,48), wxDefaultSize, 0, _T("ID_ST_CURRENTDATE"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("FOOD NAME:"), wxPoint(10,16), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT3, _("DATE"), wxPoint(10,48), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(8,120), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    RB_incoming = new wxRadioButton(this, ID_RB_INCOMING, _("INCOMING"), wxPoint(200,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RB_INCOMING"));
    RB_outgoing = new wxRadioButton(this, ID_RB_OUTGOING, _("OUTGOING"), wxPoint(80,152), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RB_OUTGOING"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT4, _("MANUAL CONTROL"), wxPoint(8,128), wxSize(112,17), 0, _T("ID_STATICTEXT4"));
    wxFont StaticText3Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    CB_saveImg = new wxCheckBox(this, ID_CB_SAVEIMG, _("Save Img"), wxPoint(440,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CB_SAVEIMG"));
    CB_saveImg->SetValue(false);
    CB_log = new wxCheckBox(this, ID_CB_LOG, _("Log"), wxPoint(544,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CB_LOG"));
    CB_log->SetValue(true);
    B_process = new wxButton(this, ID_B_PROCESS, _("PROCESS"), wxPoint(16,80), wxSize(368,34), 0, wxDefaultValidator, _T("ID_B_PROCESS"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT5, _("DATE"), wxPoint(16,192), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
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
    st_dayInQuantity = new wxStaticText(this, ID_ST_DAYINQUANTITY, _("0"), wxPoint(112,312), wxDefaultSize, 0, _T("ID_ST_DAYINQUANTITY"));
    st_dayInPorc = new wxStaticText(this, ID_ST_DAYINPORC, _("0"), wxPoint(216,312), wxDefaultSize, 0, _T("ID_ST_DAYINPORC"));
    st_dayOutQuantity = new wxStaticText(this, ID_ST_DAYOUTQUANTITY, _("0"), wxPoint(112,344), wxDefaultSize, 0, _T("ID_ST_DAYOUTQUANTITY"));
    st_dayOutPorc = new wxStaticText(this, ID_ST_DAYOUTPORC, _("0"), wxPoint(216,344), wxDefaultSize, 0, _T("ID_ST_DAYOUTPORC"));
    StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxPoint(0,384), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    StaticText15 = new wxStaticText(this, ID_STATICTEXT16, _("DB REQUEST"), wxPoint(8,392), wxSize(184,17), 0, _T("ID_STATICTEXT16"));
    wxFont StaticText15Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText15->SetFont(StaticText15Font);
    StaticText16 = new wxStaticText(this, ID_STATICTEXT17, _("START DATE"), wxPoint(24,424), wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    StaticText17 = new wxStaticText(this, ID_STATICTEXT18, _("END DATE"), wxPoint(32,464), wxDefaultSize, 0, _T("ID_STATICTEXT18"));
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
    B_manEnter = new wxButton(this, ID_B_MANENTER, _("ENTER"), wxPoint(315,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_B_MANENTER"));
    StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxPoint(0,656), wxSize(400,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));

    StaticBitmapIn = new wxStaticBitmap(this, ID_STATICBITMAPIN, wxBitmap(wxImage(_T("../data/start.jpg")).Rescale(wxSize(600,300).GetWidth(),wxSize(600,300).GetHeight())), wxPoint(432,64), wxSize(600,300), 0, _T("ID_STATICBITMAPIN"));
    StaticBitmapIn->SetBackgroundColour(wxColour(196,196,196));
    StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("INCOMING"), wxPoint(440,40), wxSize(120,17), 0, _T("ID_STATICTEXT13"));
    wxFont StaticText13Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText13->SetFont(StaticText13Font);
    StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("OUTGOING"), wxPoint(440,376), wxSize(152,17), 0, _T("ID_STATICTEXT12"));
    wxFont StaticText12Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText12->SetFont(StaticText12Font);
    StaticBitmapOut = new wxStaticBitmap(this, ID_STATICBITMAPOUT, wxBitmap(wxImage(_T("../data/start.jpg")).Rescale(wxSize(600,300).GetWidth(),wxSize(600,300).GetHeight())), wxPoint(432,400), wxSize(600,300), 0, _T("ID_STATICBITMAPOUT"));
    StaticLine5 = new wxStaticLine(this, ID_STATICLINE5, wxPoint(408,0), wxSize(5,800), wxLI_HORIZONTAL, _T("ID_STATICLINE5"));
    Timer1.SetOwner(this, ID_TIMER1);
    
    DatePickerCtrlMan = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxPoint(64,184), wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    DatePickerCtrlSta = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxPoint(120,416), wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    DatePickerCtrlEnd = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL3, wxDefaultDateTime, wxPoint(120,456), wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL3"));

    Connect(ID_CB_SAVEIMG,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MyFrame::OnCB_saveImgClick);
    Connect(ID_CB_LOG,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MyFrame::OnCB_logClick);
    Connect(ID_B_PROCESS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_processClick);
    Connect(ID_B_FIND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_findClick);
    Connect(ID_B_CSV,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_csvClick);
    Connect(ID_B_MANENTER,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MyFrame::OnB_manEnterClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&MyFrame::OnTimer1Trigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MyFrame::OnClose);

}

void MyFrame::OnExit(wxCommandEvent& event)
{
    std::cout << "Close OnExit Event" << std::endl;
    Close(true);
}


void MyFrame::OnClose(wxCloseEvent& event)
{
    std::cout << "Close OnClose Event" << std::endl;
    
    if(myProcessFlag == true)
    {
        exitSignalIn.set_value();
        exitSignalOut.set_value();
        SetStatusText("Wait!!!");
        tIncoming.join();
        tOutgoing.join();
    }
    tResultExit.set_value();
    /* Send a special message to request close */
    DBNewRecord myNewRecord("", "", true, 0, 0, true);
    auto ftr_store = (std::async(std::launch::async, &RecordQueue<DBNewRecord>::Store, &(myResult->newDataResult), std::move(myNewRecord)));
    tResults.join();
    Timer1.Stop();
    event.Skip(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("C++ Capstone Project for the Udacity C++ Nanodegree Program","", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnB_processClick(wxCommandEvent& event)
{
    
    if(myProcessFlag == true)
    {
        /* TURN OFF */
        SetStatusText("Wait!!!");
        B_process->SetBackgroundColour(*wxYELLOW);
        B_process->SetLabel("PLEASE WAIT");
        exitSignalIn.set_value();
        exitSignalOut.set_value();
        StaticBitmapIn->SetBitmap(wxBitmap( "../data/start.jpg", wxBITMAP_TYPE_PNG));
        StaticBitmapOut->SetBitmap(wxBitmap( "../data/start.jpg", wxBITMAP_TYPE_PNG));
        tIncoming.join();
        tOutgoing.join();
        myProcessFlag = false;
        exitSignalIn = {}; /* Reset the Promise */
        exitSignalOut = {};
        Timer1.Stop();
        SetStatusText("Manual Mode");
        B_process->SetBackgroundColour(*wxLIGHT_GREY);
        B_process->SetLabel("PROCESS");

        B_manEnter->Enable(true);
        B_csv->Enable(true);
        B_find->Enable(true);
        DatePickerCtrlEnd->Enable(false);
        DatePickerCtrlSta->Enable(false);
        T_manPorc->Enable(true);
        DatePickerCtrlMan->Enable(false);
        CB_log->Enable(true);
        CB_saveImg->Enable(true);
        RB_incoming->Enable(true);
        RB_outgoing->Enable(true);
    }
    else
    {
        /* TURN ON*/
        B_process->SetBackgroundColour(*wxGREEN);
        B_process->SetLabel("RUN");
        SetStatusText("Processing a new images!");
        futureObjIn = exitSignalIn.get_future();
        futureObjOut = exitSignalOut.get_future();
        myProcessFlag = true;
        Timer1.Start(1000, wxTIMER_CONTINUOUS);
        tIncoming = std::thread(&Camera::processImage, myInCamera, std::move(futureObjIn), myResult);
        tOutgoing = std::thread(&Camera::processImage, myOutCamera, std::move(futureObjOut), myResult);
   
        B_manEnter->Enable(false);
        B_csv->Enable(false);
        B_find->Enable(false);
        DatePickerCtrlEnd->Enable(false);
        DatePickerCtrlSta->Enable(false);
        T_manPorc->Enable(false);
        DatePickerCtrlMan->Enable(false);
        CB_log->Enable(false);
        CB_saveImg->Enable(false);
        RB_incoming->Enable(false);
        RB_outgoing->Enable(false);
   
    }
    
}

void MyFrame::OnCB_saveImgClick(wxCommandEvent& event)
{
    if(CB_saveImg->GetValue() == true)
    {
        myInCamera.SaveFlag(true);
        myOutCamera.SaveFlag(true);
    }
    else
    {
        myInCamera.SaveFlag(false);
        myOutCamera.SaveFlag(false);
    }
}

void MyFrame::OnCB_logClick(wxCommandEvent& event)
{
    if(CB_log->GetValue() == true)
    {
        myInCamera.SaveFlag(true);
        myOutCamera.SaveFlag(true);
    }
    else
    {
        myInCamera.SaveFlag(false);
        myOutCamera.SaveFlag(false);
    }
}

void MyFrame::OnB_manEnterClick(wxCommandEvent& event)
{
    unsigned int percentage;
    bool dataValid = true;
    std::string perString = std::string(T_manPorc->GetValue());
    try {
      percentage = std::stoi(perString);
      percentage = myResult->valPercentage(percentage);
    } catch (const std::invalid_argument& ex) {
      dataValid = false;
    }
    
    if(dataValid == true)
    {
        bool inFlagMan = false;
        if(RB_incoming->GetValue() == true) {inFlagMan = true;}
        wxDateTime dateTime = DatePickerCtrlSta->GetValue();
        // From SQLITE DOC -> DATE format TEXT as ISO8601 strings ("YYYY-MM-DD HH:MM:SS.SSS").
        std::string date = std::string(dateTime.Format(wxT(DB_DATE_FORMAT), wxDateTime::UTC ));
        DBNewRecord myNewRecord(myResult->PlateName(), date, inFlagMan, percentage, myResult->ExpPercentage(), true);
        auto ftr_store = (std::async(std::launch::async, &RecordQueue<DBNewRecord>::Store, &(myResult->newDataResult), std::move(myNewRecord)));
    }
    else
    {
        wxMessageBox("INVALID DATA","", wxOK | wxICON_INFORMATION);
    }
}

void MyFrame::OnB_findClick(wxCommandEvent& event)
{
    wxDateTime dateTimeStart = DatePickerCtrlSta->GetValue();
    wxDateTime dateTimeEnd = DatePickerCtrlEnd->GetValue();
    myResult->requestUpdate(std::string(dateTimeStart.FormatISODate()), std::string(dateTimeEnd.FormatISODate()));

    st_reqInQuantity->SetLabel(std::to_string(myResult->findQuantity(true)));
    st_reqInPorc->SetLabel(std::to_string(myResult->findPercentage(true)));
    st_reqOutQuantity->SetLabel(std::to_string(myResult->findQuantity(false)));
    st_reqOutPorc->SetLabel(std::to_string(myResult->findPercentage(false)));

}

void MyFrame::OnB_csvClick(wxCommandEvent& event)
{
    wxDateTime dateTimeStart = DatePickerCtrlSta->GetValue();
    wxDateTime dateTimeEnd = DatePickerCtrlEnd->GetValue();
    myResult->csvFile(std::string(dateTimeStart.FormatISODate()), std::string(dateTimeEnd.FormatISODate()));
}

void MyFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    StaticBitmapIn->SetBitmap(wxBitmap( "../data/lastIn.jpg", wxBITMAP_TYPE_PNG));
    StaticBitmapOut->SetBitmap(wxBitmap( "../data/lastOut.jpg", wxBITMAP_TYPE_PNG));

    st_dayInQuantity->SetLabel(std::to_string(myResult->dayQuantity(true)));
    st_dayInPorc->SetLabel(std::to_string(myResult->dayPercentage(true)));

    st_dayOutQuantity->SetLabel(std::to_string(myResult->dayQuantity(false)));
    st_dayOutPorc->SetLabel(std::to_string(myResult->dayPercentage(false)));
}
