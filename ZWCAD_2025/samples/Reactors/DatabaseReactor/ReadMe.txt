Description: 
This application demonstrates the use of the AcDbDatabaseReactor class, which can be used to receive the notification to be issued when an object is appended, modified, or erased from a drawing database.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use DatabaseReactor.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the DatabaseReactor.zrx file in the output directory.
3. Execute the "AddDBReactor" command to add the DatabaseReactor(Execute the "RemoveReactor" to remove). Draw some entities, then modify them and delete them. You can find that these operations will trigger the database reactor. For the detailed scenarios that will trigger the reactor, see the description of this class and its methods in the development document.