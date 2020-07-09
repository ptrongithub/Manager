//
// Created by jvines on 6/27/2020.
// Copyright (c) 2020 Phoenix Technological Research All rights reserved.
//

#ifndef MANAGER_MANUALQUERY_H
#define MANAGER_MANUALQUERY_H

// includes main application object and global library includes
#include "src/includes.h"
#include "src/db.inc.h"

class ManualQuery : public wxFrame {
public:
	ManualQuery();
	ManualQuery(wxWindow* parent,
	            wxWindowID id = wxID_ANY,
	            const wxString& = "Manual Query Entry",
	            const wxPoint& pos = wxDefaultPosition,
	            const wxSize& size = wxDefaultSize,
	            long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL);
	virtual	~ManualQuery();
	bool Create(wxWindow* parent,
	            wxWindowID id = wxID_ANY,
	            const wxString& = "Manual Query Entry",
	            const wxPoint& pos = wxDefaultPosition,
	            const wxSize& size = wxDefaultSize,
	            long style = wxCAPTION|wxCLOSE_BOX|wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL);
	void Init();

protected:
	wxButton* btnExecute;
	wxButton* btnClose;
	wxCheckBox* cbWordWrap;
	wxTextCtrl* tcQuery;
	wxTextCtrl* tcResult;

private:
	enum {
		ID_Btn_Execute = wxID_HIGHEST,
		ID_Btn_Close,
		ID_Cb_WordWrap,
		ID_Tc_Query,
		ID_Tc_Result
	};
	virtual void OnExecute(wxCommandEvent& event);
	virtual void OnClose(wxCommandEvent& event);
	virtual void OnWordWrap(wxCommandEvent& event);


DECLARE_EVENT_TABLE();
};


#endif //MANAGER_MANUALQUERY_H
