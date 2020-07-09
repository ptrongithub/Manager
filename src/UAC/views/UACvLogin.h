//
// Created by jvines on 6/28/2020.
// Copyright (c) 2020 Phoenix Technological Research. All rights reserved.
//

#ifndef MANAGER_UACVLOGIN_H
#define MANAGER_UACVLOGIN_H

// includes main application object and global library includes
#include "src/includes.h"
#include "src/views.inc.h"

class UACvLogin : public wxDialog {
public:
	UACvLogin();
	UACvLogin(wxWindow* parent,
	          wxWindowID id = wxID_ANY,
	          const wxString& title = "Login",
	          const wxPoint& pos = wxDefaultPosition,
	          const wxSize& size = wxDefaultSize,
	          long style = wxCAPTION | wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	virtual ~UACvLogin();
	bool Create(wxWindow* parent,
	            wxWindowID id = wxID_ANY,
	            const wxString& title = "Login",
	            const wxPoint& pos = wxDefaultPosition,
	            const wxSize& size = wxDefaultSize,
	            long style = wxCAPTION | wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	void Init();
	void CreateControls();

	const wxString& GetUser() const;
	const wxString& GetPass() const;
	void SetUser(const wxString& sUser);
	void SetPass(const wxString& sPass);

protected:
	wxTextCtrl* tcUser;
	wxTextCtrl* tcPass;
	wxButton*   btnOk;
	wxButton*   btnCancel;

private:
	enum {
		ID_Tc_User = wxID_HIGHEST,
		ID_Tc_Pass,
		ID_Btn_Ok,
		ID_Btn_Cancel
	};
	wxString sUser;
	wxString sPass;

DECLARE_EVENT_TABLE()
};

#endif //MANAGER_UACVLOGIN_H
