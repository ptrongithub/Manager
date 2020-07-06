//
// Created by jvines on 6/3/2020.
//

#ifndef MANAGER_CONFIGDATABASECONN_H
#define MANAGER_CONFIGDATABASECONN_H

// includes main application object and global library includes
#include "src/includes.h"
#include "src/Preferences/helpers/PrefsData.h"
#include "src/Preferences/views/Preferences.h"

#include <map>
#include <vector>
#include <wx/tglbtn.h>

class DatabaseConn : public wxPanel {
//	DECLARE_CLASS(DatabaseConn)
	DECLARE_EVENT_TABLE()

public:

	DatabaseConn();
	DatabaseConn(wxWindow* parent, wxWindowID id = wxID_ANY,
	             const wxPoint& pos = wxDefaultPosition,
	             const wxSize& size = wxDefaultSize,
	             long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);
	virtual ~DatabaseConn();
	bool Create(wxWindow* parent, wxWindowID id = wxID_ANY,
	            const wxPoint& pos = wxDefaultPosition,
	            const wxSize& size = wxDefaultSize,
	            long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);

	void Init();

	bool SetDialog(PrefsData* PrefsDialog);

protected:

	wxTextCtrl*   tcHost;
	wxTextCtrl*   tcPort;
	wxTextCtrl*   tcUser;
	wxTextCtrl*   tcPass;
	wxTextCtrl*   tcData;
	wxButton*     bTest;
	wxStaticText* stResult;

private:

	enum {
		ID_Grid = wxID_HIGHEST,
		ID_BTN_Test,
		ID_ST_Result,
		ID_TC_Host,
		ID_TC_Port,
		ID_TC_User,
		ID_TC_Pass,
		ID_TC_Data
	};

	// Event Handlers
	virtual void OnTextChange(wxCommandEvent& event);
	virtual void OnTestButton(wxCommandEvent& event);

	PrefsData* Dialog;
	wxString   host;
	wxString   port;
	wxString   user;
	wxString   pass;
	wxString   data;
};


#endif //MANAGER_CONFIGDATABASECONN_H
