#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>

enum function { SQRT = 0, LG, LN, SIN, COS, TAN, ARCSIN, ARCCOS, ARCTAN };
enum measure { LENGHT = 0, WEIGHT, POWER };
struct Units
{
    enum lenght { MM = 0, CM, DM, M, KM };
    enum weight { G = 0, DAG, HG, KG, };
    enum power { W = 0, KW, HP, SF, BTU };
};

bool error = false;
bool rad = false;
bool minuss = false;
bool condition = false;

void MainWindow::icons()
{
    ui->btnDeleteHistory->setIcon(QIcon(BASKET));
    ui->btnPi->setIcon(QIcon(PI));
    ui->btnE->setIcon(QIcon(EULER));
}

void MainWindow::variables()
{
    bracket = 0;
}

void MainWindow::ShowPage(int index) {
    qDebug() << "show page request: " << index;
    ui->stackedWidget->setCurrentIndex(index);
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->lineEdit->insert("0");
    icons();
    variables();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//----------------NUMBERS---------------------

void MainWindow::on_buttonStandard_clicked()
{
    ui->BoxList->clear();
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void MainWindow::on_buttonLenght_clicked()
{
    ui->BoxList->clear();
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->BoxList->setPlaceholderText("Lenght");
    ui->BoxList->addItem("milimeter");
    ui->BoxList->addItem("centimeter");
    ui->BoxList->addItem("decimeter");
    ui->BoxList->addItem("meter");
    ui->BoxList->addItem("kilometer");
    ui->line2_Edit->clear();
    ui->textEdit_2->clear();
    measure = LENGHT;

}


void MainWindow::on_buttnoWeight_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->BoxList->clear();
    ui->BoxList->setPlaceholderText("Weight");
    ui->BoxList->addItem("gram");
    ui->BoxList->addItem("decagram");
    ui->BoxList->addItem("hectogram");
    ui->BoxList->addItem("kilogram");
    ui->line2_Edit->clear();
    ui->textEdit_2->clear();
    measure = WEIGHT;

}


void MainWindow::on_buttonPower_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    ui->BoxList->clear();
    ui->BoxList->setPlaceholderText("Power");
    ui->BoxList->addItem("watt");
    ui->BoxList->addItem("kilowatt");
    ui->BoxList->addItem("kilojoule");
    ui->BoxList->addItem("horsepower");
    ui->BoxList->addItem("foot-pounds/minute");
    ui->BoxList->addItem("BTU/minute");
    ui->line2_Edit->clear();
    ui->textEdit_2->clear();
    measure = POWER;

}

//NUMBERS 0 - 9

void MainWindow::addNumbers(std::string& number)
{

    std::string operation = ui->lineEdit->text().toStdString();
    std::string signs = "!)ep";

    if ((operation.size() - 1 == 0) && (operation.c_str()[operation.size() - 1] == '0'))
    {
        ui->lineEdit->backspace();
        ui->lineEdit->insert(QString::fromStdString(number));
    }
    else if (signs.find(operation.c_str()[operation.size() - 1]) == std::string::npos)
        ui->lineEdit->insert(QString::fromStdString(number));
    else if (signs.find(operation.c_str()[operation.size() - 1]) != std::string::npos)
    {
        ui->lineEdit->insert("*");
        ui->lineEdit->insert(QString::fromStdString(number));
    }
}

void MainWindow::on_btnZero_clicked()
{
    std::string number = "0";
    addNumbers(number);
}

void MainWindow::on_btnOne_clicked()
{
    std::string number = "1";
    addNumbers(number);
}

void MainWindow::on_btnTwo_clicked()
{
    std::string number = "2";
    addNumbers(number);
}

void MainWindow::on_btnThree_clicked()
{
    std::string number = "3";
    addNumbers(number);
}

void MainWindow::on_btnFour_clicked()
{
    std::string number = "4";
    addNumbers(number);
}

void MainWindow::on_btnFive_clicked()
{
    std::string number = "5";
    addNumbers(number);
}

void MainWindow::on_btnSix_clicked()
{
    std::string number = "6";
    addNumbers(number);
}

void MainWindow::on_btnSeven_clicked()
{
    std::string number = "7";
    addNumbers(number);
}

