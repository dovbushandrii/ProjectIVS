#ifndef FUNCPADFACTORY_H
#define FUNCPADFACTORY_H

#include <QPushButton>
#include <QGridLayout>
#include <QSizePolicy>
#include <string>
#include <vector>


class FuncpadFactory{

    /**
     * For "←"(backspace) and "=" sets orange background
     * and white text color
     * @brief Creates nice Button
     * @author Andrii Dovbush
     * @param symb line that is writen on the button
     * @param h height of the button
     * @param w width of the button
     * @return constructed button
     */
    static QPushButton* createNiceButton(QString symb,int h,int w){
        QPushButton* button = new QPushButton(symb);
        if(symb == "←" || symb == "="){
            button->setStyleSheet("color: white; background-color: #FF5102");
        }
        button->setFixedSize(w,h);
        return button;
    }
public:

    /**
     * Fucntions on the keyboard:
     * (),+,-,/,*,^,√,!,lg,ln,=,←(backspace)
     * @brief Constructs keyboard with functions
     * @author Andrii Dovbush
     * @param buttonH button height
     * @param buttonW button width
     * @return widget with constructed keyboard with functions
     */
    static QWidget* constructFuncpad(int buttonH, int buttonW){
        QWidget* funcWindow = new QWidget;

        size_t columnHeight = 4;

        std::vector<QString> funcs = {
            "(",")","!","←",
            "+","-","^","lg",
            "*","/","√","ln"
        };

        QGridLayout* layout = new QGridLayout(funcWindow);
        layout->setContentsMargins(0,0,0,0);
        layout->setSpacing(0);
        size_t columnCount = ceil((double)(funcs.size() + 1)/(double)(columnHeight));

        for(size_t i = 0,count = 0; i < columnHeight - 1; i++){
            for(size_t j = 0; count < funcs.size() && j < columnCount; j++,count++){
                layout->addWidget(createNiceButton(funcs[count],buttonH,buttonW),i,j,Qt::AlignCenter);
            }
        }
        QPushButton* equalBut = createNiceButton("=",buttonH,buttonW*columnCount);
        layout->addWidget(equalBut,columnHeight-1,0,1,columnCount,Qt::AlignCenter);
        return funcWindow;
    }
};

#endif // FUNCPADFACTORY_H
