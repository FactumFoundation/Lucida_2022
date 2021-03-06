// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

//#ifndef WX_PRECOMP
#include <wx/wx.h>
//#endif

#include "AuxUtils.h"
#include <opencv2/opencv.hpp>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

cv::Mat ocv_image;
wxImage	wxw_image;
unsigned char* rawData;

#include "wx/preferences.h"

#include "wx/app.h"
#include "wx/config.h"
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // Testing the framework...
    LaserScanner::Average myAverage;
    myAverage.addValue(9.0);
    myAverage.addValue(9.0);
    myAverage.addValue(9.0);
    myAverage.addValue(9.0);
    float av = myAverage.getValue();

    // Testing OpenCV
    ocv_image = cv::imread("C:\\dev\\shaded.jpg");
    //const MySettings& settings = wxGetApp().GetSettings();
    //std::string fileName = wxGetApp().GetSettings().DataPath;


    // Creating WxWidget image
    wxw_image = wxImage(640, 480, rawData, TRUE);

    if (ocv_image.empty())
    {
        wxMessageBox("No image found","About Hello World", wxOK | wxICON_INFORMATION);
        Close(true);
    }

    cv::namedWindow("test"); // Create a window
    imshow("test", ocv_image); // Show our image inside the created window.
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    cv::destroyAllWindows();
    ocv_image.release();
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
        "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}