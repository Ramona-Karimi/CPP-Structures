// ============================== Header ====================
/*  Author: Ramona Karimi
    Program Description: Using structures and other programming concepts to give user two options of calculations for graphs.
    Date Created: 2023-01-12
    Date Last Modified: 2023-01-17
*/// ===================== Pre-Processors =================
#include <iostream>
#include <limits> // for storing infinity

using namespace std;
// ======================= Structures ==============================
struct Line
{
    float slope; // infinite or real
    float intercept; // x-int or y-int
};

struct Point
{
    float xCoordinate;
    float yCoordinate;
};
// ====================== Function Prototypes ==========================
int genericMenu(int numberOfMenuOptions, string menuOptions [], string errorMsg, string menuPrompt);
void initializeLine(Line & _line, float _slope, float _intercept);
void initializePoint(Point & _point, float _xCoordinate, float _yCoordinate);
void displayArrayElementsListed(int numberOfElements, string arrayToBeDisplayed []);
void displayPointCoordinates(Point _point);
void displayEquationOfLinePassingThrough2PointsInterface();
void displayEquationOfALine(Line _line);
float determineInterceptOfALine(Point _pointOne, Point _pointTwo);
void displayIfTwoLinesIntersectInterface();
Point calculatePointOfIntersectionForTwoLines(Line _firstLine, Line _secondLine);
float calculateSlopeOfLinePassingThroughTwoPoints(Point _pointOne, Point _pointTwo);
// ====================== Function Definitions ============================
int genericMenu(int numberOfMenuOptions, string menuOptions [], string errorMsg, string menuPrompt)
{
    int userResponse = 0; // stores user response to menu

    do // keeps menu going until user has entered valid response
    {
        cout << menuPrompt << endl; // display menu prompt for user to view
        displayArrayElementsListed(numberOfMenuOptions, menuOptions);
        cin >> userResponse; // user gives response to menu

        if (userResponse < 1 or userResponse > numberOfMenuOptions) // runs if user chooses inappropriate respnose
        {
            cout << errorMsg; // error msg displays
        }
    } while (userResponse < 1 or userResponse > numberOfMenuOptions);

    return userResponse; // returns user's choice
}

void initializeLine(Line & _line, float _slope, float _intercept)
{
    _line.slope = _slope;
    _line.intercept = _intercept;

    return;
}

void initializePoint(Point & _point, float _xCoordinate, float _yCoordinate)
{
    _point.xCoordinate = _xCoordinate;
    _point.yCoordinate = _yCoordinate;

    return;
}

void displayArrayElementsListed(int numberOfElements, string arrayToBeDisplayed [])
{
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << i + 1 << ") " << arrayToBeDisplayed[i] << endl;
    }

    return;
}

void displayPointCoordinates(Point _point)
{
    cout << "(" << _point.xCoordinate << "," << _point.yCoordinate << ")";

    return;
}

void displayEquationOfLinePassingThrough2PointsInterface()
{
    // find slope
    // find intercept
    // could just display and not use point struct
    Line userLine;
    Point userPointOne;
    Point userPointTwo;

    // now initialize....
    initializeLine(userLine, 0, 0); // just setting values for the sake of setting values,
    initializePoint(userPointOne, 5, 5); // just giving some default values
    initializePoint(userPointTwo, 1, 1);

    cout << "Enter the x-value of your first point." << endl;
    cin >> userPointOne.xCoordinate;
    cout << "Enter the y-value of your first point." << endl;
    cin >> userPointOne.yCoordinate;
    cout << "Enter the x-value of your second point." << endl;
    cin >> userPointTwo.xCoordinate;
    cout << "Enter the y-value of your second point." << endl;
    cin >> userPointTwo.yCoordinate;

    system("PAUSE");
    system("CLS");

    userLine.slope = calculateSlopeOfLinePassingThroughTwoPoints(userPointOne, userPointTwo);
    userLine.intercept = determineInterceptOfALine(userPointOne, userPointTwo);

    cout << "The equation in slope intercept form of the line that passes through the points ";
    displayPointCoordinates(userPointOne);
    cout << " and ";
    displayPointCoordinates(userPointTwo);
    cout << " is ";
    displayEquationOfALine(userLine);
    cout << "." << endl;

    system("PAUSE");
    system("CLS");

    return;
}

