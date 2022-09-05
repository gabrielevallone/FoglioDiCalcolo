#include <wx/wx.h>
#include "gtest/gtest.h"
#include "../FoglioDiCalcolo.h"
#include "../main.h"


TEST(MySpreadsheetSuite, testingConstructor) {

    auto ptr = dynamic_cast<FoglioDiCalcolo *> (wxTheApp->GetTopWindow());
    ASSERT_EQ(ptr->GetSize(), wxSize(720, 480));
    ASSERT_EQ(ptr->getNumOfCells(), 50);
    ASSERT_EQ(ptr->getCells()[0]->GetValue(), wxEmptyString);
    ASSERT_TRUE(ptr->getValues()[0].isEmpty);

}
