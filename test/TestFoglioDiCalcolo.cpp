#include <wx/wx.h>
#include "gtest/gtest.h"
#include "../FoglioDiCalcolo.h"
#include "../main.h"


TEST(FoglioDiCalcolo, testingConstructor) {

    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    ASSERT_EQ(ptr->GetSize(), wxSize(720, 480));
    ASSERT_EQ(ptr->getNumOfCells(), 50);
    ASSERT_EQ(ptr->getCells()[0]->GetValue(), wxEmptyString);
    ASSERT_TRUE(ptr->getValues()[0].isEmpty);

}

TEST(FoglioDiCalcolo, testingEvent) {

    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    ptr->getCells()[0]->SetValue(wxT("4.3"));
    ptr->getCells()[1]->SetValue(wxT("0"));

    double d = 0;
    wxString s = ptr->getCells()[0]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(4.3, d);

    s = ptr->getCells()[1]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(0, d);

    ptr->getCells()[0]->SetValue(wxT("-1e3"));
    s = ptr->getCells()[0]->GetValue();
    s.ToDouble(&d);
    ASSERT_DOUBLE_EQ(-1000, d);
}