void MainWindow::on_btnEight_clicked()
{
    std::string number = "8";
    addNumbers(number);
}

void MainWindow::on_btnNine_clicked()
{
    std::string number = "9";
    addNumbers(number);
}


//----------------SIGNS---------------------

//PLUS, MINUS, MULTIPICATION, DIVISION, EXPONENT


void MainWindow::signChoice(const QString& signs)
{
    QString operation = ui->lineEdit->text();
    QString mathematicSigns = "*/+-.^";
    QString numbers = "0123456789";

    if (numbers.contains(operation.right(1)) || operation.isEmpty())
    {
        ui->lineEdit->insert(signs);
    }
    else if ((operation.right(1) == "(") && (signs == "+" || signs == "-"))
    {
        ui->lineEdit->insert(signs);
    }
    else if ((operation.right(2).left(1) == "(") && (signs == "+" || signs == "-"))
    {
        ui->lineEdit->backspace();
        ui->lineEdit->insert(signs);
    }
    else if (!mathematicSigns.contains(operation.right(1)) && operation.right(1) != "(")
    {
        ui->lineEdit->insert(signs);
    }
    else if (mathematicSigns.contains(operation.right(1)) && !operation.right(2).contains("("))
    {
        ui->lineEdit->backspace();
        ui->lineEdit->insert(signs);
    }
}

void MainWindow::on_btnPlus_clicked()
{
    QString signs = "+";
    signChoice(signs);
}


void MainWindow::on_btnMinus_clicked()
{
    QString signs = "-";
    signChoice(signs);
}


void MainWindow::on_btnOne_2_clicked()
{
    QString signs = "*";
    signChoice(signs);
}


void MainWindow::on_btnDivide_clicked()
{
    QString signs = "/";
    signChoice(signs);
}


void MainWindow::on_pbtnExponent_clicked()
{
    QString signs = "^";
    signChoice(signs);
}

void MainWindow::on_pbtnExponent2_clicked()
{
    QString operation = ui->lineEdit->text();
    QString numbers = "01234567890ep!)";

    if (numbers.contains(operation.right(1)))
    {
        ui->lineEdit->insert("^2");
    }
}

//EXPONENT -1


void MainWindow::on_btnExponentMinus_clicked()
{
    QString operation = ui->lineEdit->text();
    QString character = "0123456789ep)";

    if (character.contains(operation.right(1)))
    {
        ui->lineEdit->insert("^(-1)");
    }
}



//DOT

void MainWindow::on_btnDot_clicked()
{
    QString signs = ".";
    signChoice(signs);
}

//DELETE BUTTONS

void MainWindow::on_btnAC_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->insert("0");
    bracket = 0;
}

void MainWindow::on_btnDeleteSign_clicked()
{
    QString sign = ui->lineEdit->text();
    // QString do usuwania wszystkich słów (na przykład SIN, COS, TAN)
    QString signs = "acegilnopqrst";

    if (sign.right(1) == "(")
    {
        bracket--;
        sign.chop(1);
        ui->lineEdit->backspace();
        while (!sign.isEmpty())
        {
            if (signs.contains(sign.right(1)))
            {
                sign.chop(1);
                ui->lineEdit->backspace();
            }
            else
            {
                break;
            }
        }
        if (sign.isEmpty())
        {
            ui->lineEdit->clear();
            ui->lineEdit->insert("0");
        }
    }
    else
    {
        ui->lineEdit->backspace();
        if (ui->lineEdit->text().isEmpty())
            ui->lineEdit->insert("0");
    }
}

//FACTORIAL

void MainWindow::on_btnFactorial_clicked()
{
    std::string operation = ui->lineEdit->text().toStdString();
    std::string characters = "0123456789)!";

    if (characters.find(operation.c_str()[operation.size() - 1]) != std::string::npos)
    {
        if (operation.size() >= 5)
        {
            int number = 0;
            for (int i = operation.size() - 1; i > operation.size() - 6; i--)
            {
                if (operation.c_str()[i] == '!')
                    number++;
            }
            if (number < 5)
                ui->lineEdit->insert("!");
        }
        else
            ui->lineEdit->insert("!");
    }

}

//BRACKETS

