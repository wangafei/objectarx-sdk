Description: 
This application demonstrates how to use the zrx interface to define lisp functions and commands.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use DefLispSample.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the DefLispSample.zrx file in the output directory.
3. Enter "(c:showhello)" or "showhello" and press Enter on the command line. The "showhello" is a lisp command defined by the zrx interfaces to print "showhellocmd". 
4. Enter "(rectarea (getpoint "The first point:\n") (getpoint "The corner point:\n"))" or "(rectarea '(0 0 0) '(100 100 0))" and press Enter on the command line. The "rectarea" is as lisp function defined by the zrx interfaces to calculate the area of the rectangle.