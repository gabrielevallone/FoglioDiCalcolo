#include <wx/wx.h>
#include "gtest/gtest.h"
#include "../FoglioDiCalcolo.h"
#include "../main.h"


TEST(FoglioDiCalcoloSuite, testingConstructor) {

    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    ASSERT_EQ(ptr->GetSize(), wxSize(720, 480));
    ASSERT_EQ(ptr->getNumOfCells(), 50);
    ASSERT_EQ(ptr->getCells()[0]->GetValue(), wxEmptyString);
    ASSERT_TRUE(ptr->getValues()[0].isEmpty);

}

TEST(FoglioDiCalcoloSuite, testingEvent) {

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


TEST(FoglioDiCalcoloSuite, testingCellsValues) {

    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    ptr->getCells()[0]->SetValue(wxT("14"));
    ptr->getCells()[1]->SetValue(wxT("-7"));

    ASSERT_DOUBLE_EQ(14, ptr->getValues()[0].value);
    ASSERT_FALSE(ptr->getValues()[0].isEmpty);

    ASSERT_DOUBLE_EQ(-7, ptr->getValues()[1].value);
    ASSERT_FALSE(ptr->getValues()[1].isEmpty);

    ptr->getCells()[0]->SetValue(wxEmptyString);
    ASSERT_FALSE(ptr->getValues()[0].isEmpty);
    ASSERT_TRUE(ptr->getValues()[2].isEmpty);
}


TEST(FoglioDiCalcoloSuite, testingOserverList) {

    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    unsigned long int l = ptr->getObserverList().size();
    ASSERT_EQ(0, l);

    auto sum = new Sum(ptr);
    auto max = new Max(ptr);
    auto min = new Min(ptr);
    auto media = new Media(ptr);
    l = ptr->getObserverList().size();
    ASSERT_EQ(4, l);

    delete sum;
    delete max;
    l = ptr->getObserverList().size();
    ASSERT_EQ(2, l);

    delete min;
    delete media;
    l = ptr->getObserverList().size();
    ASSERT_EQ(0, l);

}