void MainWindow::on_btnOpenBracket_clicked()
{
    QString operation = ui->lineEdit->text();
    QString character = "acegilnopqrst";
    QString signs = "*/+-^(";
    QString numbers = "0123456789!ep)";

    if (numbers.contains(operation.right(1)))
    {
        ui->lineEdit->insert("*(");
        bracket++;
    }
    else if (signs.contains(operation.right(1)))
    {
        ui->lineEdit->insert("(");
        bracket++;
    }
}

void MainWindow::on_btnCloseBracket_clicked()
{
    QString operation = ui->lineEdit->text();
    QString signs = "+-*/.^(";

    if ((bracket > 0) && !signs.contains(operation.right(1)))
    {
        ui->lineEdit->insert(")");
        bracket--;
    }
}

//FUNCTIONS

void MainWindow::mathematicFunctions(const QString& function)
{
    QString operation = ui->lineEdit->text();
    QString numbers = "0123456789!ep)";
    QString signs = "+-*/^(";

    if (numbers.contains(operation.right(1)))
    {
        ui->lineEdit->insert("*" + function);
        bracket++;
    }
    else if (signs.contains(operation.right(1)))
    {
        ui->lineEdit->insert(function);
        bracket++;
    }
}

void MainWindow::on_btnSin_clicked()
{
    QString function = "sin(";
    mathematicFunctions(function);
}

void MainWindow::on_btnCos_clicked()
{
    QString function = "cos(";
    mathematicFunctions(function);
}

void MainWindow::on_btnTan_clicked()
{
    QString function = "tan(";
    mathematicFunctions(function);
}

void MainWindow::on_btnLog_clicked()
{
    QString function = "log(";
    mathematicFunctions(function);
}

void MainWindow::on_btnLn_clicked()
{
    QString function = "ln(";
    mathematicFunctions(function);
}

void MainWindow::on_btnSqrt_clicked()
{
    QString function = "sqrt(";
    mathematicFunctions(function);
}

void MainWindow::on_btnArcSin_clicked()
{
    QString function = "arcsin(";
    mathematicFunctions(function);
}

void MainWindow::on_btnArcCos_clicked()
{
    QString function = "arccos(";
    mathematicFunctions(function);
}

void MainWindow::on_btnArcTan_clicked()
{
    QString function = "arctan(";
    mathematicFunctions(function);
}

//PI AND EULER'S NUMBER




void MainWindow::on_btnPi_clicked()
{
    QString function = "p";
    mathematicFunctions(function);
}

void MainWindow::on_btnE_clicked()
{
    QString function = "e";
    mathematicFunctions(function);
}

//EQUAL

std::string& MainWindow::changing_Pi_and_E(std::string& operation)
{
    std::string mE = "2,718282";
    std::string p = "3.141593";
    for (int i = 0; i < operation.size(); i++)
    {
        switch (operation.c_str()[i])
        {
        case 'e': {operation.erase(i, 1); operation.insert(i, mE); break; }
        case 'p': {operation.erase(i, 1); operation.insert(i, p); break; }
        }
    }
    return operation;
}

void MainWindow::advancedContinued(float& variable, int& calculation)
{
    switch (calculation)
    {
    case SQRT: {if (minuss == true) error = true; variable = std::sqrt(variable); break; }
    case LG: {variable = log10(variable); break; }
    case LN: {if (minuss == true) error = true; variable = log(variable); break; }
    case SIN:
    {
        if (rad == false)
        {
            variable = sin(variable * (M_PI / 180));
            if (minuss == true) variable -= variable * 2;
        }
        else
        {
            variable = sin(variable);
            if (minuss == true) variable -= variable * 2;
        }
        break;
    }
    case COS:
    {
        if (rad == false)
            variable = cos(variable * (M_PI / 180));
        else
            variable = cos(variable);
        break;
    }
    case TAN:
    {
        if (rad == false)
        {
            variable = tan(variable * (M_PI / 180));
            if (minuss == true) variable -= variable * 2;
        }
        else
        {
            variable = tan(variable);
            if (minuss == true) variable -= variable * 2;
        }
        break;
    }
    case ARCSIN:
    {
        if (variable < -1.0)
            error = true;
        if (variable > 1.0)
            error = true;
        if (rad == false)
            variable = asin(variable) * 180 / M_PI;
        if (minuss == true) variable -= variable * 2;
        break;
    }
    case ARCCOS:
    {
        if (variable < -1.0)
            error = true;
        if (variable > 1.0)
            error = true;
        if (rad == false)
            variable = acos(variable) * 180 / M_PI;
        if (minuss == true) variable -= variable * 2;
        break;
    }
    case ARCTAN:
    {
        if (rad == true)
        {
            variable = sin(variable * (M_PI / 180));
            if (minuss == true) variable -= variable * 2;
        }
        else
        {
            variable = sin(variable);
            if (minuss == true) variable -= variable * 2;
        }
        break;
    }
    }
}

