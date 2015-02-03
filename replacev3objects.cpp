#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <qdatetime.h>
#include "replacev3objects.h"

replaceV3Objects::replaceV3Objects(int argc, char *argv[])
{
    DoTime();
    Open_Files(argc, argv);
    Read_Lines();
    Close_Files();
}


void replaceV3Objects::DoTime()
{
    // time seed for randomization
    QTime timmy(0, 0, 0);
    qsrand(timmy.secsTo(QTime::currentTime()));
}


void replaceV3Objects::Open_Files(int argc, char *argv[])
{
    // input visitor 3 object export file, text
    QFile file(argv[1]);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Unable to open " << file.fileName();
        exit(1);
    }

    qDebug() << "Opened input file: " << file.fileName();

    // output visitor 3 export file, text
    QFile file2(argv[2]);
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Unable to open " << file2.fileName();
        exit(1);
    }

    qDebug() << "Opened output file: " << file2.fileName();
}


void replaceV3Objects::Read_Lines()
{
    QTextStream in(&file);
    QTextStream out(&file2);
    QString line;
    QStringList list;

    // read and process until we are at the end of the input file
    while (!in.atEnd())
    {
        line = in.readLine();
        line = line.toLower();
        list = line.split(";");

        qDebug() << "opened this gay list" << list;

        // PMCTODO okay so replace this hardcoded crap with the same stuff as in replace_object tool has ;)

    /*
    PMC Somalia house replacement
        if (list[0].compare("\"pmc\\pmc_somalia_obj\\pmc_house_block_01\"") == 0)
        {
            int idx = (qrand() % 4);
                        if (idx == 0)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_block_01\"";
            }

            if (idx == 1)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_block_02\"";
            }

            if (idx == 2)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_block_03\"";
            }

            if (idx == 3)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_block_04\"";
            }
        }
    */

    // PMC Somalia BLOCK house replacement to single houses
        if (list[0].compare("\"pmc\\pmc_somalia_obj\\pmc_house_block_01\"") == 0)
        {
            int idx = (qrand() % 16);

            if (idx == 0)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_01\"";
            }

            if (idx == 1)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_02\"";
            }

            if (idx == 2)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_03\"";
            }

            if (idx == 3)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_04\"";
            }

            if (idx == 4)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_05\"";
            }

            if (idx == 5)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_06\"";
            }

            if (idx == 6)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_07\"";
            }

            if (idx == 7)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_08\"";
            }

            if (idx == 8)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_09\"";
            }

            if (idx == 9)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_10\"";
            }

            if (idx == 10)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_11\"";
            }

            if (idx == 11)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_12\"";
            }

            if (idx == 12)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_13\"";
            }

            if (idx == 13)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_14\"";
            }

            if (idx == 14)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_15\"";
            }

            if (idx == 15)
            {
                list[0] = "\"pmc\\pmc_somalia_obj\\pmc_house_16\"";
            }
        }

/*
    // PMC Rugen fucked up forst singlestrom replacement
        if (list[0].compare("\"pmc\\pmc_rugen_obj\\pmc_bis_les_singlestrom\"") == 0)
        {
            int idx = (qrand() % 4);
                        if (idx == 0)
            {
                list[0] = "\"pmc\\pmc_rugen_obj\\pmc_bis_smrk_siroky\"";
            }

            if (idx == 1)
            {
                list[0] = "\"pmc\\pmc_rugen_obj\\pmc_bis_smrk_velky\"";
            }

            if (idx == 2)
            {
                list[0] = "\"pmc\\pmc_rugen_obj\\pmc_bis_smrk_velky\"";
            }

            if (idx == 3)
            {
                list[0] = "\"pmc\\pmc_rugen_obj\\pmc_bis_les_singlestrom\"";
            }
        }
*/

        // write into output visitor 3 export file
        out << list[0] << ";" << list[1] << ";" << list[2] << ";" << list[3] << ";" << list[4] <<";\n";
    }
}


void replaceV3Objects::Close_Files()
{
    file.close();
    file2.close();
    qDebug() << "All done, bye.";
}
