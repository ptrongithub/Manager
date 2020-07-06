//
// Created by jvines on 6/3/2020.
//

#ifndef MANAGER_PREFERENCES_H
#define MANAGER_PREFERENCES_H

// includes main application object and global library includes
#include "src/includes.h"

#include <wx/treebook.h>
#include "src/Preferences/Database/views/ConfigDatabaseConn.h"
#include "src/Preferences/helpers/PrefsData.h"

class PreferencesWindow : public wxDialog, public PrefsData {
public:
	PreferencesWindow(wxWindow* parent, wxWindowID id = wxID_ANY,
	                  const wxString& title = "Preferences",
	                  const wxPoint& pos = wxDefaultPosition,
	                  const wxSize& size = wxSize(640,480),
	                  long style = wxCAPTION | wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL
	);

protected:

	wxButton*   DialogButtonsApply;
	wxButton*   DialogButtonsCancel;
	wxButton*   DialogButtonsOK;
	wxTreebook* TreeBook;

private:
	enum {
		ID_Tree_Book = wxID_HIGHEST
	};

	// Event Handlers
	virtual void OnTreeSelection(wxTreeEvent& event);
	virtual void OnApplyButton(wxCommandEvent& event);
	virtual void OnCancelButton(wxCommandEvent& event);
	virtual void OnOkayButton(wxCommandEvent& event);
	virtual void OnIdle(wxIdleEvent& event);

	DECLARE_EVENT_TABLE();
};

#endif //MANAGER_PREFERENCES_H