void MainWindow::advanced(std::string& operation, std::string& text, int& lenght, bool& function, int& stringSize, int& calculation)
{
    float variable = 0;
    int firstSign = operation.find(text);
    stringSize = operation.find(text) + lenght;
    if (operation[operation.find(text) + lenght + 1] == '-')
    {
        minuss = true;
        operation.erase(lenght + 1, 1);
    }
    std::string neww = "";
    while (function != false)
    {
        stringSize++;
        neww += operation[stringSize];
        lenght++;
        if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize > operation.size() - 1))
        {
            variable = (std::stoi(neww));
            advancedContinued(variable, calculation);
            operation.erase(firstSign, lenght);
            operation.insert(firstSign, std::to_string(variable));
            function = false;
            stringSize = 0;
        }
        else if (operation.c_str()[stringSize] == '.')
        {
            variable = std::stoi(neww);
            neww = "";
            int size = -1;
            while (function != false)
            {
                stringSize++;
                size++;
                neww += operation[stringSize];
                lenght++;
                if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize > operation.size() - 1))
                {
                    variable += (std::stoi(neww) / pow(10, size));
                    advancedContinued(variable, calculation);
                    operation.erase(firstSign, lenght);
                    operation.insert(firstSign, std::to_string(variable));
                    function = false;
                    stringSize = 0;
                }
            }
        }
    }

}

unsigned long long MainWindow::factorialCalculated(int n, int number)
{
    if (n == 0 || n == 1) { return 1; }
    else
    {
        if (n < number) return n * factorialCalculated(n + 1 - n, number);
        return n * factorialCalculated(n - number, number);
    }
}

void MainWindow::factorials(std::string& operation, std::string& text, int& lenght, int& number, bool& function, int& stringSize)
{
    unsigned long long variable = 0;
    stringSize = operation.find(text) + number;
    std::string temporaryString = "";
    while (function != false)
    {
        stringSize--;
        temporaryString += operation[stringSize];
        lenght++;
        if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize == 0))
        {
            if (stringSize != 0)
            {
                stringSize++;
                lenght--;
            }
            reverse(temporaryString.begin(), temporaryString.end());
            variable = (std::stoi(temporaryString));
            variable = factorialCalculated(variable, number + 1);
            operation.erase(stringSize, lenght);
            operation.insert(stringSize, std::to_string((int)variable));
            stringSize = 0;
            function = false;
        }
    }
}

