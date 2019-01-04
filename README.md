# Vector-of-Classes
Creates a Vector of C++ Classes.  Has a singleton to provide the classes with common data.

After developing this example, I have come to several conclusions and observations: 
First, using an abstract class easily can lead to "bowl of spaghetti" code. In this example, 
I instanciated the abstract class.  This allowed the singleton reference to be passed to all children.
Additional abstract class code just led to a confusing mess.  However, it might be possible to 
make paintEvent(QPaintEvent*) a pure virtual for all of the children (I have not tried this).

Second, the basic structure looks powerful.  The MainWindow constructs the tool widgets and adds them 
to the QVector. In the same, order a corresponding button which inherits QToolButton (or QPushButton) 
is created.  This button gets the index of the tool widget.  When the button is clicked, it emits a 
signal which brings up the corresponding tool widget.

Third, the singleton repository of application data looks very good.  However, it likely would be wise 
to do a mutex lock on all singleton set and get functions.
