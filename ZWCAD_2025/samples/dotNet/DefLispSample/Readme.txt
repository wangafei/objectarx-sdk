Description: 
This application demonstrates how to use the .NET interface to define lisp functions.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use DefLispSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the DefLispSample.dll file in the output directory.
3. Enter "HelloCS" and press Enter on the command line, and the "Hello World!" will be printed. This is a example of a registration command with .NET.
4. Enter "(rectarea (getpoint "The first point:\n") (getpoint "The corner point:\n"))" or "(rectarea '(0 0 0) '(100 100 0))" and press Enter on the command line. The "rectarea" is as lisp function defined by the .NET interfaces to calculate the area of the rectangle.