#include <iostream>
#include <sstream>

#include "accounting_entry_model.hpp"

const std::string input_text = R"(1    VE20140621201406211           7587010    MEUBLES 1                       690.00C1                 
1    VE20140621201406211           7587019    JOUETS                          186.00C1                 
1    VE20140621201406211           7587017    BAZAR                           771.70C1                 
1    VE20140621201406211           7587018    MERCERIE                         84.00C1                 
1    VE20140621201406211           7587090    LIVRAISONS                       30.00C1                 
1    VE20140621201406211           7587011    MEUBLES 2                       130.00C1                 
1    VE20140621201406211           7587027    MEUBLES 4                       195.00C1                 
1    VE20140621201406211           7587016    BIBELOTS 1                      583.50C1                 
1    VE20140621201406211           7587013    ELECTROMENAGER                  467.00C1                 
1    VE20140621201406211           7587020    TV-HIFI-ORDI                    297.00C1                 
1    VE20140621201406211           7587012    VETEMENTS                       791.50C1                 
1    VE20140621201406211           7587015    LIVRES                          338.50C1                 
1    VE20140621201406211           7587026    MEUBLES 3                       225.00C1                 
1    VE20140621201406211           411030P    Especes                        2596.00D1                 
1    VE20140621201406211           411020P    Cheque                          323.00D1                 
1    VE20140621201406211           411010P    Carte Bancaire                 1736.20D1                 
1    VE20140621201406211           401020P    Cheque D                        134.00D1                 
1    VE20140621201406211           709000     Remise sur Vente                  7.80D1                 
1    VE20140621201406211           419700     Equilibrage Remise sur ve         7.80C1)";

void testReading() {
    std::stringstream input(input_text);
    AccountingEntryModel line1;
    input >> line1;
    AccountingEntryModel line2;
    input >> line2;
1    VE20140621201406211           7587010    MEUBLES 1                       690.00C1                 

    assert(line1.movement_number[0] == "1     ");
    assert(line1.journal_number == 1);


}


int main(int argc, char** argv) {

}

