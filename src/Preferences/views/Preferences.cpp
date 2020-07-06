//
// Created by jvines on 6/3/2020.
//

#include "Preferences.h"

wxBEGIN_EVENT_TABLE(PreferencesWindow, wxDialog)
//	EVT_TREE_SEL_CHANGED(ID_Tree_Changed, PreferencesWindow::OnTreeSelection)
	EVT_BUTTON(wxID_APPLY, PreferencesWindow::OnApplyButton)
	EVT_BUTTON(wxID_CANCEL, PreferencesWindow::OnCancelButton)
	EVT_BUTTON(wxID_OK, PreferencesWindow::OnOkayButton)
	EVT_IDLE(PreferencesWindow::OnIdle)
wxEND_EVENT_TABLE()

PreferencesWindow::PreferencesWindow(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                     const wxSize &size, long style)
		: wxDialog(parent, id, title, pos, size, style) {
	this->SetExtraStyle(wxFRAME_EX_CONTEXTHELP);
	this->SetMinClientSize(size);
	TreeBook = new wxTreebook(this, ID_Tree_Book);
	auto* dbConf = new DatabaseConn(TreeBook, ID_Tree_Book);
	dbConf->SetDialog(this);
	TreeBook->AddPage(dbConf, "Database Connection");

	DialogButtonsOK = new wxButton( this, wxID_OK );
	DialogButtonsApply = new wxButton( this, wxID_APPLY );
//	DialogButtonsApply->Enable(false);
	DialogButtonsCancel = new wxButton( this, wxID_CANCEL );

	DialogButtonsApply->Enable(false);
	DialogButtonsCancel->Enable(false);
	DialogButtonsOK->Enable(true);

	auto* DialogButtons = new wxStdDialogButtonSizer();
	DialogButtons->AddButton( DialogButtonsOK );
	DialogButtons->AddButton( DialogButtonsApply );
	DialogButtons->AddButton( DialogButtonsCancel );
	DialogButtons->Realize();

	auto* bSizerRoot = new wxBoxSizer(wxVERTICAL);
	bSizerRoot->Add(TreeBook, 1, wxALL | wxEXPAND, 5);
	bSizerRoot->Add(DialogButtons, 0, wxEXPAND | wxBOTTOM | wxRIGHT, 5 );

	this->SetSizer(bSizerRoot );
	this->Layout();
	this->Centre( wxBOTH );

}


void PreferencesWindow::OnTreeSelection(wxTreeEvent& event) {
	// TODO: Preferences Tree Page Selection: switch to preferences page.
//	ShowSelectedPanel();
	event.Skip();
}

void PreferencesWindow::OnApplyButton(wxCommandEvent& event) {
	// TODO: Apply Button: force app to reprocess updated in-memory preferences.
//	Close(true);
	SavePrefs();
	event.Skip();
}

void PreferencesWindow::OnCancelButton(wxCommandEvent& event) {
	// TODO: Cancel Button: roll-back in-memory preferences.
	Close(true);
	event.Skip();
}

void PreferencesWindow::OnOkayButton(wxCommandEvent& event) {
	// TODO: OK Button: save new preferences to disk.
	if (GetModified()) {
		SavePrefs();
	}
	Close(true);
	event.Skip();
}

void PreferencesWindow::OnIdle(wxIdleEvent& event) {
	DialogButtonsApply->Enable(GetModified());
	DialogButtonsCancel->Enable(GetModified());
//	DialogButtonsOK->Enable(GetModified());
}

