//
// Created by vallons on 05/09/22.
//
#include "gtest/gtest.h"
#include "../FoglioDiCalcolo.h"
#include "../Sum.h"
#include "../Media.h"
#include "../Max.h"
#include "../Min.h"

TEST(CalculateSuite, testingSum) {
    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    auto sum = new Sum(ptr);

    ptr->getCells()[0]->SetValue(wxT("4.3"));
    ptr->getCells()[1]->SetValue(wxT("8.3"));

    ASSERT_EQ(wxT("12.600000"), ptr->getResults()[0]->GetValue());

    ptr->getCells()[2]->SetValue(wxT("-15"));
    ptr->getCells()[0]->SetValue(wxT("11"));

    ASSERT_EQ(wxT("4.300000"), ptr->getResults()[0]->GetValue());

    ptr->getCells()[0]->SetValue(wxEmptyString);
    ptr->getCells()[1]->SetValue(wxEmptyString);
    ptr->getCells()[2]->SetValue(wxEmptyString);

    ASSERT_EQ(wxT("No values"), ptr->getResults()[0]->GetValue());

    delete sum;
}

TEST(CalculateSuite, testingMedia) {
    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    auto media = new Media(ptr);

    ptr->getCells()[45]->SetValue(wxT("5"));
    ptr->getCells()[7]->SetValue(wxT("-3"));

    ASSERT_EQ(wxT("1.000000"), ptr->getResults()[1]->GetValue());

    ptr->getCells()[22]->SetValue(wxT("10"));
    ptr->getCells()[45]->SetValue(wxT("11"));

    ASSERT_EQ(wxT("6.000000"), ptr->getResults()[1]->GetValue());

    ptr->getCells()[45]->SetValue(wxEmptyString);
    ptr->getCells()[7]->SetValue(wxEmptyString);
    ptr->getCells()[22]->SetValue(wxEmptyString);

    ASSERT_EQ(wxT("No values"), ptr->getResults()[1]->GetValue());

    delete media;
}

TEST(CalculateSuite, testingMax) {
    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    auto max = new Max(ptr);

    ptr->getCells()[4]->SetValue(wxT("-12"));
    ptr->getCells()[1]->SetValue(wxT("8.3"));

    ASSERT_EQ(wxT("8.300000"), ptr->getResults()[2]->GetValue());

    ptr->getCells()[2]->SetValue(wxT("15.1"));
    ptr->getCells()[4]->SetValue(wxT("15"));

    ASSERT_EQ(wxT("15.100000"), ptr->getResults()[2]->GetValue());

    ptr->getCells()[4]->SetValue(wxEmptyString);
    ptr->getCells()[1]->SetValue(wxEmptyString);
    ptr->getCells()[2]->SetValue(wxEmptyString);

    ASSERT_EQ(wxT("No values"), ptr->getResults()[2]->GetValue());

    delete max;

}

TEST(CalculateSuite, testingMin) {
    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    auto min = new Min(ptr);

    ptr->getCells()[0]->SetValue(wxT("-7"));
    ptr->getCells()[11]->SetValue(wxT("6.25"));

    ASSERT_EQ(wxT("-7.000000"), ptr->getResults()[3]->GetValue());

    ptr->getCells()[5]->SetValue(wxT("14.125"));
    ptr->getCells()[0]->SetValue(wxT("12"));

    ASSERT_EQ(wxT("6.250000"), ptr->getResults()[3]->GetValue());

    ptr->getCells()[0]->SetValue(wxEmptyString);
    ptr->getCells()[11]->SetValue(wxEmptyString);
    ptr->getCells()[5]->SetValue(wxEmptyString);

    ASSERT_EQ(wxT("No values"), ptr->getResults()[3]->GetValue());

    delete min;
}

