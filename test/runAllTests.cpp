//
// Created by vallons on 05/09/22.
//

#include <gtest/gtest.h>
#include "wx/wx.h"
#include "../main.h"

IMPLEMENT_APP_NO_MAIN(MyApp)

int main(int argc, char *argv[]) {

    wxEntryStart(argc, argv);
    auto ptr = dynamic_cast<MyApp *>(wxTheApp);
    ptr->CallOnInit();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


bool MyApp::OnInit() {

    ptr = new FoglioDiCalcolo(wxT("Foglio di Calcolo"));
    return true;
}