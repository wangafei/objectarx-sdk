Description: 
This application demonstrates the use of the AcApDocManagerReactor class which provides notification for a variety of document management events.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use DocManagerReactor.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the DocManagerReactor.zrx file in the output directory.
3. Execute the "AddDocManReactor" command to add the DocManagerReactor(Execute the "RemoveDocManReactor" to remove). The document operations such as document opening, document switching, and document closing will trigger the DocManagerReactor. For the detailed scenarios that will trigger the reactor, see the description of this class and its methods in the development document.