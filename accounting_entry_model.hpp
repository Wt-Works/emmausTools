/** This is the model of an accounting entry */

#include <string>
#include <stringstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>

// The total number of characters to store a line in a file
const unsined int record_size;

class AccountingEntryModel {
public;
    enum DebitCredit {  Credit = 'C', Debit = 'D' };
    using std::string;
    unsigned long movement_number[5]; /** 5 characters */
    string journal_number;  /** 2 characters */
    string entry_date;      /** 8 characters */
    string due_date;        /** 8 characters */
    string piece_number;    /** 12 characters */
    string account_number;  /** 11 characters */
    string label_name;      /** 25 characters */
    double amount;          /** 13 characters */
    DebitCredit debit_credit;        /** 1 character ('D' for debit, or 'C' for credit) */
    string points;          /** 12 characters */
    string budget_code;     /** 6 characters */
};


namespace std {
    std::istream& operator >>(std::istream& in, AccountingEntryModel& model) {
        std::string line;
        line.reserve(record_size);
        std::getline(in, line);
        auto data = line.cbegin();
        decltype(data) end;
        using std::copy_n;
        using std::back_inserter;

        // All file values will be read into this buffer. It should be as big as the longest value.
        std::string temp;

        copy_n(data, 5, back_inserter(temp));
        model.movement_number = atol(temp.c_str());

        copy_n(data, 2, back_inserter(model.journal_number));

        // TODO: maybe convert these into c++ 11 dates later
        copy_n(data, 8, back_inserter(model.entry_date));
        copy_n(data, 8, back_inserter(model.due_date));

        copy_n(data, 12, back_inserter(model.piece_number));
        copy_n(data, 11, back_inserter(model.account_number));
        copy_n(data, 25, back_inserter(model.label_name));
        // Amount is a double
        temp.clear();
        copy_n(data, 13, back_inserter(temp));
        std::stringstream amount_stream(temp);
        amount_stream >> model.amount;
        // Debit is a single char
        model.debit_credit = *(data)++;
        copy_n(data, 12, model.points);
        copy_n(data, 6, model.budget_code);
    }
}