void displayEquationOfALine(Line _line)
{
    if (_line.slope == numeric_limits<float>::infinity()) // found infinity code on stackoverflow
    {
        cout << "x = " << _line.intercept;
    }
    else
    {
        cout << "y = ";

        if (_line.slope != 0)
        {
            cout << _line.slope << "x";
        }

        if (_line.intercept != 0)
        {
            if (_line.intercept > 0 && _line.slope != 0)
            {
                cout << " + ";
            }

            cout << _line.intercept;
        }

        return;
    }

    return;
}

float determineInterceptOfALine(Point _pointOne, Point _pointTwo)
{
    float slopeOfLine = calculateSlopeOfLinePassingThroughTwoPoints(_pointOne, _pointTwo);

    // y = mx + b
    if (slopeOfLine == numeric_limits<float>::infinity())
    {
        return _pointOne.xCoordinate;
    }
    else
    {
        return _pointOne.yCoordinate - (slopeOfLine * _pointOne.xCoordinate);
    }
}

void displayIfTwoLinesIntersectInterface()
{
    Line userFirstLine;
    Line userSecondLine;

    initializeLine(userFirstLine, 4, 0);
    initializeLine(userSecondLine, 5, 6);

    cout << "What is the slope of your first line?" << endl;
    cin >> userFirstLine.slope;
    cout << "What is the intercept of your first line?" << endl;
    cin >> userFirstLine.intercept;
    cout << "What is the slope of your second line?" << endl;
    cin >> userSecondLine.slope;
    cout << "What is the intercept of your second line?" << endl;
    cin >> userSecondLine.intercept;

    system("CLS");

    cout << "The lines ";
    displayEquationOfALine(userFirstLine);
    cout << " and ";
    displayEquationOfALine(userSecondLine);

    if (userFirstLine.slope == userSecondLine.slope && userFirstLine.intercept != userSecondLine.intercept)
    {
        cout << " are parallel and will never intersect.";
    }
    else if (userFirstLine.slope == userSecondLine.slope && userFirstLine.intercept == userSecondLine.intercept)
    {
        cout << " are the same line and will intersect infinitely.";
    }
    else
    {
        Point pointOfIntersectionBetweenTwoLines = calculatePointOfIntersectionForTwoLines(userFirstLine, userSecondLine); // could i just cout this?

        cout << " will intercept at ";
        displayPointCoordinates(pointOfIntersectionBetweenTwoLines);
        cout << ".";
    }

    cout << endl;

    system("PAUSE");
    system("CLS");

    return;
}

Point calculatePointOfIntersectionForTwoLines(Line _firstLine, Line _secondLine)
{
    Point pointOfIntersection;

    initializePoint(pointOfIntersection, 0, 0);

    //(-1 * intercept2 - (-1) * intercept1) / slope1 * -1 - slope2 * -1
    pointOfIntersection.xCoordinate = (-1 * _secondLine.intercept - -1 * _firstLine.intercept) / (_firstLine.slope * -1 - _secondLine.slope * -1);
    pointOfIntersection.yCoordinate = (_firstLine.intercept * _secondLine.slope - _secondLine.intercept * _firstLine.slope) / (_firstLine.slope * -1 - _secondLine.slope * -1);

    return pointOfIntersection;
}

float calculateSlopeOfLinePassingThroughTwoPoints(Point _pointOne, Point _pointTwo)
{
    if (_pointOne.xCoordinate == _pointTwo.xCoordinate)
    {
        return numeric_limits<float>::infinity(); // slope will be infinite
    }
    else
    {
        return (_pointOne.yCoordinate - _pointTwo.yCoordinate) / (_pointOne.xCoordinate - _pointTwo.xCoordinate);
    }
}

int main()
{
    int userResponse = 0;
    string menuOptions [3] = {"Display equation of line passing through two points.", "Display point of intersection (if existent) of two lines.","Quit."};

    do
    {
        userResponse = genericMenu(3, menuOptions, "Invalid response! Re-examine the prompt and respond accordingly.", "Pick an option from 1-3 inclusive.");

        if (userResponse == 1)
        {
            displayEquationOfLinePassingThrough2PointsInterface();
        }
        else if (userResponse == 2)
        {
            displayIfTwoLinesIntersectInterface();
        }
    } while (userResponse != 3);

    cout << "You have quit.";

    return 0;
}