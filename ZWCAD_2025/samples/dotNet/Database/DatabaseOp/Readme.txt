Description: 
This application implements three commands to demonstrate the use of the operations of the dwg database.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use DatabaseOp.dll:
1. Start ZWCAD and open a new drawing .
2. Run NETLOAD command and load the DatabaseOp.dll file in the output directory.
3. Execute the "CreateDwgTest" command, which creates a new database and saves as "testDrawing2.dwg" file in the document directory.
4. Execute the "ReadDwgFileTest" command, which reads "testDrawing2.dwg" in the document directory and prints the information of entities.
5. Execute the "OpenDwgFileTest" command, which opens "testDrawing2.dwg" in the document directory.