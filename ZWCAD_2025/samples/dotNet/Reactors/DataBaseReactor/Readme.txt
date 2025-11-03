Description: 
This application demonstrates the use of the events related to database operations, which can be used to receive the notification to be issued when an object is appended, modified, or erased from a drawing database.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use DataBaseReactor.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the DataBaseReactor.dll file in the output directory.
3. Execute the "AddReactor" command to add the DatabaseReactor(Execute the "RemoveReactor" to remove). Draw some entities, then modify them and delete them. You can find that these operations will trigger the database reactor. For the detailed scenarios that will trigger the reactor, see the description of this class and its methods in the development document.