std::string MainWindow::calculation(const char* x)
{
    using namespace std;
    std::string operation = x;
    std::vector< long double >numbers;//NUMBERS
    std::vector< char >signs; //SIGNS
    std::vector< char >secondSigns; //SIGNS WITHOUT POWER
    std::vector<char>lastSigns; //SIGNS WITHOUT MULTIPLICATION AND DIVISION
    std::vector< long double >exponent; //RESULT OF POWER
    std::vector< long double >multiplication;//NUMBERS WITHOUT POWER
    std::vector< long double >finalOperations;//NUMBERS WITHOUT MULTIPLICATION AND DIVISION
    int stringSize = 0;
    double result = 0;
    bool function = true;

    while (stringSize < operation.size())
    {
        if (operation.find("!!!!!") != std::string::npos)
        {
            std::string text = "!!!!!";
            int number = 4;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!!!!") != std::string::npos)
        {
            std::string text = "!!!!";
            int number = 3;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!!!") != std::string::npos)
        {
            std::string text = "!!!";
            int number = 2;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!!") != std::string::npos)
        {
            std::string text = "!!";
            int number = 1;
            int lenght = 1;
            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("!") != std::string::npos)
        {
            std::string text = "!";
            int number = 0;
            int variable = 0;
            int lenght = 1;

            factorials(operation, text, lenght, number, function, stringSize);
        }

        if (operation.find("sqrt") != std::string::npos)
        {
            std::string text = "sqrt";
            int lenght = 3;
            int calculation = SQRT;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("lg") != std::string::npos)
        {
            std::string text = "lg";
            int lenght = 1;
            int calculation = LG;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("ln") != std::string::npos)
        {
            std::string text = "ln";
            int lenght = 1;
            int calculation = LN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("arcsin") != std::string::npos)
        {
            std::string text = "arcsin";
            int lenght = 5;
            int calculation = ARCSIN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("arccon") != std::string::npos)
        {
            std::string text = "arccos";
            int lenght = 5;
            int calculation = ARCCOS;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("arctan") != std::string::npos)
        {
            std::string text = "arctan";
            int lenght = 5;
            int calculation = ARCTAN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("sin") != std::string::npos)
        {
            std::string text = "sin";
            int lenght = 2;
            int calculation = SIN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("cos") != std::string::npos)
        {
            std::string text = "cos";
            int lenght = 2;
            int calculation = COS;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }
        if (operation.find("tan") != std::string::npos)
        {
            std::string text = "tan";
            int lenght = 2;
            int calculation = TAN;
            advanced(operation, text, lenght, function, stringSize, calculation);
        }

        stringSize++;
        function = true;
    }
    int change = 0;
    stringSize = 0;
    if (operation[0] == '-')
    {
        std::string change = "0";
        change += operation;
        operation = change;
    }
    while (operation != "")
    {
        if (stringSize == operation.size() - 1)
        {
            numbers.push_back(std::stoi(operation));
            break;
        }
        stringSize++;

        if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (operation.c_str()[stringSize] == '.'))
        {
            if (operation.c_str()[stringSize] == '.')
            {
                numbers.push_back(std::stoi(operation));
                for (int y = 0; y <= stringSize; y++)
                {
                    operation.erase(operation.begin());
                }
                stringSize = 0;
                int liczba = 0;
                while (operation != "")
                {
                    stringSize++;
                    liczba++;
                    if ((operation.c_str()[stringSize] == '+') || (operation.c_str()[stringSize] == '-') || (operation.c_str()[stringSize] == '*') || (operation.c_str()[stringSize] == '/') || (operation.c_str()[stringSize] == '^') || (stringSize >= operation.size() - 1))
                    {

                        if (stringSize != operation.size() - 1)
                            signs.push_back(operation.c_str()[stringSize]);
                        else
                            liczba++;

                        if ((numbers[numbers.size() - 1] < 0) || (condition == true))
                            numbers[numbers.size() - 1] -= (std::stoi(operation) / pow(10, liczba));
                        else if ((numbers[numbers.size() - 1] >= 0) && (condition == false))
                            numbers[numbers.size() - 1] += (std::stoi(operation) / pow(10, liczba));

                        for (int y = 0; y <= stringSize; y++)
                        {
                            operation.erase(operation.begin());
                        }
                        stringSize = 0;
                        condition = false;
                        break;
                    }
                }
            }
            else
            {
                signs.push_back(operation.c_str()[stringSize]);
                numbers.push_back(std::stoi(operation));
                for (int y = 0; y <= stringSize; y++)
                {
                    operation.erase(operation.begin());
                }
                if (operation.c_str()[0] == '-')
                    condition = true;
                stringSize = 0;
            }
        }
    }
    signs.push_back('+');


    //CALCULATING POWERS


    for (int i = numbers.size() - 1; i >= 0; i--)
    {

        if (signs[i] == '^')
        {
            exponent.push_back(numbers[i + 1]);
            while (signs[i] == '^')
            {
                exponent[exponent.size() - 1] = pow(numbers[i], exponent[exponent.size() - 1]);
                if (i > 0)
                    i--;
                else
                    break;
            }
        }
    }

    //NUMBERS IN THE NEW TABLE

    int j = exponent.size() - 1;


    for (int i = 0; i < numbers.size(); i++)
    {
        if (signs[i] == '^')
        {
            multiplication.push_back(exponent[j]);
            j--;
            while (signs[i] == '^')
                i++;
        }
        else
            multiplication.push_back(numbers[i]);
    }

    //SIGNS IN THE NEW TABLE

    for (int i = 0; i < signs.size(); i++)
    {
        if (signs[i] != '^')
            secondSigns.push_back(signs[i]);
    }

    //CALCULATION MULTIPLICATION,DIVIDEMENT AND NUMBERS IN THE NEW TABLE

    int y = 0;

    for (int i = 0; i < multiplication.size(); i++)
    {
        if ((i == 0) && (secondSigns[i] != '*') && (secondSigns[i] != '/'))
        {
            finalOperations.push_back(multiplication[i]);
            y++;
        }
        if (secondSigns[i] == '*')
        {
            finalOperations.push_back(multiplication[i] * multiplication[i + 1]);
            i++;
            while (true)
            {
                if (secondSigns[i] == '*')
                    finalOperations[y] *= multiplication[i + 1];
                else if (secondSigns[i] == '/')
                    finalOperations[y] /= multiplication[i + 1];
                else if ((secondSigns[i] != '*') && (secondSigns[i] != '/'))
                    break;
                i++;
            }
            y++;
        }
        else if (secondSigns[i] == '/')
        {
            finalOperations.push_back(multiplication[i] / multiplication[i + 1]);
            i++;
            while (secondSigns[i] == '/')
            {
                if (secondSigns[i] == '/')
                    finalOperations[y] /= multiplication[i + 1];
                else if (secondSigns[i] == '*')
                    finalOperations[y] *= multiplication[i + 1];
                else if ((secondSigns[i] != '*') && (secondSigns[i] != '/'))
                    break;
                i++;
            }
            y++;
        }
        else if ((i > 0) && (secondSigns[i] != '*') && (secondSigns[i] != '/') && (secondSigns[i - 1] != '*') && (secondSigns[i - 1] != '/'))
        {
            finalOperations.push_back(multiplication[i]);
            y++;
        }
    }

    //SIGNS IN THE NEW TABLE

    for (int i = 0; i < secondSigns.size(); i++)
    {
        if (secondSigns[i] == '+')
            lastSigns.push_back('+');
        else if (secondSigns[i] == '-')
            lastSigns.push_back('-');
    }

    //LAST CALCULATION

    result = finalOperations[0];

    for (int i = 0; i < finalOperations.size() - 1; i++)
    {
        if (lastSigns[i] == '+')
            result += finalOperations[i + 1];
        else
            result -= finalOperations[i + 1];
    }

    if ((int)result - result == 0)
        return operation = std::to_string((int)result);
    else
        return operation = std::to_string(result);
}

std::string MainWindow::brackets(std::string& operation)
{
    int currentSign = 0;
    bool bracketExists = false;

    //REMOVE BRACKETS

    while (currentSign < operation.size())
    {
        if (operation.c_str()[currentSign] == '(')
        {
            bracketExists = true;
            int firstSign = currentSign + 1;
            int sizeSigns = 0;
            while (operation.c_str()[currentSign] != ')')
            {
                currentSign++;
                sizeSigns++;
                if (operation.c_str()[currentSign] == '(')
                {
                    firstSign = currentSign + 1;
                    sizeSigns = 0;
                }
            }
            char* y = new char[operation.size()] {};
            operation.copy(y, sizeSigns - 1, firstSign);
            operation.replace(firstSign - 1, sizeSigns + 1, calculation(y));
        }
        if (currentSign < operation.size())
            currentSign++;
        if ((currentSign >= operation.size()) && (bracketExists == true))
        {
            bracketExists = false;
            currentSign = 0;
        }
    }
    return operation;
}

//EQUAL BUTTON

void MainWindow::on_btnEqual_clicked()
{
    std::string signs = "+-*/^.";
    operation = ui->lineEdit->text().toStdString();

    if (signs.find(operation.c_str()[operation.size() - 1]) != std::string::npos)
    {
        operation.erase(operation.size() - 1);
        ui->lineEdit->backspace();
    }

    char* result = new char[operation.size() + 1] {};
    changing_Pi_and_E(operation);
    brackets(operation).copy(result, operation.size(), 0);
    calculation(result);
    if (error == true)
    {
        ui->textEdit->setPlainText("ERROR");
        ui->lineEdit->clear();
        ui->lineEdit->insert("0");
        error = false;
    }
    else
    {
        ui->textEdit->setText(ui->lineEdit->text() + " Result: " + QString::fromStdString(calculation(result)));
        ui->textHistory->insertPlainText(QString::fromStdString(operation) + " = " + QString::fromStdString(calculation(result)) + "\n");
        condition = false;
        minuss = false;
    }

}

void MainWindow::on_btnRadDeg_clicked()
{
    if (ui->btnRadDeg->text() == "deg")
    {
        ui->btnRadDeg->setText("rad");
        rad = true;
    }
    else if (ui->btnRadDeg->text() == "rad")
    {
        ui->btnRadDeg->setText("deg");
        rad = false;
    }
}

void MainWindow::on_btnDeleteHistory_clicked()
{
    ui->textHistory->clear();
}

//--------------------------------------CONVENTER-----------------------------------------------------------

void MainWindow::conventer()
{
    Units unit;
    QString text = ui->line2_Edit->text();
    double number = 0;

    // Sprawdzenie separatora dziesiętnego
    QChar decimalSeparator = ',';
    if (text.indexOf('.') != -1) {
        decimalSeparator = '.';
    }

    // Przeliczenie liczby z tekstu
    if (text.indexOf(decimalSeparator) == -1) {
        number = text.toDouble();
    }
    else {
        QString wholePart = text.left(text.indexOf(decimalSeparator));
        QString afterDecimal = text.mid(text.indexOf(decimalSeparator) + 1);
        number = wholePart.toDouble() + (afterDecimal.toDouble() / std::pow(10, afterDecimal.size()));
    }

    QString result;
    if (measure == LENGHT)
    {
        switch (units)
        {
        case unit.MM:
        {
            result = QString::number(number) + " mm\n" +
                     QString::number(number / 10) + " cm\n" +
                     QString::number(number / 100) + " dm\n" +
                     QString::number(number / 1000) + " m\n" +
                     QString::number(number / 1000000) + " km\n";
            break;
        }
        case unit.CM:
        {
            result = QString::number(number) + " cm\n" +
                     QString::number(number / 10) + " mm\n" +
                     QString::number(number / 100) + " dm\n" +
                     QString::number(number / 1000) + " m\n" +
                     QString::number(number / 1000000) + " km";
            break;
        }
        case unit.DM:
        {
            result = QString::number(number) + " dm\n" +
                     QString::number(number * 100) + " mm\n" +
                     QString::number(number / 10) + " cm\n" +
                     QString::number(number / 10) + " m\n" +
                     QString::number(number / 10000) + " km";
            break;
        }
        case unit.M:
        {
            result = QString::number(number) + " m\n" +
                     QString::number(number * 1000) + " mm\n" +
                     QString::number(number / 100) + " cm\n" +
                     QString::number(number / 10) + " dm\n" +
                     QString::number(number / 1000) + " km";
            break;
        }
        case unit.KM:
        {
            result = QString::number(number) + " km\n" +
                     QString::number(number * 1000000) + " mm\n" +
                     QString::number(number / 100000) + " cm\n" +
                     QString::number(number / 10000) + " dm\n" +
                     QString::number(number / 1000) + " m";
            break;
        }
        }

    }
    else if (measure == WEIGHT)
    {
        switch (units)
        {
        case unit.G:
        {
            result = QString::number(number) + " g\n" +
                     QString::number(number / 10) + " dac\n" +
                     QString::number(number / 100) + " hg\n" +
                     QString::number(number / 1000) + " kg";
            break;
        }
        case unit.DAG:
        {
            result = QString::number(number) + " dac\n" +
                     QString::number(number * 10) + " g\n" +
                     QString::number(number / 10) + " hg\n" +
                     QString::number(number / 100) + " kg";
            break;
        }
        case unit.HG:
        {
            result = QString::number(number) + " hg\n" +
                     QString::number(number * 100) + " g\n" +
                     QString::number(number * 10) + " dac\n" +
                     QString::number(number / 10) + " kg";
            break;
        }
        case unit.KG:
        {
            result = QString::number(number) + " kg\n" +
                     QString::number(number * 1000) + " g\n" +
                     QString::number(number * 100) + " dac\n" +
                     QString::number(number * 10) + "hg";
            break;
        }
        }
    }
    else if (measure == POWER)
    {
        switch (units)
        {
        case unit.W:
        {
            result = QString::number(number) + " W\n" +
                     QString::number(number / 1000) + " kW\n" +
                     QString::number(number / 1000 * 1.34) + " HP\n" +
                     QString::number(number * 44.25373) + " [ft•lb/(min•ft^2)]\n" +
                QString::number(number * 0.056869) + " BTU";
            break;
        }
        case unit.KW:
        {
            result = QString::number(number) + " kW\n" +
                     QString::number(number * 1000) + " W\n" +
                     QString::number(number * 1.34) + " HP\n" +
                     QString::number(number * 44253.73) + " [ft•lb/(min•ft^2)]\n" +
                QString::number(number * 56.86902) + " BTU";
            break;
        }
        case unit.HP:
        {
            result = QString::number(number) + " HP\n" +
                     QString::number(number * 745.6999) + " W\n" +
                     QString::number(number * 0.7457) + " kW\n" +
                     QString::number(number * 33000) + " [ft•lb/(min•ft^2)]\n" +
                QString::number(number * 42.40722) + " BTU";
            break;
        }
        case unit.SF:
        {
            result = QString::number(number) + " [ft•lb/(min•ft^2)]\n" +
                QString::number(number * 0.022597) + " W\n" +
                     QString::number(number * 0.000022597) + " kW\n" +
                     QString::number(number * 0.000030303) + " HP\n" +
                     QString::number(number * 0.00128507) + " BTU";
            break;
        }
        case unit.BTU:
        {
            result = QString::number(number) + " BTU\n" +
                     QString::number(number * 17.58427) + " W\n" +
                     QString::number(number * 0.0175843) + " kW\n" +
                     QString::number(number * 0.0235809) + " HP\n" +
                     QString::number(number * 778.1694) + " [ft•lb/(min•ft^2)]";
            break;
        }
        }
    }
    ui->textEdit_2->setText(result);
}

void MainWindow::on_btn2_Zero_clicked()
{
    ui->line2_Edit->insert("0");
    conventer();
}


void MainWindow::on_btn2_One_clicked()
{
    ui->line2_Edit->insert("1");
    conventer();
}


void MainWindow::on_btn2_Two_clicked()
{
    ui->line2_Edit->insert("2");
    conventer();
}


void MainWindow::on_btn2_Three_clicked()
{
    ui->line2_Edit->insert("3");
    conventer();
}


void MainWindow::on_btn2_Four_clicked()
{
    ui->line2_Edit->insert("4");
    conventer();
}


void MainWindow::on_btn2_Five_clicked()
{
    ui->line2_Edit->insert("5");
    conventer();
}

void MainWindow::on_btn2_Six_clicked()
{
    ui->line2_Edit->insert("6");
    conventer();
}


void MainWindow::on_btn2_Seven_clicked()
{
    ui->line2_Edit->insert("7");
    conventer();
}


void MainWindow::on_btn2_Eight_clicked()
{
    ui->line2_Edit->insert("8");
    conventer();
}


void MainWindow::on_btn2_Nine_clicked()
{
    ui->line2_Edit->insert("9");
    conventer();
}


void MainWindow::on_BoxList_activated(int index)
{
    units = index;
    if (ui->line2_Edit->text() != "")
        conventer();
}

void MainWindow::on_btn2_DeleteSign_clicked()
{
    QString text = ui->line2_Edit->text();
    if (text.size() > 1)
    {
        if (text.at(text.size() - 2) == ',')
        {
            ui->line2_Edit->backspace();
            ui->line2_Edit->backspace();
        }
        else
        {
            ui->line2_Edit->backspace();
        }
    }
    else
    {
        ui->line2_Edit->backspace();
    }

    if (!ui->line2_Edit->text().isEmpty())
    {
        conventer();
    }
    else
    {
        ui->textEdit_2->clear();
    }
}

void MainWindow::on_btn2_AC_clicked()
{
    ui->line2_Edit->clear();
    ui->textEdit_2->clear();
}

void MainWindow::on_btn2_Dot_clicked()
{
    QString text = ui->line2_Edit->text();
    if (!text.isEmpty() && text.at(text.size() - 1) != ',')
    {
        ui->line2_Edit->insert(",");
    }
}
