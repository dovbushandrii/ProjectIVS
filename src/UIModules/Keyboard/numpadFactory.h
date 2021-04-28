#ifndef NUMPADFACTORY_H
#define NUMPADFACTORY_H

#include <QPushButton>
#include <QGridLayout>
#include <QSizePolicy>
#include <vector>
#include <math.h>

class NumpadFactory{
    static QChar convertNumbToChar(int numb){
        QChar symb;
        if(numb < 10){
            symb = '0';
            ushort symbCode = symb.unicode();
            symb = QChar(symbCode + numb);
        }
        else{
            symb = 'A';
            ushort symbCode = symb.unicode();
            symb = QChar(symbCode - 10 + numb);
        }
        return symb;
    }

    static QPushButton* createNiceButton(QString symb){
        QPushButton* button = new QPushButton(symb);
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        return button;
    }

    static QPushButton* createNiceButton(int numb){
        return createNiceButton(convertNumbToChar(numb));
    }
public:

    /**
     * @brief Constructs Numpad for numeric system with base
     * @author Andrii Dovbush 
     * @param base base of numeric system
     * @return widget with constructed numpad
     */
    static QWidget* constructNumpad(const int base){

        size_t columnHeight = 4;

        std::vector<QPushButton*> buttons;
        int i = 0;
        for(; i < base; i++){
            buttons.push_back(createNiceButton(i));
        }
        buttons.push_back(createNiceButton("."));


        QWidget* numWindow = new QWidget;

        QGridLayout* layout = new QGridLayout(numWindow);
        layout->setContentsMargins(0,0,0,0);
        size_t columnCount = ceil((double)(base + 1)/(double)(columnHeight));

        for(size_t i = 0, count = 0; i < columnCount; i++){
            for(size_t j = 0; j < columnHeight && count < buttons.size(); j++,count++){
                layout->addWidget(buttons[count],j,i,Qt::AlignCenter);
            }
        }

        return numWindow;
    }
};

#endif // NUMPADFACTORY_H
