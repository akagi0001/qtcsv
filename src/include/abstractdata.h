#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <QStringList>

#include "qtcsv_global.h"

namespace QtCSV
{
    // AbstractData is pure abstract container class. It's main purpouse is to
    // provide common interface for concrete container classes, that could be
    // used in processing of csv-files.
    //
    // From Wikipedia:
    // A comma-separated values (CSV) (also sometimes called character-separated
    // values) file stores tabular data (numbers and text) in plain-text form.
    // Plain text means that the file is a sequence of characters, with no data
    // that has to be interpreted as binary numbers. A CSV file consists of any
    // number of records, separated by line breaks of some kind; each record
    // consists of fields, separated by some other character or string, most
    // commonly a literal comma or tab. Usually, all records have an identical
    // sequence of fields.
    // A general standard for the CSV file format does not exist, but RFC 4180
    // provides a de facto standard for some aspects of it.
    // (http://en.wikipedia.org/wiki/Comma-separated_values)
    //
    // You can create concrete Data class with AbstractData as public base class
    // and implement functions for:
    // - adding new rows of values;
    // - getting rows values;
    // - clearing all saved information;
    // - and so on.
    //
    // Note, that AbstractData is just interface for container class, not a
    // container class. So you are free to decide how to store added
    // information.
    class QTCSVSHARED_EXPORT AbstractData
    {
    public:
        explicit AbstractData() {}
        virtual ~AbstractData() {}

        // Add new empty row
        virtual void addEmptyRow() = 0;
        // Add new row with specified values (as strings)
        virtual void addRow(const QStringList &values) = 0;
        // Clear all data
        virtual void clear() = 0;
        // Get number of rows
        virtual int getNumberOfRows() const = 0;
        // Get values (as list of strings) of specified row
        virtual QStringList getRowValues(const int &row) const = 0;
        // Check if there are any rows
        virtual bool isEmpty() const = 0;
    };
}

#endif // ABSTRACTDATA_H
